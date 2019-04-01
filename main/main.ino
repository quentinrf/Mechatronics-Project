//IR RECEIVER LIBRARY + VARIABLES
#include "QSerial.h"
QSerial myIRserial;
char start;

//--------MOTOR--------//
//MOTOR PIN DEFINITIONS
#define turnSpeed 95
#define directionRight 4
#define powerRight 5
#define directionLeft 7
#define powerLeft 6

//MOTOR POWER VALUES
int straightRWheel = 95; //known straight right value
int straightLWheel = 95; // known straight left value

//------SERVO ARM------//
//SERVO LIBRARY
#include <Servo.h>

//SERVO PIN DEFINITIONS
#define tiltServoPin 8 
#define gripServoPin 10 
#define panServoPin 9 

//SERVO VARIABLES
Servo gripServo, tiltServo, panServo;

//------LINE TRACKER------//

//lINE TRACKER PIN DEFINITIONS
#define lineRightPin A4
#define lineMiddlePin A5
#define lineLeftPin A3

//LINE TRACKER THRESHOLD
#define lThresh 900 //Quentin's robot

//LINE TRACKER VARIABLES
int leftLine, middleLine, rightLine, backLine = 0;

//VARIABLES FOR SIGNIFICANT LINE CORRECTION
int leftLW = straightLWheel-20;
int leftRW = straightRWheel+20;
int rightLW = straightLWheel+20;
int rightRW = straightRWheel-20;

//VARIABLES FOR SLIGHT LINE CORRECTION 
int slightLeftLW = straightLWheel-10;
int slightLeftRW = straightRWheel+10;
int slightRightLW = straightLWheel+10;
int slightRightRW = straightRWheel-10;

//VARIABLE LAST MISTAKE USED FOR LINE TRACKER CORRECTIONS 
int lastMistake = 0;

//VARIABLE TO COUNT WHEN A CROSSED LINE IS PASSED
int passed = 0; //to indicate when the horz line has been passed

void setup() {
  
  //IR RECEIVER PIN ASSIGNMENT
  myIRserial.attach(2, -1);
  //BLUETOOTH AND IR RECEIVER DATA RATE DEFINITION
  Serial.begin(9600);
  
  //SERVO VARIABLE PIN ASSIGNMENT
  gripServo.attach(gripServoPin); //attaches pin to grip
  tiltServo.attach(tiltServoPin); //attaches pin to tilt
  panServo.attach(panServoPin); //attaches pin to pan

  //MOTOR DIRECTION PIN ASSIGNMENT
  pinMode(directionRight, INPUT);
  pinMode(directionLeft, INPUT);

  //MOTOR POWER PIN ASSIGNMENT
  pinMode(powerRight, INPUT);
  pinMode(powerLeft, INPUT);

  //IR LINE TRACKER PIN ASSIGNMENT
  pinMode(lineRightPin, INPUT);
  pinMode(lineMiddlePin, INPUT);
  pinMode(lineLeftPin, INPUT);
  
  //DEFAULT SERVO POSITION
  gripServo.write(100);
  tiltServo.write(90);
  panServo.write(93); 
}


void loop() {
  //IR RECEIVER FOR STARTING POSITION AND PATH DECISION
  int val = myIRserial.receive(200);
  if (val > 0) {
    //TYPE CAST IF ASCII CODE IS GREATER THAN 0
    char value = (char)val;
    //IF TYPECASTED VALUE EQUALS ZERO RUN PATH 1 CODE
    if(value=='0'){
    S1_1();
    S1_2();
    S1_3();
    S1_4();
    S1_5();
    celebrate();
    }
    //IF TYPECASTED VALUE EQUALS ONE RUN PATH 1 CODE
    else if(value =='1'){
    S2_1();
    S2_2();
    S2_3();
    S2_4();
    S2_5();
    celebrate();
    }
    //IF TYPECASTED VALUE EQUALS TWO RUN PATH 1 CODE
    else if(value == '2'){
    S3_1();
    S3_2();
    S3_3();
    S3_4();
    S3_5();
    celebrate();
    }
  }
}
