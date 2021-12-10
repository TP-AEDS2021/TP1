#ifndef LISTA_PROCESSO_H
#define LISTA_PROCESSO_H

#include "../processo/processo.h"

typedef struct Tcelula {
  struct Tprocesso *processo;
  int ant;
  int prox;
} Celula;

typedef struct Tlista {
  int primeiro;
  int celula_disponivel;
  int ultimo;
  int numCelOcupadas;
  Celula *lista;
} Lista;

void inicializa_celula(Celula *celula, struct Tprocesso *processo);
void inicializa_lista(Lista *lista, int tamanho);
void adiciona_celula(Lista *lista, Celula *celula);
void remove_celula(Lista *lista, int indice);
void remove_primeiro(Lista *lista);
void remove_ultimo(Lista *lista);
void imprime_lista(Lista *lista);

#endif // LISTA_PROCESSO_H