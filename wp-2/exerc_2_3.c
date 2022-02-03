// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 3
// Submission code: xxxxxx

/**
 * This program ... Binary files
 * 
**/

// ------ Includes   ----------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------ Variables etc   ----------

const char *MENU = "\nSelect an option from 1 - 5. \n\n1. Create a new and delete the old file. \n2. Add a new person to the file. \n3. Search for a person in the file. \n4. Print out all in the file. \n5. Exit the program. ";
const char *fileName = "binaryFile.bin";

// ------ Structs   ----------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// ------ Function declarations   ----------

void start(void);

// Function declaration (to be extend)
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void);                  // Prints out all persons in the file
void search_by_firstname(char *name);  // Prints out the person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file
int check_file_exists(void);           // check if file exists, return 0 or 1

// ------ Main   --------------------------
int main(void)
{
    start();    // start main program
    return (0); // if everything works, return 0
}

// ------ Function definitions   ----------

void start(void)
{
    int input = 0; // use to store user input
    do             // keep showing menu
    {
        printf("%s\n", MENU); // display menu options
        scanf("%d", &input);  // take user input
        switch (input)        // check for different values of input
        {
        case 1:
        {
            PERSON ppost, *person;
            ppost = (PERSON){.firstname = "Dummy", .famname = "Record", .pers_number = "200010027654"}; // create dummy record
            person = &ppost;                                                                            // pointer to the address of ppost
            write_new_file(person);                                                                     // call method to write to a new file
            printf("%s", "\nCreated new file with dummy data!");                                        // display file created message
            break;
        };
        case 2:
        {
            int fileExists = check_file_exists(); // check before user inputs that file first exists
            if (fileExists == 0)                  // if file exists
            {
                PERSON person = input_record(); // get a person from user input
                PERSON *personP = &person;      // pointer to the address of ppost
                append_file(personP);           // call append file method
            }
            else
            {
                printf("File doesn't exist. Create a file first to append to the document"); // show err message
            }

            break;
        };
        case 3:
        {
            char str[] = "";                             // init str
            printf("%s", "\nEnter first or last name to search by: "); // display ask user for name to search message
            scanf("%s", &str);                           // take string input
            search_by_firstname(str);                    // call search by name method with user inputted string
            break;
        };
        case 4:
        {
            printf("%s", "\nPrinting list..."); // display printing list message
            printfile();                        // call print file method
            break;
        };
        case 5:
        {
            printf("%s", "\nExiting..."); // display exit message
            break;
        };
        default:
        {
            printf("%s", "\nEnter a valid number (1-5).\n "); // if other number than 1 - 5, this error message is displayed
            break;
        };
        }
    } while (input != 5); // keep loop going unless 5 is entered
}

PERSON input_record(void) // Reads a person’s record.
{
    PERSON person; // init person

    printf("%s", "\nEnter first name: "); // ask for first name message
    scanf("%s", person.firstname);        // take string input and assign first name to person

    printf("%s", "\nEnter last name: "); // ask for last name message
    scanf("%s", person.famname);         //  take string input and assign last name to person

    printf("%s", "\nEnter personal number: "); // ask for personal number message
    scanf("%s", person.pers_number);           // take string input and assign personal number

    return person; // return newly created person
}

void write_new_file(PERSON *inrecord) // Creates a file and writes the first record
{
    FILE *file = fopen(fileName, "wb"); // open write connection to binary file
    if (file != NULL)                   // if file exists
    {
        fwrite(inrecord, sizeof(PERSON) - 1, 1, file); // write record to file, ensuring garbage values aren't added
        fwrite("\n", sizeof(char), 1, file);           // add new line after record to file
    }
    else // otherwise
    {
        printf("%s", "\n Something went wrong..."); // print error message
    }
    fclose(file); // close connection to file
}

void printfile(void) // Prints out all persons in the file
{
    FILE *file = fopen(fileName, "rb"); // open read connection to binary file
    if (file != NULL)                   // if file exists
    {
        PERSON person; // init empty person
        int nr = 0;    // use to count how many records
        while (fread(&person, sizeof(PERSON), 1, file))
        {
            printf("%s", "\n------------------------------------------------------");                            // print line to format a bit
            printf("\nName: %s %s | Personal Number: %s", person.firstname, person.famname, person.pers_number); // print record
            nr++;                                                                                                // increment number of records
        }
        if (nr == 0) // if no records
        {
            printf("%s", "List is empty!"); // display list is empty message
        }
    }
    else // otherwise
    {
        printf("%s", "\nSomething went wrong..."); // if file doesn't exist, display error message
    }
    fclose(file); // close connection to file
}

void search_by_firstname(char *name) // Prints out the person if in list, can take either first name or last name
{
    FILE *file = fopen(fileName, "rb"); // open read connection to binary file
    int nr = 0;                         // counter for number of matching records found
    int recordNr = 0;                   // counter for number of records
    if (file != NULL)                   // if file exists
    {
        PERSON person;                                  // init empty person
        while (fread(&person, sizeof(PERSON), 1, file)) // read file
        {
            if (strcmp(person.firstname, name) == 0) // compare current person first name to user inputted name
            {
                printf("\nName: %s %s | Personal Number: %s", person.firstname, person.famname, person.pers_number); // print record
                nr++;                                                                                                // increment nr
            }
            if (strcmp(person.famname, name) == 0) // compare current person last name to user inputted name
            {
                printf("\nName: %s %s | Personal Number: %s", person.firstname, person.famname, person.pers_number); // print record
                nr++;                                                                                                // increment nr
            }
            recordNr++; // increment number of records
        }
        if (recordNr == 0) // if no records
        {
            printf("%s", "\nList is empty! Nothing to search"); // print list is empty message
        }
        else if (nr == 0) // if nr of matching records  is 0
        {
            printf("%s", "\nNo matches found!"); // display no matches found message
        }
    }
    else // otherwise
    {
        printf("%s", "Something went wrong."); // if file is null then show err message
    }
    fclose(file); // close connection to file
}

void append_file(PERSON *inrecord) // appends a new person to the file
{
    FILE *file = fopen(fileName, "ab"); // open connection to binary file, to append records to
    if (file != NULL)                   // if file exists
    {
        fwrite(inrecord, sizeof(PERSON) - 1, 1, file); // write record, ensuring no garbage characters
        fwrite("\n", 1, 1, file);                      // insert new line to file
    }
    else // otherwise
    {
        printf("%s", "\nSomething went wrong..."); // if file doesn't exist show error message
    }
    fclose(file); // close connection to file
}

int check_file_exists(void)
{
    FILE *file = fopen(fileName, "rb"); // open read connection to file
    if (file == NULL)                   // if file doesn't exist
    {
        fclose(file); // close connection to file
        return 1;     // return 1 if file doesn't exist
    }
    fclose(file); // close connection to file
    return 0;     // return 0 if file exists
}