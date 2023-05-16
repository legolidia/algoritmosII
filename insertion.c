#include <stdio.h>
#include <stdlib.h>

void insertionSort_modificado(int vetor[], int tam){
   for(int i = 1; i <= tam - 1; i++){
      int k = vetor[i], j = i - 1;

      while (j >= 0 && k%2==0 && vetor[j]%2!=0) {
         vetor[j+1] = vetor[j];
         j--;
      }
      
      while (j >= 0 && k%2!=0 && vetor[j]%2==0) {
         vetor[j+1] = vetor[j];
         j--;
      }

      vetor[j+1] = k;
   }
}

int main(){
    int vetor[10] = {8, 3, 1, 42, 12, 5, 19, 72, 45, 23};
    int tam = 10;
    
    insertionSort_modificado(vetor, tam);
    
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}