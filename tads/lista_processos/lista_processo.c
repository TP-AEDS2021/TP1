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
void adiciona_celula(Lista *lista, Celula *celula, int tam)
{
  if (lista->numCelOcupadas == tam)
  {
    printf("\nERRO - Lista cheia");
  }
  else
  {
    if (lista->numCelOcupadas == 0)
    {
      lista->primeiro = lista->ultimo = lista->primeira_disponivel;
      celula->ant = celula->prox = -1;
      lista->plista[lista->primeira_disponivel] = *celula;
      lista->primeira_disponivel = lista->plista[lista->primeira_disponivel].prox;
    }
    else
    {
      cursor aux = lista->plista[lista->primeira_disponivel].prox;
      if (celula->processo->PID < lista->plista[lista->primeiro].processo->PID)
      {
        celula->ant = -1;
        celula->prox = lista->primeiro;
        lista->plista[lista->primeira_disponivel] = *celula;
        lista->plista[lista->primeiro].ant = lista->primeira_disponivel;
        lista->primeiro = lista->primeira_disponivel;
        lista->primeira_disponivel = aux;
      }
      else if (celula->processo->PID > lista->plista[lista->ultimo].processo->PID)
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
    /*if (lista->numCelOcupadas == 1)
    {
      if (celula->processo->PID >= lista->plista[lista->primeiro].processo->PID)
      {
        celula->ant = lista->primeiro;
        celula->prox = -1;
        lista->plista[lista->primeira_disponivel] = *celula;
        lista->ultimo = 1;
        lista->numCelOcupadas++;
      }
      else
      {
      }
    }
    else
    {
      
      if (lista->numCelOcupadas >= lista->tam)
      {
        printf("Lista cheia");
        return;
      }
      cursor index = lista->primeiro;
      while (lista->plista[index].prox != -1)
      {
        if (lista->plista[index].processo->PID <= celula->processo->PID)
        {
          index++;
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
    }*/
    lista->numCelOcupadas++;
  }
}

/*int buscaDisp(Lista *lista){
  int i = -1;
  for(int j = 0; j < lista->tam; j++){
    if(lista->plista[j].processo == NULL){
      i = j;
      break;
    }
  }
  return i;


}

void adiciona_celula2(Lista *lista, Celula *celula, int tam)
{
  if (lista->numCelOcupadas == 0)
  {
    celula->ant = celula->prox = -1;
    lista->primeiro = lista->ultimo = 0;
    lista->plista[0] = *celula;
    lista->numCelOcupadas++;
    lista->primeira_disponivel = 1;
    return;
  }
  else
  {

    if (lista->numCelOcupadas >= tam)
    {
      printf("Lista cheia");
      return;
    }
    cursor index = lista->primeiro;
    //Insere no inicio da lista
    if(celula->processo->PID <= lista->plista[index].processo->PID ){
      cursor indice_primeiro = lista->primeiro;
      cursor aux = lista->plista[lista->primeira_disponivel].prox;
      celula->prox = indice_primeiro;
      celula->ant = -1;
      lista->plista[lista->primeiro].ant = lista->primeira_disponivel;
      if(lista->plista[lista->primeiro].prox == -1){
        
      }
      lista->primeiro = lista->primeira_disponivel;
      lista->plista[lista->primeira_disponivel] = *celula;
      lista->primeira_disponivel = aux;
      lista->numCelOcupadas++;
      return;
    }
    //insere no meio da lista
    while (lista->plista[index].processo->PID <= celula->processo->PID)
    {
      if ((lista->plista[index].prox == -1) && (lista->numCelOcupadas == 1))
      {
        int index_primeiro = lista->primeiro;
        celula->ant = index_primeiro;
        celula->prox = -1;
        lista->plista[lista->primeiro].prox = lista->primeira_disponivel;
        lista->ultimo = lista->primeira_disponivel;
        lista->plista[lista->primeira_disponivel] = *celula;
        int disp = buscaDisp(lista);
        if(disp != -1){
          printf("lista cheia");
          return;
        }
        lista->primeira_disponivel = disp;
        break;
      }
      else
      {
        index++;
        continue;
      }
    }
    printf("%d\n", index);
    return;
  }
}*/

void remove_primeiro(Lista *lista, int indice)
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
}