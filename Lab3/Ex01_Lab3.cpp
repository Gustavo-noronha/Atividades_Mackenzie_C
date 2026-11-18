#include <stdio.h>

int idade(){
	int idade;
	printf("Digite sua idade: ");
	scanf("%d",&idade);
	return idade;
}
int classificar(int idade){
	if (5<=idade && 7>=idade){
		return 1;
	}
	else if (8<=idade && 10>=idade){
		return 2;
	}
	else if (11<=idade && 13>=idade){
		return 3;
	}
	else if (14<=idade && 17>=idade){
		return 4;
	}
	else if (idade>=18){
		return 5;
	}
	else{
		return -1;
	}
}
void exibir(int numero){
	if(numero==1){
		printf("Infantil A");
	}
	else if(numero==2){
		printf("Infantil B");
	}
	else if(numero==3){
		printf("Juvenil A");
    }
    else if(numero==4){
    	printf("Juvenil B");
	}
	else if(numero==5){
		printf("Adulto");
	}
	else{
		printf("Idade abaixo de 5 anos");
	}
}
int main(){
	int i =idade();
	printf("Idade: %d\n",i);
	exibir(classificar(i));
	return 0;
}
