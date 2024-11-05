#include <Arduino.h>
#include "buzzer.h"
#include "config.h"

bool gboGameState = 0;

void setup() {
  // init of buzzer 
  for (int i = 0; i < N_BUZZER; i++) {
    vInitBuzzerPin(gaptBuzzerList[i]);
  }

  // init reset pin
  pinMode(PIN_RESET, INPUT);

}

void loop() {
  
  // reset game state
  if (true == digitalRead(PIN_RESET)) gboGameState = 0;

  if (0 == gboGameState)
  {
    // read all inputs
    for (int i = 0; i < N_BUZZER; i++) {

      // read the switch pin
      vReadFromInputPin(gaptBuzzerList[i]);

      if (true == boIsBuzzerPressed(gaptBuzzerList[i])) 
      {
        vWriteToLEDPin(gaptBuzzerList[i]);
        gboGameState = 1;
      }      
    }
  }
}