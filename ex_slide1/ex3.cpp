#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int evento = 5;
	char corrida = 'C';
	float tempo = 27.25;
	
	printf("O tempo vitorioso na eliminatória %c da competição %d foi %.2f", corrida, evento, tempo);
	
	return 0;
	
}
	
	
