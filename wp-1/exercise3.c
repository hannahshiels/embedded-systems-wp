// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels, group: 06 __ (2022)
// Work package 1
// Exercise 3
// Submission code: XXXXXX


//You should develop a very simple game in which the computer creates a random integer number, between 1..100, and the
//user then tries to guess the number.

/**
 * Include Section
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Define section
 */
#define MAX_NUMBER 10


/**
 * main code
 */

void main(void)
{
    //Variable declaration
    const char *prompt = "Can you guess what number I'm thinking of right now? It's between 0 and 100.\n";
    const char *lowErr = "Wrong number but close, guess a smaller number.\n";
    const char *highErr = "Wrong number but close, guess a bigger number.\n";
    const char *idiotErr = "I said a number between 0 and 100. Guess again!\n";
    const char *loserMsg = "You couldn't guess and now your time is up. Loooooser X)";
    const char *winnerMsg = "Well done, this is exactly what I've guessed. Here have some nothing for this victory :)";
    const char *tryNum = "You tried this many times:   ";
    int number;   //the random number is saved in here
    int guess;   //User's guess is saved in here
    int isFound = 0;   //changes into 1 if the number is correctly guessed by the user
    int tryCounter = 0;   //counts the number of tries that user does




    //main body
    //generate a random number between 0 and 100
    number  = rand() % 100;
    printf("%d", number);

    //ask the user to enter their input
    printf("%s", prompt);

    //save user's guess
    scanf("%d", &guess);

    //these steps happen as long as the number is not guessed by the user,or they run out of tries
    while (isFound == 0 && tryCounter < MAX_NUMBER)
    {
        tryCounter++;
        if (guess == number)
        {
            printf("%s \n %s %d\n", winnerMsg, tryNum, tryCounter);
            isFound = 1;
        } else if (guess < number && guess > 0)
        {
            printf("%s \n %s %d\n", highErr, tryNum, tryCounter);
            scanf("%d", &guess);
        } else if (guess > number && guess < 100)
        {
            printf("%s \n %s %d\n", lowErr, tryNum, tryCounter);
            scanf("%d", &guess);
        } else
        {
            printf("%s \n %s %d\n", idiotErr, tryNum, tryCounter);
            scanf("%d", &guess);
        }
    }

    if (isFound == 0)
    {
        printf("%s", loserMsg);
    }

}