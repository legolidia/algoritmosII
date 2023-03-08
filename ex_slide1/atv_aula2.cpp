#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, soma = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			if (i % j == 0)
				soma += j;

		if (soma == i * 2)
			printf("%d ", i);

		soma = 0;
	}

	return 0;
}
