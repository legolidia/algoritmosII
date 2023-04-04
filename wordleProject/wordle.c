#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void sorteiaPalavra()
{
    FILE *palavras;
    FILE *sorteada;

    palavras = fopen("palavras.txt", "r");

    char palavra[20];
    int i = 0;
    while (!feof(palavras))
    {
        if (fgets(palavra, 20, palavras) != NULL)
            i++;
    }

    srand(time(NULL));

    rewind(palavras);

    bool tamanhoCerto = 1;

    while (tamanhoCerto)
    {
        rewind(palavras);
        int sorteio;
        sorteio = rand() % 6621;
        i = 0;

        while (i != sorteio)
        {
            fgets(palavra, 20, palavras);
            i++;
        }

        if (strlen(palavra) == 6)
        {
            sorteada = fopen("sorteada.txt", "w");
            fprintf(sorteada, "%s", palavra);
            printf("%s", palavra);
            tamanhoCerto = 0;
        }
    }
    rewind(palavras);
    fclose(palavras);
}

int verificaPalavra(char palavra[])
{
    int i;
    FILE *palavraSorteada;
    FILE *todasPalavras;

    char linha[20];

    int r;

    palavraSorteada = fopen("sorteada.txt", "r");
    todasPalavras = fopen("palavras.txt", "r");

    while (!feof(todasPalavras))
    {

        fgets(linha, 6, todasPalavras);

        if (strcmp(linha, palavra) == 0)
        {
            printf("Palavra existe.\n");
            r = 1;
            break;
        }

        else
            r = 0;
    }

    return r;
}

int main()
{
    FILE *sorteada;
    char linha[100];
    char tent[10];

    sorteiaPalavra();

    sorteada = fopen("sorteada.txt", "r");
    fgets(linha, 100, sorteada);
    printf("%s", linha);

    scanf("%s", &tent);

    verificaPalavra(tent);

    fclose(sorteada);
    fclose(fopen("sorteada.txt", "wb"));
}

// https://github.com/thoughtworks/dadoware/blob/master/fontes/sem_acentos.txt