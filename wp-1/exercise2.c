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
const char *RESULT_MESSAGE = "Encryption: ";
const int a = 97, z = 122, A = 65, Z = 90; // start and end codes for alphabet upper and lower-case
const int ctrlZ = 64;                      // Code for ctrl+z input
const int middle = 13;                     // middle of alphabet
int shift = 13;                            // how much to shift input characters

/**
 * Functions
 **/
// This method returns a reversed character array
char *reverse_char_array(const char *input)
{
   char *result = malloc(MAX_INPUT); // store the result of this function

   strcpy(result, input); // copy input into result
   char *curr = result;   // for storing what the pointer is looking at(?)

   // Loop through the characters in "curr" until "\0"
   while (*curr != '\0')
   {
      // if character is between a-z and A-Z
      if ((*curr >= a && *curr <= z) || (*curr >= A && *curr <= Z))
      {
         // if the character is in the last half of a-z and A-Z, shift it down(-)
         if (*curr >= (a + middle) || (*curr >= (A + middle) && *curr <= Z))
         {
            *curr -= shift;
         }
         else // else, shift it up(+)
         {
            *curr += shift;
         }
      }

      curr++; // Move the pointer through the char array
   }

   return result;
}

/**
 * main method, which runs until user inputs ctrl+z
 **/
int main(int argc, char *argv[])
{

   // if an argument is supplied,
   // TODO: Error handling
   if (argv[1] != NULL)
   {
      shift = atoi(argv[1]); // use argument to define amount to shift
   }

   // TODO: Loop which allows user to enter a string and encrypt it with ROT13
   while (1)
   {
      // Variables
      char input[MAX_INPUT];            // input for user;
      char *result = malloc(MAX_INPUT); // allocate place to save reverse_char result

      printf("%s", INPUT_MESSAGE);    // print pre-input message
      fgets(input, MAX_INPUT, stdin); // get user input

      char *pInput = input;                   // make pointer to input
      if (pInput == '\0' || *pInput == ctrlZ) // if user enters ctrl + z on Win
         return 0;                            // end the program

      result = reverse_char_array(input);     // "reverse" the users input, and save in result
      printf("%s%s", RESULT_MESSAGE, result); // print the result
   }
}