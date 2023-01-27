#include <stdio.h>
#include <stdlib.h>

void MostrarMatriz(int **, int, int);
void TransporMatriz(int**, int, int);

int main(){
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);
    int **matriz = (int**) malloc(x*sizeof(int*));
    for(int i=0; i<x; i++){
        matriz[i] = (int*) malloc(y*sizeof(int));
    }

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d ", &matriz[i][j]);
        }
    }


    //MostrarMatriz(matriz, x, y);

    int **matriz2 = (int**) malloc(y*sizeof(int*));
    for(int i=0; i<y;i++){
        matriz2[i] = (int*) malloc(x*sizeof(int));
    }

    TransporMatriz(matriz, x, y);

    free(matriz);

}

void MostrarMatriz(int **matriz, int x, int y){
    //printf("\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d%c", matriz[i][j], j<y-1?' ':'\n');
            }
    }

}

void TransporMatriz(int** matriz, int x, int y){
    int **matriz2 = (int**) malloc(y*sizeof(int*));
    for(int i=0; i<y;i++){
        matriz2[i] = (int*) malloc(x*sizeof(int));
    }

    int aux;

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            matriz2[j][i] = matriz[i][j];
        }
    }
    MostrarMatriz(matriz2, y, x);
}