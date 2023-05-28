#include <stdio.h>



int main()
{
    const int TAM = 10;

    int i, j;

    printf("    SQUARE *-*\n");

    for (i = 1; i <= TAM; i++)
    {
        for (j = 1; j <= TAM; j++)
        {
            if (i == 1 || i == TAM || j == 1 || j == TAM)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}