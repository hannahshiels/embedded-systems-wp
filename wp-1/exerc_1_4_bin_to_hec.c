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

int isValid(char *checker);   //checks if the argument is in the binary format and the values are 0s & 1s

/**
 * second code: Convert binary to hexadecimal value
 */

int main(int argc, char* argv[])
{
    //variable declaration/initiation
    const char *errMsg = "Invalid Input. Try again later. Use '-h' to view tutorial!";   //will be displayed if the argument is invalid
    const char *helpMsg = "Enter a binary value and receive the equivalent hexadecimal version of it.";   //will be displayed if the user is seeking help
    unsigned long input;   //the argument is saved in this variable as the type long
    int i;   //used in the process of conversion from binary to decimal
    unsigned long int output;   //hexadecimal value will be saved in this
    unsigned long int remainder; //used in the process of conversion from binary to decimal
    int intChecker;   //int variable to save the int version of the argument in it and check if the argument is a number
    int validBinChecker; //boolean variable to confirm the validation of the number in the argument



    //body

    //save the argument value in an int so that it can be used in isdigit method to check the validation
    intChecker = *argv[1];

    //get the validation check of the argument digits so that they are not anything other than 0s and 1s
    validBinChecker = isValid(argv[1]);


    //Check for the input validation

    if (strcmp(argv[1], "-h") == 0)   //if the user input is '-h' and user seeks help
    {
        //the help message is displayed
        printf("%s", helpMsg);
        //exit with code 2
        return 2;

    } else if (isdigit(intChecker) == 0 || validBinChecker == 0)   // check if the argument is a number and if it is, is it a valid binary number
    {
        //if the input is not according the above criteria, an error message is displayed
        printf("%s", errMsg);
        //exit with code 2
        return 2;

    } else   //if everything makes sense in the argument!
    {
        input = atoi(argv[1]);   //save the argument into a long type variable
        i = 1;   //start the loop with the value 1 since 2 to the power of 0 is 1

        //convert the binary to hexadecimal
        while(input != 0)   //teh loop continues until the binary format divided by 10 has a value less than 1
        {
            remainder = input % 10;   //get the last digit of the binary format
            output = output + remainder * i;   // multiply the remainder by its corresponding power of two and add it to
                                               // output
            i = i * 2;   //go to the next power of two
            input = input / 10;   //remove the last digit of the input
        }

        //print out the result as hexadecimal
        printf("\n%02lX", output);
        return 0;
    }
}

int isValid(char *checker) {

    //iterates over the elements existing in the pointer array and checks if they are sth other than 1s and 0s
    for (int i = 0; i < sizeof (checker); i++)
    {
        if (checker[i] != '0' && checker[i] != '1')    //if they are not 0 or 1
        {
            //isvalid is false
            return 0;
        }
    }
    //isvalid is true
    return 1;
}
