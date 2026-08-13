#include <stdio.h>

int main(){
    int idade;
    char nome[50];
    printf("qual sua idade ?:");
    scanf("%d",&idade);
    printf("Qual seu nome?: ");
    scanf("%s",nome);
    printf("Sue nome e %s de idade %d anos",nome,idade);
    return 0;
}