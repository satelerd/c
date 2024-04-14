#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    // Basic pointer declaration and usage
    int x = 10;
    int *p = &x; // Pointer to an integer
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void *)p);
    printf("Value at the address stored in p: %d\n", *p);

    // Dynamic memory allocation with malloc
    int *arr = (int *)malloc(5 * sizeof(int)); // Allocating space for 5 integers
    if (arr != NULL) {
        for (int i = 0; i < 5; i++) {
            arr[i] = i * i; // Assign values to the array
        }

        printf("Array elements: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    free(arr); // Freeing the allocated memory

    // Pointer arithmetic
    int *arr2 = (int *)malloc(5 * sizeof(int));
    if (arr2 != NULL) {
        int *ptr = arr2;
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
    }
    free(arr2);

    // Functions using pointers
    void increment(int *value) {
        (*value)++;
    }

    int a = 10;
    increment(&a);
    printf("Value of a after increment: %d\n", a);

    return 0;
}
