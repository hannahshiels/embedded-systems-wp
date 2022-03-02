//Tinker cad link : https://www.tinkercad.com/things/b12WVXzj9o2-wp6exerc1/editel

//--------Defines-----
#define motorA 9      //The pin allocated to the motor responsible for speed
#define motorB 10     //The pin allocated to the motor responsible for the direction
#define ENCA 2        //The pin allocated to encoder A
#define ENCB 3        //The pin allocated to encoder B


//-------Variable Declaration--------
bool motorStarted = false;    //To check if the user has entered the required inputs already
int speedInput = 0;           //The variable that stores the speed input from the user
int directionInput = 0;       //The variable that stored the direction input from the user
int encoderA = 0;             //The reading from encoder A pin is stored here
int encoderB = 0;             //The reading from encoder B pin is stored here
int position = 0;             //The position of the motor is stored in here
int degree = 0;               //The position of the motor in degree

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
    fix_bug2();        //resolve tinker cad bug
    getInput();        //Ask users Input and save it
}

void loop() {

    if(!motorStarted)       //If the motor's speed and direction has not been set before
    {
        startMotor();       //Starts the motor with the user input
        motorStarted = true;//change the status so that this method is not called in the future iterations.(performance)
    }
    positionHandler();  //Handles the calculation related to degree and the position of the motor
    delay(20);                             //To improve performance?
}

void positionHandler()
{
    degree = map(position,0,2299,0,359);    //Map the corresponding angle for a position in the motor
    if (position > 2299){              //If the position is more than a whole round
        degree = degree - 359;         //calculate the equivalent angle in a circle for the degree more than 360
        position = position - 2299;    //calculate the equivalent position
    }
    if (position < 0){                 //If the position is negative
        degree = 359 + degree;         //calculate the equivalent positive degree for the angle
        position = 2299 + position;    //calculate the equivalent positive position
    }

    Serial.println("Position            |" + (String) position);          //Print out the position
    Serial.println("Position in degree  |" + (String) degree);  //Print out the degree

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

void startMotor()
{
    Serial.print("your speed input               |" + (String) speedInput);     //Debugging in the serial
    Serial.print("your rotation direction input  |" + (String)directionInput);  //Debugging in the serial
    analogWrite(motorA,speedInput);          //move the motor with a certain speed
    digitalWrite(motorB,directionInput);     //rotate the motor in a certain direction
}

void getInput()
{
    Serial.println("Please insert the speed of the motor (0-255):");             //prompt to the user
    while (Serial.available() == 0) {}                                           //Wait for the user to insert input
    speedInput = (int) Serial.parseInt();                                        //Save user input
    Serial.println("In which direction the motor will rotate? (CW: 0, CCW: 1)"); //prompt to the user
    while (Serial.available() == 0) {}                                           //Wait for the user to insert input
    directionInput = (int) Serial.parseInt();                                    //Save user input

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