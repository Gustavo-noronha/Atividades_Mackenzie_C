#include <stdio.h>

int main(){
    int numero;	
	printf("Digite um numero inteiro: ");
	scanf("%d",&numero);
	if (numero%5==0){
		printf("E multiplo de 5");
	}
	else{
		printf("Nao e multiplo de 5");
	}
	return 0;
}