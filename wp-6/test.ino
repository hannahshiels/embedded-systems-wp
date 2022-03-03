// WP 6 Exercise 1 Template DIT 632

#define ENCA 2
#define ENCB 3
#define PWM1 9
#define PWM2 10

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

    Serial.begin(9600);
    pinMode(ENCA,INPUT_PULLUP);
    pinMode(ENCB,INPUT_PULLUP);
    pinMode(PWM1,OUTPUT);
    pinMode(PWM2,OUTPUT);

    /*
    ==> TO DO TO DO TO DO
    ATTACH INTERRUPT HERE.
    */
    attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);
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

    // Check if motor rotated all the way around, and reset counter
    if (pos > 2299){
        deg = deg - 359;
        pos = pos - 2299;
    }
    if (pos < 0){
        deg = 359 + deg;
        pos = 2299 + pos;
    }

    // Print current position
    Serial.print("The current position is: ");
    Serial.print(deg);
    Serial.print("\n");

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
            analogWrite(PWM2, 0);
            analogWrite(PWM1, speed);
        }

            // Rotating counter-clockwise
        else{
            if (-speed < 100) // motor does not react with too low inputs
                speed = -100;
            analogWrite(PWM1, 0);
            analogWrite(PWM2, -speed);
        }

        Serial.println(deg);
        //deg = map(pos,0,2299,0,359);
        // Calculate new error
        e = -degtarget + deg;
        if (!e)                    //To stop the motor in case of reaching to the desired position
        {
            analogWrite(PWM2, 0);   //Stop the motor
        }
    }
}

int getInput(){

    int ready = 0;
    char buf[3];
    int input = -1;

    Serial.print("Please enter the desired position: \n");

    while(!ready){
        ready = Serial.readBytes(buf,3);
        input = atoi(&buf[0]);
    }

    return input;
}

int getAction(int error){
    /*
    ==> TO DO TO DO TO DO
    Calculate u_out as function of the error and the kp (tuning parameter).
    */

    u_out = kp * error;
    if (u_out > 254){ //u_out cannot be more than 255...
        return 255;
    }
    else if (u_out < -254){ //...or less than -254
        return -255;
    }
    else
        return u_out;
}

void ISR_readEncoder(){
    /*
    ==> TO DO TO DO TO DO
    READ THE ENCODER SIGNAL HERE.
    Read the encoder signals and increase or decrease pos accordingly.
    */
    a = digitalRead(ENCA);    //Read the pin for encoder A only to fulfill WP description...
    b = digitalRead(ENCB);    //Read the pin for encoder B
    if(b > 0){                //If encoder B is already high it means the rotation is CW
        pos++;                  //add 1 to the position
    }
    else{                            //If encoder A is high and B is low it means the rotation is CCW
        pos--;                  //subtract 1 from the position
    }
}