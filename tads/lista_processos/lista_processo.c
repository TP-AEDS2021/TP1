#include <stdlib.h>
#include <stdio.h>
#include "./lista_processo.h"
#include "../processo/processo.h"

// Inicializa uma celula com o processo passado como parametro
// void inicializa_celula(Celula *celula, struct Tprocesso *processo)
// {
//   celula->ant = -1;
//   celula->prox = -1;
//   celula->processo = processo;
// }
// Inicializa uma lista de processos
void inicializa_celula_nula(Celula *celula, int index)
{
  celula->prox = index + 1;
  celula->ant = -1;
}

void inicializa_lista(Lista *lista, int tamanho)
{
  lista = (Lista *)malloc(sizeof(Lista));
  lista->primeiro = -1;                                         // incice - cursor
  lista->ultimo = -1;                                           // indice - cursor
  lista->numCelOcupadas = 0;                                    // numero de celulas ocupadas
  lista->primeira_disponivel = 0;                               // indice da primeira celula disponivel
  lista->plista = (Celula *)malloc(tamanho * (sizeof(Celula))); // aloca o lista de celulas
  if (lista->plista == NULL)
  {
    printf("Erro ao inicializar a lista");
    exit(1);
  }
}

void iniciliza_celula(Celula *celula, Processo *processo)
{
  celula = (Celula *)malloc(sizeof(Celula));
  celula->ant = celula->prox = -1;
  celula->processo = processo;
}

// Adiciona uma celula na lista
void adiciona_celula(Lista *lista, Celula *celula)
{
  if (lista->numCelOcupadas == 0)
  {
    celula->ant = celula->prox = -1;
    lista->primeiro = lista->ultimo = 0;
    lista->plista[0] = *celula;
    lista->numCelOcupadas++;
    lista->primeira_disponivel = 1;
  }
  else
  {
    cursor index = lista->primeiro;
    while (lista->plista[index].prox != -1)
    {
      if (lista->plista[index].processo->PID <= celula->processo->PID)
      {
        index = lista->plista[index].prox;
        continue;
      }
      else
      {
        break;
      }
    }
    cursor aux1 = index;                     // 0
    cursor aux2 = lista->plista[index].prox; // 2
    lista->plista[lista->plista[index].prox].ant = lista->primeira_disponivel;
    lista->plista[index].prox = lista->primeira_disponivel;
    celula->prox = aux2;
    celula->ant = aux1;
    lista->numCelOcupadas++;
    int tam = (sizeof(lista->plista) / sizeof(Celula));
    if (lista->primeira_disponivel >= tam)
    {
    }
  }
}
void remove_celula(Lista *lista, int indice)
{
}
void remove_primeiro(Lista *lista)
{
}
void remove_ultimo(Lista *lista)
{
}
void imprime_lista(Lista *lista)
{
}