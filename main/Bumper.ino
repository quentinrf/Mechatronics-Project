//FUNCTION TO RETURN 1 IF BUMPER ACTIVATED
int reactBumpers() {
  int react = digitalRead(3);
  if(react==0){
    return 1;
  }
  else return 0;
}

//FUNCTION TO PICK UP BALL WHEN BUMPER ACTIVATED
void wallHitPickUp(){
  while(true) {
  goStraight (HIGH);
  if(reactBumpers()==1){
    kill();
    reverseForTime(150);
    grab();
    delay(500);
    DefaultArmBall();
    delay(2000);
    break;
  }
}
}

//FUNCTION TO DROP BALL WHEN BUMPER ACTIVATED
void wallHitDrop(){
  while(true) {
  goStraight (HIGH);
  if(reactBumpers()==1){
    kill();
    dropBall();
    DefaultArm();
    delay(1000);
    break;
  }
}
reverseForTime (250);
}
