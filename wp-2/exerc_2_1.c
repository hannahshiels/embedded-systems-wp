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

// robot related values
#define MAX_INPUT_POS_VAL 99     // max value for x,y
#define MIN_INPUT_POS_VAL 0      // min value for x,y
#define MAX_INPUT_POS 6          // max input for x,y; '99 99' + end char
#define MAX_INPUT_DIR 100        // max input for 'm' and 't'
// Printf messages:
#define INPUT_MESSAGE_1 "\nInput the Robots starting position('x y' between 0-99, or '-h' for help): " // Input message 1
#define INPUT_MESSAGE_2 "\nInput a sequence of 'm' and 't' (Ex 'mmmt', or '-h' for help): "            // Input message 2
#define ERROR_MESSAGE "\nYour input was not correct. Input -h for help"            // ERROR message
#define FINISH_MESSAGE "\nThe Robots location is: "                                // Robots position message
// Help messages:
#define HELP_MESSAGE_1 "\nPosition: For the position you have to input two numbers between 0-99, seperated by a space."
#define HELP_MESSAGE_2 "\nMove & Turn: Move and turn by supplying any amount or combination of 'm' and 't'."
#define HELP_MESSAGE_3 "\nExit: Leave program by inputting 'x'.\n"
// input characters
#define END_CHARACTER "x\n"
#define HELP_CHARACTER "-h\n"

// ------ Variables etc   ----------

// to check if end of program; is set to false on specific user END_CHARACTER input
int eop = 1;

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

// This method handles user input, and handles the robots starting position
// returns 1 if function is successfull, otherwise 0
int handlePositionInput(ROBOT *robot);

// This method handles user input, and handles the robots direction and heading(turning and moving forward)
// returns 1 if function is successfull, otherwise 0
int handleDirectionInput(ROBOT *robot);

// This function moves the robot 1 time forward, by changing its x and y values (changed based on robots direction)
void move(ROBOT *robot);

// This function turns the robot 90 degrees
void turn(ROBOT *robot);

// This function prints input message, and gets user input
// returns 1 if function is successfull, otherwise 0
int getInput(char *inputMessage, char *input, int maxInput);

// This function enables printf in Clion while debugging
// https://stackoverflow.com/questions/47776094/clion-wont-show-output-in-debug
void enablePrintf();

// ------ Main   --------------------------
// The main entry point for the program
// TODO: Refactor, Error handling, Make methods return true,false instead
int main(int argc, char *argv[]) {
   ROBOT robot;                        // Create a robot
   enablePrintf();                     // enable console logs when debugging

   // main loop runs while eop is true
   while (eop) {

      // 1. manage robot starting position, end if function returns 0
      if (handlePositionInput(&robot) == 0)
         return 2;

      // 2. manage robots movement and turning, end if function returns 0
      if (handleDirectionInput(&robot) == 0)
         return 2;

      // 3. print robots position
      printf("%sX = %d; Y = %d", FINISH_MESSAGE, robot.xpos, robot.ypos);

   }

   return 1; // end program
}

// ------ Function definitions   ----------

int handlePositionInput(ROBOT *robot) {
   char startPosInput[MAX_INPUT_POS];  // input for starting position
   int correctPosInput = 0;            // boolean for correct/false input

   // runs while user inputs wrong input for starting position
   while (!correctPosInput) {
      int loop = 0; // set loop to 0

      // get input for start pos if getInput is true, else return 0;
      if (getInput(INPUT_MESSAGE_1, startPosInput, MAX_INPUT_POS) == 0)
         return 0;

      // get the first string from input
      char *splitString = strtok(startPosInput, " ");

      // loop through the string to extract all other strings
      while (splitString != NULL) {
         char *pEnd;    // ...
         int stringAsInt = strtol(splitString, &pEnd, 10);

         // set first string to x pos, then set y, only if value is between 0-99
         if (loop == 0 && stringAsInt >= MIN_INPUT_POS_VAL && stringAsInt <= MAX_INPUT_POS_VAL) {
            // convert input to int and store in x
            robot->xpos = stringAsInt;
         } else if (stringAsInt >= MIN_INPUT_POS_VAL && stringAsInt <= MAX_INPUT_POS_VAL) {
            // convert input to int and store in y
            robot->ypos = stringAsInt;
         }

         // grab the next string and set to splitString
         splitString = strtok(NULL, " ");

         // increase loop counter
         loop++;
      }

      // if the user has supplied two strings seperated by a space;
      if (loop == 2) {
         correctPosInput = 1;       // user has correct amount of input
      }
   }

   return 1;
}

int handleDirectionInput(ROBOT *robot) {
   char dirInput[MAX_INPUT_DIR];       // input for direction
   // create a pointer to dirInput
   const char *pDirInput = dirInput;

   // get input for direction if getInput is true, else return 0;
   if (getInput(INPUT_MESSAGE_2, dirInput, MAX_INPUT_DIR) == 0)
      return 0;

   // Loop through the characters in "input" until "\0"
   // Comparisons work based on character decimal codes
   while (*pDirInput != '\0') {
      char *currentChar;                  // store current character in input
      currentChar = malloc(2);       // allocate memory
      currentChar[0] = '\0';              // set to empty
      strncat(currentChar, pDirInput, 1);

      // If the character is 'm'
      if (strcmp(currentChar, "m") == 0) {
         move(robot); // move
         // if the character is 't'
      } else if (strcmp(currentChar, "t") == 0) {
         turn(robot); // turn
      }

      free(currentChar); // free from memory

      pDirInput++; // Move the pointer forward
   }

   return 1;
}

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

int getInput(char *inputMessage, char *input, const int maxInput) {
   // print input message
   printf("%s", inputMessage);

   // get user input
   fgets(input, maxInput, stdin);

   // if 'x' is inputted, return 0
   if (strcmp(input, END_CHARACTER) == 0)
      return 0;

   // if '-h' is inputted, print help messages
   if (strcmp(input, HELP_CHARACTER) == 0)
      printf("%s%s%s", HELP_MESSAGE_1, HELP_MESSAGE_2, HELP_MESSAGE_3);

   // flush stdin
   fflush(stdin);

   return 1;
}

void enablePrintf() {
   setvbuf(stdout, NULL, _IONBF, 0); // enables console logs while debugging in Clion
}