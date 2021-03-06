// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 1
// Exercise 2
// Submission code: 571006

/**
 * This program shifts a string inputted by a user by 13 or by the amount supplied in an argument.
 * Only works on a-z and A-Z characters
 **/

// ------ Includes   ----------

#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>

// ------ Defines   ----------

#define MAX_INPUT 26 // how many characters user is allowed to input
#define MIDDLE 13    // middle of alphabet

// start and end codes for alphabet upper and lower-case:
#define ASCII_A_LOW 97
#define ASCII_Z_LOW 122
#define ASCII_A 65
#define ASCII_Z 90

#define INPUT_MESSAGE "\nEnter a text: "
#define RESULT_MESSAGE "Encryption: "
#define INVALI_ARGUMENT "The shift size must be between 0 and 13. Please provide a valid shift size in the argument."

/**
 * Variables
 **/

int shift; // how much to shift input characters

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
      if ((*pRes >= ASCII_A_LOW && *pRes <= ASCII_Z_LOW) || (*pRes >= ASCII_A && *pRes <= ASCII_Z))
      {
         // if the character is in the last half of a-z and A-Z, shift it down(-)
         if (*pRes >= (ASCII_A_LOW + MIDDLE) || (*pRes >= (ASCII_A + MIDDLE) && *pRes <= ASCII_Z))
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

   //Check the shift magnitude. Since there are only 26 characters in the alphabet, the shift size cannot exceed 13 or
   //it will show characters other than alphabet
   if (shift > 13 || shift < 0)
   {
      //print out the relevant error message
      printf(INVALI_ARGUMENT);
      //exits with code 1
      return 1;
   }

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
         // allocate place to save reverse_char result
         char *result;
         result = malloc(MAX_INPUT);

         // "reverse" the users input, and save in result
         result = reverse_char_array(input, result);

         // print the result
         printf("%s%s", RESULT_MESSAGE, result);

         free(result); // free result
      }
      else
      {
         loop = 0; // set loop to 0
      }
   }

   return 0;
}
