#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	float c, f;
	
	printf("Digite a temperatura em graus Celsius: ");
	scanf("%f", &c);
	
	f = c * (9/5) + 32;
	
	printf("A Temperatura em graus Fahrenheit é %.2f", f);
	
	return 0;
}
