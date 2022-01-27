// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 3
// Submission code: XXXXXX

/**
 * This program creates  a  random  integer  number,  between 1..100,
 * and the user then tries to guess the number.
 *
 * The program works as specified below:
 * - The computer creates a random number
 * - The user guesses the number
 * - The computer responds by printing one of the following:
 *    • You have guessed AA times and your guess is correct (if the user guesses correctly)
 *    • Your guess is too low or too high, depending on the mistake of the user
 * - If wrong the user is asked for a new guess, this will continue until the guess is right,
 *   or the number of guesses exceeds the value MAX_NUMBER.
 * - After end of one round the user is asked for a new round or to finish.
 * - The program only accepts guessed numbers in the range of 1 ...100. //
 * - The program does not fail (crashes) if a user by accident inputs a number outside of the range,
 *   or a character/string.
 **/

// ------ Includes   ----------
#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,
#include <time.h>

// ------ Defines   ----------
#define MAX 100        // Defines the max number
#define LOW 1          // Defines the lowest number
#define MAX_INPUT 4    // How many characters user is allowed to input; is not set to 3 since
#define MAX_NUMBER 3 // Max number of guesses

/**
 * Variables
 **/
const char *INTRO_MESSAGE = "\nA random number between 1-100 has been generated";
const char *INPUT_MESSAGE = "\nGuess the number: ";
const char *LOW_GUESS = "\nYour guess is too low";
const char *HIGH_GUESS = "\nYour guess is too high";
const char *GUESS1 = "\nYou have guessed ", *GUESS2 = " times", *GUESS3 = ", and your guess is correct!";
const char *FINISH = "\nDo you want to go again(input anything) or finish(input ctrl-z)?: ";
const char *FINISH2 = "\nYou ran out of guesses";
const char *BETWEEN = "\nPlease input a number between 1-100";

// ------ Function declarations   ----------

// This function generates a random number,
// and returns it
int generate_random_number();

// This function asks user to exit program or start again.
// Changes loop to 0 if exit
void exit_continue(char *input, int *loop);

// ------ Function definitions   ----------

int generate_random_number()
{
    // generate a new number between 0-100
    int number = (rand() % (MAX - LOW + 1) + LOW);

    return number;
}

void exit_continue(char *input, int *loop)
{
    // if fgets returns NULL (i.e; If user enters "ctrl-z")
    if (fgets(input, MAX_INPUT, stdin) == NULL)
    {
        // set loop to false/0
        loop = 0;
    }
}

// ------ Main   --------------------------
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
/**
 * Main method which initializes randomization seed and other variables,
 * and which contains the main program loop
 **/
int main(void)
{
    // Variables
    char input[MAX_INPUT]; // input for user
    int guesses = 0;
    int randNum;
    int loop = 1;

    srand(time(0)); // use the current time as seed for generating random numbers.

    randNum = generate_random_number(randNum); // generate random number

    printf("%s", INTRO_MESSAGE); // print intro message

    while (loop) // loop which keeps going until user enters "ctrl-z"
    {

        printf("%s", INPUT_MESSAGE);    // print input message
        fgets(input, MAX_INPUT, stdin); // get user input

        // get input as int
        // stops characters from passing as input; will transform ex: 12hello -> 12; ex hello12 -> 0
        int inputAsInt = atoi(input);

        guesses++; // user guessed -> increase guesses

        printf("%s%d%s", GUESS1, guesses, GUESS2); // print amount of guesses

        // Display wrong input responses
        if (inputAsInt > MAX || inputAsInt < LOW) // input is larger than 100 or lesser than 1
        {
            printf("%s", BETWEEN); // print answer was not between range
        }
        else if (randNum < atoi(input)) // user guessed too high
        {
            printf("%s", HIGH_GUESS); // print too high guess
        }
        else if (randNum > atoi(input)) // user guessed too low
        {
            printf("%s", LOW_GUESS); // print too low guess
        }

        // Handle loop-ending triggers with responses
        if (randNum == inputAsInt || guesses >= MAX_NUMBER) // if user guessed correctly || if user ran out of guesses
        {
            if (randNum == inputAsInt)         // if user guessed correctly
                printf("%s%s", GUESS3, FINISH); // print success

            if (guesses >= MAX_NUMBER)        // if user ran out of guesses
                printf("%s", FINISH2, FINISH); // print ran out of guesses

            exit_continue(input, loop); // ask if exit or continue

            randNum = generate_random_number(randNum); // generate a new random number

            guesses = 0; // reset guesses
        }
    }

    return 0; // exit
}
#pragma clang diagnostic pop
