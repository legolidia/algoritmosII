#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *livro;

    livro = fopen("livro.txt", "r");

    char txt[30];
    int i = 0;
    while (!feof(livro))
    {
        
    }

    printf("%d\n", i);
}