#include <stdio.h>
#include <stdlib.h>

int quadradoMagico(int linha, int coluna, int matriz[][50]){
    int i, j, somaLinha, somaColuna, somaDiagonal1, somaDiagonal2, auxL=0, auxC=0;
    somaLinha = 0;
    somaColuna = 0;
    somaDiagonal1 = 0;
    somaDiagonal2 = 0;

    if(linha!=coluna)
        return 0;

    for (i = 0; i < linha; i++) 
        somaDiagonal1 += matriz[i][i];
    

    for (i = 0; i < linha; i++) 
        somaDiagonal2 += matriz[i][linha-1-i];
    

    if(somaDiagonal1 != somaDiagonal2)
        return 0;

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            somaLinha += matriz[i][j];
            somaColuna += matriz[j][i];
        }

        if(i==0){
            auxL = somaLinha;
            auxC = somaColuna;
        } else {
            if(somaLinha != auxL || somaColuna != auxC)
                return 0;
        }

        somaLinha = 0;
        somaColuna = 0;
    }

    if(auxL==auxC && auxL==somaDiagonal1)
        return 1;
    else
        return 0;
}

int main()
{
    int linha, coluna, matriz[50][50], i, j;;
    scanf("%d%d", &linha, &coluna);
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (quadradoMagico(linha, coluna, matriz))
        printf("É um quadrado mágico\n");
    else
        printf("Não é um quadrado mágico\n");

    return 0;
}

