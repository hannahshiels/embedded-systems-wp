
// WP 6 Exercise 1 Template DIT 632

#define ENCA 2   //the pin for encoder A
#define ENCB 3   //The pin for encoder B
#define PWM1 9   //The pin for speed motor
#define PWM2 10  //The pin for rotation motor

int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal

void setup() {

    Serial.begin(9600); // Initialize serial
    
    // Set pin modes
    pinMode(ENCA,INPUT_PULLUP);
    pinMode(ENCB,INPUT_PULLUP);
    pinMode(PWM1,OUTPUT);
    pinMode(PWM2,OUTPUT);

    attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);  //interrupt for encoder a
    
    // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
    analogWrite(PWM2, 10);
    delay(1000); // TinkerCad bug
    analogWrite(PWM1, 10);
}

void loop() {
    // Stop the motor, but not to zero because then TinkerCad dies....
    analogWrite(PWM1, 10);
    delay(1000); // TinkerCad...bug
    analogWrite(PWM2, 10);

    deg = map(pos,0,2299,0,359);   //get the new degree after error handling of the tinker cad
    
    // Check if motor rotated all the way around, and reset counter
    if (pos > 2299){  //if the pulses are more than the total pulses ina  round
        deg = deg - 359;   //find and replace the corresponding value for the degree between 0-360
        pos = pos - 2299;   //find and replace the corresponding value for the position between 0-2300
    }
    if (pos < 0){       //same as above for negative positions
        deg = 359 + deg;
        pos = 2299 + pos;
    }

    // Print current position
    Serial.println("New input----------------------------------------------");
    serial_messages();

    // Get input
    degtarget = getInput();

    // Calculate initial error
    e = degtarget - deg;

    // Loop until error is zero
    while(e){

        // Map current position into degrees
        deg = map(pos,0,2299,0,359);

        // Get necessary speed signal
        speed = getAction(e);

        // Send speed signal to motor
        // Rotating clockwise
        if(speed >= 0){
            if (speed < 100) // motor does not react with too low inputs
                speed = 100;
            analogWrite(PWM2, 0); // Set to off
            analogWrite(PWM1, speed); // Set to 'speed'
        }

            // Rotating counter-clockwise
        else{
            if (-speed < 100) // motor does not react with too low inputs
                speed = -100; //set the speed to this value in case of too low speeds
            analogWrite(PWM1, 0); // Set to off
            analogWrite(PWM2, -speed); // Set to 'speed'
        }
        // Calculate new error
        e = -degtarget + deg;
        if (!e)                    //To stop the motor in case of reaching to the desired position
        {
            analogWrite(PWM2, 0);   //Stop the motor
        }
        //print out the error in each iteration
        Serial.println("The current error:   " + (String) e);

    }
    //print out the values
    serial_messages();

    delay(20);   //To increase performance. this shouldn't be increased too much otherwise tinker cad dies
}

// print current degree and motor position
void serial_messages()
{
    Serial.print("The current degree is: ");
    Serial.println(deg);
    Serial.print("The current position is: ");
    Serial.print(pos);
    Serial.print("\n");
}

int getInput(){

    int ready = 0;       //to check if all the characters in the serial are read
    char buf[3];        //the input will be saved here
    int input = -1;     //the input converted into an int value is stored in here

    Serial.print("Please enter the desired position: \n");  //ask for the user input

    while(!ready){      //while the length of the input is not 0
        ready = Serial.readBytes(buf,3);   //read the char in the input array
        input = atoi(&buf[0]);    //convert the char into int
    }

    //return the input value
    return input;
}

int getAction(int error){

    u_out = kp * error;  //Tune the value of motor speed using kp
    if (u_out > 254){ //u_out cannot be more than 255...
        return 255;
    }
    else if (u_out < -254){ //...or less than -254
        return -255;
    }
    else
        return u_out; // else set to calculated value
}

void ISR_readEncoder(){

    a = digitalRead(ENCA);    //Read the pin for encoder A only to fulfill WP description...
    b = digitalRead(ENCB);    //Read the pin for encoder B
    if(b > 0){                //If encoder B is already high it means the rotation is CW
        pos++;                  //add 1 to the position
    }
    else{                            //If encoder A is high and B is low it means the rotation is CCW
        pos--;                  //subtract 1 from the position
    }
}
