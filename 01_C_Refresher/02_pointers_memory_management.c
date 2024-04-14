// # Detailed Explanation:
// ## Introduction to Pointers:
// Demonstrates how to declare pointers, use the address-of operator (&), and dereference pointers with the dereference operator (*).

// ## Dynamic Memory Allocation with malloc:
// Shows how to allocate memory dynamically and check if the allocation was successful. This is followed by initialization and access of the memory.
// ### Freeing the Allocated Memory:
// Explains and demonstrates the process of freeing allocated memory and the importance of setting pointers to NULL after freeing to avoid dangling pointers.

// ## Pointer Arithmetic:
// Covers how to perform arithmetic on pointers to iterate through arrays, showcasing a common use case in C programming.

// ## Functions Using Pointers:
// A simple function that increments the value of an integer demonstrates the utility of passing pointers to functions for modifying the original data.



#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    // Introduction to Pointers
    printf("\n--- Introduction to Pointers ---\n");
    int x = 10;
    int *p = &x; // Pointer to an integer
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void *)p);
    printf("Value at the address stored in p: %d\n", *p);

    // Dynamic Memory Allocation
    printf("\n--- Dynamic Memory Allocation ---\n");
    int *arr = (int *)malloc(5 * sizeof(int)); // Allocating space for 5 integers
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return -1; // Proper error handling
    }
    printf("Allocated memory for 5 integers.\n");
    for (int i = 0; i < 5; i++) {
        arr[i] = i * i; // Assign values to the array
    }

    printf("Array elements after initialization: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr); // Freeing the allocated memory
    // After freeing, accessing arr is undefined behavior. It might show garbage values, original values, or cause a crash.
    printf("Array elements after freeing: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = NULL;

    // Pointer Arithmetic
    printf("\n--- Pointer Arithmetic ---\n");
    int *arr2 = (int *)malloc(5 * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    int *ptr = arr2;
    printf("Storing values using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        *ptr = i + 1;
        ptr++; // Moving pointer to the next integer position
    }

    ptr = arr2; // Reset pointer back to the start of the array
    printf("Array elements using pointer arithmetic: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
    free(arr2);
    printf("Freed the allocated memory.\n");

    // Functions and Pointers
    printf("\n--- Functions and Pointers ---\n");
    void increment(int *value) {
        (*value)++;
    }

    int a = 10;
    printf("Value of a before increment: %d\n", a);
    increment(&a);
    printf("Value of a after increment: %d\n", a);

    return 0;
}
