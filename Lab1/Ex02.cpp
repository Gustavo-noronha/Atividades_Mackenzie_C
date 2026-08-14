#include <stdio.h>

int main(){
	int horas,minutos;
	printf("Que horas sao agora (24H)? : ");
	scanf("%d",&horas);
	printf("quantos min?");
	scanf("%d",&minutos);
	int min = (horas*60)+minutos;
	printf("Ja se passaram %d minutos desde o inicio do dia\n",min);
	return 0;
}