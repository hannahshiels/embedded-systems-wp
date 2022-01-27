// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 2
// Submission code: XXXXXX

/**
 * This program shifts a string inputted by a user by 13 or by the amount supplied in an argument.
 * Only works on a-z and A-Z characters
 **/

// ------ Includes   ----------

#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,

// ------ Defines   ----------

#define MAX_INPUT 26 // How many characters user is allowed to input
#define MIDDLE 13    // middle of alphabet
// start and end codes for alphabet upper and lower-case
#define a 97
#define z 122
#define A 65
#define Z 90

#define INPUT_MESSAGE "\nEnter a text: "
#define RESULT_MESSAGE "Encryption: "

/**
 * Variables
 **/

int shift = 13; // how much to shift input characters

/**
 * Function declarations
 **/

// This method returns a reversed character array
char *reverse_char_array(const char *input, char *result);

// for checking arguments
void check_arguments(char *argv[]);

/**
 * Function definitions
 **/

void check_arguments(char *argv[])
{
   // if argument [1] is supplied,
   if (argv[1] != NULL)
   {
      shift = atoi(argv[1]); // use argument to define amount to shift
   }
}

char *reverse_char_array(const char *input, char *result)
{
   strcpy(result, input); // copy input into result
   char *pRes = result;   // pointer for result

   // Loop through the characters in "result" until "\0"
   // Comparisons work based on character decimal codes
   while (*pRes != '\0')
   {
      // if character is between a-z and A-Z
      if ((*pRes >= a && *pRes <= z) || (*pRes >= A && *pRes <= Z))
      {
         // if the character is in the last half of a-z and A-Z, shift it down(-)
         if (*pRes >= (a + MIDDLE) || (*pRes >= (A + MIDDLE) && *pRes <= Z))
         {
            *pRes -= shift; // Shift the character down
         }
         // else, shift it up(+)
         else
         {
            *pRes += shift; // Shift the character up
         }
      }

      pRes++; // Move the pointer forward
   }

   return result;
}

/**
 * main method, which runs until user inputs ctrl+z
 **/
int main(int argc, char *argv[])
{
   // variables
   int loop = 1;

   // Check arguments
   check_arguments(argv);

   // Loop which allows user to enter a string and encrypt it with ROT13
   while (loop)
   {
      // Variables
      char input[MAX_INPUT]; // input for user;

      // Get user input
      printf("%s", INPUT_MESSAGE);

      // if fgets returns NULL (i.e; If user enters "ctrl-z")
      if (fgets(input, MAX_INPUT, stdin) != NULL)
      {
         char *result = malloc(MAX_INPUT);           // allocate place to save reverse_char result
         result = reverse_char_array(input, result); // "reverse" the users input, and save in result
         printf("%s%s", RESULT_MESSAGE, result);     // print the result
         free(result);                               // free result from memory
      }
      else
      {
         loop = 0; // set loop to 0
      }
   }

   return 0;
}
