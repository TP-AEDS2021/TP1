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
#ifdef WIN32
        getch();
#else
        getchar();
#endif
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
      t = clock(); // armazena tempo
      int tipo_da_operacao, quantidade, num_testes;
      size_t len = sizeof(char) * 20;
      char *linha = malloc(len);
      long int tamanho_do_vetor;
      int nlinha = 0;
#pragma region leitura do arquivo
      while (getline(&linha, &len, file) > 0)
      {
        if (nlinha == 0)
        { // primeira linha7
          sscanf(linha, "%ld", &tamanho_do_vetor);
          printf("tamanho do vetor: %ld\n", tamanho_do_vetor);
        }
        else if (nlinha == 1)
        { // segunda linha
          sscanf(linha, "%d", &num_testes);
          printf("numero de testes: %d\n", num_testes);
        }

        if (nlinha > 1)
        {
          sscanf(linha, "%d %d", &tipo_da_operacao, &quantidade);
          if (tipo_da_operacao == INSERE)
          {
            puts("inserindo");
          }
          else if (tipo_da_operacao == REMOVE)
          {
            puts("removendo");
          }
          else
          {
            puts("operacao invalida");
          }
          printf("%d itens\n", quantidade);

          lista_processos = inicializa_lista(lista_processos, tamanho_do_vetor);

          for (int i = 0; i < quantidade; i++)
          {
            Processo *p;
            Celula *celula;
            p = inicializa_processo(p);
            celula = inicializa_celula(celula, p);
            if(i % 10000 == 0)
            {
              printf(".", i);
            }
            if (tipo_da_operacao == 0)
            {
              adiciona_celula(lista_processos, celula);
            }
            else if (tipo_da_operacao == 1)
            {
              remove_primeiro(lista_processos);
            }
          }
        }
        nlinha++;
      }
      #pragma endregion
      if (linha)
        free(linha);

      fclose(file);
      t = clock() - t;
      printf("Tempo de execucao: %f\n", ((float)t) / CLOCKS_PER_SEC);
      fflush(stdin);
      _get();
      char *output = strtok(filename, ".");
      strcat(output, ".out");
      outputfile = fopen(output, "w");
      if (outputfile == NULL || outputfilename == '\0')
      {
        puts("Erro ao ler o arquivo\t (pressione enter para continuar)");
        fflush(stdin);
        _get();
        continue;
      }
      printf("Arquivo de saida escrito com sucesso\t (pressione enter para continuar)");
      fflush(stdin);
      _get();

      #pragma region escrita_arquivo
      // inicio da escrita do arquivo

      fclose(outputfile);
      #pragma endregion
      break;

    default:
      puts("Opcao invalida ( digite qualquer tecla )\n");
      fflush(stdin);
      _get();
      break;
    }
  } while (op != 'q');
}