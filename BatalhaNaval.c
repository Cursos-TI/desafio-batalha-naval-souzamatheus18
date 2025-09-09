#include <stdio.h>

    int main(){
        int i, j;
        int matriz[10][10] = {0};

        for(i = 0; i < 10; i++){
            matriz[2][6] = 3;
        }
        for(j = 0; j < 10; j++){
                matriz[7][8] = 3;
                matriz[7][7] = 3;
                matriz[7][6] = 3; 
            }
        
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }

        return 0;
    }