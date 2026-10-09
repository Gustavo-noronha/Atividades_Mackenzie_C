#include <stdio.h>


void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


int bubble_sort_original(int v[], int n, int *comparacoes) {
    int i, j;
    *comparacoes = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                trocar(v, j, j + 1);
            }
        }
    }
    return *comparacoes;
}


int bubble_sort_otimizado(int v[], int n, int *comparacoes) {
    int i, j;
    *comparacoes = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                trocar(v, j, j + 1);
            }
        }
    }
    return *comparacoes;
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
    int n = 6;
    

    int v_orig[] = {5, 0, -1, 3, 2, 4};
    int v_otim[] = {5, 0, -1, 3, 2, 4};
    
    int comp_orig = 0;
    int comp_otim = 0;

    printf("Vetor inicial: ");
    imprimir_vetor(v_orig, n);
    printf("----------------------------------------\n");

    bubble_sort_original(v_orig, n, &comp_orig);
    bubble_sort_otimizado(v_otim, n, &comp_otim);

    printf("Versao Original:\n");
    printf("- Vetor ordenado: ");
    imprimir_vetor(v_orig, n);
    printf("- Total de comparacoes: %d\n\n", comp_orig);

    printf("Versao Otimizada:\n");
    printf("- Vetor ordenado: ");
    imprimir_vetor(v_otim, n);
    printf("- Total de comparações: %d\n", comp_otim);

    return 0;
}
