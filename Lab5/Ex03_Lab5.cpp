#include <stdio.h>
#include <string.h>

#define MAX_NOME 100


void insertion_sort_strings(char v[][MAX_NOME], int n) {
    int i, j;
    char chave[MAX_NOME];

    for (i = 1; i < n; i++) {

        strcpy(chave, v[i]);
        j = i - 1;

        while (j >= 0 && strcmp(v[j], chave) > 0) {
            strcpy(v[j + 1], v[j]);
            j--;
        }


        strcpy(v[j + 1], chave);
    }
}

int main() {
    int n, i;

    printf("Introduza o numero de nomes a ordenar: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Numero invalido.\n");
        return 1;
    }


    char nomes[n][MAX_NOME];

    while (getchar() != '\n');

    printf("Introduza os %d nomes:\n", n);
    for (i = 0; i < n; i++) {
        printf("Nome %d: ", i + 1);
        fgets(nomes[i], MAX_NOME, stdin);
        
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    insertion_sort_strings(nomes, n);

    printf("\nNomes em ordem alfabetica:\n");
    for (i = 0; i < n; i++) {
        printf("- %s\n", nomes[i]);
    }

    return 0;
}
