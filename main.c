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
    menu();
    op = getch();
    
    switch(op){
      case '0':
        exit(0);
        break;
      case '1':
        puts("Digite o nome do arquivo: ");
        scanf("%s", filename);
        fflush(stdin);
        if(filename == NULL){
          puts("Erro ao ler o arquivo\n");
          break;
        }
        file = fopen(filename, "r");
        if(file == NULL){
          puts("Erro ao ler o arquivo\n");
          break;
        }
        getch();
        break;
      default:
        puts("Opcao invalida ( digite qualquer tecla )\n");
        getch();
        break;
    }
  }while(op != 'q');

}