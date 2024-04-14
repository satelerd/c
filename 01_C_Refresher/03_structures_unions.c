#include <stdio.h>

// Define a structure for a car
typedef struct {
    char make[50];
    int model_year;
    float price;
} Car;

// Define a union for a data packet
typedef union {
    int intValue;
    float floatValue;
    char strValue[20];
} DataPacket;

int main() {
    // Using a Structure
    printf("== Using a Structure ==\n");
    Car myCar; // Declare a Car structure variable
    strcpy(myCar.make, "Tesla"); // Assign data to the structure's fields
    myCar.model_year = 2021;
    myCar.price = 30300.99;

    // Print details of the car
    printf("Car Make: %s\n", myCar.make);
    printf("Model Year: %d\n", myCar.model_year);
    printf("Price: $%.2f\n", myCar.price);
    printf("\n");

    // Using a Union
    printf("== Using a Union ==\n");
    DataPacket packet;
    packet.intValue = 123; // Store an integer
    printf("DataPacket as Int: %d\n", packet.intValue);

    packet.floatValue = 456.78; // Store a float, overwrites the int
    printf("DataPacket as Float: %f\n", packet.floatValue);

    strcpy(packet.strValue, "Example String"); // Store a string, overwrites the float
    printf("DataPacket as String: %s\n", packet.strValue);
    printf("\n");

    // Demonstrating the overlay of union data
    printf("== Overlay of Data in Union ==\n");
    printf("Int value after storing string: %d (garbage value)\n", packet.intValue);
    printf("Float value after storing string: %f (garbage value)\n", packet.floatValue);

    return 0;
}
