#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    void sorteiaPalavra();
    int verificaPalavra(char palavra[]);
    void wordle();

    int menu = 0;

    while (menu > -1)
    {
        printf("-------------GENIO----------------\n");
        printf("1 - Iniciar Jogo\n");
        printf("2 - Sair\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            wordle();
            menu = 0;
            break;
        case 2:
            printf("\n          OBRIGADA POR JOGAR!\n\n");
            printf("            ♡⸜(˃ ᵕ ˂ )⸝♡\n\n");
            printf("           Desenvolvido por:\n\n");
            printf("     Isabella de Castro Jorge - TIA\n");
            printf("  Lídia Carolina de Andrade Rosa - 32281374\n\n");
            printf("  Turma 02G11 - FCI - Ciência da Computação\n\n\n");
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
            tamanhoCerto = 0;
        }
    }
    rewind(palavras);
    fclose(palavras);
    fclose(sorteada);
}

int verificaPalavra(char palavra[])
{
    int i;
    int r;
    char linha[20];

    FILE *todasPalavras;

    todasPalavras = fopen("palavras.txt", "r");
    rewind(todasPalavras);

    while (!feof(todasPalavras))
    {

        fgets(linha, 20, todasPalavras);

        printf("%s\n", linha);
        
        if (strcmp(linha, palavra) == 0 && strlen(linha) == 5)
        {
            r = 1;
            printf("%s\n", linha);
            printf("%s\n", palavra);
            break;
        }

        else{
            r = 0;
            printf("Não existe essa palavra\n");
        }
    }

    return r;

    fclose(todasPalavras);
}

void wordle()
{
    FILE *palavraSorteadaArquivo;
    char tentativa[6];
    char resultado[6];

    strcpy(resultado, "xxxxx");

    int numTentativas = 0;

    printf("Vamos começar!\n");
    printf("Você tem 5 tentativas para tentar acertar a palavra. Apenas palavras que existem serão aceitas.\n");

    sorteiaPalavra();

    char palavraSorteada[6];
    palavraSorteadaArquivo = fopen("sorteada.txt", "r");

    fgets(palavraSorteada, 6, palavraSorteadaArquivo);

    fclose(palavraSorteadaArquivo);

    while (numTentativas < 5)
    {
        printf("Digite uma palavra de 5 letras: ");
        scanf("%s", &tentativa);

        int existe = verificaPalavra(tentativa);

        while(strlen(tentativa) != 5 || existe == 0)
        {
            printf("Digite uma palavra de 5 letras: ");
            scanf("%s", &tentativa);
            existe = verificaPalavra(tentativa);
        }
        

        if (strcmp(tentativa, palavraSorteada) == 0)
        {
            printf("Parabéns, você acertou!\n");
            break;
        }

        else
        {
            int i = 0;
            for (i = 0; i < 5; i++)
            {
                if (tentativa[i] == palavraSorteada[i])
                    resultado[i] = '^';
                else
                {
                    int letrasIguais = 0;
                    for (int j = 0; j < 5; j++){
                        if (tentativa[i] == palavraSorteada[j])
                            letrasIguais++;
                    }
                    if (letrasIguais > 0)
                        resultado[i] = '!';
                    else
                        resultado[i] = 'x';
                }
            }

            for(i=0; i<5;i++){
                tentativa[i] = toupper(tentativa[i]);
            }

            printf("%s\n", tentativa);
            printf("%s\n", resultado);

            numTentativas++;
            if(numTentativas < 5)
                printf("Você tem mais %d tentativa(s).\n", 5 - numTentativas);
        }
    
    }

    printf("A palavra era: %s\n", palavraSorteada);
}