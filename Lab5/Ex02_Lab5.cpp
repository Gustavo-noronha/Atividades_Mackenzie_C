#include <stdio.h>

void trocar(float v[], int i, int j) {
    float aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void selection_sort(float v[], int n) {
    int i, j, min_index;

    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            trocar(v, i, min_index);
        }

        printf("Passagem %d: indice minimo escolhido = %d (valor posicionado: %.2f)\n", i + 1, min_index, v[i]);
    }
}

int main() {
    int n, i;

    printf("Introduza o numero de notas: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Numero invalido.\n");
        return 1;
    }

    float notas[n];

    printf("Introduza as %d notas :\n", n);
    for (i = 0; i < n; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    selection_sort(notas, n);

    printf("\nNotas finais em ordem crescente:\n{");
    for (i = 0; i < n; i++) {
        printf("%.2f", notas[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
