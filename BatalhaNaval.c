#include <stdio.h>
//declarei duas constantes para a matriz
#define LINHA 10
#define COLUNA 10

    int main(){
        int i, j;  // declarei as variaveis i e j para exibição da matriz
        int matriz[LINHA][COLUNA] = {0}; // defini as linhas e colunas da matriz como 0 para ser identificado como água

        printf("  A B C D E F G H I J\n");

        //coordenadas para o navio na  vertical
        matriz[2][6] = 3;
        matriz[3][6] = 3;
        matriz[4][6] = 3;

        //coordenadas para o navio na horizontal
        matriz[7][8] = 3;
        matriz[7][7] = 3;
        matriz[7][6] = 3;

        //coordenadas para os navios na diagonal
        matriz[0][0] = 3;
        matriz[1][1] = 3;
        matriz[2][2] = 3;
        matriz[3][3] = 3;

        matriz[9][0] = 3;
        matriz[8][1] = 3;
        matriz[7][2] = 3;

        //loop aninhado para exibir a matriz
        for(i = 0; i < LINHA; i++){
            printf("%d ", i);
            for(j = 0; j < COLUNA; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        return 0;
    }