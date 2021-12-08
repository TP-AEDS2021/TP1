/*@ 
@autors: João Pedro Rafael, Alan Gabriel, Miguel Silva
@motivation: Trabalho prático 1 de Algoritmos e estruturas de dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "./utils/utils.c"


int main(){
  
  FILE *file;
  char *filename, op;
  do{
    cls();
    // menu de opções
    printf("Opcoes:\n");
    printf("1 - Ler arquivo de testes\n");
    menu();
    //menu de opções
    op = getch();
    
    switch(op){
      case '0':
        exit(0);
      case '1':
        printf("Digite o nome do arquivo: ");
        scanf("%s", filename);
        fflush(stdin);
        if(filename == NULL){
          printf("Erro ao ler o arquivo\n");
          break;
        }
        break;
      default:
        printf("Opcao invalida\n");
    }
  }while(op != 'q');

}