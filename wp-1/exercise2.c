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

void encryptMe(char i);

/**
 * Define Section
 */
#define Shift 13   //shift amount for each letter in ASCII code to be encoded
#define Max_Capacity 1024   //The maximum number of characters allowable to be entered by the user
#define CTRL_Z 26
/**
 * Main body
 */

int main(void)
{
    //variable declaration
    int i;   //will be used in the for loop as the index number
    const char *prompt = "Enter the word you want to encode:\n";
    char input[Max_Capacity];


    //Code body
    //keep asking the user for their input
    //TODO EOF ctrlZ is not there yet!
   // while (input[0] != 26)
    {
        //ASk user to enter their word
        printf("\n%s", prompt);

        //Get the user input
        scanf("%s", input);

        //Iterate over the word received in the argument and switch the characters with encoded ones
        for(i = 0; i < strlen(input); i++)
        {
            //Switch each character with the encoded char
            encryptMe(input[i]);

        }
    }

    return 0;
}

/**
 * Auxiliary Methods
 */
//Switches the chars with their equivalent encrypted chars
void encryptMe(char mainLetter)
{
    if ((mainLetter < 78 && mainLetter > 64) || (mainLetter < 110 && mainLetter > 96))
    {
        mainLetter = mainLetter + Shift;
    } else if ((mainLetter > 77 && mainLetter < 91) || (mainLetter > 109 && mainLetter < 123))
    {
        mainLetter = mainLetter - Shift;
    }

    printf("%c", mainLetter);
}




