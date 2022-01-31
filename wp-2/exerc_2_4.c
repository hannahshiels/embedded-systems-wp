// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package x
// Exercise x
// Submission code: xxxxxx

/**
 * This program ...
 * 
 * Write two programs – one that pack bits into a byte and the other one which unpacks into a string instructions.  
You need to store 4 different values in a byte. The values are: 
 
Name         Range    Bits   Info    
engine_on    0..1     1     Is engine on or off . This is bit no 7  
(MSB == Most Significant Bit, the one that carries the value 128 in decimal) 
gear_pos      0..4     3      The position of the gear. Three bits means that we can have 23 == 7 positions    
key_pos       0..2     2       Position of the key – 0 == stop, 1 == on, 2 == engine starter on     
brake1         0..1     1        Position of the front brakes   
brake2         0..1     1        Position of the rear brakes. Bit no 0 (LSB) 
 
We should store them in a byte like this: 
[engine_on]    [gear_pos]  [key_pos] [brake1] [brake2]     
 1 bit         3 bits      2 bits     1 bit       1 bit      
 
The first program, code.c, takes 5 arguments (fewer or more than 5 arguments should be treated as an error).  
 
The arguments should correspond to the values/variables above. 
 
Example for a start of the program from command line:  
code   1 2 2 1 1           
 
The above should be treated as: 
Name            Value    
------------------------  
engine_on    1   Bit no 7 
gear_pos     2    
key_pos      2    
brake1      1    
brake2      1   Bit no 0 
 
The  program  should  pack  these  values  together  in  a  byte  (unsigned  char)  and  print  it  out  to  the  console  in 
hexadecimal form. For this example, it should be ‘AB’ corresponding to bits ‘10101011.  After printing out the 
code to the console, the program should exit. The program should be fail-safe, i.e. if it finds anything wrong (too 
many/few arguments, faulty input values) your program should print out an error message and exit. 
 
The second program, decode.c, takes 1 argument (one argument, hexadecimal number) and prints out the bit 
positions for the engine, gear, etc. In the example of ‘AB’  (again,  make  it  fail-safe).  The  argument  should 
correspond to the decoded byte, e.g. as printed by code.c.  If your program finds anything wrong (too many/few 
arguments, faulty input values) your program should  print  out an error message and exit. 
 
The program should unpack the bytes according to the specification above. Print out the result as below:  
Name         Value    
----------------------------- 
engine_on        
gear_pos         
key_pos          
brake1           
brake2       
 
 
For example, start program in the console window :   
decode AB    
 
and the result should be:  
Name         Value    
----------------------------- 
engine_on    1    
gear_pos     2    
key_pos      2    
brake1       1    
brake2      1 
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

int exampleInt = 0;

// ------ Structs   ----------

// ------ Function declarations   ----------

// This function generates a set of random numbers
void example_function();

// ------ Main   --------------------------
// The main entry point for the program
int main(void)
{
   // ...
}

// ------ Function definitions   ----------

void example_function()
{
   // ...
}
