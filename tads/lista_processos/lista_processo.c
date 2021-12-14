#include <stdlib.h>
#include <stdio.h>
#include "./lista_processo.h"
#include "../processo/processo.h"

void inicializaNull(Celula *celula, int index)
{
  // Cria um processo nulo
  Processo *processo = (Processo *)malloc(sizeof(Processo));
  processo->horario_criacao = NULL;
  processo->PID = -1;
  processo->prioridade = -1;

  celula->prox = index + 1;
  celula->ant = -1;
  celula->processo = processo;
}
// Inicializa uma celula com o processo passado como parametro
void inicializa_celula(Celula *celula, struct Tprocesso *processo)
{
}
// Inicializa uma lista de processos
void inicializa_lista(Lista *lista, int tamanho)
{
  lista = (Lista *)malloc(sizeof(Lista));
  lista->primeiro = -1;           // incice - cursor
  lista->ultimo = -1;             // indice - cursor
  lista->numCelOcupadas = 0;      // numero de celulas ocupadas
  lista->primeira_disponivel = 0; // indice da primeira celula disponivel
  // lista->plista = (Celula *)malloc(tamanho * (sizeof(Celula))); // aloca o lista de celulas
  //  for (int i = 0; i < tamanho; i++)
  //  {
  //    inicializaNull(&lista->plista[i], i);
  //  }
}
// Adiciona uma celula na lista
void adiciona_celula(Lista *lista, Celula *celula)
{
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