#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sortearNumero() {
    return (rand() % 100) + 1;
}

int obterPalpite() {
    int palpite;
    do {
        printf("Digite seu palpite (entre 1 e 100): ");
        if (scanf("%d", &palpite) != 1) {
            while (getchar() != '\n');
            palpite = 0;
        }
        
        if (palpite < 1 || palpite > 100) {
            printf("Valor invalido! Por favor, digite um numero entre 1 e 100.\n");
        }
    } while (palpite < 1 || palpite > 100);
    
    return palpite;
}

int verificarPalpite(int palpite, int numeroSorteado) {
    if (palpite == numeroSorteado) {
        return 1;
    } else if (palpite < numeroSorteado) {
        printf("Voce chutou muito baixo!\n");
        return 0;
    } else {
        printf("Voce chutou muito alto!\n");
        return 0;
    }
}

int main() {
    srand(time(NULL));

    int numeroSorteado = sortearNumero();
    int acertou = 0;
    int tentativas = 0;

    printf("Adivinhar\n");

    while (!acertou) {
        int palpite = obterPalpite();
        tentativas++;
        acertou = verificarPalpite(palpite, numeroSorteado);
    }

    printf("Parabéns!!! Você acertou! Tentativas: %d\n", tentativas);

    return 0;
}