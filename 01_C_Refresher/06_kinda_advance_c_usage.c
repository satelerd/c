#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>

// Advanced Memory Management
// Dynamically allocate a buffer that can be resized. This is useful for applications that need to handle varying sizes of data.
void* allocate_buffer(size_t size) {
    static void* buffer = NULL;
    static size_t current_size = 0;
    if (size > current_size) {
        free(buffer); // Free the existing buffer if the new size is larger.
        buffer = malloc(size); // Allocate new memory with the larger size.
        current_size = size;
        printf("Buffer resized to %zu bytes\n", size);
        printf("\n");
    }
    return buffer;
}

// In-Place Operations
// This function demonstrates in-place addition, where the results are stored in one of the input arrays.
void in_place_add(int* A, int* B, int size) {
    printf("Before in-place addition:\n");
    printf("Array A: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Array B: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", B[i]);
    }
    printf("\n\n");

    for (int i = 0; i < size; i++) {
        A[i] += B[i]; // Add and store the result in array A.
    }

    printf("After in-place addition:\n");
    printf("Array A: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

// Concurrency and Parallel Processing with OpenMP
// Parallel matrix multiplication using OpenMP to utilize multiple CPU cores.
void parallel_matrix_multiply(double *A, double *B, double *C, int N) {
    printf("Starting parallel matrix multiplication...\n");
    #pragma omp parallel for // OpenMP directive to parallelize the outer loop.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
    printf("Completed parallel matrix multiplication. Result matrix:\n");
    // Print a small part of the result matrix for demonstration.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", C[i * N + j]);
            if (j == 4) printf("\n");
        }
        if (i == 4) break;
    }
}

int main() {
    printf("Starting the advanced techniques demonstrations...\n");

    // Demonstrate advanced memory management
    size_t size = 500 * sizeof(int); // Size for 500 integers
    int* matrix = (int*) allocate_buffer(size);
    printf("--- Allocated memory for matrix operations--- \n");

    // Demonstrate in-place operations
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {5, 4, 3, 2, 1};
    in_place_add(A, B, 5);

    // Demonstrate parallel matrix multiplication
    int N = 1000;
    double *matA = (double*) malloc(N * N * sizeof(double));
    double *matB = (double*) malloc(N * N * sizeof(double));
    double *matC = (double*) malloc(N * N * sizeof(double));

    // Initialize matrices A and B
    for (int i = 0; i < N * N; i++) {
        matA[i] = i * 0.001;
        matB[i] = i * 0.002;
    }

    printf("--- Started parallel matrix multiplication--- \n");
    parallel_matrix_multiply(matA, matB, matC, N);

    free(matA);
    free(matB);
    free(matC);

    printf("Demonstration completed.\n");

    return 0;
}
