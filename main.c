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
        if(linha == 0){ //primeira linha
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
    case 2:
      // todo: implementar multiplataforma
      char opt;
      long int tam;
      printf("Digite o tamanho da lista: ");
      int resultado = scanf("%ld", &tam);
      while (resultado != 1)
      {
        printf("Entrada invalida. Digite o tamanho da lista: \n");
        resultado = scanf("%ld", &tam);
      }
      while (tam < 1 || tam > 999999)
      {
        printf("Tamanho invalido. Digite o tamanho da lista: \n");
        scanf("%ld", &tam);
      }
      lista_processos = inicializa_lista(lista_processos, tam);
      do
      {
        menu_teclado();
        fflush(stdin);
        opt = getchar();
        switch (opt)
        {
        case '0':
          int quantidade;
          printf("Digite o numero de processos a serem inseridos: ");
          resultado = scanf("%d", &quantidade);
          while (resultado != 1)
          {
            printf("Entrada invalida. Digite o numero de processos a serem inseridos: \n");
            resultado = scanf("%d", &quantidade);
          }
          while (quantidade < 0)
          {
            printf("Numero de processos invalido. Digite o numero de processos a serem inseridos: \n");
            scanf("%d", &quantidade);
          }
          for (int i = 0; i < quantidade; i++){
            Processo *p;
            Celula *celula;
            p = inicializa_processo(p);
            celula = inicializa_celula(celula, p);
            adiciona_celula(lista_processos, celula);
          }
          break;
        case '1':
          int quantidade;
          printf("Digite o numero de processos a serem removidos: ");
          resultado = scanf("%d", &quantidade);
          while (resultado != 1)
          {
            printf("Entrada invalida. Digite o numero de processos a serem removidos: \n");
            resultado = scanf("%d", &quantidade);
          }
          while (quantidade < 0)
          {
            printf("Numero de processos invalido. Digite o numero de processos a serem removidos: \n");
            scanf("%d", &quantidade);
          }
          for (int i = 0; i < quantidade; i++)
          {
            remove_primeiro(lista_processos);
          }
          break;
        case '2':
          num_celulas_ocupadas(lista_processos);
          break;
        case '3':
          imprime_lista(lista_processos);
          break;
        case '4':
          exit(0);
          break;
        default:
          puts("Opcao invalida ( digite qualquer tecla )\n");
          getchar();
          break;
        }  
        break;
      } while(opt != 'q');
    default:
      puts("Opcao invalida ( digite qualquer tecla )\n");
      getchar();
      break;
    }
  } while (op != 'q');
}