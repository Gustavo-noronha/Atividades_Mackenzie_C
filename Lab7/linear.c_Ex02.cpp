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
    Busca o elemento 'e' no vetor 'v'.
    O parâmetro 'cont' é um ponteiro que altera a variável original na main.
*/
int busca_linear(int v[], int n, int e, int *cont) {
    int i;
    *cont = 0; // Inicializa o contador zerado

    for(i=0; i<n; i++) {
        (*cont)++; // 
        
        if(v[i] == e) {
            return i; // Retorna a posição e encerra a função
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
    int contador; // Variável que armazenará os passos da busca

    gerar_vetor(dados, n);

    while (!sair) {
        printf("## Dados: ");
        imprimir(dados, n);

        printf("## Elemento a ser buscado de forma linear (ou -1 para sair): ");
        scanf("%d", &op);

        if(op == -1) {
            sair = true;
        } else {
            // Passamos o endereço de memória (&contador) para a função
            int indice = busca_linear(dados, n, op, &contador);
            
            printf("## Contador: %d .\n", contador);
            printf("## Posicao em que o elemento foi encontrado: %d\n\n", indice);
        }
    }
    printf("\n## Fim!");
    
    return 0;
}
