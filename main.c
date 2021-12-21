/*@
@autors: João Pedro Rafael, Alan Gabriel, Miguel Silva
@motivation: Trabalho prático 1 de Algoritmos e estruturas de dados
*/
#define _GNU_SOURCE

#ifdef WIN32
#include <conio.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tads/processo/processo.h"
#include "./tads/processo/processo.c"
#include "./tads/lista_processos/lista_processo.h"
#include "./tads/lista_processos/lista_processo.c"

#define INSERE 0
#define REMOVE 1

#define file_string_length 30

#ifdef WIN32
#define _get getch
#else
#define _get getchar
#endif

int main()
{

  FILE *file, *outputfile;
  char filename[20], op, outputfilename[50];
  Lista *lista_processos;
  char *string;
  clock_t t;
  srand(time(NULL));
  int nteste;

  do
  {
    cls();
    // menu de opções
    menu();
    fflush(stdin);
    puts("\nDigite a opcao desejada: ");
#ifdef WIN32
    op = getch();
#else
    op = getchar();
#endif

    switch (op)
    {
    case '0':
      exit(0);
      break;
    case '1':
      fflush(stdin);
      puts("Digite o nome do arquivo: ");
      printf(">> ");
      scanf("%s", &filename);
      fflush(stdin);
      if (filename == NULL)
      {
        puts("Erro ao ler o arquivo\n pressione enter para continuar");
        _get();
        break;
      }
      file = fopen(filename, "r");
      if (file == NULL)
      {
        puts("Erro ao ler o arquivo\t (pressione enter para continuar)\n");
        _get();
        break;
      }
      printf("Arquivo lido com sucesso\t (pressione enter para continuar)\n");
      _get();

      // inicio da leitura do arquivo
      outputfile = fopen("output.txt", "a");
      if (outputfile == NULL || outputfilename == '\0')
      {
        puts("Erro ao abrir o arquivo\t (pressione enter para continuar)");
        fflush(stdin);
        _get();
        continue;
      }
      fprintf(outputfile, "\n%s:\n", filename);
      // armazena tempo
      t = clock();
      // reinicia o numero de testes
      nteste = 0;
      int tipo_da_operacao, quantidade, num_testes;
      size_t len = sizeof(char) * file_string_length;
      char *linha = malloc(len);
      long int tamanho_do_vetor;
      int nlinha = 0;

      while (getline(&linha, &len, file) > 0)
      {
        if (nlinha == 0)
        { // primeira linha7
          sscanf(linha, "%ld", &tamanho_do_vetor);
          printf("tamanho do vetor: %ld\n", tamanho_do_vetor);
          free(lista_processos->plista);
          free(lista_processos);
          lista_processos = inicializa_lista(lista_processos, tamanho_do_vetor);
        }
        else if (nlinha == 1)
        { // segunda linha
          sscanf(linha, "%d", &num_testes);
          printf("numero de operacoes: %d\n", num_testes);
        }

        if (nlinha > 1)
        {
          // inicia o tempo
          clock_t start_time = clock();

          nteste++;
          sscanf(linha, "%d %d", &tipo_da_operacao, &quantidade);

          int progresso = 0;
          int prog = 0;

          for (int i = 0; i < quantidade; i++)
          {
            progresso++;
            if (tipo_da_operacao == INSERE)
            {
              Processo *p;
              Celula *celula;
              p = inicializa_processo(p);
              celula = inicializa_celula(celula, p);
              adiciona_celula(lista_processos, celula);
            }
            else if (tipo_da_operacao == REMOVE)
            {
              remove_primeiro(lista_processos);
            }
            if (progresso % (tamanho_do_vetor / 100) == 0)
            {
              progresso = 0;
              prog++;
              printf(".\r");
              for (int j = 0; j < prog; j++)
              {
                printf("\xB2");
              }
              printf(" %d%%", prog);
            }
          }
          // finaliza o tempo
          clock_t end_time = clock();
          double time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
          fprintf(outputfile, "\n\tteste %d :%f s\n", nteste, time);
        }
        nlinha++;
      }
      printf("\n");
      if (linha)
        free(linha);

      fclose(file);
      t = clock() - t;
      printf("\n\nTempo total de execucao: %2f\n (pressione enter para continuar)", ((float)t) / CLOCKS_PER_SEC);
      fflush(stdin);
      fclose(outputfile);
      _get();
      break;

    default:
      puts("Opcao invalida ( digite qualquer tecla )\n");
      fflush(stdin);
      _get();
      break;
    }
  } while (op != 'q');
}