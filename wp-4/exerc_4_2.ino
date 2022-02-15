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

// declare variables
Servo servo_s; // servo for seconds
Servo servo_m; // servo for minutes
#define SERVO_S_PIN A0
#define SERVO_M_PIN A1
int sDegrees = 0; // degrees for seconds servo
int mDegrees = 0; // degrees for minutes servo
int seconds = 0;
int minutes = 0;

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
    update_seconds();                  // increment number of seconds and update minutes if need be
    delay(1000);                       // wait 1 second
}

void check_seconds() // check the seconds
{
    if (seconds == 60) // if the seconds are 60
    {
        seconds = 0;                       // reset number of seconds
        minutes++;                         // increment number of minutes
        increment_degrees_minutes_servo(); // increment minute servo
    }
}

void update_seconds()
{
    check_seconds(); // check if seconds need to be reset and update minutes if necessary
    seconds++;       // increment seconds
}

void reset_degrees()
{
    if (sDegrees == 180) // if the servo is fully rotated
    {
        sDegrees = 0; // reset the position
    }
    if (mDegrees == 180) // if the servo is fully rotated
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
    Serial.print(minutes); // print minutes
    Serial.print(":");     // print spacer
    Serial.print(seconds); // print seconds
    Serial.println();      // ensure next line is on a new line
}