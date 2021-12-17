#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "processo.h"
#include "../../utils/utils.c"
#include <inttypes.h>

unsigned long long rand_uint64_slow(void)
{
  unsigned long long r = 0;
  for (int i = 0; i < 64; i++)
  {
    r = r * 2 + rand() % 2;
  }
  return r;
}

// funcao para inicializar o processo
Processo* inicializa_processo(Processo *processo)
{
  processo = (Processo *)malloc(sizeof(Processo));
  srand(time(NULL));
  unsigned long long pid = rand_uint64_slow();
  if(pid <= 0)
  {
    pid = pid * -1;
  }
  set_PID(processo, pid );
  srand(time(NULL));
  srand(time(NULL));
  set_prioridade(processo, (rand() % 5) + 1);
  printf("prioridade: %d\n", get_prioridade(processo));
  set_horario_criacao(processo, currentTime());
  return processo;
}

// funcao para imprimir o processo
void imprime_processo(Processo* processo)
{
  printf("|\t%lu\t|\t%d\t|\t %d-%d-%d \t|\n", processo->PID, processo->prioridade, processo->horario_criacao->tm_hour, processo->horario_criacao->tm_min, processo->horario_criacao->tm_sec);
  return;
}

// retorna o PID do processo
long long int get_PID(Processo *processo)
{
  return processo->PID;
}

// define o PID do processo
void set_PID(Processo *processo, unsigned long long PID)
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