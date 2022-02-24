// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 5
// Exercise 1
// Submission code: 836121


// define pins to use
#define PINS 0b11000000 // pins 6 and 7

void setup()
{
  DDRD = PINS; // set up pins 6 and 7
  PORTD = 0b01000000; // sets digital pin 6 HIGH, turns on second led when button is pressed
  Serial.begin(9600); // begin serial monitor
}

void loop()
{
  blink_led(); // blink led
}

void blink_led()
{
  PORTD = 0b11000000; // turn on led on pin 7
  delay(1000); // Wait for 1000 millisecond(s)
  PORTD = 0b01000000; // turn off led on pin 7
  delay(1000); // Wait for 1000 millisecond(s)
}
