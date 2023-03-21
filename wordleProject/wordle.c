#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sorteiaPalavra()
{
    FILE *palavras;
    FILE *sorteada;

    palavras = fopen("palavra.txt", "r");

    char palavra[20];
    int i = 0;
    while(i<5)
    {
        if(fgets(palavra, 20, palavras) != NULL)
            i++;
    }
    srand(time(NULL));
    printf("%d\n", i);
    int sorteio = rand() % i;
    i = 0;
    rewind(palavras);

    sorteada = fopen("sorteada.txt", "w");
    while (fgets(palavra, 100, palavras) != NULL)
    {
        if (i == sorteio)
            fprintf(sorteada, "%s", palavra);
        i++;
    }
    fclose(palavras);
    fclose(sorteada);
}

int main()
{
    FILE *sorteada;
    char linha[100];

    sorteiaPalavra();

    sorteada = fopen("sorteada.txt", "r");
    fgets(linha, 100, sorteada);
    printf("%s", linha);

    fclose(sorteada);
}

// https://github.com/thoughtworks/dadoware/blob/master/fontes/sem_acentos.txt