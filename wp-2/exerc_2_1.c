// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 1
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

// ------ Defines   ----------

#define MAX_INPUT_POS_VAL 99     // max value for x,y
#define MIN_INPUT_POS_VAL 0      // min value for x,y
#define MAX_INPUT_POS 6          // max input for x,y; '99 99' + end char
#define MAX_INPUT_DIR 100        // max input for 'm' and 't'
#define INPUT_MESSAGE_1 "\nInput the Robots starting position(x y between 0-99): " // Input message 1
#define INPUT_MESSAGE_2 "\nInput a sequence of 'm' and 't' (Ex 'mmmt'): "          // Input message 3
#define ERROR_MESSAGE "\nYour input was not correct. Input -h for help"            // Input message 2
#define HELP_MESSAGE "\nPosition: For the position you have to input two numbers between 0-99, seperated by a space" // Input message 4
#define FINISH_MESSAGE "\nThe Robots new location is: "                // Input message 5

// ------ Variables etc   ----------

// defines possible directions
enum DIRECTION {
   N,
   E,
   S,
   W
};

// ------ Structs   ----------

// This struct defines a robot
typedef struct {
   int xpos;
   int ypos;
   enum DIRECTION dir;
} ROBOT;

// ------ Function declarations   ----------

// This function moves the robot between 0-99 by changing its x and y values
void move(ROBOT *robot);

// This function turns the robot 90 degrees
void turn(ROBOT *robot);

// This function prints input message, and gets user input
void getInput(char *inputMessage, char *input, int maxInput);

// This function enables printf in Clion while debugging
// https://stackoverflow.com/questions/47776094/clion-wont-show-output-in-debug
void enablePrintf();

// ------ Main   --------------------------
// The main entry point for the program
// TODO: Refactor, Error handling
int main(int argc, char *argv[]) {
   char dirInput[MAX_INPUT_DIR];       // input for direction
   char startPosInput[MAX_INPUT_POS];  // input for starting position
   int correctPosInput = 0;            // boolean for correct/false input
   ROBOT robot;                        // Create a robot

   enablePrintf(); // enable console logs when debugging

   // main loop runs while no EOF
   while (!feof(stdin)) {

      // runs while user inputs wrong input for starting position
      while (!correctPosInput) {
         int loop = 0; // set loop to 0

         // Get input for start pos
         getInput(INPUT_MESSAGE_1, startPosInput, MAX_INPUT_POS);

         // get the first string from input
         char *splitString = strtok(startPosInput, " ");

         // loop through the string to extract all other strings
         while (splitString != NULL) {
            char *pEnd;    // ...
            int stringAsInt = strtol(splitString, &pEnd, 10);

            // set first string to x pos, then set y, only if value is between 0-99
            if (loop == 0 && stringAsInt >= MIN_INPUT_POS_VAL && stringAsInt <= MAX_INPUT_POS_VAL) {
               // convert input to int and store in x
               robot.xpos = stringAsInt;
            } else if (stringAsInt >= MIN_INPUT_POS_VAL && stringAsInt <= MAX_INPUT_POS_VAL) {
               // convert input to int and store in y
               robot.ypos = stringAsInt;
            }

            // grab the next string and set to splitString
            splitString = strtok(NULL, " ");

            // increase loop counter
            loop++;
         }

         char const *help = "-h\n"; // help string
         // if the user has supplied two strings seperated by a space; assumes they are
         if (loop == 2) {
            correctPosInput = 1;       // user has correct amount of input
            // if the user input is '-h' and user seeks help, print help message
         } else if (strcmp(startPosInput, help) == 0) {
            printf("%s", HELP_MESSAGE);
            // else, print error
         } else {
            printf("%s", ERROR_MESSAGE);
         }
      }

      // get input for direction
      getInput(INPUT_MESSAGE_2, dirInput, MAX_INPUT_DIR);

      const char *pDirInput = dirInput; // create a pointer to input
      int loop = 0; // for getting character in input

      // Loop through the characters in "input" until "\0"
      // Comparisons work based on character decimal codes
      while (*pDirInput != '\0') {
         char *currentChar;                  // store current character in input
         currentChar = malloc(2);       // allocate memory
         currentChar[0] = '\0';              // set to empty
         strncat(currentChar, pDirInput, 1);

         // If the character is 'm'
         if (strcmp(currentChar, "m") == 0) {
            move(&robot); // move
            // if the character is 't'
         } else if (strcmp(currentChar, "t") == 0) {
            turn(&robot); // turn
         }

         free(currentChar); // free from memory

         pDirInput++; // Move the pointer forward
      }

      // print robots final position
      printf("%sX = %d; Y = %d", FINISH_MESSAGE, robot.xpos, robot.ypos);

   }

   return 1; // end program
}

// ------ Function definitions   ----------

void move(ROBOT *robot) {

   // based on robots direction, and if value is between 0-99, increase x and y
   if (robot->dir == 0) {                    // N
      robot->ypos++; // increase pos
   } else if (robot->dir == 1) {             // E
      robot->xpos++; // increase pos
   } else if (robot->dir == 2) {             // S
      robot->ypos--; // increase pos
   } else {                                  // W
      robot->xpos--; // increase pos
   }
}

void turn(ROBOT *robot) {
   // Turn robot from 0-3, or N, W, E, S
   robot->dir = ((robot->dir) + 1) % 4;
}

void getInput(char *inputMessage, char *input, const int maxInput) {
   // print input message
   printf("%s", inputMessage);

   // get user input
   fgets(input, maxInput, stdin);

   // flush stdin
   fflush(stdin);
}

void enablePrintf() {
   setvbuf(stdout, NULL, _IONBF, 0); // enables console logs while debugging in Clion
}