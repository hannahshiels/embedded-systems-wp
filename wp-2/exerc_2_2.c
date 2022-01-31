// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package x
// Exercise x
// Submission code: xxxxxx

/**
 * This program ... Linked List
 * 
 * a) Write a function that creates a linked list with a NUMBER of records of type REGTYPE (see below). 
The value of the variable data is given a random number between 0 and 100. 
 
         Function declaration :  REGTYPE * random_list (void); 
 
Test the function from the main() program.  
 
b) Extend the program with a function with the function declaration:  
 
         REGTYPE * add_first (REGTYPE * temp, int data); 
 
That adds a new record to the first position of the list and assign the field numbers the value of data. 
The function must return a pointer to the new first entry in the list. Extend main() so that this 
function is tested. 
 **/

// ------ Includes   ----------

#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <time.h>   // time

#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,

// ------ Defines   ----------

#define MAX 5

// ------ Variables etc   ----------

int exampleInt = 0;

// ------ Structs   ----------

typedef struct q
{
   int number;
   struct q *next;
   struct q *prev;
} REGTYPE;

// ------ Function declarations   ----------

// This function
REGTYPE *random_list(void);

// This function
REGTYPE *add_first(REGTYPE *temp, int data);

// ------ Main   --------------------------

int main(int argc, char *argv[])
{
   int nr = 0;

   REGTYPE *act_post, *head = NULL;

   srand(time(0)); //   Random seed
   head = random_list();
   act_post = head;
   while (act_post != NULL)
   {
      printf("\n Post nr %d : %d", nr++, act_post->number);
      act_post = act_post->next;
   }

   // --- Free the allocated memory  ---

   while ((act_post = head) != NULL)
   {
      head = act_post->next;
      free(act_post);
   }

   return 0;
}

// ------ Function definitions   ----------

REGTYPE *random_list(void)
{
   int nr, i = 0;
   REGTYPE *top, *old, *item;

   return (top);
}

REGTYPE *add_first(REGTYPE *temp, int data)
{
}