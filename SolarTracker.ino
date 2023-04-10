
#include <Stepper.h> //stepper library

const int pwm = 6 ;  //initializing pin 2 as pwm
const int DcIn = 13 ; //initializing pin 2 as pwm
const int DcIn2 = 12 ; //initializing pin 2 as pwm


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for stepper

// initialisng the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
  ///////////////////////////////////
  pinMode(pwm, OUTPUT) ;  //we have to set PWM pin as output
  pinMode(DcIn, OUTPUT) ; //Logic pins are also set as output
  pinMode(DcIn2, OUTPUT) ;

  ////////////////////////////////////
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop()
{
  // step one revolution  in one direction:
 // StepClockwise();
 // StepAntiClockwise();

//
  DcClockwise();
  DcAntiClockwise();
}


void ldrdetection()
{



}




void StepClockwise()
{
  Serial.println("Clockwise Step");
  myStepper.step(stepsPerRevolution);
  delay(500);
}

void StepAntiClockwise()
{
  Serial.println("Anticlockwise Stepper");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

void DcClockwise() 
{
  /*setting pwm of the motor to 255
    we can change the speed of rotaion
    by chaning pwm input but we are only
    using arduino so we are using higest
    value to driver the motor  */
  //For Clock wise motion , DcIn = High , DcIn2 = Low
  Serial.println("Clockwise DC");
  digitalWrite(DcIn, HIGH) ;
  digitalWrite(DcIn2, LOW) ;
  analogWrite(pwm, 150) ;
  //delay time 3 seconds
  delay(1000) ;

}


void DcAntiClockwise() 
{
  //For Anti Clock-wise motion - DcIn = LOW , DcIn2 = HIGH
  Serial.println("Anticlockwise DC");
  digitalWrite(DcIn, LOW) ;
  digitalWrite(DcIn2, HIGH) ;
  //delay time 3 seconds
  delay(1000);
}

void DcBreak() 
{
  //For brake
  digitalWrite(DcIn, HIGH) ;
  digitalWrite(DcIn2, HIGH) ;
  delay(1000) ;

}
