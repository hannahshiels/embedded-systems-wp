// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 2
// Submission code: xxxxxx

// define pins to use
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13
#define TEMP_PIN A0
#define LIGHT_PIN A1
// define interval to check sensor values
#define INTERVAL_MS 1000

void setup()
{
    Serial.begin(9600);              // begin serial monitor
    pinMode(LED_PIN_RED, OUTPUT);    // set red led up for output
    pinMode(LED_PIN_YELLOW, OUTPUT); // set yellow led up for output
    pinMode(LED_PIN_GREEN, OUTPUT);  // set green led up for output
}

// used to turn on led light, outputing the the temperature deviations in relation to the light intensity
void turn_on_led(int PIN)
{
    digitalWrite(PIN, HIGH); // turn on led
    delay(500); // wait a bit
}

// used to turn off leds depending on temperature deviations 
void turn_off_leds(int PIN)
{
    if (PIN != LED_PIN_RED) // if the red led isn't the led to be turned on
    {
        digitalWrite(LED_PIN_RED, LOW); // turn off the red led
    }
    if (PIN != LED_PIN_YELLOW) // if the yellow led isn't the led to be turned on
    {
        digitalWrite(LED_PIN_YELLOW, LOW); // turn off the yellow led
    }
    if (PIN != LED_PIN_GREEN) // if the green led isn't the led to be turned on
    {
        digitalWrite(LED_PIN_GREEN, LOW); // turn off the green led
    }
}

void loop()
{
    int tempReading = analogRead(TEMP_PIN); // read analog value of temperature
    float calc = ((float)tempReading * 5.0) / 1024.0; 
    float temp = (calc - 0.5) * 100;
    int lightReading = analogRead(LIGHT_PIN); // read light sensor value
    Serial.println(lightReading);
    float percentage = ((float)lightReading / 1023.0) * 100.0; // light sensor has analog values from 0 - 1023, therefore to calculate light intensity percentage we divide by 1023 and multiply by 100 to get a usable percentage
    Serial.println(temp);                                      // print temperature
    Serial.println(percentage);                                // print light intensity
    if (percentage == 0.0 || percentage < 1.0) // if the light intensity percentage is zero or less than 1
    { 
        Serial.println("Light intensity percentage is 0%"); // print message about current light intensity percentage
        if (temp < -12.0) // if the temperature is less than minus 12 degrees
        {
            Serial.println("Green"); // the reading is normal, LED should turn green
            turn_off_leds(LED_PIN_GREEN); // turn off all leds but the green
            turn_on_led(LED_PIN_GREEN); // turn on green led
        }
        else // otherwise
        {
            Serial.println("Red"); // the reading is too high, LED should turn red
            turn_off_leds(LED_PIN_RED); // turn off all leds but the red
            turn_on_led(LED_PIN_RED); // turn on red led
        }
    }
    else if (percentage >= 1.0 && percentage < 21.0) // if the light intensity is between 1 and 20% percent
    {
        Serial.println("Light intensity percentage is between 1% and 20%"); // print message about current light intensity percentage
        if (temp < -12.0) // if the temperature is lower minus 12 degrees
        {
            Serial.println("Yellow"); // reading is too low, LED should turn yellow
            turn_off_leds(LED_PIN_YELLOW);  // turn off all leds but the yellow
            turn_on_led(LED_PIN_YELLOW); // turn on yellow led
        }
        else if (temp > -12.0 && temp < 1.0) // if the temperature is between minus 12 degrees and less than 1 degree
        {
            Serial.println("Green"); // reading is normal, LED should turn green
            turn_off_leds(LED_PIN_GREEN); // turn off all leds but the green
            turn_on_led(LED_PIN_GREEN); // turn on green led
        }
        else // otherwise
        {
            Serial.println("Red"); // reading is too high, LED should turn red
            turn_off_leds(LED_PIN_RED); // turn off all leds but the red
            turn_on_led(LED_PIN_RED); // turn on red led
        }
    }
    else if (percentage >= 21.0 && percentage < 61.0) // if the light intensity is between 21% and 60%
    {
        Serial.println("Light intensity percentage is between 21% and 60%"); // print message about current light intensity percentage
        if (temp < 0.0) // if the temperature is lower than 0 degrees
        {
            Serial.println("Yellow"); // reading is too low, LED should turn yellow
            turn_off_leds(LED_PIN_YELLOW);  // turn off all leds but the yellow
            turn_on_led(LED_PIN_YELLOW); // turn on yellow led
        }
        else if (temp > 20.0) // if the temperature is greater than 20 degrees
        {
            Serial.println("Red"); // reading is too high, LED should turn red
            turn_off_leds(LED_PIN_RED); // turn off all leds but the red
            turn_on_led(LED_PIN_RED); // turn on red led
        }
        else // otherwise
        {
            Serial.println("Green"); // reading is normal, LED should turn green
            turn_off_leds(LED_PIN_GREEN); // turn off all leds but the green
            turn_on_led(LED_PIN_GREEN); // turn on green led
        }
    }
    else // otherwise light intensity percentage is between 61% and 100%
    {
        Serial.println("Light intensity percentage is between 61% and 100%"); // print message about current light intensity percentage
        if (temp >= 21.0) // if the temperature is greater than or equal to 21 degrees
        {
            Serial.println("Green"); // reading is normal, LED should turn green
            turn_off_leds(LED_PIN_GREEN); // turn off all leds but the green
            turn_on_led(LED_PIN_GREEN); // turn on green led
        }
        else // otherwise
        {
            Serial.println("Yellow"); // reading is too low, LED should turn yellow
            turn_off_leds(LED_PIN_YELLOW);  // turn off all leds but the yellow
            turn_on_led(LED_PIN_YELLOW); // turn on yellow led
        }
    }
    delay(INTERVAL_MS); // Wait for 1000 millisecond(s)
}