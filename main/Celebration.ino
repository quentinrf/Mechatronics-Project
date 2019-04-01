//FUNCTION TO MAKE ROBOT CELEBRATE WHEN DONE BALL COLLECTION
void celebrate(){
  digitalWrite(directionRight, LOW);
  digitalWrite(directionLeft, HIGH);
  analogWrite(powerRight, turnSpeed);
  analogWrite(powerLeft, turnSpeed);
  delay(6000);
  analogWrite(powerRight, 0);
  analogWrite(powerLeft, 0);
  while(true){
  gripServo.write(150);
  delay(250);
  gripServo.write(70);
  delay(250);
}
}

