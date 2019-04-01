//FUNCTION TO GRAB BALL WHEN WALL HIT
void grab(){
  int defaultTilt = 70;
  int pickupTilt = 48;
  tiltServo.write(pickupTilt);
  delay(1000);
  gripServo.write(150);
  }
//FUNCTION FOR DEFAULT BALL HOLD
void DefaultArmBall(){
  gripServo.write(150);
  tiltServo.write(90);
  panServo.write(93);
}
//FUNCTION FOR DEFAULT POSITION-NO BALL
void DefaultArm(){
  gripServo.write(100);
  tiltServo.write(70);
  panServo.write(93);
}
//FUNCTION TO DROP BALL
void dropBall(){
  //To do : program the arm to drop the ball 
    tiltServo.write(150);
    delay(1000);
    tiltServo.write(40);
    delay(18);
    gripServo.write(70);
}
