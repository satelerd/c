// # Key Points to Understand:

// ##File Operations:
// fopen(): Opens a file. You need to specify the mode, e.g., 'r' for reading, 'w' for writing.
// fprintf() and fscanf(): Used to write to and read from a file similar to printf() and scanf() but for file I/O.
// fgetc() and fputc(): Read and write a single character to/from a file, useful for iterating over the contents of a file.
// fclose(): Closes an opened file, freeing up any buffers used for reading or writing.

// ## Error Handling:
// Always check if the file was opened successfully by verifying the file pointer is not NULL after an attempt to open a file.

// ## Practical Usage:
// File handling is essential for any program that needs persistent storage, like log files, configurations, data analysis, etc.


#include <stdio.h>
#include <stdlib.h> // For exit() function

int main() {
    FILE *fptr; // File pointer

    // Opening a file for writing
    printf("== Opening a File for Writing ==\n");
    fptr = fopen("example.txt", "w"); // Open file in write mode
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Writing to the file
    printf("Writing to the file 'example.txt'\n");
    fprintf(fptr, "Hello, world! This is a test file.\n");
    fprintf(fptr, "Writing numbers: %d, %f\n", 25, 9.81);

    // Closing the file
    fclose(fptr);
    printf("File 'example.txt' has been written and closed.\n");
    printf("\n");

    // Opening a file for reading
    printf("== Opening a File for Reading ==\n");
    fptr = fopen("example.txt", "r"); // Open file in read mode
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Reading from the file
    printf("Reading from the file 'example.txt'\n");
    char ch;
    while ((ch = fgetc(fptr)) != EOF) { // Read until end of file
        printf("%c", ch); // Print each character
    }

    // Closing the file
    fclose(fptr);
    printf("\nFile 'example.txt' has been read and closed.\n");

    return 0;
}
