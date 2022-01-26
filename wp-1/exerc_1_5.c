// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 5
// Submission code: XXXXXX

/**
 * This program calculates statistical values for an array of integers
 * It plots a histogram for the frequency of different numbers in the array.
 * 
 * 1. create an array of integers (table [MAX]), where MAX is the number of random numbers between 0 and MAXNUMBER
 * 2. frequency[] array
 * 3. ...
 **/

// ------ Includes   ----------

#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,
#include <time.h>

// ------ Defines   ----------

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
#define LOWNUMBER 1  // Defines the maximum value of random numbers

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
   int tempTable[MAX]; // for storing which numbers have been found

   // loop for generating the temporary array
   for (size_t i = 0; i < MAX; i++)
   {
      tempTable[i] = -1; // initialize array to -1 to remove garbage
   }

   // from 1-100, loop through and check for duplicate numbers
   for (size_t i = 0; i < MAX; i++)
   {
      int tabI = tab[i]; // store the active number
      int count = 1;     // set count for number frequency; Initialize as 1 since we assume to always find a number in every index

      // Check tab array from 1-100
      for (size_t j = i + 1; j <= MAX; j++)
      {
         int tabJ = tab[j]; // store the active number

         // if duplicate is found && the number hasn't been set as 0 through a previous loop iteration
         if (tabI == tabJ && tempTable[i] != 0)
         {
            // increase the count if a duplicate has been found
            count++;

            // Set noticed number to 0, to keep track of which numbers have already been seen
            tempTable[j] = 0;
         }
      }

      // if the number has not already been seen and counted,
      if (tempTable[i] != 0)
      {
         // store the count in freq array
         freq[tabI] = count;
      }
   }
}

void draw_histogram(int *freq)
{
   // for MAXNUMBER, print the found randomized numbers and their frequencies
   for (size_t i = 1; i <= MAXNUMBER; i++)
   {
      // do not show frequencies of number 0
      if (freq[i] != 0)
      {
         // print all numbers used in random number generation
         printf("\n%d: ", i);

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
      frequency[i] = -1; // set all integer values to -1

   srand(time(0)); // use the current time as seed for generating random numbers.

   // run throuh methods in order to finally display a histogram of found random numbers with their frequency
   create_random(table);
   count_frequency(table, frequency);
   draw_histogram(frequency);
}