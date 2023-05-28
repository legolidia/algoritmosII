#include <stdio.h>
#include <locale.h>

float fahreinheitParaCelsius(float f) {
	float celsius;
	celsius = (f-32)/1.8;
	return celsius;
    
}

int main() {
	float f, c;
	setlocale(LC_ALL, "Portuguese");
	printf("fahreinheit: ");
	scanf("%f", &f);
	c = fahreinheitParaCelsius(f);
	printf("celsius: %.2f °C", c);	
	return 0;
}
