#include <Arduino.h>
#include "buzzer.h"
#include "config.h"


// put function declarations here:
int myFunction(int, int);

void setup() {
  // init of buzzer 
  vInitBuzzerPins(&gtBuzzerGreen);
  vInitBuzzerPins(&gtBuzzerBlue);
  vInitBuzzerPins(&gtBuzzerRed);
  vInitBuzzerPins(&gtBuzzerYellow);
  vInitBuzzerPins(&gtBuzzerWhite);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}