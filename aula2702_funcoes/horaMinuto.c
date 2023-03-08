#include <stdio.h>
#include <math.h>

float minuto(float hora1, float min1, float hora2, float min2) {
	float H1, H2, dif;
	H1 = hora1*60 + min1;
	H2 = hora2*60 + min2;
	
	dif = abs(H2 - H1);
	
	return dif;
    
}

int main() {
	float h1, m1, h2, m2, hora;
	float dif;
	int diff, min;
	
	scanf("%f:%f", &h1, &m1);
	scanf("%f:%f", &h2, &m2);
	
	dif = minuto(h1, m1, h2, m2);
	
	
	hora = floor(dif/60);
	diff = dif;
	min = diff%60;
	if(min<10)
		printf("%.0f:0%dh", hora, min);
	else
		printf("%.0f:%dh", hora, min);

	return 0;
}
