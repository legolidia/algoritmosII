#include <stdio.h>

int divisores(int n){
	int c = 0, i;
	for(i=1; i<=n; i++){
		if(n%i==0)
			c++;
	}
	printf("%d\n", c);
	return c;
}

int isPrimo(int n){
	if(n==2)
		return 1;
	else 
		return 0;
}


int main(){
	int num, p;
	scanf("%d", &num);
	p =	isPrimo(divisores(num));
	if (p==1)
		printf("eh primo");
	else
		printf("nao eh primo");
	
	return 0;
}
