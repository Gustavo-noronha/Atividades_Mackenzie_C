#include <stdio.h>


void calcular (float media,int frequencia){
	if (frequencia < 75){
		printf("Reprovado por baixa presenca");
	}
	else if (frequencia>= 75 && media >= 7.5){
		printf("Aprovado");
	}
	else if (media<7.5){
		printf("Esta de exame");
	}
}
int main(){
	float media; 
	int frequencia;
	printf("Insira sua Media: ");
	scanf("%f",&media);
	printf("Insira sua Frequencia(%%): ");
	scanf("%d",&frequencia);
	calcular(media,frequencia);
	return 0;
} 