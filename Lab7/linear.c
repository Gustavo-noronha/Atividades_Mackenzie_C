#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
//esse programa ele busca dentro do vetor e imprime qual indice ele esta presente atravez de comparar todos os elementos da lista
void gerar_vetor(int v[], int n) {
    srand(time(NULL));
    int r = rand();
    int i;

    for(i=0; i<n; i++) {
        v[i] = 1 + rand() % (n*2);
    }
}

/*
    Busca o elemento 'e' no vetor 'v', retornando o índice
    da posicao da primeira ocorrencia.
    
    retorna -1 se o elemento nao esta presente no vetor.
*/
int busca_linear(int v[], int n, int e) {
    int i;
    for(i=0; i<n; i++) {
        if(v[i] == e) {
            return i;
        }
    }
    return -1;
}

void imprimir(int v[], int n) {
	int i;
    for( i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n = 10;
    int dados[10];
    bool sair = false;
    int op;

    // Gera 10 elementos aleatorios no vetor e realiza a busca linear do elemento
    gerar_vetor(dados, n);

    while (!sair) {
        printf("## Dados: ");
        imprimir(dados, n);

        printf("## Elemento a ser buscado de forma linear (ou -1 para sair): ");
        scanf("%d", &op);

        if(op == -1) {
            sair = true;
        } else {
            int indice = busca_linear(dados, n, op);
            printf("## Posicao em que o elemento foi encontrado: %d\n\n", indice);
        }
    }
    printf("\n## Fim!");
}
