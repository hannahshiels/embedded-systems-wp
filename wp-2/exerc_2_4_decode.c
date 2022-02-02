// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 4
// Submission code: xxxxxx

/**
 * This program decodes a hexadecimal value of size 2 (ex AB), and prints resulting values for a car
 **/

// ------ Includes   ----------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"
#include <math.h>
#include <ctype.h> // isxdigit,

// ------ Defines   ----------
#define ARG_LENGTH 2   //The length of the argument as a hexadecimal number
#define LENGTH_ERR "\nThe length of the argument is not correct. Enter a 2 character length argument."   //when the argument size is not correct
#define INVALID_HEX "\nThe entered argument is not a hexadecimal number. Please try again.."   //In case the argument contains other letters
#define NUMBER_OF_BITS 8   //number of bits in a single byte
#define FINAL_PROMPT "Decode"   //shows when the arg is decoded
#define HEADER "Name             Value"   //header of the result's table
#define ENGINE "engine_on"
#define GEAR "gear-pos"
#define KEY "key_pos"
#define BRAKE1 "brake1"
#define BRAKE2 "break2"
// ------ Function declarations   ----------

int getValue(int *car, int i);

// ------ Main   --------------------------

int main(int argc, char *argv[])
{
    //Variable declaration
    int i;   //used as counter in for loops
    char car[9];   //the binary format of the hexadecimal input is saved in this variable
    int intCar;   //stores the binary value of the car in int format
    int engine_on;   //to save the value allocated to engine
    int gear_pos;   //to save the value allocated to gears
    int key_pos;   //to save the value allocated to keys
    int brake1;   //to save the value allocated to brake1
    int brake2;   //to save the value allocated to brake2

    //Error handling
    if (strlen(argv[1]) != ARG_LENGTH)   //check for the size of the argument
    {
        //display the relevant error in the console
        printf(LENGTH_ERR);
        //exit
        return 1;
    }

    //Body
    //get the binary value from the hexadecimal format
    for (i = 0; i < (strlen(argv[1])); i++) {
        //check if the characters are valid hexadecimal values
        if (!isxdigit(argv[1][i])) {
            //print the relevant err
            printf(INVALID_HEX);
            //exit the program
            return 1;
        }
        //convert the hexadecimal elements into binary format and save them in a variable
        strcat(car, hexToBin(argv[1][i]));
    }
    //add this character to the end of the array to make it into a string
    car[8] = '\0';

    //convert the binary value from char to int
    intCar = atoi(car);

    //disassemble the digits to get the value corresponding to each car component. The order matters in here!
    // get the brake2
    brake2 = binToDec(getValue(&intCar, 1));
    // get the brake 1
    brake1 = binToDec(getValue(&intCar, 1));
    //get the key pos
    key_pos = binToDec(getValue(&intCar, 2));
    //get the gear pos
    gear_pos = binToDec(getValue(&intCar, 3));
    //get the engin status
    engine_on = binToDec(getValue(&intCar, 1));

    //Show the result in console window
    printf("\n%s %s\n\n%s\n", FINAL_PROMPT, argv[1], HEADER);

    for (i = 0; i < 25; i++) {
        printf("-");
    }
    printf("\n%s          %d\n%s           %d\n%s            %d\n%s             %d\n%s             %d\n",
           ENGINE, engine_on, GEAR, gear_pos, KEY, key_pos, BRAKE1, brake1, BRAKE2, brake2);

}


// ------ Function definitions   ----------

int getValue(int *car, int i) {

    int result;

    i = pow(10, i);
    result = *car % i;
    *car = *car / i;

    return result;
}