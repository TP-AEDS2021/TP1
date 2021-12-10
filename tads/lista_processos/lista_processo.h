#ifndef LISTA_PROCESSO_H
#define LISTA_PROCESSO_H

#include "./tads/processo/processo.h"

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

void inicializa_celula(Celula *celula);
void inicializa_lista(Lista *lista);
void adiciona_celula(Lista *lista, Celula *celula);

#endif // LISTA_PROCESSO_H