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
#define MAX_VOLT 5.0   //The maximum voltage for the sensor
#define BIT_RESOLUTION 10   //The bit resolution for the voltage

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

    //convert the reading from the sensor into volts
    voltage  = tmpSensor * MAX_VOLT;
    voltage /= (pow (2, BIT_RESOLUTION));

    //Convert volt into milli volt
    voltage *= 1000;

    //Convert the voltage into celsius degree temperature
    temperature = (voltage - 500.0) / 10.0;

    //print the voltage to ease the comparison
    Serial.print("Voltage is: "); Serial.print(voltage); Serial.println(" milli volts");

    //print out the temperature
    Serial.print("Temperature is: ");Serial.print(temperature);Serial.println(" centigrade");

    // Delay to improve simulation performance
    delay(500);
}