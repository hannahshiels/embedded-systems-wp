// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels, group: 06 __ (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX 

// Write  a  program  that  reads  in  an  integer  number  between  1  and  5  from  the  keyboard  and  prints  out  one  of 
// existing five sentences on the console depending on what number was entered. You can invent the sentences 
// as you want, but each sentence should be unique.  
 
// The program continues to ask for a new number and exits if number isn ́t in the interval 1 to 5.

/**
 * Include Section
 */
#include <stdio.h>
#include <ctype.h>

/**
 * Main Function
 */

void main(void){

    //Variable Declaration section
    const char *prompt = "Please enter a number between 1 and 5 to see you fortune...\n";   //This message will ask users for the input
    const char *errPrompt = "The input must be an number between 0 and 6. Try again please\n";   //This message will be displayed in case of invalid input
    const char *msg_1 = "I am the first sentence\n";   //This message corresponds to input number 1
    const char *msg_2 = "Orange juice is delicious\n";   //This message corresponds to input number 2
    const char *msg_3 = "No way, pizza is the best\n";   //This message corresponds to input number 3
    const char *msg_4 = "Go to hell, only ice cream\n";   //This message corresponds to input number 4
    const char *msg_5 = "I am the best\n";   //This message corresponds to input number 5
    int input;   //User input will be saved in this variable

    //Main Body

    //Ask user to enter a number
    printf("%s", prompt);

    //Save the input in the defined variable
    scanf("%d", &input);

    //Check if the user input is between 0-6 and prompt them otherwise
    while (input < 1 || input > 5 /*|| !isdigit(input)*/)
    {
        //prompt user to enter an input again
        printf("%s", errPrompt);

        //Save the new value of input
        scanf("%d", &input);
    }

    //Show the corresponding message to each input number
    if (input == 1)
    {
        printf("%s", msg_1);
    }
    else if (input == 2)
    {
        printf("%s", msg_2);
    }
    else if (input == 3)
    {
        printf("%s", msg_3);
    }
    else if (input == 4)
    {
        printf("%s", msg_4);
    }
    else if (input == 5)
    {
        printf("%s", msg_5);
    }
}