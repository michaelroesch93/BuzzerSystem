#include <Arduino.h>
#include "buzzer.h"
#include "config.h"

bool gboGameState = 0;


// put function declarations here:
int myFunction(int, int);

void setup() {
  // init of buzzer 
  for (int i = 0; i < N_BUZZER; i++) {
    vInitBuzzerPin(gaptBuzzerList[i]);
  }
}

void loop() {
  
  if (0 == gboGameState)
  {
    // read all inputs
    vReadFromInputPin(&gtBuzzerGreen);
    vReadFromInputPin(&gtBuzzerBlue);
    vReadFromInputPin(&gtBuzzerRed);
    vReadFromInputPin(&gtBuzzerYellow);
    vReadFromInputPin(&gtBuzzerWhite);
  }


  // process all inputs
  if (true == boIsBuzzerPressed(&gtBuzzerGreen)) {
    vSetLEDState(&gtBuzzerGreen, true);
  } else {
    vSetLEDState(&gtBuzzerGreen, false);
  }

  // write output pins
  vWriteToLEDPin(&gtBuzzerGreen);
  vWriteToLEDPin(&gtBuzzerBlue);
  vWriteToLEDPin(&gtBuzzerRed);
  vWriteToLEDPin(&gtBuzzerYellow);
  vWriteToLEDPin(&gtBuzzerWhite);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}