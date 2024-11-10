#include <Arduino.h>
#include "buzzer.h"
#include "config.h"

bool gboGameState = 0;

void setup() {
  
  Serial.begin(9600);
  // debug
  Serial.write("Initializing... \n");
  // init of buzzer 
  for (int i = 0; i < N_BUZZER; i++) {
    vInitBuzzerPin(gaptBuzzerList[i]);
  }

  
  

  // init reset pin
  pinMode(PIN_RESET, INPUT);

  Serial.write("done \n");
}

void loop() {
  
  uint8_t ui8ValueGreen, ui8ValueBlue;

  ui8ValueGreen = (uint8_t) digitalRead(PIN_BUZZER_INPUT_GREEN);
  ui8ValueBlue = (uint8_t) digitalRead(PIN_BUZZER_INPUT_BLUE);


  digitalWrite(PIN_BUZZER_LED_GREEN, ui8ValueGreen);
  digitalWrite(PIN_BUZZER_LED_BLUE, ui8ValueBlue);
  
  #ifdef COMMENT_OUT

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
  #endif
}