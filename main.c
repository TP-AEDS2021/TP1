/*@
@autors: João Pedro Rafael, Alan Gabriel, Miguel Silva
@motivation: Trabalho prático 1 de Algoritmos e estruturas de dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processo.h"
#include "processo.c"

int main()
{

  FILE *file;
  char *filename, op;

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
        puts("Erro ao ler o arquivo\n pressione enter para continuar");
        break;
      }
      puts("Arquivo lido com sucesso\n pressione enter para continuar");
      getchar();
      break;
    default:
      puts("Opcao invalida ( digite qualquer tecla )\n");
      getchar();
      break;
    }
  } while (op != 'q');
}