#include <stdio.h>

int main(){
	int num1,num2;
	printf("Digite o primero numero ");
	scanf("%d",&num1);
	printf("Digite o segundo numero ");
	scanf("%d",&num2);
	int soma = num1+num2;
	int divi= num1/num2;
	int sub = num1 - num2;
	int mult = num1*num2;
	printf("soma : %d , divisao : %d , subtracao : %d , multiplicao : %d",soma,divi,sub,mult);
	return 0;
}