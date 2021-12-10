#include <stdlib.h>
#include ".\lista_processos\lista_processo.h"
#include ".\processo\processo.h"

// Inicializa uma celula com o processo passado como parametro
void inicializa_celula(Celula *celula, struct Tprocesso *processo) {
  celula->prox = NULL;
  celula->ant = NULL;
  celula->processo = processo;
}
// Inicializa uma lista de processos
void inicializa_lista(Lista *vetor, int tamanho){
  vetor->primeiro = 0;//incice
  vetor->ultimo = 0;//indice
  vetor->numCelOcupadas = 0;//numero de celulas ocupadas
  vetor->celula_disponivel = 0;//indice da primeira celula disponivel
  vetor->lista = (Celula*) malloc(tamanho * sizeof(Celula));
}
// Adiciona uma celula na lista
void adiciona_celula(Lista *lista, Celula *celula){

}
void remove_celula(Lista *lista, int indice){

}
void remove_primeiro(Lista *lista){

}
void remove_ultimo(Lista *lista){

}
void imprime_lista(Lista *lista){

}