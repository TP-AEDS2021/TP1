/*@
@autors: João Pedro Rafael, Alan Gabriel, Miguel Silva
@motivation: Trabalho prático 1 de Algoritmos e estruturas de dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tads/processo/processo.h"
#include "./tads/processo/processo.c"
#include "./tads/lista_processos/lista_processo.h"
#include "./tads/lista_processos/lista_processo.c"

int main()
{

  FILE *file;
  char *filename, op;
  Lista *lista_processos;
  Processo *processo = (Processo *)malloc(sizeof(Processo));
  inicializa_processo(processo);
  inicializa_lista(lista_processos, 2);
  


  getchar();

  do
  {
    cls();
    // menu de opções
    menu();
    op = getchar();

    switch (op)
    {
    case '0':
      exit(0);
      break;
    case '1':
      puts("Digite o nome do arquivo: \n");
      scanf("%s", filename);
      fflush(stdin);
      if (filename == NULL)
      {
        puts("Erro ao ler o arquivo\n pressione enter para continuar");
        break;
      }
      file = fopen(filename, "r");
      if (file == NULL)
      {
        puts("Erro ao ler o arquivo\t (pressione enter para continuar)");
        getchar();
        break;
      }
      puts("Arquivo lido com sucesso\t (pressione enter para continuar)");
      getchar();
      break;
    default:
      puts("Opcao invalida ( digite qualquer tecla )\n");
      getchar();
      break;
    }
  } while (op != 'q');
}