#include <stdio.h>


void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


int bubble_sort_sentinela(int v[], int n) {
    int i = 0;
    int houve_troca = 1; 
    int passagens = 0;

    while (i < n - 1 && houve_troca) {
        houve_troca = 0; 
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                trocar(v, j, j + 1);
                houve_troca = 1; 
            }
        }
        passagens++;
        i++;
    }

    return passagens;
}


void imprimir_vetor(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {

    int v_quase[] = {1, 2, 3, 5, 4};
    int n_quase = 5;


    int v_decresc[] = {5, 4, 3, 2, 1};
    int n_decresc = 5;

    printf("--- Teste a: Vetor quase ordenado ---\n");
    printf("Original: ");
    imprimir_vetor(v_quase, n_quase);
    int passagens_quase = bubble_sort_sentinela(v_quase, n_quase);
    printf("Ordenado: ");
    imprimir_vetor(v_quase, n_quase);
    printf("Total de passagens (quase ordenado): %d\n\n", passagens_quase);

    printf("--- Teste b: Vetor em ordem decrescente ---\n");
    printf("Original: ");
    imprimir_vetor(v_decresc, n_decresc);
    int passagens_decresc = bubble_sort_sentinela(v_decresc, n_decresc);
    printf("Ordenado: ");
    imprimir_vetor(v_decresc, n_decresc);
    printf("Total de passagens (decrescente): %d\n", passagens_decresc);

    return 0;
}
