// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 4
// Exercise 3
// Submission code: 777339


/**
 * Create a system based on Arduino Uno or Arduino Yun, which periodically measures one of the following:
 • Temperature
 • Sound (using sonic sensor), or
 • Light intensity
 using NeoPixel ring (addressable LEDs) to display the value based on the sensor. For example, the temperature based on
 the temperature sensor. Since the NeoPixel ring is a ring, you should indicate that you reached the limit of LEDs by
 adding one more, standard red LED. The red LED should be ON after all NeoPixel ring’s LEDs are ON. Optional: you can add
 speaker (Pizo) to make a sound in addition to turning ON the red LED.

TinkerCad Link: https://www.tinkercad.com/things/b3uAztfvfwF-wp4exerc3/editel
 */

//------ Imports   ----------
#include <Adafruit_NeoPixel.h>      //The library associated to neon pixels


// ------ Defines   ----------
#define NEO_PIN 2                   //The digital pin that the neo pixel is connected through
#define STANDARD_LED_PIN 4          //Teh digital pin that the standard LED is connected with
#define LIGT_SENSOR_PIN A0          //The analogue pin which the light sensor is connected through
#define SPEAKER 3                   //The digital pin which the speaker is connected with
#define NUMBER_OF_PIXELS 24         //The number of pixels in a neon pixel
#define LOWEST_LIGHT_VALUE 6.00     //The lowest value that the light sensor shows
#define HIGHEST_LIGHT_VALUE 679.00  //The highest value that the light sensor shows
#define DELAY 100                   //The allocated time for delays in milliseconds

//------ Variables etc   ----------
float lightVal = 0.0;               //The value which is rad from the board goes in this
const float intensityUnit = (HIGHEST_LIGHT_VALUE - LOWEST_LIGHT_VALUE) / NUMBER_OF_PIXELS;           //The light intensity value corresponding to each pixel
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMBER_OF_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800); //To use the neo library
int redColor = 0;                   //The red amount of the pixel color
int greenColor = 255;               //The green amount of the pixel color
int blueColor = 0;                  //The blue amount of the pixel color
int onPixels = 0;                   //The umber of pixels that are on
int offPixels = 0;                  //The number of pixels that are off

// ------Main   ----------
//Initiate the program
void setup()
{
    pixels.begin();                    //Initialize the library
    pinMode(LIGT_SENSOR_PIN, INPUT);   //Define the light sensor as input
    pinMode(SPEAKER, OUTPUT);          //Define the speaker as output
    pinMode(STANDARD_LED_PIN, OUTPUT); //Define the pin for the standard LED
    Serial.begin(9600);                //For debugging purpose
}

//This loop happens over and over while running the code
void loop()
{

    lightVal = analogRead(LIGT_SENSOR_PIN);          //Read the value from the light sensor
    Serial.println(lightVal);           //Print out the value for debugging
    ledHandler();                       //Turn on the LEDs in neo pixel according to the light intensity
    setAlert();                         //Alert with the speaker and the standard LED
    delay(DELAY);                       //To avoid laptop explosion
}

void ledHandler()
{
    onPixels = lightVal / intensityUnit;       //Calculate the number of pixels that should turn on according to the current light intensity
    Serial.println(onPixels);                  //Print the value for err handling

    for (int i = 0; i < onPixels; i++) {           //Loop through the LEDs which are supposed to turn on
        setColor(i, true);                         //set the color of LEDs and turn the neo pixel on

    }

    for (int i = onPixels; i < NUMBER_OF_PIXELS; i++) {   //Loop through the LEDs that are supposed to be off
        setColor(i, false);                               //Turn them off if they are not already
    }

}

void setColor(int i,bool isOn)
{
    if(isOn)    //if the LED should turn on
    {
        redColor = 153;    //Set LED to a purple color
        greenColor = 51;   //Set LED to a purple color
        blueColor = 255;   //Set LED to a purple color
    } else    //if the LED should turn off
    {
        redColor = 0;    //turn off
        greenColor = 0;  //turn off
        blueColor = 0;   //Turn off
    }
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));     //Set the LED color
    pixels.show();             //turn on the noe pixel in arduino board
}

void setAlert()
{
    if (lightVal == HIGHEST_LIGHT_VALUE){      //If the light intensity is the highest
        tone(SPEAKER, 500, 200);               //Alert in some frequency
        digitalWrite(STANDARD_LED_PIN, HIGH);  //Alert with red LED
    } else {                  //If the light intensity is not the highest
        noTone(SPEAKER);                       //turn off the speaker
        digitalWrite(STANDARD_LED_PIN, LOW);  //Turn off the red LED
    }
}

