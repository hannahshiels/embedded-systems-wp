// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package x
// Exercise x
// Submission code: xxxxxx

/**
 * This program is a control program for a robot
 * 
 * The program asks for the robot's starting position (x-y between 0-99),
 * and for a string of chars 'm' and 't'.
 * m = move one step in current direction (+ 1)
 * t = turn direction 90 degrees clockwise
 * 
 * start direction is north
 * 
 * user supplies strings one by one
 * when all instructions are executed, the robot stops and the program prints out the new position of the robot
 * the program then asks for a new starting position and the string of characters
 * 
 * The program repeats until the program encounters a dedicated end character;
 * 
 * 
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
enum DIRECTION
{
   N,
   O,
   S,
   W
};

// ------ Structs   ----------

typedef struct
{
   int xpos;
   int ypos;
   enum DIRECTION dir;
} ROBOT;

// ------ Function declarations   ----------

// This function
void move();

// This function
void turn();

// ------ Main   --------------------------
// The main entry point for the program
int main(void)
{
   // ...
}

// ------ Function definitions   ----------

void move()
{
   // ...
}

void turn()
{
   // ...
}