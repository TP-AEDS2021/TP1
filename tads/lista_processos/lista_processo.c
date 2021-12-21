#include <stdlib.h>
#include <stdio.h>
#include "./lista_processo.h"
#include "../processo/processo.h"
#include <string.h>

Celula *inicializa_celula(Celula *celula, Processo *processo)
{
  celula = (Celula *)malloc(sizeof(Celula));
  celula->ant = celula->prox = -1;
  celula->processo = processo;
  return celula;
}
Lista *inicializa_lista(Lista *lista, long int tamanho)
{
  lista = (Lista *)malloc(sizeof(Lista));
  lista->tam = tamanho;
  lista->primeiro = -1;                                         // incice - cursor
  lista->ultimo = -1;                                           // indice - cursor
  lista->numCelOcupadas = 0;                                    // numero de celulas ocupadas
  lista->primeira_disponivel = 0;                               // indice da primeira celula disponivel
  lista->plista = (Celula *)malloc(tamanho * (sizeof(Celula))); // aloca o lista de celulas
  for (long i = 0; i < tamanho; i++)
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

void adiciona_celula(Lista *lista, Celula *celula)
{
  if (lista->numCelOcupadas == lista->tam)
  {
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
          if (lista->plista[lista->plista[index].prox].processo->PID > celula->processo->PID)
          {
            celula->ant = index;
            celula->prox = lista->plista[index].prox;
            lista->plista[lista->plista[index].prox].ant = lista->primeira_disponivel;
            lista->plista[index].prox = lista->primeira_disponivel;
            lista->plista[lista->primeira_disponivel] = *celula;
            lista->primeira_disponivel = aux; // lista->plista[lista->primeira_disponivel].prox;
          }
          index = lista->plista[index].prox;
        }
      }
    }
    lista->numCelOcupadas++;
  }
}

void remove_primeiro_teste(Lista *lista)
{
  if (lista->primeiro == -1)
  {
    return;
  }
  // se a lista não estiver vazia
  if (lista->numCelOcupadas != 0)
  {
    cursor aux, aux2, aux3, aux4;
    // se a lista tem mais de um elemento
    if (lista->plista[lista->primeiro].prox != -1)
    {
      // define o anterior do segundo elemento como -1
      if (lista->primeiro == -1)
      {
        aux4 = 0;
        for (long i = 0; i < lista->tam; i++)
        {
          if (lista->plista[i].processo != NULL)
          {
            if (lista->plista[i].processo < lista->plista[aux].processo)
            {
              aux = i;
            }
          }
        }
        lista->primeiro = aux;
      }
      lista->plista[lista->plista[lista->primeiro].prox].ant = -1;

      // a lista estava completamente cheia
      if (lista->primeira_disponivel == -1)
      {
        lista->primeira_disponivel = lista->primeiro;
        // segundo elemento
        aux = lista->plista[lista->primeiro].prox;

        lista->plista[lista->primeiro].prox = -1;
        lista->primeiro = aux;
      }
      if (lista->primeiro == -1)
      {
        aux4 = 0;
        for (long i = 0; i < lista->tam; i++)
        {
          if (lista->plista[i].processo != NULL)
          {
            if (lista->plista[i].processo < lista->plista[aux].processo)
            {
              aux = i;
            }
          }
        }
        lista->primeiro = aux;
      }
      // a lista tem somente uma posicao vazia
      else if (lista->plista[lista->primeira_disponivel].prox == -1 && lista->primeiro > lista->primeira_disponivel)
      {
        lista->plista[lista->primeira_disponivel].prox = lista->primeiro;
        lista->plista[lista->primeiro].ant = -1;
        aux = lista->plista[lista->primeiro].prox;
        lista->plista[lista->primeiro].prox = -1;
        lista->primeiro = aux;
        lista->plista[lista->primeiro].ant = -1;
      }
      else if (lista->plista[lista->primeira_disponivel].prox == -1 && lista->primeiro < lista->primeira_disponivel)
      {
        lista->plista[lista->plista[lista->primeiro].prox].ant = -1;
        aux = lista->primeira_disponivel;
        lista->primeira_disponivel = lista->primeiro;
        lista->plista[lista->primeira_disponivel].prox = aux;
      }
      else if (lista->primeiro < lista->primeira_disponivel)
      {
        aux = lista->primeira_disponivel;
        lista->primeira_disponivel = lista->primeiro;
        aux2 = lista->primeiro;
        lista->primeiro = lista->plista[lista->primeiro].prox;

        lista->plista[aux2].prox = aux;
      }
      else
      {
        aux = lista->primeira_disponivel;
        while (lista->primeiro > aux)
        {

          aux = lista->plista[aux].prox;
        }
        lista->plista[aux].prox = lista->primeiro;
        aux3 = lista->plista[lista->primeiro].prox;
        lista->plista[lista->primeiro].prox = aux;
        if (aux3 == -1)
        {
          return;
        }
        lista->primeiro = aux3;
      }
    }
    // a lista só tem um elemento
    else
    {
      if (lista->primeiro < lista->primeira_disponivel)
      {
        lista->plista[lista->primeiro].prox = lista->primeira_disponivel;
        lista->primeira_disponivel = 0;
        lista->primeiro = lista->ultimo = -1;
      }
      else
      {
        aux = lista->primeira_disponivel;
        while (lista->primeiro > aux)
        {
          aux2 = aux;
          aux = lista->plista[aux].prox;
        }
        lista->plista[aux2].prox = lista->primeiro;
        lista->plista[lista->primeira_disponivel].prox = aux;
        lista->primeiro = lista->ultimo = -1;
      }
    }
    lista->numCelOcupadas--;
  }
  else
  {
    printf("vazia");
  }
}

void remove_primeiro(Lista *lista)
{
  if (lista->numCelOcupadas != 0 && lista->primeiro != -1)
  {
    cursor aux, aux2, aux3;
    if (lista->primeira_disponivel == -1)
    {
      lista->plista[lista->plista[lista->primeiro].prox].ant;
      lista->primeira_disponivel = lista->primeiro;
      aux = lista->plista[lista->primeiro].prox;
      lista->plista[lista->primeiro].prox = -1;
      lista->primeiro = aux;
    }
    else if (lista->plista[lista->primeira_disponivel].prox == -1)
    {
      lista->plista[lista->primeira_disponivel].prox = lista->primeiro;
      lista->plista[lista->primeiro].ant = -1;
      aux = lista->plista[lista->primeiro].prox;
      lista->plista[lista->primeiro].prox = -1;
      lista->primeiro = aux;
    }
    else
    {
      if (lista->plista[lista->primeiro].prox != -1)
      {
        lista->plista[lista->plista[lista->primeiro].prox].ant = -1;
      }
      aux = lista->primeira_disponivel;
      aux3 = lista->plista[lista->primeiro].prox;
      while (lista->primeiro > aux)
      {
        aux2 = aux;
        aux = lista->plista[aux].prox;
        if (lista->primeiro < aux || aux == -1)
        {
          lista->plista[aux2].prox = lista->primeiro;
          lista->plista[lista->primeiro].prox = aux;
          break;
        }
      }
      if (lista->primeiro < lista->primeira_disponivel)
      {
        lista->plista[lista->primeiro].prox = lista->primeira_disponivel;
        lista->plista[lista->primeiro].ant = -1;
        lista->primeira_disponivel = lista->primeiro;
      }
      lista->primeiro = aux3;
      lista->numCelOcupadas--;
      if (lista->numCelOcupadas == 0)
      {
        lista->primeiro = lista->ultimo = -1;
      }
    }
  }
}

void imprime_lista(Lista *lista)
{

  // imprime a lista de processos
  if (lista->numCelOcupadas == 0)
  {
    printf("Lista vazia\n");
    return;
  }
  printf("\nLista de processos:\n");
  Celula aux = lista->plista[lista->primeiro];
  if(lista->numCelOcupadas == 1){
    imprime_processo(aux.processo);//printf("%llu\n", aux.processo->PID);
    return;
  }
  while (aux.prox != -1)
  {
    imprime_processo(aux.processo);
    aux = lista->plista[aux.prox];
  }
  imprime_processo(lista->plista[lista->ultimo].processo);
  return;
}

long get_celulas_ocupadas(Lista *lista)
{
  return lista->numCelOcupadas;
}

void num_celulas_ocupadas(Lista *lista)
{
  printf("\nNumero de celulas ocupadas: %ld\n", get_celulas_ocupadas(lista));
}