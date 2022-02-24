// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 5
// Exercise 1
// Submission code: 836121


// define pins to use
#define PINS 0b11000000 // pins 6 and 7
// define pins that are set to HIGH 
#define BUTTON_PIN_ON 0b01000000 // digital pin 6 high
#define LED_BUTTON_ON 0b11000000 // digital pins 6 and 7

#define DELAY 1000 // milliseconds to delay, 1 second

void setup()
{
  DDRD = PINS; // set up pins 6 and 7
  PORTD = BUTTON_PIN_ON; // sets digital pin 6 HIGH, turns on second led when button is pressed
}

void loop()
{
  blink_led(); // blink led
}

void blink_led()
{
  PORTD = LED_BUTTON_ON; // turn on led on pin 7
  delay(DELAY); // wait for 1000 millisecond(s)
  PORTD = BUTTON_PIN_ON; // turn off led on pin 7
  delay(DELAY); // wait for 1000 millisecond(s)
}
