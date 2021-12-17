#ifndef LISTA_PROCESSO_H
#define LISTA_PROCESSO_H

#include "../processo/processo.h"

typedef int cursor;

typedef struct Tcelula {
  Processo *processo;
  cursor ant;
  cursor prox;
} Celula;

typedef struct Tlista {
  cursor primeiro;
  cursor primeira_disponivel;
  cursor ultimo;
  int numCelOcupadas;
  Celula *plista;
  int tam;
} Lista;

Celula *inicializa_celula(Celula *, Processo *);
void inicializa_celula_nula(Celula *, int);
Lista * inicializa_lista(Lista *lista, int tamanho);
void adiciona_celula(Lista *lista, Celula *celula);
void remove_primeiro(Lista *lista);
void imprime_lista(Lista *lista);
void num_celulas_ocupadas(Lista *lista);
int get_celulas_ocupadas(Lista *lista);
void get_lista(Lista *, char*);

#endif // LISTA_PROCESSO_H