

//--------Defines-----
#define motorA 9      //The pin allocated to the motor responsible for speed
#define motorB 10     //The pin allocated to the motor responsible for the direction

//-------Variable Declaration--------
int speedInput = 0;           //The variable that stores the speed input from the user
int directionInput = 0;       //The variable that stored the direction input from the user

//---------Main Body-------

void setup() {
    Serial.begin (9600);          //Initiate serial
    pinMode(motorA,OUTPUT);       //Set speed pin as output
    pinMode(motorB,OUTPUT);       //Set direction pin as output
    fix_bug();                    //resolve tinkercad bug
    fix_bug2();                   //resolve tinkercad bug
    getInput();                   //Ask users Input and save it
}

void loop() {

    Serial.println(speedInput);              //Debugging in the serial
    Serial.println(directionInput);          //Debugging in the serial
    analogWrite(motorA,speedInput);          //move the motor with a certain speed
    digitalWrite(motorB,directionInput);     //rotate the motor in a certain direction
    delay(1000);                             //To improve performance?
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

// Tinkercad bug fix 2
void fix_bug2() {
    // Stop the motor, but not to zero because then TinkerCad dies....
    analogWrite(motorA, 10);
    delay(1000);// TinkerCad...bug
    analogWrite(motorB, 10);
}