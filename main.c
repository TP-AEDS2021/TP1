/*@
@autors: João Pedro Rafael, Alan Gabriel, Miguel Silva
@motivation: Trabalho prático 1 de Algoritmos e estruturas de dados
*/
#define _GNU_SOURCE
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
  char * string;
  srand(time(NULL));
  // for (int i = 0; i < 10; i++)
  // {
  //   Processo *p;
  //   Celula *celula;
  //   p = inicializa_processo(p);
  //   celula = inicializa_celula(celula, p);

  //   adiciona_celula(lista_processos, celula);
  // }

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
        getchar();
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
      int tipo_da_operacao, quantidade, num_testes;
      size_t len = sizeof(char) * 20;
      char *linha = malloc(len);
      long int tamanho_do_vetor;
      int nlinha = 0;
      while (getline(&linha, &len, file) > 0)
      {
        printf("%s", linha);
        if(linha == 0){ //primeira linha7
        sscanf(linha, "%ld", &tamanho_do_vetor);
        }
        else if(linha == 1){ //segunda linha
        sscanf(linha, "%d", &num_testes);
        }
        if(nlinha > 1){
          sscanf(linha, "%d %d", &tipo_da_operacao, &quantidade);
        }
        for (int i = 0; i < quantidade; i++){
          Processo *p;
          Celula *celula;
          p = inicializa_processo(p);
          celula = inicializa_celula(celula, p);
          adiciona_celula(lista_processos, celula);
        }
          nlinha++;
      }
      if (linha)
        free(linha);
      getchar();
      fclose(file);
      break;
    default:
      puts("Opcao invalida ( digite qualquer tecla )\n");
      getchar();
      break;
    }
  } while (op != 'q');
}