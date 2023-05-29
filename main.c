/**** INÍCIO do Código ****/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/** Operações de Pilha **/
#define STACK_MAX_SIZE 100 // tamanho máximo da pilha

typedef struct stack Stack; // tipo abstrato Pilha
typedef int elm_t;          // tipo de elemento da pilha

struct stack {
  int top;
  elm_t data[STACK_MAX_SIZE];
};

Stack *stk_alloc(); // aloca, inicializa e retorna um ponteiro para um novo
                    // objeto Pilha
void stk_free(Stack *stk); // desaloca o objeto Pilha stk alocado com stk_alloc
bool stk_isempty(Stack *stk); // retorna true se a pilha stk estiver vazia, e
                              // false caso contrário
bool stk_isfull(Stack *stk);  // retorna false se a pilha stk estiver cheia, e
                              // false caso contrário
void stk_push(Stack *stk, elm_t i); // empilha o elemento i na pilha stk
elm_t stk_pop(Stack *stk); // remove e retorna o elemento do topo da pilha stk
elm_t stk_top(
    Stack *stk); // retorna o elemento do topo da pilha stk, sem removê-lo
void imprimir(Stack *stk);

/** Operações das Questões **/
// Questão 1
// implemente AQUI a operação da questão 1
// comente a sua implementação!


//torna i como o segundo elemento da pilha
bool segundo_alterada(Stack *stk, int i) {
  bool valido = true;
  int a;

  if (!stk_isempty(stk)) {
    a = stk_pop(stk); // guarda o elemento retirado

    if (!stk_isempty(stk)) {
      stk_pop(stk);     // retira o segundo elemento
      stk_push(stk, i); // adiciona o elemento i
    } else {
      stk_push(stk, a); // caso a pilha possua apenas 1 elemento, ele é
                        // devolvido
      valido = false;
    }
  } else {
    valido = false;
  }
  return valido;
};

// Questão 2
// implemente AQUI a operação da questão 2
// comente a sua implementação!

//torna i como o segundo elemento da pilha, sem alterar seus elementos originais
bool segundo_inalterada(Stack *stk, int i) {
  bool valido = true;
  int a;

  if (!stk_isempty(stk)) {
    a = stk_pop(stk);       // retiro o primeiro elemento e armazeno em a
    stk_push(stk, i);       // coloco o elemento i no topo da pilha
    if (!stk_isfull(stk)) { // verifica se a pilha está cheia
      stk_push(stk, a);     // coloco novamente o elemento a no topo da pilha
    } else {
      stk_pop(stk);     // retiro o elemento adc
      stk_push(stk, a); // reconstroi a pilha original
      valido = false;
    }

  } else {
    valido = false;
  }
  return valido;
}

// Questão 3
// implemente AQUI a operação da questão 3
// comente a sua implementação!


// define i como o n_esimo elemento
bool n_esimo_alterado(Stack *stk, int n, int i) {
  bool valido = true;
  elm_t lista[n];
  if (!stk_isempty(
          stk)) { // verifico se a pilha está vazia e se a quantidade de
                  // elementos da pilha é maior ou igual ao n recebido
    for (int c = 0; c < n; c++) {
      if (!stk_isempty(stk)) {
        lista[c] = stk_pop(
            stk); // retiro os n elementos da pilha e armazeno na array lista
      } else {
        for (int i = c - 1; i >= 0; i--) {
          stk_push(stk, lista[i]); // em caso de problema, resconstruo a pilha
        }
        return false;
      }
    }

  } else {
    valido = false;
  }

  if (valido) {
    stk_push(stk, i); // adc o elemento i apenas de a operação de retirada dos n
                      // elementos foi bem sucedida
  }
  return valido;
}

// Questão 4
// implemente AQUI a operação da questão 4
// comente a sua implementação!

// define i como o n_esimo elemento, sem alterar seus elementos
bool n_esimo_inalterado(Stack *stk, int n, int i) {
  bool valido = true;
  elm_t lista[n];
  if (!stk_isempty(
          stk)) { // verifico se a pilha está vazia e se a qnt de elementos da
                  // pilha é igual ou maior que o n recebido
    for (int c = 0; c < n - 1; c++) {
      if (!stk_isempty(stk)) {
        lista[c] = stk_pop(stk); // adc os elementos retirados na array lista
      } else {
        for (int i = c - 1; i >= 0; i--) {
          stk_push(stk, lista[i]); // caso de erro, reconstruo a lista
          return false;
        }
      }
    }

  } else {
    valido = false;
  }
  if (valido) {
    stk_push(stk, i); // adc o elemento i
    for (int a = n - 2; a >= 0; a--) {
      stk_push(stk, lista[a]); // empilho os elementos retirados anteriormente
    }
  }
  return valido;
}

// Questão 5
// implemente AQUI a operação da questão 5
// comente a sua implementação!

//define i como o ultimo elemento da pilha
bool ultimo_alterada(Stack *stk, int i) {
  while (!stk_isempty(stk)) {
    stk_pop(stk); // enquanto a pilha nao estiver vazia, eu retiro todos os
                  // elementos
  }
  stk_push(stk, i); // adc o elemento i
  return true;
}

// Questão 6
// implemente AQUI a operação da questão 6
// comente a sua implementação!


//define i como o ultimo elemento da pilha, sem alterar seus elementos
bool ultimo_inalterada(Stack *stk, int i) {

  if (stk_isfull(stk)) {
    return false; // se a pilha está cheia, retorno false
  }

  int lista[STACK_MAX_SIZE];
  int c = -1;
  while (!stk_isempty(stk)) {
    c++;
    lista[c] = stk_pop(stk); // retiro todos os elementos e adc na array lista
  }

  stk_push(stk, i); // adc o elemento i

  while (c >= 0) {
    stk_push(stk, lista[c]); // reconstruo a pilha
    c--;
  }

  return true;
}

/** Programa Principal **/
int main(int argc, char *argv[]) {

  // criação de pilha com elementos para testes
  Stack *com_elementos = stk_alloc();
  stk_push(com_elementos, 1);
  stk_push(com_elementos, 2);
  stk_push(com_elementos, 3);
  stk_push(com_elementos, 4);
  stk_push(com_elementos, 5);
  stk_push(com_elementos, 6);

  // criação de pilha vazia para testes:
  Stack *vazia = stk_alloc();

  // criação de pilha com um elemento para teste:
  Stack *um_elemento = stk_alloc();
  stk_push(um_elemento, 1);

  // PILHAS DE TESTES!!!!
  // atribua o a essa variavel o valor "com_elementos", para testar uma pilha
  // com dois ou mais elementos, "vazia" para testar com uma pilha vazia ou
  // "um_elemento", para testar com uma pilha de apenas um elemento
  Stack *pilha = com_elementos; // pilha para as questãos

  // Teste da Questão 1
  // imprima a pilha de testes antes e depois da execução da operação
  // comente o seu teste! Teste os casos excepcionais!

  printf("\t TESTE DA QUESTÃO 1: \t\n");

  printf("Pilha original: ");
  imprimir(pilha);
  bool valido = segundo_alterada(pilha, 2);
  if (valido) {
    printf("\nOperação realizada com sucesso! Pilha alterada: ");
    imprimir(pilha);
  } else {
    printf("\nERRO: a pilha permanece inalterada: ");
    imprimir(pilha);
  }

  // Teste da Questão 2
  // imprima a pilha de testes antes e depois da execução da operação
  // comente o seu teste! Teste os casos excepcionais!

  printf("\n\n\t TESTE DA QUESTÃO 2: \t\n");

  printf("Pilha original: ");
  imprimir(pilha);
  bool valido2 = segundo_inalterada(pilha, 1);
  if (valido2) {
    printf("\nOperação realizada com sucesso! Pilha alterada: ");
    imprimir(pilha);
  } else {
    printf("\nERRO: a pilha permanece inalterada: ");
    imprimir(pilha);
  }

  // Teste da Questão 3
  // imprima a pilha de testes antes e depois da execução da operação
  // comente o seu teste! Teste os casos excepcionais!

  printf("\n\n\t TESTE DA QUESTÃO 3: \t\n");

  printf("Pilha original: ");
  imprimir(pilha);
  bool valido3 = n_esimo_alterado(pilha, 3, 7);
  if (valido3) {
    printf("\nOperação realizada com sucesso! Pilha alterada: ");
    imprimir(pilha);
  } else {
    printf("\nERRO: a pilha permanece inalterada: ");
    imprimir(pilha);
  }

  // Teste da Questão 4
  // imprima a pilha de testes antes e depois da execução da operação
  // comente o seu teste! Teste os casos excepcionais!

  printf("\n\n\t TESTE DA QUESTÃO 4: \t\n");

  printf("Pilha original: ");
  imprimir(pilha);
  bool valido4 = n_esimo_inalterado(pilha, 3, 0);
  if (valido4) {
    printf("\nOperação realizada com sucesso! Pilha alterada: ");
    imprimir(pilha);
  } else {
    printf("\nERRO: a pilha permanece inalterada: ");
    imprimir(pilha);
  }

  // Teste da Questão 5
  // imprima a pilha de testes antes e depois da execução da operação
  // comente o seu teste! Teste os casos excepcionais!

  printf("\n\n\t TESTE DA QUESTÃO 5: \t\n");

  printf("Pilha original: ");
  imprimir(pilha);
  bool valido5 = ultimo_alterada(pilha, 9);
  if (valido5) {
    printf("\nOperação realizada com sucesso! Pilha alterada: ");
    imprimir(pilha);
  } else {
    printf("\nERRO: a pilha permanece inalterada: ");
    imprimir(pilha);
  }

  // Teste da Questão 6
  // imprima a pilha de testes antes e depois da execução da operação
  // comente o seu teste! Teste os casos excepcionais!

  printf("\n\n\t TESTE DA QUESTÃO 6: \t\n");

  printf("Pilha original: ");
  imprimir(pilha);
  bool valido6 = ultimo_inalterada(pilha, 8);
  if (valido6) {
    printf("\nOperação realizada com sucesso! Pilha alterada: ");
    imprimir(pilha);
  } else {
    printf("\nERRO: a pilha permanece inalterada: ");
    imprimir(pilha);
  }

  return EXIT_SUCCESS;
}

/** Implementação das Operações de Pilha **/
// implemente AQUI as estruturas e operações de Pilha definidas acima.

Stack *stk_alloc() {
  Stack *stk = (Stack *)malloc(sizeof(
      struct stack)); // usa o malloc para fazer a alocação da pilha na memoria
                      // heap, com uma tamanho de um "struct stack"
  stk->top =
      -1; // inicializa o topo da pilha como "-1", para indicar pilha vazia

  return stk; // retorna a pilha
};

void stk_free(Stack *stk) {
  free(stk); // desaloca a pilha da memoria
};

bool stk_isempty(Stack *stk) {
  if (stk->top == -1) { // verifica se o topo da pilha é "-1", ou seja, se está
                        // vazia. Se sim, retorna true, se não, retorna false.
    return true;
  } else {
    return false;
  }
};

bool stk_isfull(Stack *stk) {
  if (stk->top == STACK_MAX_SIZE -
                      1) { // verifica se o topo da pilha, que guarda a
                           // quantidade de elementos, é igual ao tamanho
                           // máximo, se sim, retorna true, se não retorna false
    return true;
  } else {
    return false;
  }
};

void stk_push(Stack *stk, elm_t i) {
  stk->top++; // incrementa o valor do topo
  stk->data[stk->top] =
      i; // adiciona o elemento recebido no parametro no topo da pilha
};

elm_t stk_pop(Stack *stk) {
  // armazeno o valor removido
  elm_t pop = stk->data[stk->top];
  stk->top--; // decremento o valor do topo
  return pop;
}; // remove e retorna o elemento do topo da pilha stk

elm_t stk_top(Stack *stk) {
  // elm_t top = stk_pop(stk);
  // stk_push(stk, top);

  return stk->data[stk->top]; // retorna o elemento que está no topo
};

void imprimir(Stack *stk) { // imprime todos os elementos da pilha
  printf("[ ");
  for (int c = 0; c <= stk->top; c++) {
    printf("%d ", stk->data[c]);
  }
  printf("]\n");
}

/**** FIM do Código ****/