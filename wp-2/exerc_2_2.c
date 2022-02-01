// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 2
// Submission code: xxxxxx

/**
 * Linked Lists
 **/

// ------ Includes   ----------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ------ Defines   ----------

#define MAX 5 // max length for random list

// ------ Structs   ----------

typedef struct Node
{
    int number;
    struct Node *next;
    struct Node *prev;
} Node;

// ------ Function declarations   ----------

Node *random_list(void); // This function generates a set of random numbers
Node *add_first(Node *temp, int data);
int get_random_number(void); // get a random number from 0 to 100

// ------ Main   --------------------------
// The main entry point for the program
int main(int argc, char *argv[])
{
    int nr = 0;

    Node *act_post, *head = NULL;

    srand(time(0)); //   Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    head = add_first(head, 101); // insert new node and set to new head
    act_post = head; // reset pointer to head
    nr = 0; // reset number

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

Node *random_list(void)
{
    // init variables for the loop
    int nr, i = 0;
    Node *head, *old, *item; 

    head = malloc(sizeof(Node)); // allocate memory
    old = malloc(sizeof(Node));  // allocate memory

    // create head
    head->number = get_random_number(); // assign number to head
    head->prev = NULL; // init prev pointer
    head->next = NULL; // init next pointer

    for (i = 0; i < MAX; i++) // since head is created, 5 more elements will created and added to listed list (wondering if I should change...)
    {
        item = malloc(sizeof(Node)); // allocate memory
        nr = get_random_number();    // get random number
        item->number = nr;           // assign number to item
        head = add_first(head, get_random_number()); // temporary solution
    }

    return head;
}

/** 
*  That adds a new record to the first position of the list and assign the field numbers the value of data.
*  The function must return a pointer to the new first entry in the list. 
*  Extend main() so that this function is tested.
**/

Node *add_first(Node *temp, int data)
{
    Node *new = malloc(sizeof(Node)); // allocate memory
    new->number = data;               // assign data to number field
    new->next = NULL;                 // init next pointer
    new->prev = NULL;                 // init prev pointer

    if (temp == NULL) // if temp is null
    {
        temp = new;  // assign the new node to temp
        return temp; // return temp
    }
    new->next = temp; // assign new node's next pointer to the current first element of the linked list
    temp->prev = new; // point the former first element previous pointer to newly created node
    return new;       // return the new node
}

int get_random_number(void)
{
    return rand() % 101; // return random number between 0 and 100
}