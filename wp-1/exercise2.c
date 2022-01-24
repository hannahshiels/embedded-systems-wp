// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels, group: 06 __ (2022)
// Work package 1
// Exercise 2
// Submission code: XXXXXX


//Create  a  very  simple  encryption  program.  The  program  “shifts  characters” in  the  ASCII-code  table  of  a
//given input string. In the example below, A has shifted 13 characters in the ASCII table to N, B to O, etc. The word
//HELLO becomes URYYB after encryption. The  user  enters  a  text  and  the  program prints out the encrypted text.
//Let the program  read  character  by  character,  and encrypt it as above. The program is repeated until  EOF
//indicated  the  program  ends. EOF means End Of File and is a special character, e.g. when the user enters Ctrl +Z
//for Windows and Ctrl + d for Linux system. The number of characters to shift should be provided as a program argument.



/**
 * Include Section
 */

#include <stdio.h>
#include <string.h>

void encryptMe(char* i);

/**
 * Main body
 */

void main(int argc,char*argv[])
{
    //variable declaration
    int i;   //will be used in the for loop as the index number

    //Code body

    //Iterate over the word received in the argument and switch the characters with encoded ones
    for(i = 0; i < strlen(argv[1]); i++)
    {
        //Switch each character with the encoded char
        encryptMe(&argv[1][i]);

    }
    //printf("%s", argv[1]);
}

/**
 * Auxiliary Methods
 */
//Switches the chars with their equivalent encrypted chars
void encryptMe(char* mainLetter) {
    //Variable declaration
    char firstRowLower[13] = "abcdefghijklm";
    char secondRowLower[13] = "nopqrstuvwxyz";
    int i;

    //printf("%c", mainLetter);
    for(i = 0; i < strlen(firstRowLower); i++)
    {
        //printf("%c", firstRowLower[i]);
        if(&mainLetter == firstRowLower[i])
        {
            *mainLetter = secondRowLower[i];
        }
    }

    for(i = 0; i < strlen(secondRowLower); i++)
    {
        //printf("%c", secondRowLower[i]);
        if(*mainLetter == secondRowLower[i])
        {
            *mainLetter = firstRowLower[i];
        }
    }

    printf("%c", *mainLetter);

}




