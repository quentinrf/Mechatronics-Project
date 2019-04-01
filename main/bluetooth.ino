#include "bluetooth.h"
//FUNCTION TO CHECK FOR BLUETOOTH CONNECTION
//CALLS KILL, S1, S2 OR S3 BASED ON INPUT
void checkBluetooth() {
	int checkAvailable = Serial.available();
	int checkRead = Serial.read();
	if (checkAvailable > 0 && checkRead == 'K') {
		killB(0, 0);
    while(true){
      int checkAvailable = Serial.available();
      int checkRead = Serial.read();
      if(checkAvailable>0 && checkRead == 'G'){
        break;
        delay(100);
      }
    }
	}
 if (checkAvailable > 0 && checkRead == 'L') {
  start = '0';
 }
 else if (checkAvailable > 0 && checkRead == 'M') {
  start = '1';
 }
 else if (checkAvailable > 0 && checkRead == 'R')
  start = '2';
}
