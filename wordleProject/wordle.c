#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    void sorteiaPalavra();
    int verificaPalavra(char palavra[]);
    void wordle();

    int menu = -1;

    while (menu > -1)
    {
        printf("-------------WORDLE----------------\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            wordle();
            break;
        case 2:
            printf("Obrigada por jogar!\n");
            printf("Desenvolvido por:\n");
            printf("Isabella de Castro Jorge - TIA\n");
            printf("Lídia Carolina de Andrade Rosa\n");
            printf("Turma 02G11 - FCI - Ciência da Computação\n");
            menu = -1;
            break;
        default:
            printf("Opção inválida, digite novamente.\n");
            printf("1 - Iniciar Jogo\n");
            printf("2 - Sair\n");
            scanf("%d", &menu);
            break;
        }
    }
}

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

void wordle()
{
    char tentativa[6];
    int numTentativas = 0;

    printf("Vamos começar!\n");
    sorteiaPalavra();

    while (numTentativas < 5)
    {
       do{
        printf("Digite uma palavra de 5 letras: ");
        scanf("%s", tentativa);
       } while(strlen(tentativa) != 5);
    }

    printf("ok.\n");
}