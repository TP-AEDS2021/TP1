#ifndef PROCESSO_H
#define PROCESSO_H

#include <time.h>

//definicao do tipo
typedef struct Tprocesso
{
    int PID; // identificador do processo
    int prioridade;
    struct tm* horario_criacao;
} Processo;

//funcao para inicializar o processo
void inicializa_processo(Processo*);

//funcao para imprimir o processo
void imprime_processo(Processo);

//gets e sets
int get_PID(Processo*);

void set_PID(Processo*, int);

int get_prioridade(Processo*);

void set_prioridade(Processo*, int);

struct tm* get_horario_criacao(Processo*);

void set_horario_criacao(Processo*, struct tm*);

char* str_horario(struct tm*);

#endif