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
#define Max_8bit_Num 255         //Largest decimal number that had 8 digits as a binary number
#define Max_16bit_Num 2147483647 //Largest number existing as lon in C compiler
#define Short_Length_Binary 8    //The number of the digits displayed to user while their number is less than maximum 8 bit number
#define Long_length_Binary 16    //The number of the digits displayed to user when their number is less than maximum 16 bit number

//This method converts a decimal number into binary format and displays the results using the number and the array length
//needed to save and show the results
void binConverter(long input, int arrayLength);

/**
* first code: Convert a decimal number to binary format
*/

int main(int argc, char *argv[])
{
    //Variable initiation
    unsigned long long longChecker;                                                                 //To check if the number is in the allowable range of long type in C compiler
    const char *errMsg = "The number you entered is too big for this compiler. Try again later..";  //Occurs when the argument magnitude is higher than maximum 16 bit
    const char *errMsg2 = "The value in the argument is not a number";                              //Occurs if the argument is a string
    const char *helpMsg = "Enter a decimal value and receive the equivalent binary version of it."; //will be displayed if the user is seeking help
    int intChecker;                                                                                 //To check if the argument is a number
    long int input;                                                                                 //the in format entered as argument

    //Body

    //change the type of the argument from char into long int
    input = atoi(argv[1]); //string to long

    //save the arg in a long long format to get values more than max long value.
    //According to the exercise description, the number should be a long. But to catch the errors in case the number is
    //more than allowable long, we save the argumnet in a long long too, and display an error message with the return
    //value 2.
    longChecker = atoi(argv[1]);

    //Check if the argument is in a number format. To do this check, we need to have the argument value as int to be able
    //to use it in isdigit method. Therefor there is another variable defined in type int to save the argument value in.
    //Again, the value of input also could be int and input could have been used in all of these checks, but the description
    //wants us to use long for input so that is why there are various variables defined.
    intChecker = *argv[1];

    if (strcmp(argv[1], "-h") == 0) //if the user input is '-h' and user seeks help
    {
        //the help message is displayed
        printf("%s", helpMsg);
        //exit with code 2
        return 2;
    }
    //Check for errors:
    else if (longChecker > Max_16bit_Num)
    { //if the number entered as the argument is more than the maximum long in C compiler
        //display the relevant error to the user
        printf("%s", errMsg);
        //exit with code number 2
        return 2;
    }
    //Check for errors:
    else if (isdigit(intChecker) == 0) //if the argument contains non digit values
    {
        //display the relevant error
        printf("%s", errMsg2);
        //exit with code 2
        return 2;
    }
    else
    { //if the argument is a regular decimal number

        //Check the magnitude of the argument
        if (input <= Max_8bit_Num) //if the number's binary form is less than 8digits
        {
            //convert the number displaying an 8 digit binary
            binConverter(input, Short_Length_Binary);
        }
        else if (input <= Max_16bit_Num && input > Max_8bit_Num) //if the number's binary form is more than 8 digits
        {
            //convert the number displaying an 16 digit binary
            binConverter(input, Long_length_Binary);
        }
        //exit with code 0
        return 0;
    }
}

void binConverter(long input, int arrayLength)
{
    //variable declaration
    int i;                   //used in loops to keep the track of indices
    int output[arrayLength]; //generate an array with the length needed to save the binary values

    //empty the memory allocated to the output array by iterating over the array replace previous values with 0
    for (i = 0; i < arrayLength; i++)
    {
        //place zero instead of the possible existing values
        output[i] = 0;
    }

    //get the binary equivalent to the input by saving the remainders of the division of input over 2.
    //The loop continues until the input value is so low that the result of input/2 is less than 1.
    for (i = 0; input > 0; i++)
    {
        //get the remainder value of the number divided by 2 and store it in the output array
        output[i] = input % 2;
        //next step
        input = input / 2;
    }
    //print out binary format of the input by starting from the last element in the output array
    for (i = (arrayLength - 1); i >= 0; i--)
    {
        //prints out the values
        printf("%d", output[i]);
    }
}
