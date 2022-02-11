// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 1
// Submission code: 736984

/**
 * Create a simple system in TinkerCad, which will use one LED to blink periodically, e.g. once a second. Add one more
 * LED and a button. The second LED should be on when the button is pressed, and off, when the button is not pressed.
 **/

// C++ code
//
// ------ Defines   ----------
#define BLINK_LED 13   //The pin corresponding to the blinking LED
#define BUTTON_LED 6   //The pin corresponding to the LED with button

// ------ Main   ----------
//Initializing
void setup()
{
    //set pins as output
    pinMode(BLINK_LED, OUTPUT);
    pinMode(BUTTON_LED, OUTPUT);
    //triggers the circuit including the button LED
    digitalWrite(BUTTON_LED, HIGH);

}

//This happens over and over
void loop()
{
    //Does the blinking!
    blink();
}

void blink()
{
    //Turn on the blinking LED
    digitalWrite(BLINK_LED, HIGH);

    // Stay on for a sec
    delay(1000);

    //Turn off the blinking LED
    digitalWrite(BLINK_LED, LOW);

    //Stay off for a sec
    delay(1000);

}