#include <stdio.h>

int verifica (float a,float b,float c){
	if(a < b + c && b < a + c && c < a + b){
		return 0;
	}
	return 1;
}
void exibir(int numero){
	if(numero == 0){
		printf("Existe");
	}
	else{
		printf("Nao existe");
	}
}
int main (){
	float A,B,C;
	printf("Digite o lado A: ");
	scanf("%f",&A);
	printf("Digite o lado B: ");
	scanf("%f",&B);
	printf("Digite o lado C: ");
	scanf("%f",&C);
	exibir(verifica(A,B,C));
	return 0;	
}