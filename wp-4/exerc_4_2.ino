// (C) Maryam Esmaeli Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 4
// Exercise 2
// Submission code: xxxxxx

/**
 * This program functions as an analog timer, where the servos measure
 * the seconds and minutes.
 **/

// use servo library
#include <Servo.h>

// pins for servos
#define SERVO_S_PIN A0
#define SERVO_M_PIN A1
#define MAX_DEGREES 180 // max degree for servo motor

// declare variables
Servo servo_s; // servo for seconds
Servo servo_m; // servo for minutes

int sDegrees = 0; // degrees for seconds servo
int mDegrees = 0; // degrees for minutes servo
int seconds = 0;  // measure number of seconds
int minutes = 0;  // measure number of minutes

void setup()
{
    servo_s.attach(SERVO_S_PIN, 500, 2500); // set up servo, with min and max values
    servo_m.attach(SERVO_M_PIN, 500, 2500); // set up servo, with min and max values
    Serial.begin(9600);                     // start serial monitor
    servo_m.write(0);                       // set initial position of minute servo
}

void loop()
{
    reset_degrees();                   // if degrees are 180 then reset the position of servos
    increment_degrees_seconds_servo(); // increment number of degrees to seconds servo
    print_output();                    // print current seconds and minutes
    check_seconds();                   // increment number of seconds
    delay(1000);                       // wait 1 second
}

void check_seconds() // check the seconds
{
    seconds++;         // increment seconds
    if (seconds == 60) // if the seconds are 60
    {
        seconds = 0; // reset number of seconds
    }
}

void increment_minutes()
{
    minutes++;                         // increment number of minutes
    increment_degrees_minutes_servo(); // increment minute servo
}

void reset_degrees()
{
    if (sDegrees == MAX_DEGREES) // if the servo is fully rotated
    {
        sDegrees = 0;        // reset the position
        increment_minutes(); // update number of minutes and degrees of minute servo
    }
    if (mDegrees == MAX_DEGREES) // if the servo is fully rotated
    {
        mDegrees = 0; // reset the position
    }
}

void increment_degrees_seconds_servo() // increment the number of degrees for the seconds servo
{
    servo_s.write(sDegrees); // set the position of servo
    sDegrees += 3;           // increase degrees by 3 to ensure full rotation of servo by one minute
}

void increment_degrees_minutes_servo() // increment the number of degrees for the minutes servo
{
    servo_m.write(mDegrees += 3); // set the position of servo, incrementing by 3
}

void print_output()
{
    Serial.print(minutes);       // print minutes
    Serial.print(" Minute(s) "); // print minutes message
    Serial.print(seconds);       // print seconds
    Serial.print(" Second(s)");  // print seconds message
    Serial.println();            // ensure next line is on a new line
}