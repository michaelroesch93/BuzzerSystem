#include <Arduino.h>
#include "config.h"

bool gboGameRunning = true;

void setup() {
  
  Serial.begin(9600);
  // debug
  Serial.write("Initializing... \n");

  // init inputs
  pinMode(PIN_BUZZER_INPUT_GREEN, INPUT);
  pinMode(PIN_BUZZER_INPUT_BLUE, INPUT);
  pinMode(PIN_BUZZER_INPUT_RED, INPUT);
  pinMode(PIN_BUZZER_INPUT_YELLOW, INPUT);
  pinMode(PIN_BUZZER_INPUT_WHITE, INPUT);
  // init outputs
  pinMode(PIN_BUZZER_LED_GREEN, OUTPUT);
  pinMode(PIN_BUZZER_LED_BLUE, OUTPUT);
  pinMode(PIN_BUZZER_LED_RED, OUTPUT);
  pinMode(PIN_BUZZER_LED_YELLOW, OUTPUT);
  pinMode(PIN_BUZZER_LED_WHITE, OUTPUT);
  // init reset pin
  pinMode(PIN_RESET, INPUT);

  Serial.write("done \n");
}

void loop() {
  
  bool boInputReset = false;
  bool boBuzzerGreen = false;
  bool boBuzzerBlue = false;
  bool boBuzzerRed = false;
  bool boBuzzerYellow = false;
  bool boBuzzerWhite = false;

  if (true == gboGameRunning) {

    boBuzzerGreen = (uint8_t) digitalRead(PIN_BUZZER_INPUT_GREEN);
    boBuzzerBlue = (uint8_t) digitalRead(PIN_BUZZER_INPUT_BLUE);
    boBuzzerRed = (uint8_t) digitalRead(PIN_BUZZER_INPUT_RED);
    boBuzzerYellow = (uint8_t) digitalRead(PIN_BUZZER_INPUT_YELLOW);
    boBuzzerWhite = (uint8_t) digitalRead(PIN_BUZZER_INPUT_WHITE);


    digitalWrite(PIN_BUZZER_LED_GREEN, boBuzzerGreen);
    digitalWrite(PIN_BUZZER_LED_BLUE, boBuzzerBlue);
    digitalWrite(PIN_BUZZER_LED_RED, boBuzzerRed);
    digitalWrite(PIN_BUZZER_LED_YELLOW, boBuzzerYellow);
    digitalWrite(PIN_BUZZER_LED_WHITE, boBuzzerWhite);
  
  }

  // end game
  if (boBuzzerGreen == true) gboGameRunning = false;
  if (boBuzzerBlue == true) gboGameRunning = false;
  if (boBuzzerRed == true) gboGameRunning = false;
  if (boBuzzerYellow == true) gboGameRunning = false;
  if (boBuzzerWhite == true) gboGameRunning = false;

  // process reset
  boInputReset = (uint8_t) digitalRead(PIN_RESET);
  if (boInputReset != 0) gboGameRunning = true; 

}