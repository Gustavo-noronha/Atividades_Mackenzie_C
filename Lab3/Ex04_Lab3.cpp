#include <stdio.h>

float calcular_peso(float altura,char sexo){
	float peso;
	if(sexo=='M' || sexo=='m'){
		peso = 72.2*altura-58;
		return peso;
	}
	else if(sexo=='F' || sexo=='f'){
		peso = 62.1*altura-44.7;
		return peso;
	}
}
int main(){
	char sexo;
	float altura;
	printf("Informe seu sexo (M/F): ");
	scanf("%c",&sexo);
	printf("Informe sua altura (M): ");
	scanf("%f",&altura);
	float peso_ideal = calcular_peso(altura,sexo);
	printf("Seu peso ideal e: %.2f",peso_ideal);
}
