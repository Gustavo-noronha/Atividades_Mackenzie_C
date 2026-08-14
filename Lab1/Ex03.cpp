#include <stdio.h>

int main(){
	float nota1,nota2,nota3;
	printf("1 nota");
	scanf("%f",&nota1);
	printf("2 nota");
	scanf("%f",&nota2);
	printf("3 nota");
	scanf("%f",&nota3);
	float media = (nota1+nota2+nota3)/3;
	printf("sua media deu: %.2f",media);
	return 0;
}