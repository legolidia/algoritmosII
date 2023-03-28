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

   i--;

    while(tamanhoCerto){
        rewind(palavras);
        int sorteio;
        sorteio = rand()%6621;
        printf("%d\n", sorteio);
        i = 0;

        while (i!=sorteio){
            fgets(palavra, 20, palavras);
            i++;
        }

        if (strlen(palavra) == 6){ 
            sorteada = fopen("sorteada.txt", "w");
            fprintf(sorteada, "%s", palavra);
            printf("%s", palavra);
            tamanhoCerto = 0;
        }
    }


    /*while (strlen(palavra) > 5 || strlen(palavra) < 5)
    {

        sorteada = fopen("sorteada.txt", "w");

        int sorteio = rand() % 6621; // 7
        i = 0;
        while (i!=sorteio){ //i=0
        {
            // verificar se tem 5 letras, se tem, adicionar em sorteada, se não tem, volta ao laço
            
            fgets(palavra, 20, palavras);
            
            fprintf(sorteada, "%s", palavra);
                printf("%s", palavra);
                break;
            }
            i++;
        }
    }

    fclose(palavras);
    fclose(sorteada);*/

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
    fclose(fopen("sorteada.txt", "wb"));
}

// https://github.com/thoughtworks/dadoware/blob/master/fontes/sem_acentos.txt