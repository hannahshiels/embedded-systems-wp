// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 4
// Submission code: 736984

/**
 * This program reads input from a 4x4 keypad,
 * and prints the pressed key to the console.
 *
 * It uses the Keypad.h library
 * 
 * TINKERCAD Link: https://www.tinkercad.com/things/bXe4hZcYj6i
 **/

// INCLUDE
#include <Keypad.h>

// DEFINE
#define DATA_RATE 9600 					// Define data rate for Serial

// CONSTANTS
const char ROWS = 4; 					// Row amount
const char COLUMNS = 4; 				// Column amount
const char KEYS[ROWS][COLUMNS] = { 		// Possible KeyPad keys
              {'1', '2', '3', 'A'},
              {'4', '5', '6', 'B'},
              {'7', '8', '9', 'C'},
              {'*', '0', '#', 'D'}};

// VARIABLES
byte R_PINS[ROWS] = {11,10,9,8}; 	    // Pins for keypad rows - B8-B11
byte C_PINS[COLUMNS] = {7,6,5,4}; 	    // Pins for keypad columns - D4-D7
Keypad keypad = Keypad( makeKeymap(KEYS), R_PINS, C_PINS, ROWS, COLUMNS); // KeyPad

/**
 * Setup
 **/
void setup()
{
  Serial.begin(DATA_RATE); 					// begin serial
}

/**
 * Main loop
 **/
void loop()
{
  char pressedKey = keypad.getKey(); 	// get pressed key
  printKey(pressedKey);					// print the pressed key
}

// printKey() prints a recieved char and sets a delay for x time
void printKey(char key){
  if(key != 0) {						// if not 0
  	Serial.println(key); 				// print the pressed key
  }
}