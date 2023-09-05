#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper stepperTwo(stepsPerRevolution, 7, 6, 5, 3);

char command;
 
void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  // set the speed at 60 rpm:
  myStepper.setSpeed(120);
  stepperTwo.setSpeed(120);
  // initialize the serial port:
  Serial.begin(9600); 
}
 
void loop() {
  //myStepper.step(200);
  //stepperTwo.step(200);
  //if (Serial.available()) { 
    command = Serial.read();
    if (command == 'd') { 
     //Serial.println("clockwise");
     myStepper.step(40);
    }
    else if (command == 'a') { 
     //Serial.println("counterclockwise");
     myStepper.step(-40);
    }
    else if (command == 'w') { 
     //Serial.println("clockwise");
     stepperTwo.step(40);
    }
    else if (command == 's') { 
     //Serial.println("counterclockwise");
     stepperTwo.step(-40);
    }
  
  //}  
}