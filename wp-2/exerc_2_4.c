// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 4
// Submission code: xxxxxx

/**
 * This program ...
 **/

// ------ Includes   ----------

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen
#include "dec_to_bin.h"

// ------ Defines   ----------

#define LENGTH_ERROR "There must be 8bits in a byte! Try again..." //will be displayed in case of invalid argument
#define NUMBER_OF_BITS 8   //number of bits in a single byte
#define ENGINE_BITS_SHIFT 7   //The bits allocated to engine in the memory will shift 7 times to the right
#define GEAR_BITS_SHIFT 4   //The bits allocated to gear in the memory will shift 4 times to the right
#define KEY_BITS_SHIFT 2    //The bits allocated to keys in the memory will shift 2 times to the right
#define BRAKE1_BITS_SHIFT 1   //The bits allocated to break2 in the memory will shift 1 times to the right

// ------ Variables   ----------


// ------ Function declarations   ----------

int lengthChecker(char *argument);   //checks the length of the argument

// ------ Main   --------------------------
// The main entry point for the program
int main(int argc, char *argv[])
{

    //variable declaration:
    unsigned char car;   //the values in the argument are saved in this variable as bits
    unsigned int engine_on;
    unsigned int gear_pos;
    unsigned int key_pos;
    unsigned int brake1;
    unsigned int brake2;
    char binCar[NUMBER_OF_BITS];

    //error handling
    if (lengthChecker(argv[1]) == 0)
    {
        printf(LENGTH_ERROR);
        return 1;
    }
    //TODO complete the err handling later

    //assign value to the car attributes
    engine_on = argv[1][0] - '0';   //convert the value from char to int
    gear_pos = argv[1][1] - '0';   //convert the value from char to int
    key_pos = argv[1][2] - '0';   //convert the value from char to int
    brake1 = argv[1][3] - '0';   //convert the value from char to int
    brake2 = argv[1][4] - '0';   //convert the value from char to int

    car = ((engine_on << ENGINE_BITS_SHIFT) | (gear_pos << GEAR_BITS_SHIFT) | (key_pos << KEY_BITS_SHIFT) | (brake1 << BRAKE1_BITS_SHIFT) | brake2);

    binConverter((long)car, 8, binCar);

    for (int i = 0;  i < sizeof (binCar); i++)
    {
        printf("%d", binCar[i]);
    }


    printf("\nThe size of the car is: %llu", sizeof(car));
    printf("\n%02lX", (long)car);
}

// ------ Function definitions   ----------

int lengthChecker(char *argument) {
    //Get the length of the argument
    if (strlen(argument) == 5)   //If the length is equal to 6 considering the last character to be /0
    {
        return 1;
    }
    return 0;
}