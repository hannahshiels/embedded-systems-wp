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

// CONSTANTS
// Row and Column amount
const byte ROWS = 4;
const byte COLUMNS = 4;
// KeyPad keys
const char KEYS[ROWS][COLUMNS] = {
              {'1', '2', '3', 'A'},
              {'4', '5', '6', 'B'},
              {'7', '8', '9', 'C'},
              {'*', '0', '#', 'D'}};

// VARIABLES
// KeyPad Row Pins
byte R_PINS[ROWS] = {11,10,9,8}; 		// D8-D11
// KeyPad Column Pins
byte C_PINS[COLUMNS] = {7,6,5,4}; 		// D4-D7
// KeyPad
Keypad keypad = Keypad( makeKeymap(KEYS), R_PINS, C_PINS, ROWS, COLUMNS);

/**
 * Setup
 **/
void setup()
{
  Serial.begin(9600); 					// begin serial
}

/**
 * Main loop
 **/
void loop()
{
  char pressedKey = keypad.getKey(); 	// get pressed key
  
  if(pressedKey != NO_KEY) {			// if key has been pressed
  	Serial.println(pressedKey); 		// print the pressed key
  }
}