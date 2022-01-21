// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 1
// Submission code: XXXXXX

/**
 * This program reads in an integer number between 1 and 5 from the keyboard,
 * and prints out one of existing five sentences on the console depending on what number was entered.
 * 
 * The program continues to ask for a new number and exits if number isn't in the interval 1 to 5.
 **/

// Includes
#include <stdio.h>

// Declare Functions
int is_number(char *val);
int is_num_between(int i, int start, int end);

// Main function in the program, one program argument supported with errors handled
void main(void)
{
   // printf messages
   const char *INPUT_MESSAGE = "\nPlease enter a value between 1-5: ";
   const char *END_MESSAGE = "\nThe program is shutting down...";

   // Define an array with messages
   const char *array[] = {
       "Hehehe!",
       "HAHAHA!",
       "MWAHAHAHA!",
       "MYAHAHAHAHAHAHA!!",
       "FNGHAHAHAHAHAHAHAHAHAHAHAAHAFHS!!!!!!"};

   char input[10];       // A char array for storing user input
   int inputAsInt;       // For storing converted input
   int isNumber = 1;     // boolean for storing if "inputAsInt" is a number
   int isNumBetween = 1; // boolean for storing if "inputAsInt" is between a given range

   // Run the while loop while the input is a number and while it is between a given range
   while (isNumber && isNumBetween)
   {
      printf("%s", INPUT_MESSAGE); // Print input message
      scanf("%s", &input);         // Ask to enter a value.

      int inputAsInt = atoi(input);                    // Convert input to integer
      isNumber = is_number(input);                     // Store boolean
      isNumBetween = is_num_between(inputAsInt, 1, 5); // Store boolean
      if (isNumber == 1)                               // Check if input is number
      {
         if (isNumBetween == 1) // Check if input is between a given range
         {
            int index = inputAsInt - 1;
            printf("%s", array[index]); // Print the related char array based on inputed number
         }
      }

      // free(input); // free input from memory
   }

   printf("%s", END_MESSAGE); // Print end-of-program message
}

/**
 * This function checks if a value(val) is a number
 * RETURN 1(true) if val is a number, else false
 **/
int is_number(char *val)
{
   int isDigit = 0; // boolean

   for (int i = 0; i < strlen(val); i++) // Check provided val
   {
      isDigit = isdigit(val[i]); // Check if current index is a number

      if (isDigit == 0)
         return 0; // return 0 if detecting non-integer value
   }

   return 1; // else, return 1
}

/**
 * This function checks if an integer is between a certain range(start, end)
 * RETURN 1(true) if i is between range, else false
 **/
int is_num_between(int i, int start, int end)
{
   if (i >= start && i <= end) // check if i is withing start, end
      return 1;                // return true if i is within range

   return 0; // else, return 0
}