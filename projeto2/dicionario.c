#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef char * string;

#define NONE -1
#define MAX_LENGTH 100
#define NUM_STRINGS 2

bool buscaBinaria(char* palavra, char list[][2], int tamanho)
{
  int inicio = 0;
  int fim = tamanho - 1;
  int meio;

  while (inicio <= fim)
  {
    meio = (inicio + fim) / 2;

    if (strcmp(palavra, list[meio]) < 0)
      fim = meio - 1;
    else if (strcmp(palavra, list[meio]) > 0)
      inicio = meio + 1;
    else
      return meio;
  }

  return false;
}

int main()
{
  FILE *txt;
  FILE *dicionario;

  txt = fopen("texto.txt", "r");
  dicionario = fopen("dicionario.txt", "w");

  char palavra[50];

  int c = 0;

  txt = fopen("texto.txt", "r");

  while(!feof(txt)){
  while (fscanf(txt, "%s", palavra) != EOF){
    fprintf(dicionario, "%s\n", palavra);
    c++;
  }
  }

  while(!feof(dicionario)){
    fgets(palavra, 50, dicionario);
    printf("%s\n", palavra);
  }

  fclose(txt);
  fclose(dicionario);


  return 0;
}
