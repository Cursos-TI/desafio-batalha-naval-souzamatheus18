#include <stdio.h>

// Definicoes de tamanho para o tabuleiro e as habilidades
#define TABULEIRO_TAMANHO 10
#define HABILIDADE_TAMANHO 5

// --- Funcoes para o jogo ---

// Funcao para preencher o tabuleiro com agua (0) e navios (3)
void preencher_tabuleiro(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO]) {
    int i, j;
    // Preenche com zeros (agua)
    for (i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (j = 0; j < TABULEIRO_TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Adiciona alguns navios (3) para o exemplo
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[8][7] = 3;
}

// Funcao para criar a matriz de habilidade (cone, cruz, octaedro)
// O parametro 'tipo' define qual forma sera criada (1=cone, 2=cruz, 3=octaedro)
void criar_habilidade(int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO], int tipo) {
    int i, j;
    int centro = HABILIDADE_TAMANHO / 2;

    // Inicializa a matriz de habilidade com zeros
    for (i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (j = 0; j < HABILIDADE_TAMANHO; j++) {
            matriz_habilidade[i][j] = 0;
        }
    }

    // Preenche a matriz de habilidade com a forma correta
    switch (tipo) {
        case 1: // CONE
            for (i = 0; i < HABILIDADE_TAMANHO; i++) {
                for (j = 0; j < HABILIDADE_TAMANHO; j++) {
                    // Lógica do cone que se expande
                    if (j >= centro - i && j <= centro + i) {
                        matriz_habilidade[i][j] = 1;
                    }
                }
            }
            break;
        case 2: // CRUZ
            for (i = 0; i < HABILIDADE_TAMANHO; i++) {
                for (j = 0; j < HABILIDADE_TAMANHO; j++) {
                    // Lógica da cruz (linha horizontal e vertical)
                    if (i == centro || j == centro) {
                        matriz_habilidade[i][j] = 1;
                    }
                }
            }
            break;
        case 3: // OCTAEDRO (Losango)
            for (i = 0; i < HABILIDADE_TAMANHO; i++) {
                for (j = 0; j < HABILIDADE_TAMANHO; j++) {
                    // Lógica do losango
                    if ((i + j >= centro && i + j <= centro * 3) && (j - i >= -centro && j - i <= centro)) {
                        matriz_habilidade[i][j] = 1;
                    }
                }
            }
            break;
    }
}

// Funcao para sobrepor a habilidade no tabuleiro
void sobrepor_habilidade(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO], 
                        int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO], 
                        int origem_linha, int origem_coluna) {
    int i, j;
    int offset = HABILIDADE_TAMANHO / 2;

    for (i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (j = 0; j < HABILIDADE_TAMANHO; j++) {
            // Apenas sobrepoe se a posicao da habilidade for 1
            if (matriz_habilidade[i][j] == 1) {
                int linha_tabuleiro = origem_linha + i - offset;
                int coluna_tabuleiro = origem_coluna + j - offset;

                // Verifica se a posicao no tabuleiro esta dentro dos limites
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TABULEIRO_TAMANHO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TABULEIRO_TAMANHO) {
                    // Marca a area afetada com 5, a menos que ja seja um navio
                    if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] != 3) {
                        tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
                    }
                }
            }
        }
    }
}

// Funcao para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO]) {
    int i, j;
    for (i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (j = 0; j < TABULEIRO_TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// --- Funcao principal ---

int main() {
    int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO];
    int matriz_habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    // --- HABILIDADE CONE ---
    printf("--- Habilidade: CONE ---\n");
    preencher_tabuleiro(tabuleiro);
    criar_habilidade(matriz_habilidade, 1); // Cria a forma de cone
    sobrepor_habilidade(tabuleiro, matriz_habilidade, 5, 5); // Ponto de origem: [5][5]
    exibir_tabuleiro(tabuleiro);
    printf("\n");

    // --- HABILIDADE CRUZ ---
    printf("--- Habilidade: CRUZ ---\n");
    preencher_tabuleiro(tabuleiro); // Reseta o tabuleiro
    criar_habilidade(matriz_habilidade, 2); // Cria a forma de cruz
    sobrepor_habilidade(tabuleiro, matriz_habilidade, 7, 3); // Ponto de origem: [7][3]
    exibir_tabuleiro(tabuleiro);
    printf("\n");
    
    // --- HABILIDADE OCTAEDRO ---
    printf("--- Habilidade: OCTAEDRO (Losango) ---\n");
    preencher_tabuleiro(tabuleiro); // Reseta o tabuleiro
    criar_habilidade(matriz_habilidade, 3); // Cria a forma de octaedro
    sobrepor_habilidade(tabuleiro, matriz_habilidade, 3, 3); // Ponto de origem: [3][3]
    exibir_tabuleiro(tabuleiro);

    return 0;
}