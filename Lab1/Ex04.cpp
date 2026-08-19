#include <stdio.h>

int main(){
    float dinheiro,dinheiro_d,valor_casa;
    dinheiro=10000000;
    float salario_min,dolar,quantidade_casas;
    printf("Qual o salario min?: ");
    scanf("f%",&salario_min);
    printf("E o valor do dolar?: ");
    scanf("f%",&dolar);
    dinheiro_d=dinheiro*dolar;
    valor_casa=150*salario_min;
    quantidade_casas=dinheiro_d/valor_casa;
    printf("A quantidade de casas: f%",quantidade_casas);
    return 0;
}