#include "Stepper_28BYJ_48.h"

Stepper_28BYJ_48 stepper(11,10,9,8);

void setup() {

}

void loop() {  
  //stepper.setSpeed(5);
  stepper.step(1);
  //delay(2000);
  //stepper.step(-512);
  //delay(2000);

}
