#include <stdlib.h>
#include <stdio.h>
#include "./lista_processo.h"
#include "../processo/processo.h"

void inicializa_celula_nula(Celula *celula, int index)
{
  celula->prox = index + 1;
  celula->ant = -1;
}

Celula *inicializa_celula(Celula *celula, Processo *processo)
{
  celula = (Celula *)malloc(sizeof(Celula));
  celula->ant = celula->prox = -1;
  celula->processo = processo;
  return celula;
}
Lista *inicializa_lista(Lista *lista, int tamanho)
{
  lista = (Lista *)malloc(sizeof(Lista));
  lista->tam = tamanho;
  lista->primeiro = -1;                                         // incice - cursor
  lista->ultimo = -1;                                           // indice - cursor
  lista->numCelOcupadas = 0;                                    // numero de celulas ocupadas
  lista->primeira_disponivel = 0;                               // indice da primeira celula disponivel
  lista->plista = (Celula *)malloc(tamanho * (sizeof(Celula))); // aloca o lista de celulas
  for (int i = 0; i < tamanho; i++)
  {
    lista->plista[i].ant = -1;
    lista->plista[i].processo = NULL;
    if (i == tamanho - 1)
    {
      lista->plista[i].prox = -1;
    }
    else
    {
      lista->plista[i].prox = i + 1;
    }
  }

  if (lista->plista == NULL)
  {
    printf("Erro ao inicializar a lista");
    exit(1);
  }
  return lista;
}

// Adiciona uma celula na lista
void adiciona_celula(Lista *lista, Celula *celula)
{
  if (lista->numCelOcupadas == lista->tam)
  {
    printf("\nERRO - Lista cheia");
    return;
  }
  else
  {
    cursor aux = lista->plista[lista->primeira_disponivel].prox;
    if (lista->numCelOcupadas == 0)
    {
      
      lista->primeiro = lista->ultimo = lista->primeira_disponivel;
      celula->ant = celula->prox = -1;
      lista->plista[lista->primeira_disponivel] = *celula;
      lista->primeira_disponivel = aux;
    }
    else
    {
      if (celula->processo->PID <= lista->plista[lista->primeiro].processo->PID)
      {
        celula->ant = -1; 
        celula->prox = lista->primeiro;
        lista->plista[lista->primeira_disponivel] = *celula;
        lista->plista[lista->primeiro].ant = lista->primeira_disponivel;
        lista->primeiro = lista->primeira_disponivel;
        // TODO:Concertar celula disponivel
        
        lista->primeira_disponivel = aux;
      }
      else if (celula->processo->PID >= lista->plista[lista->ultimo].processo->PID)
      {
        celula->prox = -1;
        celula->ant = lista->ultimo;
        lista->plista[lista->ultimo].prox = lista->primeira_disponivel;
        lista->plista[lista->primeira_disponivel] = *celula;
        lista->ultimo = lista->primeira_disponivel;
        lista->primeira_disponivel = aux;
      }
      else
      {
        cursor index = lista->primeiro;
        while (lista->plista[index].processo->PID < celula->processo->PID)
        {
          if(lista->plista[lista->plista[index].prox].processo->PID > celula->processo->PID)
          {
            celula->ant = index;
            celula->prox = lista->plista[index].prox;
            lista->plista[lista->plista[index].prox].ant = lista->primeira_disponivel;
            lista->plista[index].prox = lista->primeira_disponivel;
            lista->plista[lista->primeira_disponivel] = *celula;
            lista->primeira_disponivel = aux;// lista->plista[lista->primeira_disponivel].prox;
          }
          index = lista->plista[index].prox;
        }
      }
    }
    lista->numCelOcupadas++;
  }
}

void remove_primeiro(Lista *lista)
{
  cursor aux = lista->primeira_disponivel;
  while (lista->primeiro > aux)
  {
    cursor aux2 = aux;
    aux = lista->plista[aux].prox;
    if (lista->primeiro < aux)
    {
      lista->plista[aux2].prox = lista->primeiro;
      break;
    }
  }
  cursor aux3 = lista->plista[lista->primeiro].prox;
  if (lista->plista[lista->primeiro].prox != -1)
  {
    lista->plista[lista->plista[lista->primeiro].prox].ant = -1;
  }
  if (lista->primeiro < lista->primeira_disponivel)
  {
    lista->primeira_disponivel = lista->primeiro;
  }
  lista->primeiro = lista->plista[lista->primeiro].prox;
  aux3 = aux;
  lista->numCelOcupadas--;
  if (lista->numCelOcupadas == 0)
  {
    lista->primeiro = lista->ultimo = -1;
  }
}
void imprime_lista(Lista *lista)
{

  // imprime a lista de processos
  printf("\nLista de processos:\n");
  Celula aux = lista->plista[lista->primeiro];
  while (aux.prox != -1)
  {
    printf("\nPID: %llu - prioridade: %d\n", aux.processo->PID, aux.processo->prioridade);
    aux = lista->plista[aux.prox];
  }
  return;
}