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

// Includes
#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,
#include <time.h>

// Defines
#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
#define LOWNUMBER 1  // Defines the maximum value of random numbers

// Variables
const char *X = "x";

// ------ Function declarations   ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
int *create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

// ------ Function definitions   ----------

int *create_random(int *tab)
{
   for (size_t i = 0; i < MAX; i++)
   {
      int randNum = (rand() % (MAXNUMBER - LOWNUMBER + 1) + LOWNUMBER); // generates a number between 0-100
      tab[i] = randNum;                                                 // set the current index in tab array to randNum
   }

   return tab;
}

void count_frequency(int *tab, int *freq)
{
   int tempTable[MAX];
   for (size_t i = 0; i < MAX; i++)
   {
      tempTable[i] = tab[i];
   }

   // from 1-100
   for (size_t i = 0; i < MAX + 1; i++)
   {
      int tabI = tab[i];
      int count = 1; // set count for number frequency; since there will be a number in every index, always set to

      // Check tab array from 1-100
      for (size_t j = i + 1; j <= MAX; j++)
      {
         int tabJ = tab[j];

         if (tabI == tabJ && tempTable[i] != 0)
         {
            count++;

            tempTable[j] = 0;
         }
      }

      freq[i] = count;
   }
}

void draw_histogram(int *freq)
{

   for (size_t i = 0; i <= MAXNUMBER; i++)
   {
      if (freq[i] != 0)
      {
         printf("\n%d: ", i);
         for (size_t j = 0; j < freq[i]; j++)
         {
            printf("%s", X);
         }
      }
   }
}

// ------ Main   --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{
   int table[MAX], n;
   int frequency[MAXNUMBER];

   for (size_t i = 0; i < MAXNUMBER; i++)
      frequency[i] = -1; // reset frequency array

   srand(time(0)); // use the current time as seed for generating random numbers.

   create_random(table);
   count_frequency(table, frequency);
   draw_histogram(frequency);
}