#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "processo.h"
#include "utils/utils.c"

//funcao para inicializar o processo
void inicializa_processo(Processo* processo)
{
    set_PID(processo, rand());
    set_prioridade(processo, (rand() % 5) + 1);
    set_horario_criacao(processo, curtime());
}

//funcao para imprimir o processo
void imprime_processo(Processo*);

//gets e sets
int get_PID(Processo*);

void set_PID(Processo*, int);

int get_prioridade(Processo*);

void set_prioridade(Processo*, int);

struct tm* get_horario_criacao(Processo*);

void set_horario_criacao(Processo*, struct tm*);