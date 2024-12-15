// Cubo 5x5x5 suma columnas y filas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definimos las dimensiones del cubo
#define N 5

// Llena el cubo con los valores aleatorios del número 1 al 100
void fillCubo(int cubo[N][N][N]) {
    srand(time(NULL));
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                cubo[i][j][k] = 1 + rand() % 100;
            }
        }
    }
}

// Imprime los valores del cubo
void printCubo(int cubo[N][N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                printf("%d ", cubo[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Calcula la suma de una fila específica
void filSum(int cubo[N][N][N], int fil, int *sum) {
    *sum = 0;
    int j, k;
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            *sum += cubo[fil][j][k]; // Suma cada elemento en la fila especificada
        }
    }
}

// Calcula la suma de una columna específica
void colSum(int cubo[N][N][N], int col, int *sum) {
    *sum = 0;
    int i, k;
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            *sum += cubo[i][col][k]; // Suma cada elemento de la columna especificada
        }
    }
}

int main() {
    int cubo[N][N][N]; // Crea el cubo
    fillCubo(cubo); // Llena el cubo con valores aleatorios
    printCubo(cubo); // Imprime el cubo

    int filSumResult, colSumResult;
    filSum(cubo, 0, &filSumResult); // Calcula la suma de la fila 0 y la devuelve a través de filSumResult
    printf("Suma de la fila 0: %d\n", filSumResult);

    colSum(cubo, 0, &colSumResult); // Calcula la suma de la columna 0 y la devuelve a través de colSumResult
    printf("Suma de la columna 0: %d\n", colSumResult);

    return 0;
}
