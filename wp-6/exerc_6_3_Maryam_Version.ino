//Tinker cad link : https://www.tinkercad.com/things/b12WVXzj9o2-wp6exerc1/editel

//--------Defines-----
#define motorA 9      //The pin allocated to the motor responsible for speed
#define motorB 10     //The pin allocated to the motor responsible for the direction
#define ENCA 2        //The pin allocated to encoder A
#define ENCB 3        //The pin allocated to encoder B


//-------Variable Declaration--------
bool motorStarted = false;    //To check if the user has entered the required inputs already
int degreeInput = 0;           //The variable that stores the desired degree input from the user
int encoderA = 0;             //The reading from encoder A pin is stored here
int encoderB = 0;             //The reading from encoder B pin is stored here
int position = 0;             //The position of the motor is stored in here
int degree = 0;               //The position of the motor in degree
int error = 0;                //The differentiation value between the current and desired degree is stored here
int kp = 5;                   //To tune the correction

//---------Main Body-------

void setup() {
    Serial.begin (9600);                 //Initiate serial
    pinMode(motorA,OUTPUT);              //Set speed pin as output
    pinMode(motorB,OUTPUT);              //Set direction pin as output
    pinMode(ENCA, INPUT_PULLUP);         //Set encoder pins as input
    pinMode(ENCB, INPUT_PULLUP);         //Set encoder pins as input
    attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);   //If the value of encoder A rises, this interrupt
    //is getting triggered
    fix_bug();         //resolve tinker cad bug
}

void loop() {
    fix_bug2();         //resolve tinker cad bug
    position = 0;
    degree = 0;
    getInput();         //Get the desired position from the user and store it
    error = degreeInput - degree;
    while (error)
    {
        speedHandler(error);           //Set the speed and rotation direction of the motor to get to the desired position
        positionHandler();             //Handles the calculation related to degree and the position of the motor
        error = +degreeInput - degree;  //get the current degree after turning on the motor
        if (!error)                    //To stop the motor in case of reaching to the desired position
        {
            analogWrite(motorA, 0);   //Stop the motor
        }
        Serial.println("err:  " + (String) error);  //Print out the error
//        delay(10);                             //To improve performance?
    }


}

void speedHandler(int speed)
{
    speed = kp * speed;    //tune the speed

    if (speed > 255 || (speed > 0 && speed < 100))       //if the speed value is more than a byte
    {
        speed = 100;       //set this as the speed value
    } else if (speed < -255 || (speed < 0 && speed > -100))  //if the speed value is more than a byte
    {
        speed = -100;         //set this as the speed value
    }

    if(speed < 0)           //if the rotation direction must be ccw
    {
        analogWrite(motorA, -speed);          //move the motor with this speed
        digitalWrite(motorB, 0);              //rotate the motor in a ccw direction
    } else                  //if the rotation direction must be cw
    {
        analogWrite(motorA, speed);          //move the motor with this speed
        digitalWrite(motorB, 1);             //rotate the motor in a cw direction
    }

}

void positionHandler()
{
    degree = map(position,0,2299,0,359);    //Map the corresponding angle for current position in the motor
    if (position > 2299){              //If the position is more than a whole round
        degree = degree - 359;         //calculate the equivalent angle in a circle for the degree more than 360
        position = position - 2299;    //calculate the equivalent position
    }
    if (position < 0){                 //If the position is negative
        degree = 359 + degree;         //calculate the equivalent positive degree for the angle
        position = 2299 + position;    //calculate the equivalent positive position
    }
    Serial.println("Position in degree  |" + (String) degree);            //Print out the degree

}

void readEncoder()
{
    encoderA = digitalRead(ENCA);    //Read the pin for encoder A only to fulfill WP description...
    encoderB = digitalRead(ENCB);    //Read the pin for encoder B
    if(encoderB > 0){                //If encoder B is already high it means the rotation is CW
        position++;                  //add 1 to the position
    }
    else{                            //If encoder A is high and B is low it means the rotation is CCW
        position--;                  //subtract 1 from the position
    }
}


void getInput()
{
    Serial.println("Please insert the desired position(0-359):");             //prompt to the user
    while (Serial.available() == 0) {}                                           //Wait for the user to insert input
    degreeInput = (int) Serial.parseInt();                                       //Save user input
}

void fix_bug() {
    // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
    analogWrite(motorB, 10);
    delay(1000);// TinkerCad bug
    analogWrite(motorA, 10);
}

// Tinker cad bug fix 2
void fix_bug2() {
    // Stop the motor, but not to zero because then TinkerCad dies....
    analogWrite(motorA, 10);
    delay(1000);// TinkerCad...bug
    analogWrite(motorB, 10);
}