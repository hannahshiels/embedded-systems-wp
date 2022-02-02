// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package x
// Exercise x
// Submission code: xxxxxx

/**
 * This program ... Binary files
 * 
 * You should write a program to manage a database of persons. The database should be stored as a binary file 
(this is important – binary, not text file!). The structure of the program is easiest to understand by  reading the 
description and the program skeleton below. 
 * From the main program you should be able to choose between these options: 
 
1 Create a new and delete the old file. 
2 Add a new person to the file. 
3 Search for a person in the file. 
4 Print out all in the file. 
5 Exit the program. 
 
After entered the choice the program executes the task and returns to the menu for new choices. 
 
1. Create a new and delete the old file. 
   Program creates a new file with the specified filename (hardcoded, fixed) and writes a first dummy record to 
   the file and then close it.  
 
2. Add a new person to the file. 
   Gives an opportunity to put in one new person to a temp record and then add this record in 
   the end of the file. 
 
3. Search for a person in the file. 
   Gives you an opportunity to search for all persons with either a specified first name or  
   family name (by choice). The program prints out all persons with that name. 
 
4. Print out all in file. 
   Prints out the whole list  
 
5. Exit the program. 
   Just exits the program. 
 * You should make the program fail-safe, in particular: 
• Checking if the file exists 
• Checking if the list is empty 
 **/

// ------ Includes   ----------

#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,

#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,
#include <time.h>   // time

// ------ Defines   ----------

#define EXAMPLE = 911 // Example define

// ------ Variables etc   ----------

const char *MENU = "\nSelect an option from 1 -5. \n\n1. Create a new and delete the old file. \n2. Add a new person to the file. \n3. Search for a person in the file. \n4. Print out all in the file. \n5. Exit the program. ";
const char *fileName = "binaryFile.bin";

// ------ Structs   ----------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// ------ Function declarations   ----------

void start(PERSON *inrecord);

// Function declaration (to be extend)
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void);                  // Prints out all persons in the file
void search_by_firstname(char *name);  // Prints out the person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file

// ------ Main   --------------------------
int main(void)
{
    PERSON *ppost, person;
    ppost = &person;
    // only using these right now to add as dummy record when option 1 is entered
    scanf("%s", ppost->firstname);
    scanf("%s", ppost->famname);
    scanf("%s", ppost->pers_number);

    //  fgets(ppost->firstname, 20, stdin);
    //  fgets(ppost->famname, 20, stdin);
    //  fgets(ppost->pers_number, 13, stdin);

    start(ppost);
    return (0);
}

// ------ Function definitions   ----------

void start(PERSON *inrecord)
{
    int input = 0; // control loop
    do
    {
        printf("%s\n", MENU);
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            printf("%s", "option 1");
            write_new_file(inrecord);
            break;
        };
        case 2:
        {
            printf("%s", "option 2");
            PERSON person = input_record();
            PERSON *personP = &person;
            append_file(personP);
            break;
        };
        case 3:
        {
            printf("%s", "option 3");
            break;
        };
        case 4:
        {
            printf("%s", "option 4");
            printfile();
            break;
        };
        case 5:
        {
            printf("%s", "Exiting...");
            break;
        };
        default:
        {
            printf("%s", "\nEnter a valid number (1-5).\n ");
            break;
        };
        }
    } while (input != 5);
}

PERSON input_record(void) // Reads a person’s record.
{
    PERSON person;
    printf("%s", "\nEnter first name: ");
    scanf("%s", person.firstname);
    printf("%s", "\nEnter last name: ");
    scanf("%s", person.famname);
    printf("%s", "\nEnter personal number: ");
    scanf("%s", person.pers_number);
    return person;
}
void write_new_file(PERSON *inrecord) // Creates a file and writes the first record
{
    FILE *file = fopen(fileName, "wb");
    if (file != NULL)
    {
        fwrite(inrecord, sizeof(PERSON), 1, file);
    }
    else
    {
        printf("%s", "\n Something went wrong...");
    }

    fclose(file);
}

// TODO
void printfile(void) // Prints out all persons in the file
{
    FILE *file = fopen(fileName, "rb");
    if (file != NULL)
    {
    }
    else
    {
        printf("%s", "\n Something went wrong...");
    }
    printf("%s", "\n");
    fclose(file);
}

// TODO
void search_by_firstname(char *name) // Prints out the person if in list
{
}
void append_file(PERSON *inrecord) // appends a new person to the file
{
    FILE *file = fopen(fileName, "ab");
    if (file != NULL)
    {
        fwrite("\n", sizeof(char), 1, file);
        fwrite(inrecord, sizeof(PERSON), 1, file);
    }
    else
    {
        printf("%s", "\n Something went wrong...");
    }
    fclose(file);
}