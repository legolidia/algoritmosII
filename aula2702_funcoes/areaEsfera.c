#include <stdio.h>
#include <locale.h>


float areaEsfera(float raio) {
	float area;
	area = 4 * PI * (raio*raio);
	return area;
    
}

int main() {
	const PI = 3.141593;
	setlocale(LC_ALL, "Portuguese");
	
	float r, a;
	
	scanf("%f", &r);
	a = areaEsfera(r);
	printf("area: %.4fm²", a);
		
	return 0;
}
