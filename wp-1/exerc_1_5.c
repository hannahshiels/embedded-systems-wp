// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 5
// Submission code: 571006

/**
 * This program calculates statistical values for an array of integers
 * It plots a histogram for the frequency of different numbers in the array.
 **/

// ------ Includes   ----------

#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,
#include <time.h>   // time

// ------ Defines   ----------

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
#define LOWNUMBER 1  // Defines the minimum value of random numbers

#define X "x" // marker for displaying number frequency

// ------ Function declarations   ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

// ------ Function definitions   ----------

void create_random(int *tab)
{
   // loop for placing random numbers in array
   for (size_t i = 0; i < MAX; i++)
   {
      // generates a number between 1-100
      int randNum = (rand() % (MAXNUMBER - LOWNUMBER + 1) + LOWNUMBER);

      // set the current index in tab array to randNum
      tab[i] = randNum;
   }
}

void count_frequency(int *tab, int *freq)
{
   // for all numbers in the array,
   for (size_t i = 0; i < MAX; i++)
   {
      // Increase the count for the found number
      freq[tab[i] - 1]++;
   }
}

void draw_histogram(int *freq)
{
   // for MAXNUMBER, print the found randomized numbers and their frequencies
   for (size_t i = 0; i < MAXNUMBER; i++)
   {
      // do not show frequencies of number 0
      if (freq[i] != 0)
      {
         // print all numbers used in random number generation
         printf("\n%2d: ", (i + 1));

         // for the frequency amount of the current number,
         for (size_t j = 0; j < freq[i]; j++)
         {
            // print a symbol
            printf("%s", X);
         }
      }
   }
}

// ------ Main   --------------------------

// The main entry point for the program
int main(void)
{
   // declare variables
   int table[MAX], n;
   int frequency[MAXNUMBER];

   // loop for resetting frequency array; removing bad memory
   for (size_t i = 0; i < MAXNUMBER; i++)
      frequency[i] = 0; // set all integer values to 0

   srand(time(0)); // use the current time as seed for generating random numbers.

   // run throuh methods in order to finally display a histogram of found random numbers with their frequency
   create_random(table);
   count_frequency(table, frequency);
   draw_histogram(frequency);

   // Temporaty loop for checking if frequency is similar to what is in table
   for (size_t i = 0; i < MAX; i++)
   {
      printf(" ");
      printf("%d", table[i]);
   }
}