#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "processo.h"
#include "../../utils/utils.c"
#include <inttypes.h>

static unsigned long x = 123456789, y = 362436069, z = 521288629;

unsigned long xorshf96(void)
{
  unsigned long t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;

  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;

  return z;
}

// funcao para inicializar o processo
Processo* inicializa_processo(Processo *processo)
{
  processo = (Processo *)malloc(sizeof(Processo));

  unsigned long pid = xorshf96();
  if(pid <= 0)
  {
    pid = pid * -1;
  }
  set_PID(processo, pid );  
  set_prioridade(processo, (rand() % 5) + 1);
  set_horario_criacao(processo, currentTime());
  return processo;
}

// funcao para imprimir o processo
void imprime_processo(Processo* processo)
{
  printf("\n|\t%lu\t|", get_PID(processo));
  printf("\t%d\t", get_prioridade(processo));
  printf("|\t%d-%d-%d|\n", processo->horario_criacao->tm_hour, processo->horario_criacao->tm_min, processo->horario_criacao->tm_sec);
  return;
}

void imprime_processo_arquivo(FILE* file, Processo* processo)
{
  fprintf(file, "\n|\t%lu\t|", get_PID(processo));
  fprintf(file, "\t%d\t", get_prioridade(processo));
  fprintf(file, "|\t%d-%d-%d |\n", processo->horario_criacao->tm_hour, processo->horario_criacao->tm_min, processo->horario_criacao->tm_sec);
  return;
}

// retorna o PID do processo
unsigned long get_PID(Processo *processo)
{
  return processo->PID;
}

// define o PID do processo
void set_PID(Processo *processo, unsigned long PID)
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