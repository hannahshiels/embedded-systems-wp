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

int isValid(char *checker);

/**
 * second code: Convert binary to hexadecimal value
 */

int main(int argc, char* argv[])
{
    //variable declaration/initiation
    const char *errMsg = "Invalid Input. Try again later. Use '-h' to view tutorial!";
    const char *helpMsg = "Enter a binary value and receive the equivalent hexadecimal version of it.";
    unsigned long input;
    int i = 1;
    unsigned long int output = 0;   //hexadecimal value will be saved in this
    unsigned long int remainder; //used in the process of conversion
    int intChecker;   //used in err handling to capture irrelevant
    int validBinChecker = 0; //To check if the input is in binary. digits must be 0 & 1 only
    //body


    intChecker = *argv[1];

    validBinChecker = isValid(argv[1]);


    if (strcmp(argv[1], "-h") == 0)
    {
        printf("%s", helpMsg);
        return 2;
    } else if (isdigit(intChecker) == 0 || validBinChecker == 0)
    {
        printf("%s", errMsg);
        return 2;
    } else
    {
        input = atoi(argv[1]);
        while(input != 0)
        {
            remainder = input % 10;
            output = output + remainder * i;
            i = i * 2;
            input = input / 10;
        }

        //print out the result as hexadecimal
        printf("\n%02lX", output);
        return 0;
    }
}

int isValid(char *checker) {

    for (int i = 0; i < sizeof (checker); i++)
    {
        if (checker[i] != '0' && checker[i] != '1')
        {
            return 0;
        }
    }
    return 1;
}
