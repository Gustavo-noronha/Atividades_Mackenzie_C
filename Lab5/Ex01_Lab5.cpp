#include <stdio.h>


void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


void bubble_sort(int v[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                trocar(v, j, j + 1);
            }
        }
        

        printf("Passagem %d: {", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d", v[k]);
            if (k < n - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

int main() {
    int v[] = {5, 0, -1, 3, 2, 4};
    int n = 6;

    printf("Vetor inicial: {5, 0, -1, 3, 2, 4}\n");
    printf("----------------------------------------\n");

    bubble_sort(v, n);

    return 0;
}
