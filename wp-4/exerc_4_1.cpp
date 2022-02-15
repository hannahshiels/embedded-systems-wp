// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 4
// Exercise 1
// Submission code: xxxxxx

/**
 * This program will measure temperature by using an interrupt.
 * It will measure every x seconds and depending on temperature,
 * different leds will light up.
 * 
 * This program uses pre-defined variables:
 * DDRB: used to set INPUT/OUTPUT on port B. 8-bit | 0000 0000
 * PORTB: used to set HIGH/LOW ont port B. 8-bit | 0000 0000
 * setupTimer1 and ISR: uses 
 * 
 * TINKERCAD Link: 
 **/

// DEFINE
// General:
#define DATA_RATE 9600// Define data rate for Serial
#define SECOND 1000   // A second in milliseconds

// Leds:
#define LED_PIN_RED 0B00010000   // Red led pin
#define LED_PIN_ORANGE 0B00001000// Orange led pin
#define LED_PIN_YELLOW 0B00000100// Yellow led pin
#define LED_PIN_GREEN 0B00000010 // Green led pin
#define LED_PIN_BLUE 0B00000001  // Blue led pin

// Temperature sensor:
#define TEMP_PIN A0      // Define pin for temperature sensor
#define MAX_VOLT 5.0     //The maximum voltage for the sensor
#define BIT_RESOLUTION 10//The bit resolution for the voltage

// Timer & Interrupt related:
// used in calculation: compare match register = [ clock speed/ (prescaler * interrupt frequency) ] - 1
#define PRESCALER 1024      // used for dictating speed of timer according to (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
#define INTERRUPT_FREQ 1    // define interrupt frequency
#define CLOCK_SPEED 16000000// Clock speed of the Arduino Uno
#define TIMER1_MAX 65535    // Max counter value for timer1
#define TIMER1_LOW 257      // Lowest counter value for timer1

// CONSTANTS, VARIABLES
int timer1 = 0;//	Used for saving calculated compare match register value

volatile float tmpSensor = 0.0;//	The value received from the temperature sensor will be saved here
float temp_old = 0.0;          //	A copy of above used in comparisons
float voltage = 0.0;           //	The value of voltage will be stored here
float temperature = 0.0;       //	The temperature value will be stored in this variable

/**
 * Setup
 **/
void setup() {
   setup_timer_1();        // Setup timer1
   Serial.begin(DATA_RATE);// Begin serial
}

/**
 * Main loop
 **/
void loop() {
   if (tmpSensor != temp_old) {//0. If the new tmpSensor value is different
      voltage_handler();       //1. Calculate the voltage
      temp_converter();        //2. Calculate the temperature based on the calculated voltage
      activate_leds();         //3. Turn on leds depending on temperature
   }
}

/**
 *SETUP FUNCTIONS
 **/

// This function sets up timer1 on an Arduino Uno
// Built on top of: https://www.instructables.com/Arduino-Timer-Interrupts/
// Sets timer1 interrupt at 1Hz = 1 second = 1 cycle per second
void setup_timer_1() {
   cli();//stop interrupts

   TCCR1A = 0;// set entire TCCR1A register to 0
   TCCR1B = 0;// same for TCCR1B
   TCNT1 = 0; //initialize counter value to 0


   timer1 = (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;// calculate at which point to stop the counter and set to int:

   if (timer1 >= TIMER1_MAX) {                                                         // if value went above max value
      timer1 = TIMER1_MAX;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too high and was changed to: " + timer1);// notify user
   } else if (timer1 <= TIMER1_LOW) {                                                  // if value went below lowest value
      timer1 = TIMER1_LOW;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too low and was changed to: " + timer1); // notify user
   }

   OCR1A = timer1;                     // set compare match register for 1hz increments
   TCCR1B |= (1 << WGM12);             // turn on CTC mode
   TCCR1B |= (1 << CS12) | (1 << CS10);// set CS10 and CS12 bits for 1024 prescaler
   TIMSK1 |= (1 << OCIE1A);            // enable timer compare interrupt

   sei();//allow interrupts
}

// This function sets the led pins to output; DDRB=B00011111
void setupLedPins() {
   DDRB = DDRB | LED_PIN_RED;   // Set red led up for output
   DDRB = DDRB | LED_PIN_ORANGE;// Set red led up for output
   DDRB = DDRB | LED_PIN_YELLOW;// Set yellow led up for output
   DDRB = DDRB | LED_PIN_GREEN; // Set green led up for output
   DDRB = DDRB | LED_PIN_BLUE;  // Set green led up for output
}

// Interrupt 1
// Based on setupTimer1, this ISR will trigger every x second(s)
ISR(TIMER1_COMPA_vect) {
   cli();     //stop interrupts
   get_temp();// get the temperature
   sei();     //allow interrupts
}

/**
 *LOOP FUNCTIONS
 **/

// This function gets the temperature
// TODO: change analogRead
void get_temp() {
   tmpSensor = analogRead(TEMP_PIN);//read the value from the sensor
}

// This function converts sensor reading into millivolts
void voltage_handler() {
   voltage = tmpSensor * MAX_VOLT;     //convert sensor reading into volts
   voltage /= (pow(2, BIT_RESOLUTION));//10 bit resolution
   voltage *= 1000;                    //Convert volt into milli volt
}

// This function converts millivolt to temperature
void temp_converter() {
   temperature = (voltage - 500.0) / 10.0;//Convert voltage into celsius
}

// This function turns on leds depending on current temperature
// temperature sensor has range -40 to 125
// this allows a value range of 33 for 5 leds
// TODO: Make PORTB assignment safer
void activate_leds() {
   if (temperature <= -7) {                           // if temperature is in range
      PORTB = LED_PIN_BLUE;                           // set PORTB to only light up blue led
   } else if (temperature > -7 && temperature <= 26) {// if temperature is in range
      PORTB = LED_PIN_GREEN;                          // set PORTB to only light up green led
   } else if (temperature > 26 && temperature <= 59) {// if temperature is in range
      PORTB = LED_PIN_YELLOW;                         // set PORTB to only light up yellow led
   } else if (temperature > 59 && temperature <= 92) {// if temperature is in range
      PORTB = LED_PIN_ORANGE;                         // set PORTB to only light up orange led
   } else if (temperature > 92) {                     // if temperature is in range
      PORTB = LED_PIN_RED;                            // set PORTB to only light up red led
   }
}
