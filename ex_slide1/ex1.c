#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, soma;
	float media;
	
	scanf("%d%d", &a, &b);
	
	soma = a+b;
	media = soma/2;
	
	printf("soma: %d | media: %.2f\n", soma, media);
	
	return 0;
}
