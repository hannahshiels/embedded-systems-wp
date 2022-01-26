// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 1
// Submission code: XXXXXX

/**
 * This program:
 * 1. Reads in an integer number between 1 and 5 from the keyboard.
 * 2. Prints out one of five sentences on the console depending on input.
 * 3. The program continues to ask for a new number if input is between 1 and 5
 * 4. The program exits if input isn't a number or in the interval 1 to 5.
 **/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare Constants
const char *INPUT_MESSAGE = "\nPlease enter a value between 1-5: ";
const char *END_MESSAGE = "\nThe program is shutting down...";
const char *array[] = { // Define an array with messages
    "Hehehe!",
    "HAHAHA!",
    "MWAHAHAHA!",
    "MYAHAHAHAHAHAHA!!",
    "FNGHAHAHAHAHAHAHAHAHAHAHAAHAFHS!!!!!!"};

// Declare Variables
char input[10];       // A char array for storing user input
int isNumber = 1;     // boolean for storing if "inputAsInt" is a number
int isNumBetween = 1; // boolean for storing if "inputAsInt" is between a given range

// Declare Functions
int is_number(char *val);
int is_num_between(int i, int start, int end);

// Main function in the program, one program argument supported with errors handled
void main(void)
{
    // Run the while loop while the input is a number and while it is between a given range
    while (isNumber && isNumBetween)
    {
        printf("%s", INPUT_MESSAGE); // Print input message
        scanf("%s", &input);         // Ask to enter a value.

        int inputAsInt = atoi(input);                    // Convert input to integer
        isNumber = is_number(input);                     // Store boolean
        isNumBetween = is_num_between(inputAsInt, 1, 5); // Store boolean
        if (isNumber == 1 && isNumBetween == 1)          // Check if input is number && between a given range
        {
            int index = inputAsInt - 1; // EX: input of 1 will print index 0 in array
            printf("%s", array[index]); // Print the related char array based on inputed number
        }
    }

    printf("%s", END_MESSAGE); // Print end-of-program message
}

/**
 * This function checks if a value(val) is a number
 * RETURN 1(true) if val is a number
 **/
int is_number(char *val) // Why can't we say "val" instead?
{
    int isDigit = 0; // boolean

    for (int i = 0; i < strlen(val); i++) // Check provided val
    {
        isDigit = isdigit(val[i]); // Check if current index is a number

        if (0 == isDigit)
            return 0; // return 0 if detecting non-integer value
    }

    return 1; // else, return 1
}

/**
 * This function checks if an integer is between a certain range(start, end)
 * RETURN 1(true) if i is between range
 **/
int is_num_between(int i, int start, int end)
{
    if (i >= start && i <= end) // check if i is withing start, end
        return 1;               // return true if i is within range

    return 0; // else, return 0
}