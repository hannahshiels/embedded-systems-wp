// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels
// Work package 1
// Exercise 4
// Submission code: XXXXXX

/**
 * This program...
 * 
You should write two programs, which convert between numbers in different format. You should make sure that 
these programs can be executed in a pipeline.  
The  programs  should  accept  any  number  between  0  and  the  maximum  value  of  type  long  in  C  for  your 
compiler. 
The program should use the smallest possible datatype for a given, number. For example, if the user inputs 12, 
the program should use treat this as 8 bits and format the output accordingly. If the user inputs 1200, then the 
program should format the output as 16 bits, etc.   
The first program must convert a number in a decimal format to a binary format.  
 dec2bin.exe 12 should result in 00001100 
The second program should convert binary to hexadecimal value. 
 bin2hec.exe 00001111 should result in 0F 
 
You should use the program arguments so that it is possible to use these two programs like this: 
 dec2bin.exe 12 | bin2hec.exe 
  
The programs should be fail-safe, i.e.  
• Should check if the string of the argument contains the correct digits 
• Should check be able to provide help if the user provides the parameter ‘-h’ 
• Should output an error message if the conversion was not successful 
• Should return 2 if the conversion is unsuccessful 
 **/

// Includes
#include <stdio.h>  // fgets,
#include <stdlib.h> // atoi,
#include <string.h> // strlen,
#include <ctype.h>  // toUpperCase,