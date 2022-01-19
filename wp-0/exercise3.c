// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 0
// Exercise 3
// Submission code: XXXXXX 
#include <stdio.h>
#include <string.h>
// Main function in the program, one program argument supported with errors handled

void main(int argc, char*argv[]) {
    // require exactly 1 argument
    if(argc == 2){
        // convert argument to string for comparison, if user enters -h a help message will be displayed
        if(strcmp(argv[1],"-h") == 0){
            printf("-h: You can should enter your name as an argument and an interesting message will be printed!");
        } else {
            // otherwise this message is printed, formatted
        printf("%s %s%s","Hello World! - I'm", argv[1], "!");
        }
    } else {
        // if wrong number of arguments is supplied an error message is shown
        printf("Error. Incorrect of arguments. Use argument -h for more details on how to use the program.");
    }
}