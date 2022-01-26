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
#define Max_8bit_Num 255
#define Max_16bit_Num 2147483647

/**
* first code: Convert a decimal number to binary format
*/

int main(int argc, char* argv[])
{
    //Variable initiation
    unsigned long long longChecker;   //To check the length of the number entered in the argument
    const char *errMsg = "The number you entered is too big for this compiler. Try again later..";
    const char *errMsg2 = "The value in the argument is not a number";
    int intChecker; //To check if the argument is a number
    long int input;   //the decimal format entered as argument
    long int output_8[8] = {0,0,0,0,0,0,0,0};   //the binary 8_bit format is saved here
    long int output_16[16] = {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0};   //the binary 16_bit format is saved here
    int i;   //iteration counter in for-loop


    //Body

    //change the type of the argument from char into number
    input = atoi(argv[1]);

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
            //get the binary values of the number one by one and store them in the corresponding array
            for(i = 0; input > 0; i++)
            {
                //get the remainder value of the number divided by 2 and store it
                output_8[i] = input % 2;
                input = input / 2;
            }
            //print out binary format
            for(i = 7; i >= 0; i--)
            {
                printf("%ld",output_8[i]);
            }
        } else if ( input <= Max_16bit_Num && input > Max_8bit_Num)  //if the number is a 16 bit binary
        {
            //Get the binary values of the number
            for(i = 0; input > 0; i++)
            {
                //get the remainder value of the number divided by 2 and store it
                output_16[i] = input % 2;
                input = input / 2;
            }
            //print out binary format
            for(i = 15; i >= 0; i--)
            {
                printf("%ld",output_16[i]);
            }

        }
        return 0;
    }

}

