#include <string.h>
#include <time.h>

#define cls() printf("\e[1;1H\e[2J");
#define now() time(0); 

void menu() {
  puts("Opcoes:\n");
  puts("0 - Sair\n");
  puts("1 - Ler arquivo de testes\n");
  puts("2 - Entradas por teclado\n");
  puts("menu");
}


char * uid(int length)
{
  static int mySeed = 25011984;
  char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
  size_t stringLen = strlen(string);
  char *randomString = NULL;

  srand(time(NULL) * length + ++mySeed);

  if (length < 1)
  {
    length = 1;
  }

  randomString = malloc(sizeof(char) * (length + 1));

  if (randomString != NULL)
  {
    short key = 0;

    for (int n = 0; n < length; n++)
    {
      key = rand() % stringLen;
      randomString[n] = string[key];
    }

    randomString[length] = '\0';

    return randomString;
  }
  else
  {
    printf("No memory");
    exit(1);
  }
}