// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 3
// Exercise 3
// Submission code: xxxxxx

/**
 * In this exercise you should add the display of the temperature to your temperature meter and use analog conversion
 * of the temperature meter.
 **/


// C++ code
// ------ Defines   ----------

#define SENSOR_PIN 0   //The pin that is connected to the temperature sensor

// ------ Variables etc   ----------

float tmpSensor = 0.0;   //The value received from the temperature sensor will be saved here
float voltage = 0.0;   //The value of voltage will be stored here
float temperature = 0.0;   //The temperature value will be stored in this variable

// ------Main   ----------

//start the execution
void setup()
{
    Serial.begin(9600);
}

//This happens over and over while the cod eis executing
void loop()
{
    //read the value from the sensor
    tmpSensor = analogRead(SENSOR_PIN);

    //convert the reading from the sensor into
    voltage  = tmpSensor * 5.0;
    voltage /= 1024.0;

    //Convert the voltage into celsius degree temperature
    temperature = (voltage - 0.5) * 100.0;

    //print the voltage to ease the comparison
    Serial.print("Voltage is: "); Serial.println(voltage);

    //print out the temperature
    Serial.print("Temperature is: ");Serial.println(temperature);

    // Delay to improve simulation performance
    delay(500);
}