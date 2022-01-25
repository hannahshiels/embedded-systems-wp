// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 2
// Submission code: XXXXXX

/**
 * This program shifts a string inputted by a user by 13 or by the amount supplied in an argument.
 * Only works on a-z and A-Z characters
 **/

// Includes
#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,

// Defines
#define MAX_INPUT 26 // How many characters user is allowed to input

// Variables
const char *INPUT_MESSAGE = "\nEnter a text: ";
char *RESULT_MESSAGE = "Encryption: ";
const int a = 97, z = 122, A = 65, Z = 90; // start and end codes for alphabet upper and lower-case
const int ctrlZ = 64;                      // Code for ctrl+z input
const int middle = 13;                     // middle of alphabet
int shift = 13;                            // how much to shift input characters

// Define Functions:
char *reverse_char_array(const char *input, char *result);

/**
 * main method, which runs until user inputs ctrl+z
 **/
int main(int argc, char *argv[])
{
   // Check arguments
   check_arguments(argv);

   // Loop which allows user to enter a string and encrypt it with ROT13
   while (1)
   {
      // Variables
      char input[MAX_INPUT]; // input for user;

      printf("%s", INPUT_MESSAGE);                // print pre-input message
      if (fgets(input, MAX_INPUT, stdin) == NULL) // get user input
      {
         return; // if fgets returns NULL (i.e; If user enters "ctrl-z"), return
      }

      char *result = malloc(MAX_INPUT);           // allocate place to save reverse_char result
      result = reverse_char_array(input, result); // "reverse" the users input, and save in result
      printf("%s%s", RESULT_MESSAGE, result);     // print the result

      free(result); // (?)
   }

   return 0;
}

/**
 * Functions
 **/

void check_arguments(char *argv[])
{
   // if argument [1] is supplied,
   if (argv[1] != NULL)
   {
      shift = atoi(argv[1]); // use argument to define amount to shift
   }
}

// This method returns a reversed character array
char *reverse_char_array(const char *input, char *result)
{
   strcpy(result, input); // copy input into result
   char *pRes = result;   // pointer for result

   // Loop through the characters in "result" until "\0"
   // Comparisons work based on character decimal codes
   while (*pRes != '\0')
   {
      if ((*pRes >= a && *pRes <= z) || (*pRes >= A && *pRes <= Z)) // if character is between a-z and A-Z
      {
         if (*pRes >= (a + middle) || (*pRes >= (A + middle) && *pRes <= Z)) // if the character is in the last half of a-z and A-Z, shift it down(-)
         {
            *pRes -= shift;
         }
         else // else, shift it up(+)
         {
            *pRes += shift;
         }
      }

      pRes++; // Move the pointer forward
   }

   return result;
}