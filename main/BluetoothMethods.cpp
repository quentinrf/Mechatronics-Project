#include "Arduino.h"
#include "bluetooth.h"
//bluetooth Kill function
void killB(int powerLeft, int powerRight) {
	analogWrite(powerLeft, 0);
	analogWrite(powerRight, 0);
}




