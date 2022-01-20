// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 1: If statements
// Submission code: XXXXXX

// Write  a  program  that  reads  in  an  integer  number  between  1  and  5  from  the  keyboard  and
// prints  out  one  of existing five sentences on the console depending on what number was entered. You can invent the sentences
// as you want, but each sentence should be unique.

// The program continues to ask for a new number and exits if number isn ́t in the interval 1 to 5.

#include <stdio.h>

void main(void)
{
    // init variables to use during the loop
    int cont = 0;
    int num = 0;
    // stop loop if cont equals 1
    while (cont != 1)
    {
        printf("Enter an integer between 1 and 5: \n");
        // input  a number 
        scanf("%d", &num);

        // stop the program if number is out of range
        if (num < 1 || num > 5)
        {
            cont = 1;
            printf("Not within range. Exiting....");
        }
        else
        {
            // print a new sentence based on the number
            if (num == 1)
            {
                printf("Hello, my name is Hannah! \n");
            }
            else if (num == 2)
            {
                printf("Hello, my name is Lucas! \n");
            }
            else if (num == 3)
            {
                printf("Hello, my name is Maryam! \n");
            }
            else if (num == 4)
            {
                printf("We are in the course DIT632! \n");
            }
            else
            {
                printf("Our teacher is Miroslaw Staron! \n");
            }
        }
    }
}