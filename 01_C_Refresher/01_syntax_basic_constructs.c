#include <stdio.h>

int main() {
    // Variable declarations
    int a = 5;
    float b = 3.2;
    char c = 'A';

    // Output variables
    printf("Integer a = %d\n", a);
    printf("Float b = %.1f\n", b);
    printf("Character c = %c\n", c);

    // Using a for loop to iterate from 1 to 5
    printf("Using a for loop to iterate from 1 to 5:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Using if-else to check the value of a
    if (a > 5) {
        printf("a is greater than 5\n");
    } else {
        printf("a is not greater than 5\n");
    }

    return 0;
}
