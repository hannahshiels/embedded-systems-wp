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
#define LENGTH_ERR "\nThe length of the argument is not correct. Enter a 2 character length argument."   //when the argument size is not correct
#define INVALID_HEX "\nThe entered argument is not a hexadecimal number. Please try again.."   //In case the argument contains other letters
#define VALUE_ERR "\nThe values entered in the argument are invalid for some components of the car. Try again..."   //In case the values are not in the range
#define NUMBER_OF_BITS 8   //number of bits in a single byte
#define FINAL_PROMPT "Decode"   //shows when the arg is decoded
#define HEADER "Name             Value"   //header of the result's table
#define ENGINE "engine_on"
#define GEAR "gear-pos"
#define KEY "key_pos"
#define BRAKE1 "brake1"
#define BRAKE2 "break2"
#define ENGINE_BITS_SHIFT 7   //The bits allocated to engine in the memory will shift 7 times to the right
#define GEAR_BITS_SHIFT 4   //The bits allocated to gear in the memory will shift 4 times to the right
#define KEY_BITS_SHIFT 2    //The bits allocated to keys in the memory will shift 2 times to the right
#define BRAKE1_BITS_SHIFT 1   //The bits allocated to break2 in the memory will shift 1 times to the right

// ------ Function declarations   ----------

int valueChecker(char brake2, char brake1, char pos, char pos1, char on);
// ------ Main   --------------------------

int main(int argc, char *argv[])
{
    //Variable declaration
    int i;
    int intNum;   //the integer format of the input
    char engin;   //
    char gear;
    char key;
    char brake1;
    char brake2;


    for (i = 0; i < (strlen(argv[1])); i++) {
        //check if the characters are valid hexadecimal values
        if (!isxdigit(argv[1][i])) {
            //print the relevant err
            printf(INVALID_HEX);
            //exit the program
            return 1;
        }
    }

    intNum = (int)strtol(argv[1], NULL, 16);

    if ( intNum > 255)
    {
        printf("%s", VALUE_ERR);
        return 1;
    }


    engin =  (intNum >> ENGINE_BITS_SHIFT) + '0';
    gear = ((intNum >> GEAR_BITS_SHIFT ) - (intNum >> ENGINE_BITS_SHIFT)* pow(2,(ENGINE_BITS_SHIFT-GEAR_BITS_SHIFT))) + '0';
    key = ((intNum >> KEY_BITS_SHIFT) - (intNum >> GEAR_BITS_SHIFT) * pow(2, (GEAR_BITS_SHIFT - KEY_BITS_SHIFT))) + '0';
    brake1 = ((intNum >> BRAKE1_BITS_SHIFT) - (intNum >> KEY_BITS_SHIFT) * pow(2, (KEY_BITS_SHIFT - BRAKE1_BITS_SHIFT))) + '0';
    brake2 = (intNum - (intNum >> BRAKE1_BITS_SHIFT) * pow (2, BRAKE1_BITS_SHIFT)) + '0';

    if (valueChecker(brake2, brake1, key, gear, engin) == 0) {
        printf("%s", VALUE_ERR);
        return 1;
    }

    printf("\n%s %s\n\n%s\n", FINAL_PROMPT, argv[1], HEADER);

    for (i = 0; i < 25; i++) {
        printf("-");
    }
    printf("\n%s          %c\n%s           %c\n%s            %c\n%s             %c\n%s             %c\n",
           ENGINE, engin, GEAR, gear, KEY, key, BRAKE1, brake1, BRAKE2, brake2);

    return  0;

}

// ------ Function definitions   ----------

int valueChecker(char brake2, char brake1, char key, char gear, char engine) {
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



