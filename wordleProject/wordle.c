<<<<<<< HEAD
//Isabella de Castro Jorge - 42229960
//LÌdia Carolina de Andrade Rosa - 32281374

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int menu = 0;

	while (menu != -1)
	{
		printf("------------- WORDLE ----------------\n");
		printf("1 - Iniciar Jogo\n");
		printf("2 - Sair\n\n");

		printf("Digite a opÁ„o desejada: ");
		scanf("%d", &menu);


		switch (menu)
		{
		case 1:
			wordle();
			break;
		case 2:
			printf("\n          OBRIGADA POR JOGAR!\n\n");
			printf("\n");
			printf("           Desenvolvido por:\n\n");
			printf("     Isabella de Castro Jorge - 42229960\n");
			printf("  Lidia Carolina de Andrade Rosa - 32281374\n\n");
			printf("  Turma 02G11 - FCI - CiÍncia da ComputaÁ„o\n\n\n");
			menu = -1;
			break;
		default:
			printf("\nOpÁ„o inv·lida, digite novamente.\n");
			printf("1 - Iniciar Jogo\n");
			printf("2 - Sair\n");
			scanf("%d", &menu);
			break;
		}
	}

	return 0;
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
	FILE *palavraSorteada;
	FILE *todasPalavras;

	char linha[20];

	int r;

	palavraSorteada = fopen("sorteada.txt", "r");
	todasPalavras = fopen("palavras.txt", "r");

	rewind(todasPalavras);

	while (!feof(todasPalavras))
	{

		fgets(linha, 6, todasPalavras);

		if (strcmp(linha, palavra) == 0)
		{
			r = 1;
			break;
		}

		else
		{
			r = 0;
		}
	}

	return r;
	fclose(palavraSorteada);
	fclose(todasPalavras);
}

void wordle()
{
	clock_t begin = clock();
	FILE *palavraSorteadaArquivo;
	FILE *score;

	float tempo = 0.0;

	score = fopen("score.txt", "a");

	char tentativa[6];
	char resultado[6];

	strcpy(resultado, "xxxxx");

	int numTentativas = 0;

	printf("\nVamos comeÁar!\n");
	printf("VocÍ tem 6 tentativas para tentar acertar a palavra. Apenas palavras que existem ser„o aceitas.\n\n");

	sorteiaPalavra();

	char palavraSorteada[6];
	palavraSorteadaArquivo = fopen("sorteada.txt", "r");

	fgets(palavraSorteada, 6, palavraSorteadaArquivo);

	fclose(palavraSorteadaArquivo);



	while (numTentativas < 6)
	{
		printf("Digite uma palavra de 5 letras: ");
		scanf("%s", &tentativa);
		int existe = -1;
		existe = verificaPalavra(tentativa);

		while(strlen(tentativa) != 5 || existe == 0)
		{
			printf("Palavra inv·lida, digite novamente.\n");
			scanf("%s", &tentativa);
			existe = verificaPalavra(tentativa);
		}

		if (strcmp(tentativa, palavraSorteada) == 0)
		{
			printf("Parabens, voce acertou!\n");
			
			clock_t end = clock();
			tempo += (float)(end - begin) / CLOCKS_PER_SEC;
			
			char nome[20];
			printf("Qual seu nome?\n");
			scanf("%s", &nome);
			
			fprintf(score, "%s | %s | %d | %.1f\n\n", nome, tentativa, numTentativas, tempo);
			
			fclose(score);
			
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
					int j = 0;
					int letrasIguais = 0;
					for (j = 0; j < 5; j++)
					{
						if (tentativa[i] == palavraSorteada[j])
							letrasIguais++;
					}
					if (letrasIguais > 0)
						resultado[i] = '!';
					else
						resultado[i] = 'x';
				}

			}

			for(i = 0; i < 5; i++)
			{
				tentativa[i] = toupper(tentativa[i]);
			}

			printf("%s\n", tentativa);
			printf("%s\n", resultado);

			numTentativas++;
			if(numTentativas < 6)
				printf("VocÍ tem mais %d tentativa(s).\n\n", 6 - numTentativas);
		}

	}

	if(numTentativas == 6)
		printf("A palavra era: %s\n\n", palavraSorteada);

}
=======
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

        printf("Digite a op√ß√£o desejada: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            wordle();
            menu = 0;
            break;
        case 2:
            printf("\n          OBRIGADA POR JOGAR!\n\n");
            printf("            ‚ô°‚∏ú(ÀÉ ·µï ÀÇ )‚∏ù‚ô°\n\n");
            printf("           Desenvolvido por:\n\n");
            printf("     Isabella de Castro Jorge - TIA\n");
            printf("  L√≠dia Carolina de Andrade Rosa - 32281374\n\n");
            printf("  Turma 02G11 - FCI - Ci√™ncia da Computa√ß√£o\n\n\n");
            menu = -1;
            break;
        default:
            printf("Op√ß√£o inv√°lida, digite novamente.\n");
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
            break;
        }

        else{
            r = 0;
    
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

    printf("Vamos come√ßar!\n");
    printf("Voc√™ tem 5 tentativas para tentar acertar a palavra. Apenas palavras que existem ser√£o aceitas.\n");

    sorteiaPalavra();

    char palavraSorteada[6];
    palavraSorteadaArquivo = fopen("sorteada.txt", "r");

    fgets(palavraSorteada, 6, palavraSorteadaArquivo);

    fclose(palavraSorteadaArquivo);

    while (numTentativas < 5)
    {
        printf("Digite uma palavra de 5 letras: ");
        scanf("%c", &teqwntativa);

        int existe = verificaPalavra(tentativa);

        while(strlen(tentativa) != 5 || existe == 0)
        {
            printf("Digite uma palavra de 5 letras: ");
            scanf("%c", &tentativa);
            existe = verificaPalavra(tentativa);
        }
        

        if (strcmp(tentativa, palavraSorteada) == 0)
        {
            printf("Parab√©ns, voc√™ acertou!\n");
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
                printf("Voc√™ tem mais %d tentativa(s).\n", 5 - numTentativas);
        }
    
    }

    printf("A palavra era: %s\n", palavraSorteada);
}
>>>>>>> 75482d545630bb90abbe4962357498e3f385becb
