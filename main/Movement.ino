#include "bluetooth.h"
//FUNCTION TO DRIVE ROBOT IN STRAIGHT LINE 
//CORRECTING BASED ON LINE TRACKER VARIABLES
void goStraight(bool dir) {
  getLines();
  checkBluetooth();
  digitalWrite(directionRight, dir);
  digitalWrite(directionLeft, dir);
  
  if (middleLine > lThresh) {
    straight();
  }
  else if (leftLine > lThresh) {
    left();
    lastMistake = 1;
  }
  else if (rightLine > lThresh) {
    right();
    lastMistake = 0;
  }
  else if ( leftLine < lThresh && middleLine < lThresh && rightLine < lThresh) {
    if (lastMistake == 0) {
      slightRight();
    }
    else {
      slightLeft();
    }
  }
}
//FUNCTION THAT DRIVES IN A STRAIGHT LINE
void straight() {
  analogWrite(powerLeft, straightLWheel);
  analogWrite(powerRight, straightRWheel);
}
//FUNCTION TO MAKE A SLIGHT LEFT TO CORRECT PATH
void slightLeft() {
  analogWrite(powerLeft, slight);
  analogWrite(powerRight, slightLeftRW);
}
//FUNCTINO TO MAKE A SLIGHT RIGHT TO CORRECT PATH
void slightRight() {
  analogWrite(powerLeft, slightRightLW);
  analogWrite(powerRight, slightRightRW);
}
//FUNCTINO TO MAKE A LEFT TO CORRECT PATH
void left() {
  analogWrite(powerLeft, leftLW);
  analogWrite(powerRight, leftRW);
}
//FUNCTINO TO MAKE A RIGHT TO CORRECT PATH
void right() {
  analogWrite(powerLeft, rightLW);
  analogWrite(powerRight, rightRW);
}
//FUNCTION TO KILL MOTOR POWER
void kill() {
  analogWrite(powerLeft, 0);
  analogWrite(powerRight, 0);
}
//FUNCTION TO TRAVEL A SINGLE BLOCK ON COMPETITION GRID
void IB(int blocks) {
      while (true) {
      goStraight(HIGH);
      int LC = getLinesCrossed();
      
      if (LC == 3) {
        passed = 1;
        Serial.println("Passed the line");
      }
      if (passed == 1) {
        delay(200);
        Serial.println("incremented one block");
        passed = 0; //reset for next time
        //BREAK OUT OF INCREMENT BLOCK WHEN AN INTERSECTION IS REACHED
        break;
      }
    }
  }
//FUNCTION TO THAT DETERMINES WHEN AN INTERSECTION OF TAPE HAS BEEN REACHED
int getLinesCrossed() {
  getLines();
  int LC = 0;
  if (leftLine > lThresh)
    LC++;

  if (middleLine > lThresh)
    LC++;

  if (rightLine > lThresh)
    LC++;
  Serial.print("Lines crossed:");
  Serial.println(LC);
  return LC;
}
//FUNCTION THAT RETURNS VALUES BASED ON LINE TRACKER READINGS 
void getLines() {
  leftLine = analogRead(lineLeftPin);
  middleLine = analogRead(lineMiddlePin);
  rightLine = analogRead(lineRightPin);
  Serial.println("Left");
  Serial.println(leftLine);
  //delay(2000);
  Serial.println("Middle");
  Serial.println(middleLine);
  //delay(2000);
  Serial.println("Right");
  Serial.println(rightLine);
  //delay(2000);
}
//FUNCTION THAT REVERSES THE ROBOT FOR A SPECIFIED TIME
void reverseForTime(int x) {
  digitalWrite(directionRight, LOW);
  digitalWrite(directionLeft, LOW);
  analogWrite(powerLeft, straightLWheel);
  analogWrite(powerRight, straightRWheel);
  delay(x);
  kill();
}
//FUNCTION THAT TURNS THE ROBOT 90 DEGREES
void turn(int angle, int pace) {
  delay(450);
  bool rightDir, leftDir;
  if (angle == 90) {
    rightDir = LOW;
    leftDir = HIGH;
  }
  if(angle == -90){
    //delay(250);
    rightDir = HIGH;
    leftDir = LOW;
  }
  digitalWrite(directionRight, rightDir);
  digitalWrite(directionLeft, leftDir);
  analogWrite(powerRight, pace);
  analogWrite(powerLeft, pace);
  //GET OFF THE LINES
  delay(600);
  while (true) {
    getLines();
    Serial.println(middleLine);
      if (middleLine > lThresh) {
        analogWrite(powerRight, 0);
        analogWrite(powerLeft,0);
        break;
      }
  }
}
