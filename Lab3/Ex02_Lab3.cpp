#include <stdio.h>
#include <stdbool.h>

bool verificar(int numero){
	if(numero%2==0){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int num;
	printf("Digite um numero inteiro: ");
	scanf("%d",&num);
	bool i = verificar(num);
	if(i){
		printf("Par");
	}
	else{
		printf("Impar");
	}
	return 0;
}
