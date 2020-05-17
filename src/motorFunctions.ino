void moveMotorL(float rate)
{
  int pwmVal = (int)(abs(rate)*maxPWM);
  if(rate > 0 )
  {
    digitalWrite(motorPinIn1L, HIGH);
    digitalWrite(motorPinIn2L, LOW);
  }
  else
  {
    digitalWrite(motorPinIn2L, HIGH);
    digitalWrite(motorPinIn1L, LOW);
  }
  analogWrite(motorPinPWML,pwmVal);
}

void moveMotorR(float rate)
{
  int pwmVal = (int)(abs(rate)*maxPWM);
  if(rate > 0 )
  {
    digitalWrite(motorPinIn1R, HIGH);
    digitalWrite(motorPinIn2R, LOW);
  }
  else
  {
    digitalWrite(motorPinIn2R, HIGH);
    digitalWrite(motorPinIn1R, LOW);
  }
  analogWrite(motorPinPWMR,pwmVal);
}

void moveMotors(float speedL, float speedR){
  moveMotorL(speedL);
  moveMotorR(speedR);
}

void moveStop()
{
  moveMotorL(0);
  moveMotorR(0);
}

void moveForward(float rate)
{
  moveMotors(rate,rate);
}

void moveBackward(float rate)
{
  moveMotors(-rate,-rate);
}

void moveLeft(float rate)
{
  moveMotors(-rate,rate);
}

void moveRight(float rate)
{
  moveMotors(rate,-rate);
}
