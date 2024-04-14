// # Explanation:
// ## Memory Management
// This section demonstrates how to handle dynamic memory allocations that might need resizing based on varying data sizes. It uses a static buffer to avoid reallocating memory unnecessarily.

// ## In-Place Operations
// This example shows how to perform arithmetic operations directly on the data stored in an array, modifying the array in place. This is efficient as it does not require additional memory for the result.

// ## Concurrency with OpenMP
// OpenMP is used to parallelize the matrix multiplication process, significantly speeding up the computation by dividing the work among multiple processors. The #pragma omp parallel for directive tells the compiler to distribute the loop iterations across available threads, improving performance on multi-core systems.

// ## Matrix Multiplication Output
// After computing the matrix multiplication, a small part of the resulting matrix is printed to provide a tangible sense of the operation's outcome and to illustrate how the data is organized after parallel processing.


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
    clock_t start_time = clock(); // Mark the start of the calculation

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }

    clock_t end_time = clock(); // Mark the end of the calculation
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate the total time used

    printf("\nCompleted parallel matrix multiplication.\n");
    printf("Time spent: %.2f seconds\n", time_spent);
    printf("Result matrix (first 3x3 block):\n");
    // Print a small part of the result matrix for demonstration.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", C[i * N + j]);
            if (j == 4) printf("\n");
        }
        if (i == 4) break;
    }
    printf("\nThis 3x3 block is a small part of the entire result matrix to illustrate the outcome of the parallel matrix multiplication.\n");
}

// Multiplicación de matrices de manera secuencial
void sequential_matrix_multiply(double *A, double *B, double *C, int N) {
    clock_t start_time = clock(); // Marcar el inicio del cálculo

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }

    clock_t end_time = clock(); // Marcar el fin del cálculo
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calcular el tiempo total utilizado

    printf("\nCompleted sequential matrix multiplication.\n");
    printf("Time spent: %.2f seconds\n", time_spent);
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
    int N = 3000; // Adjust this value based on your system's capability

    // Ensure there's enough memory for matrices A, B, and C
    double *A_matrix = (double*) malloc(N * N * sizeof(double));
    double *B_matrix = (double*) malloc(N * N * sizeof(double));
    double *C_matrix = (double*) malloc(N * N * sizeof(double));

    // Initialize matrices A_matrix and B_matrix here...
    for (int i = 0; i < N * N; i++) {
        A_matrix[i] = i * 0.001;
        B_matrix[i] = i * 0.002;
    }

    printf("--- Starting parallel matrix multiplication ---\n");
    parallel_matrix_multiply(A_matrix, B_matrix, C_matrix, N);
    printf("\n");

    // Reset or clear the result matrix C_matrix before the next operation
    for (int i = 0; i < N * N; i++) {
        C_matrix[i] = 0.0;
    }

    printf("--- Starting sequential matrix multiplication ---\n");
    sequential_matrix_multiply(A_matrix, B_matrix, C_matrix, N);
    printf("\n");
    
    // Free the allocated memory
    free(A_matrix);
    free(B_matrix);
    free(C_matrix);

    printf("Demonstration completed.\n");

    return 0;
}
