#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "processo.h"
#include "../../utils/utils.c"

// funcao para inicializar o processo
void inicializa_processo(Processo *processo)
{
  set_PID(processo, rand());
  set_prioridade(processo, (rand() % 5) + 1);
  set_horario_criacao(processo, currentTime());
}

// funcao para imprimir o processo
void imprime_processo(Processo processo)
{
  printf("|\t%d\t|\t%d\t|\t %d-%d-%d \t|\n", processo.PID, processo.prioridade, processo.horario_criacao->tm_hour, processo.horario_criacao->tm_min, processo.horario_criacao->tm_sec);
  printf("OK");
  return;
}

// retorna o PID do processo
int get_PID(Processo *processo)
{
  return processo->PID;
}

// define o PID do processo
void set_PID(Processo *processo, int PID)
{
  processo->PID = PID;
}

// retorna a prioridade do processo
int get_prioridade(Processo *processo)
{
  return processo->prioridade;
}

// define a prioridade do processo
void set_prioridade(Processo *processo, int prioridade)
{
  processo->prioridade = prioridade;
}
// retorna o horario de criacao do processo
struct tm *get_horario_criacao(Processo *processo)
{
  return processo->horario_criacao;
}
// define o horario de criacao do processo
void set_horario_criacao(Processo *processo, struct tm *horario)
{
  processo->horario_criacao = horario;
}