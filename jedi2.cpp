#include <stdio.h>
#include <string.h>

int main() {
  char str[256];
  int tam;
  unsigned long long num;

  scanf("%llu", &num);
  sprintf(str, "%lld", num);
  tam = strlen(str);

  for (int i = 0; i < tam; i++)
    printf("%c", str[tam-1-i]);
  
  printf("\n");
  return 0;
}