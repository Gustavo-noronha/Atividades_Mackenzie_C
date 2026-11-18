#include <stdio.h>
#include <stdlib.h>

float valor(int numero){
	if (numero<-1){
		printf("numero negativo");
		exit(0);
	}
	float s =1+1.0/2+1.0/3+1.0/4+1.0/5+1.0/numero;
	return s;
}
int main(){
	int numero;
	printf("Digite valor inteiro e positivo: ");
	scanf("%d",&numero);
	float s =valor(numero);
	printf("S deu: %.3f",s);
	return 0;
}
