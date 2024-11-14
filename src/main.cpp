#include <Arduino.h>
#include "config.h"

bool gboGameRunning = true;

void setup() {
  
  Serial.begin(9600);
  // debug
  Serial.write("Initializing... \n");

  // init inputs
  pinMode(PIN_BUZZER_INPUT_GREEN, INPUT_PULLUP);
  pinMode(PIN_BUZZER_INPUT_BLUE, INPUT_PULLUP);
  pinMode(PIN_BUZZER_INPUT_RED, INPUT_PULLUP);
  pinMode(PIN_BUZZER_INPUT_YELLOW, INPUT_PULLUP);
  // init outputs
  pinMode(PIN_BUZZER_LED_GREEN, OUTPUT);
  pinMode(PIN_BUZZER_LED_BLUE, OUTPUT);
  pinMode(PIN_BUZZER_LED_RED, OUTPUT);
  pinMode(PIN_BUZZER_LED_YELLOW, OUTPUT);
  // init reset pin
  pinMode(PIN_RESET, INPUT_PULLUP);

  Serial.write("done \n");
}

void loop() {
  
  bool boInputReset = true;
  bool boBuzzerGreen = true;
  bool boBuzzerBlue = true;
  bool boBuzzerRed = true;
  bool boBuzzerYellow = true;

  if (true == gboGameRunning) {

    boBuzzerGreen = (uint8_t) digitalRead(PIN_BUZZER_INPUT_GREEN);
    boBuzzerBlue = (uint8_t) digitalRead(PIN_BUZZER_INPUT_BLUE);
    boBuzzerRed = (uint8_t) digitalRead(PIN_BUZZER_INPUT_RED);
    boBuzzerYellow = (uint8_t) digitalRead(PIN_BUZZER_INPUT_YELLOW);


    digitalWrite(PIN_BUZZER_LED_GREEN, !boBuzzerGreen);
    digitalWrite(PIN_BUZZER_LED_BLUE, !boBuzzerBlue);
    digitalWrite(PIN_BUZZER_LED_RED, !boBuzzerRed);
    digitalWrite(PIN_BUZZER_LED_YELLOW, !boBuzzerYellow);
  
  }

  // end game
  if (boBuzzerGreen == false) gboGameRunning = false;
  if (boBuzzerBlue == false) gboGameRunning = false;
  if (boBuzzerRed == false) gboGameRunning = false;
  if (boBuzzerYellow == false) gboGameRunning = false;

  // process reset
  boInputReset = (uint8_t) digitalRead(PIN_RESET);
  if (boInputReset == 0) gboGameRunning = true;

  if (boBuzzerRed == 0) {
    Serial.write("o");
  } else {
    Serial.write("x");
  }
  
}