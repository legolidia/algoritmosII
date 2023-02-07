#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	printf("Venus está a 67 milhões de milhas de sol.\n");
	printf("A letra J pronuncia-se Jota\n");
	printf("O primeiro número é 44\n");
	printf("O segundo número é “num1 + 20.5” = 64.5\n");
	
	return 0;
}
