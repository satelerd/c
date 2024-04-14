// # Key Concepts Covered:
// 1. Matrix Creation and Initialization: Defining and initializing matrices in C using arrays.
// 2. Matrix Addition and Multiplication: Implementing two of the most fundamental matrix operations used in neural networks.
// 3. Function for Displaying Matrices: A utility function to print matrices, which helps in visualizing the results of operations.

// ## Why It's Interesting:
// This example sets the groundwork for more complex computations in neural networks and other areas of numerical computing and linear algebra. Understanding how to perform these basic operations efficiently is essential for building up to more complex neural network algorithms.
// By incorporating matrix operations, we're taking a significant step towards implementing and understanding the computational aspects of neural networks in C. This foundational knowledge is crucial as we progress towards more specific neural network structures and training algorithms.

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void printMatrix(int matrix[ROWS][COLS]);
void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]);
void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]);

int main() {
    int matrixA[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultMatrix[ROWS][COLS] = {0};

    printf("Matrix A:\n");
    printMatrix(matrixA);

    printf("\nMatrix B:\n");
    printMatrix(matrixB);

    // Adding matrices
    addMatrices(matrixA, matrixB, resultMatrix);
    printf("\nResult of Adding A and B:\n");
    printMatrix(resultMatrix);

    // Multiplying matrices
    multiplyMatrices(matrixA, matrixB, resultMatrix);
    printf("\nResult of Multiplying A and B:\n");
    printMatrix(resultMatrix);

    return 0;
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[ROWS][COLS], int matrixB[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
