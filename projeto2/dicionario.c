#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void deixaMinuscula(char *palavra);
void removeCaracteresEspeciais(char *palavra);
int buscaBinaria(char[][45], int, char[], int *);
void exibeDicionario();

int main()
{
  FILE *txt;
  FILE *dicionario;

  txt = fopen("texto.txt", "r");

  char palavra[45];
  char vetorStrings[1000][45];
  int tamanhoVetor = 0;

  while (fscanf(txt, "%s", palavra) != EOF)
  {

    if (strlen(palavra) > 0)
  {

    deixaMinuscula(palavra);
    removeCaracteresEspeciais(palavra);

    int pos;
    int achou = buscaBinaria(vetorStrings, tamanhoVetor, palavra, &pos);

    if (achou == -1)
    {
      int i = 0;
      for (i = tamanhoVetor; i > pos; i--)
        strcpy(vetorStrings[i], vetorStrings[i - 1]);

      strcpy(vetorStrings[pos], palavra);
      tamanhoVetor++;
    }
  }
  }

  dicionario = fopen("dicionario.txt", "w");

  int i = 0;

  for (i = 0; i < tamanhoVetor; i++)
    fprintf(dicionario, "%s\n", vetorStrings[i]);

  fclose(txt);
  fclose(dicionario);

  exibeDicionario();

  printf("total de palavras diferentes no dicionario=%d\n", tamanhoVetor);

  return 0;
}

void deixaMinuscula(char *palavra)
{
  int i = 0;
  for (i = 0; palavra[i]; i++)
    palavra[i] = tolower(palavra[i]);
}

void removeCaracteresEspeciais(char *palavra)
{
  int i = 0, j = 0;

  while (palavra[i])
  {
    if (isalpha(palavra[i]))
      palavra[j++] = palavra[i];

    i++;
  }

  palavra[j] = '\0';
}

int buscaBinaria(char vetor[][45], int tam, char palavra[], int *pos)
{
  int inicio = 0;
  int fim = tam - 1;
  int meio;

  while (inicio <= fim)
  {
    meio = (inicio + fim) / 2;
    if (strcmp(palavra, vetor[meio]) == 0)
      return meio;
    else if (strcmp(palavra, vetor[meio]) < 0)
      fim = meio - 1;
    else
      inicio = meio + 1;
  }

  *pos = inicio;

  return -1;
}

void exibeDicionario()
{

  FILE *dicionario = fopen("dicionario.txt", "r");

  char linha[45];
  int i = 0;

  while (fgets(linha, sizeof(linha), dicionario) != NULL)
  {
    if (linha[0] != '\n')
    {
      printf("%s", linha);
    }
  }

  fclose(dicionario);
}