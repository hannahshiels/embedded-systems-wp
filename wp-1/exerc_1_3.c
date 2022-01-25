// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6
// Work package 1
// Exercise 3: Guess the number game
// Submission code: XXXXXX

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
Simple game where user enters a number within the specified range and must guess within the guess limit.
Crashes whenever string is entered :/
*/

// declare variables
const int MIN = 1;
const int MAX = 100;
const int MAX_NUMBER = 3;

int createRandomNumber()
{
    srand(time(0));                          // ensure new number is randomly generated
    return (rand() % (MAX - MIN + 1)) + MIN; // calculate random number from upper and lower bounds
}

void main()
{
    int randomNum = createRandomNumber();                 // get random number
    printf("Randomly generated number is %d", randomNum); // print randomly generate number
    // init variables for loop
    int guess;
    int guessCount = 0;
    int cont = 0;
    while (cont != 1)
    {
        printf("\nGuess between %d and %d. You have %d guesses.\n", MIN, MAX, MAX_NUMBER); // display what numbers can be entered, and how many guesses
        scanf("%d", &guess); // take user input, a number
        if (guess < MIN || guess > MAX)
        {
            printf("\nEnter a number within range. \n"); // move to next iteration if number is not in range
        }
        else if (guess == randomNum)
        {
            guessCount++; // update guess count
            printf("\nYou have guessed %d time(s) and your guess is correct", guessCount); // show how many guesses player has
            printf("\nType 1 to play another round. Otherwise the program will exit. \n");
            int num;
            scanf("%d", &num); // check input
            if (num == 1) // start another round if input is 1
            {
                printf("\nContinuing. New number generated. \n");
                randomNum = createRandomNumber(); // new number is randomly generated
                printf("Randomly generated number is %d", randomNum); 
                guessCount = 0; // reset guess count
            }
            else // exit if 1 is not entered
            {
                printf("Exiting...");
                cont = 1;
            }
        }
        else if (guess < randomNum) // if guess is lower than random number generated
        {
            printf("\nYour guess is TOO LOW \n");
            guessCount++; // increment guess count
        }
        else if (guess > randomNum) // if guess is higher than random number
        {
            printf("\nYour guess is TOO HIGH \n");
            guessCount++; // increment guesscount
        }

        if (guessCount == MAX_NUMBER) // if guess count equals the max amount of guesses then exit
        {
            printf("Too many failed guesses. Exiting...");
            cont = 1; // stop loop
        }
    }
}