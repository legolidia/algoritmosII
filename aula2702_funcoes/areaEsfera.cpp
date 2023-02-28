#include <stdio.h>
#include <locale.h>

float areaEsfera(float raio) {
	float area, pi;
	pi = 3.141593;
	area = 4 * pi * (raio*raio);
	return area;
    
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float r, a;
	
	scanf("%f", &r);
	a = areaEsfera(r);
	printf("area: %.4fm²", a);
		
	return 0;
}
