#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int sort, palpite, c=0;

    srand(time(NULL));
    
    sort = rand()%100;
    printf("O número foi sorteado!\n");

    do{
        printf("Digite sua tentativa!\n");
        scanf("%d", &palpite);
        if(palpite<sort)
            printf("Você chutou muito baixo!\n");
        else if(palpite>sort)
            printf("Você chutou muito alto!\n");
        else{
        printf("Parabéns!!! Você acertou em %d tentativas!\n", c);
        break;
        }
        c++;
    } while(c<5);

    if(palpite!=sort && c==5)
        printf("Você excedeu o número máximo de tentativas, o número sorteado é %d.\n", sort);


    return 0;
}