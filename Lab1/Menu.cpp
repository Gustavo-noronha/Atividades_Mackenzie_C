#include <stdio.h>

int main(){
	int menu,nume1,nume2,soma,divi;
	int sair=0;
	printf("1 Soma\n2 divisao\n3 sair\n");
	printf("Digite sua escolha: ");
	scanf("%d",&menu);
	while (!sair){
		if (menu==1){
		printf("Digite o primeiro Numero: ");
		scanf("%d",&nume1);
		printf("Digite o segundo Numero: ");
		scanf("%d",&nume2);
		soma=nume1+nume2;
		printf("A soma deu %d",soma);
		break;
	}
	else if (menu==2){
		printf("Digite o primeiro Numero: ");
		scanf("%d",&nume1);
		printf("Digite o segundo Numero: ");
		scanf("%d",&nume1);	
		divi=nume1/nume2;
		printf("A soma deu %d",soma);
		break;
    }
	else if (menu==3){
		sair=1;
		break;
	}
	else{
		printf("Digite um valor valido");
		break;
	}
    }
	return 0;
}