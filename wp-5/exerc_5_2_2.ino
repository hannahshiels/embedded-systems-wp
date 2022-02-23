// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 2
// Submission code: xxxxxx

// INCLUDE
#include <DHT.h>
#include <DHT_U.h>

// define pins to use
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 13
#define LED_PIN_GREEN 12
#define TEMP_PIN 2
#define LIGHT_PIN A1
#define DHTTYPE DHT22
// define interval to check sensor values
#define INTERVAL_MS 1000

// VARIABLES
DHT dht(TEMP_PIN, DHTTYPE);// Create dht sensor

void setup() {
   Serial.begin(9600);             // begin serial monitor
   pinMode(LED_PIN_RED, OUTPUT);   // set red led up for output
   pinMode(LED_PIN_YELLOW, OUTPUT);// set yellow led up for output
   pinMode(LED_PIN_GREEN, OUTPUT); // set green led up for output
   dht.begin();                    // setup temp sensor
}

void loop() {
   check_readings();  // check the readings and turn on led based on them
   delay(INTERVAL_MS);// Wait for 1000 millisecond(s)
}

void check_readings()// check the readings of the temperature and light sensors and call check deviations, turning on a led depending on the relation of the light intensity and temperature
{
   float tempReading = dht.readTemperature();          // read temperature as celcius
   int lightReading = analogRead(LIGHT_PIN);           // read light sensor value
   int percentage = map(lightReading, 0, 1023, 0, 100);// map tinkercad readings to scale from 0 to 100

   Serial.println("----------------------------");// Line break
   Serial.print("Light intensity percentage: ");  // print message
   Serial.println(percentage);                    // print curent percentage
   Serial.print("Temperature: ");                 // print message
   Serial.println(tempReading);                   // print current temp
   check_deviations(percentage, tempReading);     // turn on led light based on dependencies between temperature and light intensity
}

// used to turn on led light, outputing the the temperature deviations in relation to the light intensity
void turn_on_led(int PIN) {
   if (digitalRead(PIN) != HIGH)// if the led isn't already on
   {
      digitalWrite(PIN, HIGH);// turn on led
      delay(500);             // wait half a second
   }
}

// used to turn off leds depending on temperature deviations
void turn_off_leds(int PIN) {
   if (PIN != LED_PIN_RED)// if the red led isn't the led to be turned on
   {
      digitalWrite(LED_PIN_RED, LOW);// turn off the red led
   }
   if (PIN != LED_PIN_YELLOW)// if the yellow led isn't the led to be turned on
   {
      digitalWrite(LED_PIN_YELLOW, LOW);// turn off the yellow led
   }
   if (PIN != LED_PIN_GREEN)// if the green led isn't the led to be turned on
   {
      digitalWrite(LED_PIN_GREEN, LOW);// turn off the green led
   }
}

void handle_leds(char color, int pin) {
   Serial.println(color);// print the color of the led
   turn_off_leds(pin);   // turn off all leds but the one connected to pin
   turn_on_led(pin);     // turn on led connected to pin
}

void check_deviations(int percentage, float temp)// used to control logic of how leds are turned on based on light intensity and temperature relation
{
   if (percentage == 0.0)// if the light intensity percentage is zero
   {
      Serial.println("Light intensity percentage is 0%");// print message about current light intensity percentage
      if (temp < -12.0)                                  // if the temperature is less than minus 12 degrees
      {
         handle_leds("Green", LED_PIN_GREEN);// Handle led
      } else                                 // otherwise
      {
         handle_leds("Red", LED_PIN_RED);// Handle led
      }
   } else if (percentage >= 1 && percentage < 21)// if the light intensity is between 1 and 20% percent
   {
      Serial.println("Light intensity percentage is between 1% and 20%");// print message about current light intensity percentage
      if (temp < -12.0)                                                  // if the temperature is lower minus 12 degrees
      {
         handle_leds("Yellow", LED_PIN_YELLOW);// Handle led
      } else if (temp > -12.0 && temp < 1.0)   // if the temperature is between minus 12 degrees and less than 1 degree
      {
         handle_leds("Green", LED_PIN_GREEN);// Handle led
      } else                                 // otherwise
      {
         handle_leds("Red", LED_PIN_RED);// Handle led
      }
   } else if (percentage >= 21 && percentage < 61)// if the light intensity is between 21% and 60%
   {
      Serial.println("Light intensity percentage is between 21% and 60%");// print message about current light intensity percentage
      if (temp < 0.0)                                                     // if the temperature is lower than 0 degrees
      {
         handle_leds("Yellow", LED_PIN_YELLOW);// Handle led
      } else if (temp > 20.0)                  // if the temperature is greater than 20 degrees
      {
         handle_leds("Red", LED_PIN_RED);// Handle led
      } else                             // otherwise
      {
         handle_leds("Green", LED_PIN_GREEN);// Handle led
      }
   } else// otherwise light intensity percentage is between 61% and 100%
   {
      Serial.println("Light intensity percentage is between 61% and 100%");// print message about current light intensity percentage
      if (temp >= 21.0)                                                    // if the temperature is greater than or equal to 21 degrees
      {
         handle_leds("Green", LED_PIN_GREEN);// Handle led
      } else                                 // otherwise
      {
         handle_leds("Yellow", LED_PIN_YELLOW);// Handle led
      }
   }
}
