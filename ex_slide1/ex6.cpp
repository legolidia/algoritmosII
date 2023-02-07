#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	float r, a;
	
	printf("raio em m: ");
	scanf("%f", &r);
	
	a = 4 * M_PI * r * r;
	
	printf("area = %fm²\n", a);
	
	return 0;
}
