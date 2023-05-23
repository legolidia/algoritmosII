#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeTabuleiro(char matriz[][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            printf("|%c|", matriz[i][j]);
        printf("\n");
    }
}

int main(){
    char matriz[3][3];
    char jogada[2];

    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            matriz[i][j] = ' ';

    imprimeTabuleiro(matriz);

    int l, c;
    int cont = 0;

    while(1){
        printf("Digite a posição da jogada: ");
        scanf("%d%d", &l, &c);

        if(cont%2==0){
            matriz[l][c] = 'X';
        }   else{
            matriz[l][c] = 'O';
        }

        imprimeTabuleiro(matriz);

        cont++;
    }

    return 0;
}
