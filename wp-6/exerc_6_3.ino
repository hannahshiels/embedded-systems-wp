// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 6
// Exercise 3
// Submission code: xxxxxx
// Tinkercad link: https://www.tinkercad.com/things/1OUts8lO2KQ-wp6-ex3/editel?sharecode=0mj_UTuvpWQJf6feKJ-VngEFTXkAEOaM4D6IxQ3A4o0
#include <Adafruit_NeoPixel.h>
#include <Keypad.h>
#include <string.h> // for comparison of strings

// CONSTANTS
#define NUMBER_OF_PIXELS 24                                                                                                // The number of pixels in a neo pixel
#define NEO_PIN 2                                                                                                          // The digital pin that the neo pixel is connected through
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMBER_OF_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);                             // To use the neo library
const char *valid_addresses[8] = {"1AC91BD", "342824A", "6D1732B", "52A64AC", "413553A", "34246CC", "23B393B", "9999999"}; // list of valid addresses to accept

const int pairs[7][2] = {{20, 21}, {0, 23}, {2, 3}, {8, 9}, {11, 12}, {14, 15}, {17, 18}}; // segments of neopixels to turn on as we lock in

#define DIGIT_COUNT 7                  // amount of digits that can be entered
char digits_entered[DIGIT_COUNT] = {}; // keep track of digits entered
int currentAmtElements = 0;            // keep track of amount of elements entered in digits entered array

// CONSTANTS
const char ROWS = 4;    // row amount
const char COLUMNS = 4; // column amount
// configure possible KeyPad keys
const char KEYS[ROWS][COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// VARIABLES
byte R_PINS[ROWS] = {11, 10, 9, 8};                                      // Pins for keypad rows - B8-B11
byte C_PINS[COLUMNS] = {7, 6, 5, 4};                                     // Pins for keypad columns - D4-D7
Keypad keypad = Keypad(makeKeymap(KEYS), R_PINS, C_PINS, ROWS, COLUMNS); // KeyPad

void setup()
{
  pixels.begin();     // initialize the neopixel
  Serial.begin(9600); // begin serial monitor
}

void loop()
{
  if (currentAmtElements != DIGIT_COUNT) // if not all 7 digits have been entered
  {
    char pressedKey = keypad.getKey(); // get pressed key
    addKey(pressedKey);                // add key to array of all entered digits
  }
  else // otherwise
  {
    for (int i = 0; i < 24; i++) // loop through all LEDs in neopixel
    {
      setColor(i); // set the color of LEDs and turn the neo pixel on
      delay(50);   // add small delay between leds turning on
    }
    turnOffLeds();          // turn off all leds
    delay(100);             // wait 100 miliseconds
    lockIn();               // lock in on each of the segements of the neopixels
    delay(2500);            // wait 2 and half seconds after locking in is done
    currentAmtElements = 0; // reset amount of elements entered
    turnOffLeds();          // turn off all leds
  }
}

// add key entered to array and print it out
void addKey(char key)
{
  if (key != 0 && key != '#' && key != '*') // if key isn't empty, and is a character from the list of valid addresses
  {
    digits_entered[currentAmtElements] = key; // set key to current amount of elements in array
    currentAmtElements++;                     // increase current of amount of elements
    Serial.print("Key entered: ");            // print msg
    Serial.println(key);                      // print the pressed key
  }
}

// turn off all leds
void turnOffLeds()
{
  pixels.clear(); // clear all leds of color
  pixels.show();  // show clear effect on leds
}

// used for "locking in" to each segment
void lockIn()
{
  // for all segments that can be turned on
  for (int i = 0; i < 6; i++)
  {
    Serial.print("Locking on segment: "); // print msg
    Serial.println((i + 1));              // print segment num
    blink_segments(i, 255, 0, 0);         // blink current amount of segments
    turnOffLeds();                        // turn off all leds
    blink_segments(i, 255, 0, 0);         // blink current amount of segments
    delay(2000);                          // wait a bit
  }
  if (checkValidAddress() == 1) // if the address is valid
  {
    errorLights(); // show error animation if the entered digits entered do not match any valid address
  }
  else // otherwise
  {
    Serial.println("Valid address entered");  // print valid address msg
    Serial.println("Locking on segment: 7 "); // print msg
    turnOffLeds();                            // turn off all leds
    blink_segments(7, 255, 0, 0);             // blink current amount of segments
    turnOffLeds();                            // turn off leds
    blink_segments(6, 255, 0, 0);             // blink current amount of segments
  }
}

// blink segments of the neopixel
void blink_segments(int pair, int r, int g, int b)
{
  setSegmentsOn(pair, r, g, b);   // set on all leds in current segment
  pixels.show();                  // show pixels on neopixel
  delay(50);                      // wait a bit
  turnOffLeds();                  // turn off all leds
  delay(50);                      // wait a bit
  setSegmentsOn(pair, 255, 0, 0); // set on all leds in current segment
  pixels.show();                  // show pixels on neopixel
  delay(50);                      // wait a bit
}

// show error animation on neo pixel if entered address if wrong
void errorLights()
{
  Serial.println("Wrong address entered"); // print out error message
  for (int i = 0; i < 4; i++)              // blink all leds 3 times
  {

    blinkAllLedsRed(); // blink all leds red
    delay(150);        // wait a bit
  }
  turnOffLeds(); // turn off all leds
  delay(1000);   // wait a second
}

void blinkAllLedsRed() // turn on all leds red and turn off again
{
  turnOffLeds();                        // turn off all leds
  delay(50);                            // wait a bit
  pixels.fill(pixels.Color(255, 0, 0)); // set all leds red
  pixels.show();                        // show leds with new color
  delay(50);                            // wait a bit
}

// set on the colours of the current amount of segments on
void setSegmentsOn(int i, int r, int g, int b)
{
  for (int j = 0; j < i + 1; j++) // turn on all leds corresponding to the amount of segments currently added
  {
    pixels.setPixelColor(pairs[j][0], pixels.Color(r, g, b)); // set the LED color of first number in pair
    pixels.setPixelColor(pairs[j][1], pixels.Color(r, g, b)); // set the LED color of second number in pair
  }
}

int checkValidAddress()
{
  char enteredStr[8];                     // store string in this
  strncpy(enteredStr, digits_entered, 7); // convert digits entered char array to a string
  enteredStr[7] = '\0';                   // add null character as last element, so string is correctly compared
  for (int i = 0; i < 8; i++)             // loop through the number of valid addresses
  {
    if (strcmp(enteredStr, valid_addresses[i]) == 0) // compare the digits entered to the current valid address, if they match
    {
      return 0; // return 0 if strings match
    }
  }
  return 1; // return 1 if there is no match
}

void setColor(int i)
{
  int red = 0;   // store amount of red
  int green = 0; // store amount of green
  int blue = 0;  // store amount of blue

  if (i % 2 == 0) // if led is even
  {
    red = 255; // set amount of red
    green = 0; // set amount of green
    blue = 0;  // set amount of blue
  }
  else // otherwise
  {
    red = 0;    // set amount of red
    green = 0;  // set amount of green
    blue = 255; // set amount of red
  }

  pixels.setPixelColor(i, pixels.Color(red, green, blue)); // set led color
  pixels.show();                                           // turn on the neo pixel
}