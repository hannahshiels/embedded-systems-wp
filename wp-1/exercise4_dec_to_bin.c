// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels, group: 06 __ (2022)
// Work package 1
// Exercise 4
// Submission code: XXXXXX


//You should write two programs, which convert between numbers in different format. You should make sure that these
//programs can be executed in a pipeline.

/**
 * Include section
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * Define Section
 */
#define Max_8bit_Num 255   //Largest decimal number that had 8 digits as a binary number
#define Max_16bit_Num 2147483647   //Largest number existing as lon in C compiler
#define Short_Length_Binary 8   //The number of the digits displayed to user while their number is less than maximum 8 bit number
#define Long_length_Binary 16   //The number of the digits displayed to user when their number is less than maximum 16 bit number


//This method converts a decimal number into binary format and displays the results using the number and the array length
//needed to save and show the results
void binConverter(long input, int arrayLength);

/**
* first code: Convert a decimal number to binary format
*/

int main(int argc, char* argv[])
{
    //Variable initiation
    unsigned long long longChecker;   //To check if the number is in the allowable range of long type in C compiler
    const char *errMsg = "The number you entered is too big for this compiler. Try again later..";   //Occurs when the argument magnitude is higher than maximum 16 bit
    const char *errMsg2 = "The value in the argument is not a number";   //Occurs if the argument is a string
    int intChecker; //To check if the argument is a number
    long int input;   //the in format entered as argument


    //Body

    //change the type of the argument from char into number
    input = atoi(argv[1]); //string to long

    //save the arg in an int format to get values more than max long value
    longChecker = atoi(argv[1]);

    //To check if the argument is a number format
    intChecker = *argv[1];

    //Check for errors
    if (longChecker > Max_16bit_Num) {
        printf("%s", errMsg);
        return 2;

    } else if (isdigit(intChecker) == 0)
    {
        printf("%s", errMsg2);
        return 2;

    } else {
        //if the argument is an 8bit binary
        if (input <= Max_8bit_Num)
        {
            binConverter ( input, Short_Length_Binary);

        } else if ( input <= Max_16bit_Num && input > Max_8bit_Num)  //if the number is a 16 bit binary
        {
            binConverter ( input, Long_length_Binary);

        }
        return 0;
    }

}

void binConverter(long input, int arrayLength) {
    int i;
    int output[arrayLength];

    for (i = 0; i < arrayLength; i++)
    {
        output[i] = 0;
    }

    for(i = 0; input > 0; i++)
    {
        //get the remainder value of the number divided by 2 and store it
        output[i] = input % 2;
        input = input / 2;
    }
    //print out binary format
    for(i = (arrayLength - 1); i >= 0; i--)
    {
        printf("%d",output[i]);
    }

}



