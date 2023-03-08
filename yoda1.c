#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, estrelas[100], estrelas2[100], soma, roubados, naoRoubados, atacadas;
    soma = 0;
    atacadas = 0;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d", &estrelas[i]);
        soma += estrelas[i];
    }

    for (i = 0; i < num; i++)
    {
        estrelas2[i] = estrelas[i];
    }

    i = 0;
    roubados = 0;

    while (i >= 0 && i < num)
    {
        if (estrelas[i] != 0)
            roubados++;

        if (estrelas[i] % 2 != 0)
        {
            i++;
            estrelas[i - 1] -= 1;
        }
        else
        {
            i--;
            estrelas[i + 1] -= 1;
        }
    }

    naoRoubados = soma - roubados;

    for (i = 0; i < num; i++)
    {
        if (estrelas2[i] != estrelas[i])
            atacadas++;
    }

    printf("%d %d\n", atacadas, naoRoubados);

    return 0;
}