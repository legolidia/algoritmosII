#include <stdio.h>

int main()
{
    FILE *txt;
    FILE *dicionario;
    char word[50];

    txt = fopen("texto.txt", "r");
    dicionario = fopen("dicionario.txt", "w");

    while (fscanf(txt, "%s", word) != EOF)
        fprintf(dicionario, "%s\n", word);

    fclose(txt);
    fclose(dicionario);

    return 0;
}