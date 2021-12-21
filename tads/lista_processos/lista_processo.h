#ifndef LISTA_PROCESSO_H
#define LISTA_PROCESSO_H

#include "../processo/processo.h"

typedef long int cursor;

typedef struct Tcelula {
  Processo *processo;
  cursor ant;
  cursor prox;
} Celula;

typedef struct Tlista {
  cursor primeiro;
  cursor primeira_disponivel;
  cursor ultimo;
  long int numCelOcupadas;
  Celula *plista;
  long int tam;
} Lista;

Celula *inicializa_celula(Celula *, Processo *);
Lista * inicializa_lista(Lista *lista,long int tamanho);
void adiciona_celula(Lista *lista, Celula *celula);
void remove_primeiro(Lista *lista);
void imprime_lista(Lista *lista);
void num_celulas_ocupadas(Lista *lista);
long int get_celulas_ocupadas(Lista *lista);

#endif // LISTA_PROCESSO_H