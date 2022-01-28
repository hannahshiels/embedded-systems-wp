// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 1
// Exercise 1: If statements
// Submission code: 571006

/* Program to read integers on a interval from 1 - 5 and prints a  sentence depending on the number entered
* Exits if number entered is out of range
*/

#include <stdio.h>

// init variables, messages to display to the user
const char prompt[] = "Enter an integer between 1 and 5: \n";
const char firstSentence[] = "Hello, my name is Hannah! \n";
const char secondSentence[] = "Hello, my name is Lucas! \n";
const char thirdSentence[] = "Hello, my name is Maryam! \n";
const char fourthSentence[] = "We are in the course DIT632! \n";
const char fifthSentence[] = "Our teacher is Miroslaw Staron! \n";
const char exitMessage[] = "Not within range. Exiting....";

void main(void)
{
    // init variables to use during the loop
    int cont = 0;
    int num = 0;
    // stop loop if cont equals 1
    while (cont != 1)
    {
        printf("%s", prompt); // ask for number
        scanf("%d", &num);    // input  a number

        // stop the program if number is out of range
        if (num < 1 || num > 5)
        {
            cont = 1;                  // stop loop
            printf("%s", exitMessage); // print exit message
        }
        else // usual case, number is within range
        {
            // print a different sentence based on the number
            if (num == 1) // if 1 is entered
            {
                printf("%s", firstSentence); // if 1 is entered show corresponding sentence
            }
            else if (num == 2) // if 2 is entered
            {
                printf("%s", secondSentence); // if 2 is entered show corresponding sentencce
            }
            else if (num == 3) // if 3 is entered
            {
                printf("%s", thirdSentence); // if 3 is entered show corresponding sentence
            }
            else if (num == 4) // if 4 is entered
            {
                printf("%s", fourthSentence); // if 4 is entered show corresponding sentence
            }
            else if (num == 5) // if 5 is entered
            {
                printf("%s", fifthSentence); // if 5 is entered show corresponding sentence
            }
        }
    }
}