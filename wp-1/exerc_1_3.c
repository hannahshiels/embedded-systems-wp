// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 3
// Submission code: XXXXXX

/**
 * This program...
 * 
You  should  develop  a  very  simple  game  in  which  the  computer  creates  a  random  integer  number,  between 
1..100, and the user then tries to guess the number. The program should work as specified below: 
- The computer creates a random number 
- The user guesses the number  
- The computer responds by printing one of the following:  
• You have guessed AA times and your guess is correct (if the user guesses correctly)  
• Your guess is too low or too high, depending on the mistake of the user 
- If wrong the user is asked for a new guess, this will continue until the guess is right or the number of 
guesses exceeds the value MAX_NUMBER. 
- After end of one round the user is asked for a new round or to finish. 
The program should only except guessed numbers in the range of 1 ...100. // TODO 1 ...100
An option, but not a demand, is to secure that the program does not fail (crashes) if a user by accident inputs a 
number outside of the range or a character/string.
 **/

// Includes
#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,
#include <time.h>

// Defines
#define MAX 100        // Defines the maximum number of the values in the table
#define MAX_INPUT 26   // How many characters user is allowed to input
#define MAX_NUMBER 100 // TODO use this

// Variables
const char *INTRO_MESSAGE = "\nA random number between 0-100 has been generated";
const char *INPUT_MESSAGE = "\nGuess the number: ";
const char *LOW_GUESS = "\nYour guess is too low";
const char *HIGH_GUESS = "\nYour guess is too high";
const char *GUESS1 = "\nYou have guessed ", *GUESS2 = " times", *GUESS3 = "and your guess is correct";
const char *FINISH = "\nDo you want to go again or finish?: ";

int main(void)
{
   // Variables
   char input[MAX_INPUT];            // input for user;
   srand(time(0));                   // use the current time as seed for generating random numbers.
   int randNum = rand() % (MAX + 1); // generates a number between 0-100
   printf("%s", INTRO_MESSAGE);

   // Loop which...
   int loop = 1;
   while (loop)
   {
      // get user input
      printf("%s", &INPUT_MESSAGE);
      fgets(input, MAX_INPUT, stdin);

      //TODO add amount of times
      printf("%s%s", GUESS1, GUESS2);
      if (randNum == atoi(input))
      {
         printf("%s", GUESS3);
      }
      else if (randNum < atoi(input))
      {
         printf("%s", GUESS3);
      }
      else if (randNum > atoi(input))
      {
         printf("%s", GUESS3);
      }
   }

   return 0;
}