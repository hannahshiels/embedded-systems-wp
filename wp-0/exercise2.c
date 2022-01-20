// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels, group: 06 __ (2022)
// Work package 0
// Exercise 2
// Submission code: XXXXXX 
#include <stdio.h>

// Main function in the program, one program argument supported
// Print message and program argument
void main(int argc,char*argv[]) {

    //Variable declaration
    const char *greeting = "Hello World! - I'm";
    const char *punctuation = " !";


    // Format and print a string 
    printf("%s %s%s", greeting, argv[1], punctuation); 
}