//Created 21 Apr. 2019
//by Sacha Hussey
 
const int buttonPin = 2;
int buttonState = 0;
int Steps=4096; //This is the number of steps for the stepper motor to do one rotation. This was calculated through the gear ratio and stride angle of the motor. 
int Inc = 4096/32 //This is number of the steps the motor takes between increments. 

#include <Stepper.h> // Arduino stepper library initialised to control the 28BYJ-48 stepper motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // Initialize the stepper library on pins 8 through 11:
const int Steps = ;  // change this to fit the number of steps per revolution for your motor


#include <Servo.h> // Arduino stepper library initialised to control the HXT900 micro servo
Servo myServo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0; // variable to store the servo position
int i = 0;

void setup() {
  myStepper.setSpeed(20); // set the speed at 60 rpm
  Serial.begin(9600); // Initialize the serial port
  myservo.attach(7);  // Attaches the servo on pin 7 to the servo object
  pinMode(buttonPin, INPUT);
 
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){ //The button is on 
    while (true) {
      if ((i % 2) == 0){
        for (pos = 0; pos <= 180; pos += 1) { // The servo motor moves 180 degrees in steps of 1 degree
        myServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(500);                       // Wait for the servo to reach the position
        }
      }
      if ((i % 2) != 0){
        for (pos = 180; pos >= 0; pos -= 1) { // The servo motor moves from 180 degrees to 0 degrees
           myServo.write(pos);              // Tell servo to go to position in variable 'pos'
           delay(500);                       // Wait for the servo to reach the position
        }
      }
      myStepper.step(17*Inc) //This makes the stepper motor move 17 increments. When the stepper motor moves this amount continuously, the pattern is formed.  
      delay(500);
    }
  }
}



  
