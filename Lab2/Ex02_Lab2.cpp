#include <stdio.h>
#include <math.h>
//pow = potencia (numero,elevado)
int main(){
	float peso,altura,imc;
	printf("Digite sua peso(kg): ");
	scanf("%f",&peso);
	printf("Digite sua altura(M): ");
	scanf("%f",&altura);
	imc = peso/pow(altura,2);
	printf("Seu Imc deu: %.2f ",imc);
	return 0;
}