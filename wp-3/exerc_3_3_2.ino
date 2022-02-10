// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 3
// Submission code: 736984

/**
 * This program reads input from a 4x4 keypad,
 * and prints the pressed key to the console.
 *
 * TINKERCAD Link: https://www.tinkercad.com/things/1s3GKzv0wlg
 **/

// DEFINE
#define DATA_RATE 9600 					// Define data rate for Serial
#define KEY_PRINT_DELAY 1000 			// Delay after printing key

// CONSTANTS
const char ROWS = 4; 					// Row amount
const char COLUMNS = 4; 				// Column amount
const char R_PINS[ROWS] = {11,10,9,8}; 	// Pins for keypad rows - B8-B11
const char C_PINS[COLUMNS] = {7,6,5,4}; // Pins for keypad columns - D4-D7
const char KEYS[ROWS][COLUMNS] = { 		// Possible KeyPad keys
              {'1', '2', '3', 'A'},
              {'4', '5', '6', 'B'},
              {'7', '8', '9', 'C'},
              {'*', '0', '#', 'D'}};

/**
 * Setup
 **/
void setup()
{
  Serial.begin(DATA_RATE); 				// begin serial
  setPins();                            // set pin output, input, high
}

/**
 * Main loop
 **/
void loop()
{
  char pressedKey = getKey(); 			// get pressed key
  printKey(pressedKey);					// print the pressed key
}

/**
 *FUNCTIONS
 **/

// getKey() returns current pressed key
char getKey() {
  char key = 0;							// store key
  
  for(char i = 0; i < ROWS; i++) {		// for rows
    digitalWrite(R_PINS[i], LOW);		// write row pin to low
    
    for(char j = 0; j < COLUMNS; j++) {	// for columns
      if(digitalRead(C_PINS[j]) == LOW){// if pin turned low
      	delay(20);						// small delay 
        key = KEYS[i][j];				// set current key to char in KEYS
      }
    }
    digitalWrite(R_PINS[i], HIGH); 	    // write row pin to HIGH again
  }
  
  return key;							// return the key
}

// printKey() prints a recieved char and sets a delay for x time
void printKey(char key){
  if(key != 0) {						// if not 0
  	Serial.println(key); 				// print the pressed key
    delay(KEY_PRINT_DELAY);				// delay
  }
}

// sets pins as either input, output, and column pins to high
void setPins(){
  for(char i = 0; i < COLUMNS; i++){	// for length of columns
  	pinMode(C_PINS[i], INPUT); 			// set column pin as input
  	digitalWrite(C_PINS[i], HIGH);		// Set column pin to high
  }
  
  for(char i = 0; i < ROWS; i++){  		// for length of rows
    pinMode(R_PINS[i], OUTPUT);    		// set row pin as output
  }
}