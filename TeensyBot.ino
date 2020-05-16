
// IR Remote library from: https://github.com/z3t0/Arduino-IRremote
#include <IRremote.h>
#include <IRremoteInt.h>

#define trigPin  0
#define echoPin  3
// Right arrow button on LG remote
#define IR_Right 0x20DF609F
// Left arrow button on LG remote
#define IR_Left  0x20DFE01F
// Up arrow button on LG remote
#define IR_Up    0x20DF02FD
// Down arrow button on LG remote
#define IR_Down  0x20DF827D
// OK button on LG remote
#define IR_Auto  0x20DF22DD
// Stop button on LG remote
#define IR_Stop 0x20DF8D72

int RECV_PIN = 23;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define motorPinIn1R  17
#define motorPinIn2R  19
#define motorPinPWMR  15
#define motorPinIn1L  14
#define motorPinIn2L  13
#define motorPinPWML  4

#define maxPWM  200
boolean autoMode = false;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPinIn1L, OUTPUT);
  pinMode(motorPinIn2L, OUTPUT);
  pinMode(motorPinPWML, OUTPUT);
  pinMode(motorPinIn1R, OUTPUT);
  pinMode(motorPinIn2R, OUTPUT);
  pinMode(motorPinPWMR, OUTPUT);
  
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  //Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    if(results.value == IR_Auto)
    {
      autoMode = !autoMode;
      moveStop();
      delay(400);
      Serial.println("Auto mode changed");
    }
    else if(!autoMode)
    {    
      if(results.value == IR_Up)
      {
       moveForward(0.5); 
        Serial.println("Up Pressed");
      }
      else if(results.value == IR_Down)
      {
        moveBackward(0.5);
        Serial.println("Down Pressed");
      }
      else if(results.value == IR_Left)
      {
        moveLeft(0.5);
        Serial.println("Left Pressed");
      }
      else if(results.value == IR_Right)
      {
        moveRight(0.5);
        Serial.println("Right Pressed");
      }
      else if(results.value == IR_Stop)
      {
        moveStop();
        Serial.println("Stop Pressed");
      }
      else if(results.value != IR_Auto)
      {
        Serial.println("Unknown command received:");
        Serial.println(results.value, HEX);
      }
    }
    irrecv.resume(); // Receive the next value
    delay(200);
  }
  else if(autoMode)
  {
    if(getDistance() < 10)
    {
     moveRight(0.5);
     delay(400); 
    }
    else
    {
     moveForward(0.5); 
    }
  }
}

int getDistance(){
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return (duration/2) / 29.1;
}  
