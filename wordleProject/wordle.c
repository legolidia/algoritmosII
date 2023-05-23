//Isabella de Castro Jorge - 42229960
//Lídia Carolina de Andrade Rosa - 32281374

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

		printf("Digite a opção desejada: ");
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
			printf("  Turma 02G11 - FCI - Ciência da Computação\n\n\n");
			menu = -1;
			break;
		default:
			printf("\nOpção inválida, digite novamente.\n");
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

	printf("\nVamos começar!\n");
	printf("Você tem 6 tentativas para tentar acertar a palavra. Apenas palavras que existem serão aceitas.\n\n");

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
			printf("Palavra inválida, digite novamente.\n");
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
				printf("Você tem mais %d tentativa(s).\n\n", 6 - numTentativas);
		}

	}

	if(numTentativas == 6)
		printf("A palavra era: %s\n\n", palavraSorteada);

}
