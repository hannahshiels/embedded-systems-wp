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

/**
 * Define Section
 */
#define Max_8bit_Num 255

/**
* main code: Convert a decimal number to binary format
*/

int main(void)
{
    //Variable initiation
    const char *prompt = "Enter the decimal number you would like to convert into binary:\n";   //Asks users to enter a num
    const char *dispMsg = "Your number in binary format is: \n";
    long int input = 0;   //the decimal format entered by the user
    long int output_8[8] = {0,0,0,0,0,0,0,0};   //the binary 8_bit format is saved here
    long int output_16[16] = {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0};   //the binary 16_bit format is saved here
    int i;   //iteration counter in for-loop


    //body
    //Ask user to Enter the number as decimal
    printf("%s", prompt);

    //Save user input in a variable
    scanf("%ld", &input);

    //check the length of the user input
    //if the input is an 8bit binary
    if (input < Max_8bit_Num)
    {
        //get the binary values of the number one by one and store them in the corresponding array
        for(i = 0; input > 0; i++)
        {
            //get the residual value of the number divided by 2 and store it
            output_8[i] = input % 2;
            input=input/2;
        }
        //print out binary format
        printf("%s", dispMsg);
        for(i = 7; i >= 0; i--)
        {
            printf("%ld",output_8[i]);
        }
    } else   //if the number is a 16 bit binary
    {
        //Get the binary values of the number
        for(i = 0; input > 0; i++)
        {
            //get the residual value of the number divided by 2 and store it
            output_16[i] = input % 2;
            input=input/2;
        }
        //print out binary format
        printf("%s", dispMsg);
        for(i = 15; i >= 0; i--)
        {
            printf("%ld",output_16[i]);
        }

    }

    return 0;
}