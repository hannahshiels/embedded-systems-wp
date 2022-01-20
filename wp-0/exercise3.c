// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels, group: 06 __ (2022)
// Work package 0
// Exercise 3
// Submission code: XXXXXX
#include <stdio.h>
#include <string.h>
// Main function in the program, one program argument supported with errors handled

void main(int argc, char *argv[])
{
    //Variable declaration
    const char *helpMsg = "-h: You should enter your name as an argument and an interesting message will be printed!";
    const char *greeting = "Hello World! - I'm";
    const char *punctuation = " !";
    const char *errorMsg = "Error. Incorrect of arguments. Use argument -h for more details on how to use the program.";


    // require exactly 1 argument
    if (argc == 2)
    {
        // convert argument to string for comparison, if user enters -h a help message will be displayed
        if (strcmp(argv[1], "-h") == 0)
        {
            //The help message will be printed
            printf(helpMsg);
        }
        else
        {
            // otherwise this message is printed, formatted
            printf("%s %s%s", greeting, argv[1], punctuation);
        }
    }
    else
    {
        // if wrong number of arguments is supplied an error message is shown
        printf(errorMsg);
    }
}