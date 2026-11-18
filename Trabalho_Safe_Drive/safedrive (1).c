
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AMOSTRAS 100
/*Gustavo Tavernari Noronha Ra: 10769664, Tiago Ribeiro de Souza Ra: 10763028,Daniel Bertolin0 Lima Ra:10264743*/
/* gera 50 registros aleatorios para as matrizes iniciais */
int inicializarDados(float velocidades[][2], float sensoresFrontais[][3], float sensoresLaterais[][2]) {

    int i;
    int registros = 50;

    for (i = 0; i < registros; i++) {
        velocidades[i][0] = 40.0 + (rand() % 800) / 10.0;   /* gera as velocidade atual entre 40 e 120 km/h */
        velocidades[i][1] = 40.0 + (rand() % 800) / 10.0;   /* gera as velocidade do carro da frente */

        sensoresFrontais[i][0] = 5.0 + (rand() % 950) / 10.0;  /* gera o radar */
        sensoresFrontais[i][1] = 5.0 + (rand() % 950) / 10.0;  /* gera o  lidar */
        sensoresFrontais[i][2] = 5.0 + (rand() % 950) / 10.0;  /* gera o  camera */

        sensoresLaterais[i][0] = (rand() % 150) / 100.0;   /* gera a faixa esquerda entre 0 a 1.5m */
        sensoresLaterais[i][1] = (rand() % 150) / 100.0;   /* gera a faixa direita entre 0 a 1.5m */
    }

    return registros;
}

/* guarda a amostra lida na main na proxima linha vazia das matrizes */
int inserirAmostra(float velocidades[][2], float sensoresFrontais[][3], float sensoresLaterais[][2],int total, float vAtual, float vFrente, float radar, float lidar, float camera,float faixaEsq, float faixaDir) {

    velocidades[total][0] = vAtual;
    velocidades[total][1] = vFrente;

    sensoresFrontais[total][0] = radar;
    sensoresFrontais[total][1] = lidar;
    sensoresFrontais[total][2] = camera;

    sensoresLaterais[total][0] = faixaEsq;
    sensoresLaterais[total][1] = faixaDir;

    return total + 1;
}

/* mediana simples de 3 valores, sem precisar ordenar vetor nenhum */
float mediana3(float a, float b, float c) {

    if ((a >= b && a <= c) || (a <= b && a >= c))
        return a;
    if ((b >= a && b <= c) || (b <= a && b >= c))
        return b;
    return c;
}

/* funde radar, lidar e camera tirando a mediana das 3 leituras */
void calcularFusaoSensores(float sensoresFrontais[][3], float processamento[][2], int total) {

    int i;

    for (i = 0; i < total; i++) {
        processamento[i][0] = mediana3(sensoresFrontais[i][0], sensoresFrontais[i][1], sensoresFrontais[i][2]);
    }
}

/* calcula a distancia de frenagem pra cada amostra */
void calcularDistanciaSegura(float velocidades[][2], float processamento[][2], int total,float atrito, int sensibilidade) {

    int i;
    float tempoReacao;
    float vMs;

    if (sensibilidade == 1)
        tempoReacao = 1.0;
    else if (sensibilidade == 2)
        tempoReacao = 1.5;
    else
        tempoReacao = 2.0;

    for (i = 0; i < total; i++) {
        vMs = velocidades[i][0] / 3.6;  /* km/h -> m/s */
        processamento[i][1] = (vMs * tempoReacao) + (vMs * vMs) / (2 * atrito * 9.81);
    }
}

/* analisa o risco frontal (AEB) */
void analisarRiscoFrontal(float velocidades[][2], float processamento[][2], int status[][3], int total) {

    int i;
    float velRelativa;

    for (i = 0; i < total; i++) {
        velRelativa = velocidades[i][0] - velocidades[i][1];

        if (velRelativa <= 0) {
            status[i][0] = 0;
        } else {
            float validada = processamento[i][0];
            float segura = processamento[i][1];

            if (validada >= segura)
                status[i][0] = 0;
            else if (validada >= 0.5 * segura)
                status[i][0] = 1;
            else
                status[i][0] = 2;
        }
    }
}

/* checa se o carro ta invadindo a faixa esquerda ou direita */
void analisarFaixaDinamica(float velocidades[][2], float sensoresLaterais[][2], int status[][3], int total) {

    int i;
    float margemDinamica, zonaAtencao;

    for (i = 0; i < total; i++) {
        margemDinamica = 0.50;

        if (velocidades[i][0] > 80.0)
            margemDinamica += (velocidades[i][0] - 80.0) * 0.01;

        zonaAtencao = margemDinamica + 0.20;

        /* faixa esquerda */
        if (sensoresLaterais[i][0] < margemDinamica)
            status[i][1] = 2;
        else if (sensoresLaterais[i][0] < zonaAtencao)
            status[i][1] = 1;
        else
            status[i][1] = 0;

        /* faixa direita */
        if (sensoresLaterais[i][1] < margemDinamica)
            status[i][2] = 2;
        else if (sensoresLaterais[i][1] < zonaAtencao)
            status[i][2] = 1;
        else
            status[i][2] = 0;
    }
}

/* funcao para printf  */
void exibirRelatorio(float velocidades[][2], float sensoresFrontais[][3], float sensoresLaterais[][2],float processamento[][2], int status[][3], int total) {

    int i;

    for (i = 0; i < total; i++) {
        printf("\n=========== AMOSTRA %d ===========\n", i + 1);
        printf("\n");

        printf("-- Dados de entrada --\n");
        printf("\n");
        
        printf("Velocidade atual: %.2f km/h | Velocidade do veiculo a frente: %.2f km/h\n",velocidades[i][0], velocidades[i][1]);
        printf("Radar: %.2f | Lidar: %.2f | Camera: %.2f\n",sensoresFrontais[i][0], sensoresFrontais[i][1], sensoresFrontais[i][2]);
        printf("Faixa esquerda: %.2f m | Faixa direita: %.2f m\n",sensoresLaterais[i][0], sensoresLaterais[i][1]);

        printf("-- Dados processados --\n");
        printf("Distancia validada: %.2f m | Distancia segura calculada: %.2f m\n",processamento[i][0], processamento[i][1]);

        printf("___ Status ___ \n");
        printf("\n");

        if (status[i][0] == 0)
            printf("Status frontal: SEGURO\n");
        else if (status[i][0] == 1)
            printf("Status frontal: ATENCAO\n");
        else
            printf("Status frontal: RISCO DE COLISAO (AEB ACIONADO)\n");

        if (status[i][1] == 0)
            printf("Faixa esquerda: NORMAL\n");
        else if (status[i][1] == 1)
            printf("Faixa esquerda: ATENCAO\n");
        else
            printf("Faixa esquerda: PERIGO DE INVASAO\n");

        if (status[i][2] == 0)
            printf("Faixa direita: NORMAL\n");
        else if (status[i][2] == 1)
            printf("Faixa direita: ATENCAO\n");
        else
            printf("Faixa direita: PERIGO DE INVASAO\n");

        if (status[i][0] == 2 || status[i][1] == 2 || status[i][2] == 2)
            printf(" STATUS GERAL: INTERVENCAO CRITICA EXIGIDA \n");
        else if (status[i][0] == 1 || status[i][1] == 1 || status[i][2] == 1)
            printf(" STATUS GERAL: ATENCAO \n");
        else
            printf(" STATUS GERAL: NORMAL \n");
    }
}

int main(void) {

    float velocidades[MAX_AMOSTRAS][2];
    float sensoresFrontais[MAX_AMOSTRAS][3];
    float sensoresLaterais[MAX_AMOSTRAS][2];
    float processamento[MAX_AMOSTRAS][2];
    int status[MAX_AMOSTRAS][3];

    int total = 0;
    int opcao;
    float atrito;
    int sensibilidade;

    srand((unsigned int) time(NULL));

    printf("=== SafeDrive motor de decisao ADAS ===\n\n");
    printf("Informe o atrito da via (ex: 0.8): ");
    scanf("%f", &atrito);
    printf("Informe a sensibilidade do ADAS (1-Esportivo, 2-Normal, 3-Seguro): ");
    scanf("%d", &sensibilidade);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Carregar dados iniciais (50 registros aleatorios)\n");
        printf("2. Inserir nova amostra\n");
        printf("3. Processar e exibir relatorio de riscos\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                total = inicializarDados(velocidades, sensoresFrontais, sensoresLaterais);
                printf("\n%d registros carregados.\n", total);
                break;

            case 2:
                if (total >= MAX_AMOSTRAS) {
                    printf("\nNao ha mais espaco para novas amostras.\n");
                    break;
                } else {
                    float vAtual, vFrente, radar, lidar, camera, faixaEsq, faixaDir;

                    printf("\nVelocidade atual (km/h): ");
                    scanf("%f", &vAtual);
                    printf("Velocidade do veiculo a frente (km/h): ");
                    scanf("%f", &vFrente);
                    printf("Leitura do radar: ");
                    scanf("%f", &radar);
                    printf("Leitura do lidar: ");
                    scanf("%f", &lidar);
                    printf("Leitura da camera: ");
                    scanf("%f", &camera);
                    printf("Distancia da faixa esquerda (m): ");
                    scanf("%f", &faixaEsq);
                    printf("Distancia da faixa direita (m): ");
                    scanf("%f", &faixaDir);

                    total = inserirAmostra(velocidades, sensoresFrontais, sensoresLaterais, total,vAtual, vFrente, radar, lidar, camera, faixaEsq, faixaDir);
                }
                break;

            case 3:
                if (total == 0) {
                    printf("\nNenhuma amostra registrada ainda.\n");
                } else {
                    calcularFusaoSensores(sensoresFrontais, processamento, total);
                    calcularDistanciaSegura(velocidades, processamento, total, atrito, sensibilidade);
                    analisarRiscoFrontal(velocidades, processamento, status, total);
                    analisarFaixaDinamica(velocidades, sensoresLaterais, status, total);
                    exibirRelatorio(velocidades, sensoresFrontais, sensoresLaterais, processamento, status, total);
                }
                break;

            case 4:
                printf("\nEncerrando o simulador...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}