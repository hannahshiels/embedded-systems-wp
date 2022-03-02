// WP 6 Exercise 1 Template DIT 632

// DEFINE
#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6
#define DATA_RATE 9600// Serial data rate
#define MAX_INPUT 3   // Max allowed input

// VARIABLES
int a = 0;        // a-encoder signal
int b = 0;        // b-encoder signal
int pos = 0;      // Position in ticks
int deg = 0;      // Position in degrees
float pwr = 0;    // power/speed of motor
int dir = 0;      // direction of motor
int e = 0;        // error
float u = 0;      // output of controller
int degtarget = 0;// Target position in degrees

// CONST
// PID constants, proportional
const int KP = 5;// Proportional constant for controller (tuning parameter)
const char ENTER_DEGREES[] = "Please enter the desired position in degrees: ";

void setup() {
   Serial.begin(DATA_RATE);// begin serial

   // set pin modes
   pinMode(ENCA, INPUT_PULLUP);
   pinMode(ENCB, INPUT_PULLUP);
   pinMode(PWM1, OUTPUT);
   pinMode(PWM2, OUTPUT);

   // attach interrupt for motor encoder ENCA
   attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);

   tinkercad_bugfix1();// Deal with tinkercad bug
}

void loop() {
   tinkercad_bugfix2();// Deal with tinkercad bug

   // Print the current motor position
   Serial.print("The current position is: ");
   Serial.print(deg);
   Serial.print("\n");

   degtarget = getInput();// Stop and wait for user serial input
   e = degtarget - deg;   // Calculate initial error
   activate_motor();      // activate motor
   check_pos();           // check motor position
}

int getInput() {

   int ready = 0;      // boolean for whether input has been read
   char buf[MAX_INPUT];// input buffer
   int input = 0;      // store input

   // Input prompt
   Serial.println("Please enter the desired position in degrees: ");

   while (!ready) {                            // while ready = 0
      ready = Serial.readBytes(buf, MAX_INPUT);// read the serial input
      input = atoi(&buf[0]);                   // convert the input to integer
   }
   Serial.print((String) input + "\n");// print the input

   return input;
}

// handle motor logic
void activate_motor() {
   while (e) {                        // Loop until error is zero
      deg = map(pos, 0, 2299, 0, 359);// Map position to degrees
      e = degtarget - deg;            // Calculate the new error
      calculate_motor();              // Calculate motor variables
      setMotor(dir, pwr, PWM1);       // Send speed signal to motor

      // Print motor target and current position in degrees
      print_motor();
   }
}

// calculate motor variables
void calculate_motor() {
   u = KP * e;// calculate control signal

   // set motor power
   pwr = fabs(u);  // set power to positive value of u
   if (pwr > 255) {// can't set power greater than 255
      pwr = 255;   // set to 255
   }

   // set motor direction
   dir = 1;    // direction set to 1
   if (u < 0) {// if the control signal is less than 0
      dir = -1;// set direction to -1
   }
}

// set the motor based on direction and power
void setMotor(int dir, int pwmValue, int pwm) {
   analogWrite(pwm, pwmValue);// write the pulsewave pwmValue to pwn

   if (dir == 1) {             // if positive direction
      digitalWrite(PWM1, HIGH);// set pin to HIGH
      digitalWrite(PWM2, LOW); // set pin to LOW
   } else if (dir == -1) {     // if negative direction
      digitalWrite(PWM1, LOW); // set pin to LOW
      digitalWrite(PWM2, HIGH);// set pin to HIGH
   } else {
      digitalWrite(PWM1, LOW);// set pin to LOW
      digitalWrite(PWM2, LOW);// set pin to LOW
   }
}

// print motor target and current position
void print_motor() {
   Serial.print("Target: ");
   Serial.print(degtarget);
   Serial.print(" ");
   Serial.print("| Current: ");
   Serial.print(deg);
   Serial.println();
}

void check_pos() {
   // Check if motor rotated all the way around, and reset counter
   if (pos > 2299) {   //If the position is more than a whole round
      deg = deg - 359; //calculate the equivalent angle in a circle for the degree more than 360
      pos = pos - 2299;//calculate the equivalent position
   }
   if (pos < 0) {      //If the position is negative
      deg = 359 + deg; //calculate the equivalent positive degree for the angle
      pos = 2299 + pos;//calculate the equivalent positive position
   }
}

// interrupt to read the ENCB encoder
void ISR_readEncoder() {
   b = digitalRead(ENCB);// Read ENCB
   if (b > 0) {          // If the pin is set to HIGH
      pos++;             // Increase position
   } else {
      pos--;// decrease position; i.e. if pin is set to LOW
   }
}

void tinkercad_bugfix1() {
   // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
   analogWrite(PWM2, 10);
   delay(1000);// TinkerCad bug
   analogWrite(PWM1, 10);
}

void tinkercad_bugfix2() {
   // Stop the motor, but not to zero because then TinkerCad dies....
   analogWrite(PWM1, 10);
   delay(1000);// TinkerCad...bug
   analogWrite(PWM2, 10);
}
