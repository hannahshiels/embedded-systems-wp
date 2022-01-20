// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 2: Encryption
// Submission code: XXXXXX

/*
    Create  a  very  simple  encryption  program.  The  program  “shifts  characters” in  the  ASCII-code  table  of  a  given 
    input string.  
    In the example below, A has shifted 13 characters in the ASCII table to N, B to O, etc. The word HELLO becomes 
    URYYB after encryption. 
    The  user  enters  a  text  and  the  program 
    prints out the encrypted text. Let the 
    program  read  character  by  character,  and 
    encrypt it as above. The program is repeated 
    until  EOF  indicated  the  program  ends.  EOF 
    means End Of File and is a special character, 
    e.g. when the user enters Ctrl +Z for 
    Windows and Ctrl + d for Linux system. 
    The number of characters to shift should be 
    provided as a program argument, e.g. 
    my_program.exe 13 
    Example of a test run: 
 
    HELLO (+enter) 
    URYYB 
    Banana (+enter) 
    Onanan 
    ( +Ctrl-z) 
 
    (Program ends)
*/

#include <stdio.h>

void main(int argc, char* argv[]){
    int cont = 0;
    int shiftBy = argv[1];
    while(cont == 0){
        printf("\nEnter word to encrypt: ");
        char wordToEncrypt[] = "";
        scanf("%s", wordToEncrypt);
        printf("\n%s", wordToEncrypt);
    }
}