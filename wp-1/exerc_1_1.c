// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6
// Work package 1
// Exercise 1: If statements
// Submission code: XXXXXX

/* Program to read integers on a interval from 1 - 5 and prints a  sentence depending on the number entered
* Exits if number entered is out of range
*/

#include <stdio.h>


// init variables 
const char prompt[] = "Enter an integer between 1 and 5: \n";
const char firstSentence[] = "Hello, my name is Hannah! \n";
const char secondSentence[] = "Hello, my name is Lucas! \n";
const char thirdSentence[] = "Hello, my name is Maryam! \n";
const char fourthSentence[] = "We are in the course DIT632! \n";
const char fifthSentence[] = "Our teacher is Miroslaw Staron! \n";

void main(void)
{
    // init variables to use during the loop
    int cont = 0;
    int num = 0;
    // stop loop if cont equals 1
    while (cont != 1)
    {
        printf("%s", prompt);  // ask for number
        scanf("%d", &num); // input  a number

        // stop the program if number is out of range
        if (num < 1 || num > 5)
        {
            cont = 1; // stop loop
            printf("Not within range. Exiting....");
        }
        else // usual case, number is within range
        {
            // print a different sentence based on the number
            switch (num)
            {
            case 1:
            {
                printf("%s", firstSentence);
                break;
            }
            case 2:
            {
                printf("%s", secondSentence);
                break;
            }
            case 3:
            {
                printf("%s", thirdSentence);
                break;
            }
            case 4:
            {
                printf("%s", fourthSentence);
                break;
            }
            case 5:
            {
                printf("%s", fifthSentence);
                break;
            }
            }
        }
    }
}