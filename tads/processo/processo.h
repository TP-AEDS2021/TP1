#ifndef PROCESSO_H
#define PROCESSO_H

#include <time.h>

//definicao do tipo
typedef struct Tprocesso
{
    unsigned long long PID; // identificador do processo
    int prioridade; //prioridade do processo
    struct tm* horario_criacao; // horario de criacao do processo
} Processo;

//funcao para inicializar o processo
Processo* inicializa_processo(Processo*);

//funcao para imprimir o processo
void imprime_processo(Processo);

//gets e sets
long long int get_PID(Processo*);

void set_PID(Processo*, unsigned long long);

int get_prioridade(Processo*);

void set_prioridade(Processo*, int);

struct tm* get_horario_criacao(Processo*);

void set_horario_criacao(Processo*, struct tm*);

char* str_horario(struct tm*);

#endif