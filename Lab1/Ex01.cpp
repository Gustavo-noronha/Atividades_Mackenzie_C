#include <stdio.h>

int main(){
	float salario_min;
	float salario_bruto;
	printf("Qual o salario minimo?: ");
	scanf("%f",&salario_min);
	printf("Qual o seu salario bruto?: ");
	scanf("%f",&salario_bruto);
	float quant = salario_bruto/salario_min;
	printf("Voce ganha %f salario(s) minimo(s)",quant);
	return 0 ;	
}