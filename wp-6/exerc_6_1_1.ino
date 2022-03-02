// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 6
// Exercise 1, Task 1
// Submission code: xxxxxx

/**
 * This program reads user input for speed and direction,
 * and sets a motor to the input
 * 
 **/

// DEFINE
#define PWM1 9
#define PWM2 10
#define DATA_RATE 9600// Serial data rate
#define MAX_INPUT 10  // max input
#define LEFT "left"   // compare user input
#define RIGHT "right" // compare user input

// VARIABLES
char *direction; // input for direction
char *speedInput;// input for speed
int speed = 0;   // Desired motor speed

// CONSTANTS
const char SPEED[] = "Please enter the desired speed(0-255): ";                // speed input qestion
const char DIRECTION[] = "Please enter the desired direction(left or right): ";// direction input qestion

void setup() {
   Serial.begin(DATA_RATE);// set serial data rate
   pinMode(PWM1, OUTPUT);  // set PWm to output
   pinMode(PWM2, OUTPUT);  // set PWm to output

   fix_bug();    // deal with TinkerCad bug
   input_start();// start input
}

void loop() {
   // Loop as long as direction input is left or right
   while (!strcmp(direction, LEFT) || !strcmp(direction, RIGHT)) {
      // Send the speed signal to motor
      // Rotating clockwise
      if (!strcmp(direction, RIGHT)) {
         analogWrite(PWM2, 0);// Write
         analogWrite(PWM1, speed);
         direction = "";// reset direction input
      }
      // Rotating counter-clockwise
      else if (!strcmp(direction, LEFT)) {
         analogWrite(PWM1, 0);
         analogWrite(PWM2, speed);
         direction = "";// reset direction input
      }

      free(direction); // free memory
      free(speedInput);// free memory
   }
}

// Get input for speed and direction
void input_start() {
   Serial.print("\n");// print a new line

   // Get input
   direction = (char *) malloc(MAX_INPUT); // allocate mem for direction
   speedInput = (char *) malloc(MAX_INPUT);// allocate mem for speed
   get_input(SPEED, speedInput);           // Input for speed
   speed = atoi(speedInput);               // Convert to integer
   get_input(DIRECTION, direction);        // Input for direction
   delay(10);                              // small delay
}

void get_input(char const string[], char *input) {

   int ready = 0;// for checking whether .readBytes has finished reading

   Serial.print(string);// Print input question

   // while ready = 0
   while (!ready) {
      ready = Serial.readBytes(input, MAX_INPUT);// read the serial input
   }

   Serial.print((String) input + "\n");// Print input answer
}

// Tinkercad bug fix 1
void fix_bug() {
   // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
   analogWrite(PWM2, 10);
   delay(1000);// TinkerCad bug
   analogWrite(PWM1, 10);
}
