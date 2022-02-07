// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 3
// Submission code: xxxxxx

/**
 * This program reads input from a 4x4 keypad,
 * and prints the pressed key to the console.
 *
 * TINKERCAD Link: https://www.tinkercad.com/things/1s3GKzv0wlg
 **/

// CONSTANTS
// Row and Column amount
const char ROWS = 4;
const char COLUMNS = 4;
// KeyPad Row Pins
const char R_PINS[ROWS] = {11,10,9,8}; 	// D8-D11
// KeyPad Column Pins
const char C_PINS[COLUMNS] = {7,6,5,4}; // D4-D7
// KeyPad keys
const char KEYS[ROWS][COLUMNS] = {
              {'1', '2', '3', 'A'},
              {'4', '5', '6', 'B'},
              {'7', '8', '9', 'C'},
              {'*', '0', '#', 'D'}};

/**
 * Setup
 **/
void setup()
{
  Serial.begin(9600); 					// begin serial
  
  for(char i = 0; i < COLUMNS; i++){	// for length of columns
  	pinMode(C_PINS[i], INPUT); 			// set column pin as input
  	digitalWrite(C_PINS[i], HIGH);		// Set column pin to high
  }
  
  for(char i = 0; i < ROWS; i++){  		// for length of rows
    pinMode(R_PINS[i], OUTPUT);    		// set row pin as output
  }
}

/**
 * Main loop
 **/
void loop()
{
  char pressedKey = getKey(); 			// get pressed key
  
  if(pressedKey != 0) {					// if not 0
  	Serial.println(pressedKey); 		// print the pressed key
  }
}

/**
 *FUNCTION: getKey() - function that returns current pressed key
 **/
char getKey() {
  char key = 0;							// store key
  
  for(char i = 0; i < ROWS; i++) {		// for rows
    digitalWrite(R_PINS[i], LOW);		// write row pin to low
    
    for(char j = 0; j < COLUMNS; j++) {	// for columns
      if(digitalRead(C_PINS[j]) == LOW){// if pin turned low
      	delay(20);						// small delay 
        key = KEYS[i][j];				// set current key to char in KEYS
      }
      
      while(digitalRead(C_PINS[j]) == LOW) { // Stop input while key is pressed down
      	key = KEYS[i][j];					 // Keep setting current key
      }
    }
    digitalWrite(R_PINS[i], HIGH); 			 // write row pin to HIGH again
  }
  
  return key;							// return the key
}