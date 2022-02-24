// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 5
// Exercise 2
// Submission code: 836121

/**
 * Create a system based on Arduino Uno or Arduino Yun, which measures the temperature and lids the LEDs. You should use
 * 5 LEDs for the temperature measurement. The LEDs should be turned on depending on the temperature – e.g. for 0-10
 * degrees Celsius, 1 LED is turned on; for 11-20, 2 LEDs are turned on, and so on.
 **/


//-------Defines----------
#define CLOCK_SPEED 16000000// Clock speed of the Arduino Uno
#define PRESCALER 1024      // used for dictating speed of timer according to (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
#define INTERRUPT_FREQ 1    // define interrupt frequency
#define TEMPERATURE_PIN 0  // the pin that connects the temperature sensor to the board
#define BIT_RESOLUTION 10   // the resolution of the value that is read via analogue pin
#define VOLTAGE 5.0          // the voltage of the board

//-------Parameters----------
int timer = 0;        // The interrupt timer value is saved in this variable
float read = 0.0;     // The value that is measured by the sensor is saved here
float voltage = 0.0;  // The equivalent voltage value of the sensor read is saved here
float temperature = 0.0;   // The temperature degree in Celsius


// -----------Main -----------

//Initiate the program
void setup()
{
    timer_setup();     // To define a certain time for the program to be interrupted
    DDRB = DDRB | B00111110;  // Set the pins connected to LEDs as output
    Serial.begin(9600);
}

//This loop happens continuously while the program is running
void loop()
{
    //doesn't do anything really!
}

// Built on top of: https://www.instructables.com/Arduino-Timer-Interrupts/
// This sets up the timer to interrupt every second
void timer_setup()
{
    cli();           //stop interrupts

    //set timer1 interrupt at 1Hz
    TCCR1A = 0;      // set entire TCCR1A register to 0
    TCCR1B = 0;      // same for TCCR1B
    TCNT1  = 0;      //initialize counter value to 0

    // calculate at which point to stop the counter and set to int
    timer = (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;

    OCR1A = timer;                         // set compare match register for 1hz increments

    TCCR1B |= (1 << WGM12);                // turn on CTC mode
    TCCR1B |= (1 << CS12) | (1 << CS10);   // Set CS10 and CS12 bits for 1024 prescaler
    TIMSK1 |= (1 << OCIE1A);               // enable timer compare interrupt
    sei();                                 //allow interrupts
}

ISR(TIMER1_COMPA_vect)       //Interupt 1
{
    cli();         //Clears all previous interupts
    tempRead();    //Read the value from the temperature sensor
    handleLEDs();  //turns on Leds according to the temperature
    sei();         //Activates the interupt
}

void tempRead()
{
    read = analogRead(TEMPERATURE_PIN);   // Read the value from the temperature sensor
    voltage = read * VOLTAGE;             // convert the sensor read into voltage
    voltage /= (pow(2, BIT_RESOLUTION));  // the bit resolution
    voltage *= 1000;                               // convert to voltage into milli volt
    temperature = (voltage - 500.0) / 10.0;        // calculate the temperature in celsius
    Serial.println(temperature);                   // Print out the temperature
}

void handleLEDs()             //To set the LEDs on or off based on the temperature
{
    if (temperature < 25) {     //If the temperature is lower than 25 celsius
        PORTB = B00100000;      //Turn on the pin 13 on port B
    } else if (temperature >= 25 && temperature <26) {   //If the temperature is between 25 and 26
        PORTB = B00110000;                               //Turn on the pin 13and 12 on port B
    } else if (temperature >= 26 && temperature < 27) {  //If the temperature is between 26 and 27
        PORTB = B00111000;                               //Turn on the pin 13and 12 & 11 on port B
    } else if (temperature >= 27 && temperature < 28) {  //If the temperature is between 27 and 28
        PORTB = B00111100;                               //Turn on the pin 13and 12 & 11 & 10 on port B
    } else {               //If the temperature is more than 28
        PORTB = B00111110; //Turn on the pin 13and 12 & 11 & 10 & 9 on port B
    }
}
