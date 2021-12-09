#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define cls() printf("\e[1;1H\e[2J");

void curtime()
{

  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  printf("[%d %d %d %d:%d:%d]\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

void menu()
{
  curtime();
  puts("Opcoes:");
  puts("0 - Sair");
  puts("1 - Ler arquivo de testes");
  puts("2 - Entradas por teclado");
}

char *uid(int length)
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