// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 4
// Submission code: 653025

/**
 * This program receives a string of length 5 with numbers between 0-4 in arguments and prints:
 * 1. the binary value
 * 2. the hexadecimal value
 **/

// ------ Includes   ----------

#include <stdio.h>
#include <string.h> // strlen
#include "dec_to_bin.h"
#include <ctype.h>

// ------ Defines   ----------

#define LENGTH_ERROR "\nThe input must be a five digit number. Try again...." //will be displayed in case of invalid argument
#define FORMAT_ERROR "\nThere should be only numbers in the input. Try again..."   //if a string is provided as argument
#define VALUE_ERROR "\nThe value of the digits in the argument are not correct. Please try again..."   //if the digits are not relevant
#define HEC_PROMPT "\nThe hexadecimal value of your argument is:   "   //will be displayed when converting to hexadecimal
#define ARGU_LENGTH 5   //The size of the argument must not exceed this value
#define NUMBER_OF_BITS 8   //number of bits in a single byte
#define ENGINE_BITS_SHIFT 7   //The bits allocated to engine in the memory will shift 7 times to the right
#define GEAR_BITS_SHIFT 4   //The bits allocated to gear in the memory will shift 4 times to the right
#define KEY_BITS_SHIFT 2    //The bits allocated to keys in the memory will shift 2 times to the right
#define BRAKE1_BITS_SHIFT 1   //The bits allocated to break2 in the memory will shift 1 times to the right

// ------ Function declarations   ----------

int lengthChecker(char *argument);   //checks the length of the argument

int formatChecker(char *string);   //checks the format of the argument to make sure it's a string

int checkNums(char engine, char gear, char key, char brake2,
              char brake1);   //checks the value of the numbers in the argument

// ------ Main   --------------------------
// The main entry point for the program

int main(int argc, char *argv[])
{

    //variable declaration:
    unsigned char car;   //the values in the argument are saved in this variable as bits
    char binCar[NUMBER_OF_BITS];   //The binary value of the car is saved in here

    //error handling
    if (lengthChecker(argv[1]) == 0)   //checks the length of the argument
    {
        //display relevant error
        printf(LENGTH_ERROR);
        //exit with code 1
        return 1;
    } else if (formatChecker(argv[1]) == 0)   //checks the format of the argument
    {
        //displays the relevant error
        printf(FORMAT_ERROR);
        //exit with code 1
        return 1;
    }

    //handle irrelevant numbers in the argument
    if (checkNums(argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4]) == 0) {
        //display relevant error
        printf(VALUE_ERROR);
        //exit the program
        return 1;
    }

    //put all the bits together in a byte with the order mentioned in assignment description
    car = (((argv[1][0] - '0') << ENGINE_BITS_SHIFT) | ((argv[1][1] - '0') << GEAR_BITS_SHIFT) | ((argv[1][2] - '0') << KEY_BITS_SHIFT) |
           ((argv[1][3] - '0') << BRAKE1_BITS_SHIFT) | (argv[1][4] - '0'));

    //get the binary value of the byte only for testing
    binConverter((long) car, 8, binCar);

    //print out the values in the binary form of the byte
    for (int i = 0; i < sizeof(binCar); i++) {
        printf("%d", binCar[i]);   //print each bit as a number in the byte
    }


    // print Hexadecimal value
    printf("%s%02lX", HEC_PROMPT, (long) car);
    return 0;
}

// ------ Function definitions   ----------

int lengthChecker(char *argument) {
    //Get the length of the argument
    if (argument != NULL && // Stop NULL arguments
        strlen(argument) == ARGU_LENGTH)   //If the length is equal to 6 considering the last character to be /0
    {
        //if the length is correct:
        return 1;
    }
    //if the length is lower or higher:
    return 0;
}

int formatChecker(char *string) {   //to check the format of argumnet

    // for all characters in the string; https://www.geeksforgeeks.org/isalpha-isdigit-functions-c-example/
    for (int i = 0; string[i] != '\0'; i++) {
        //check the format
        if (isdigit(string[i])) {
            //if it is a number:
            return 1;
        }

    }

    //if it's not a number:
    return 0;
}

int checkNums(char engine, char gear, char key, char brake2,
              char brake1) {   //check the values in the argument
    if (engine != '1' && engine != '0')   //if engine value is not in th range
    {
        //return 0
        return 0;
    } else if (gear != '4' && gear != '2' && gear != '1' && gear != '0')   //if gear value is not in th range
    {
        return 0;
    } else if (key != '0' && key != '1' && key != '2')   //if key value is not in th range
    {
        return 0;
    } else if (brake2 != '1' && brake2 != '0')   //if brake2 value is not in th range
    {
        return 0;
    } else if (brake1 != '1' && brake1 != '0')   //if break1 value is not in th range
    {
        return 0;
    }
    //If the values are in the range
    return 1;
}