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
      int randNum = rand() % (MAX + 1); // generates a number between 0-100
      tab[i] = randNum;                 // set the current index in tab array to randNum
   }

   return tab;
}

void count_frequency(int *tab, int *freq)
{
   // int table[MAX];
   int freqSize = 0;

   for (size_t i = 0; i < MAX + 1; i++)
   {
      int currTab = tab[i];

      for (size_t j = 0; j <= freqSize; j++)
      {
         int currFreq = freq[j];

         if (currFreq == currTab)
         {
            freq[j]++;
         }
         else if (j == (freqSize - 1))
         {
            freq[freqSize] = tab[i];
            freqSize++;
         }
      }
   }
}

void draw_histogram(int *freq)
{
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
   srand(time(0)); // use the current time as seed for generating random numbers.

   create_random(table);
   count_frequency(table, frequency);
   draw_histogram(frequency);

   int i = 0;
   while (frequency[i] != NULL)
   {
      printf("%d\n", frequency[i]);
      i++;
   }

   for (size_t i = 0; i < MAX; i++)
   {
      printf("%d\n", table[i]);
   }
}