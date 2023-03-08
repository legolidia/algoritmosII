#include <stdio.h>
#include <locale.h>

int minuto(int hora1, int minuto1, int hora2, int minuto2) {
	int total1 = hora1 * 60 + minuto1;
	int total2 = hora2 * 60 + minuto2;
	return total2 - total1;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int hora1, minuto1, hora2, minuto2;
    printf("Digite o horário 1 (hora e minuto): ");
    scanf("%d %d", &hora1, &minuto1);
    printf("Digite o horário 2 (hora e minuto): ");
    scanf("%d %d", &hora2, &minuto2);
    printf("A diferença entre os horários é %d minutos\\n", minuto(hora1, minuto1, hora2, minuto2));
    return 0;
}

