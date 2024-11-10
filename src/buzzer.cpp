#include "buzzer.h"
#include "config.h"
#include "Arduino.h"
#include "custom_datatypes.h"


TBuzzer gtBuzzerGreen    = {PIN_BUZZER_INPUT_GREEN, PIN_BUZZER_LED_GREEN, false, false};
TBuzzer gtBuzzerBlue     = {PIN_BUZZER_INPUT_BLUE, PIN_BUZZER_LED_BLUE, false, false};
TBuzzer gtBuzzerRed      = {PIN_BUZZER_INPUT_RED, PIN_BUZZER_LED_RED, false, false};
TBuzzer gtBuzzerYellow   = {PIN_BUZZER_INPUT_YELLOW, PIN_BUZZER_LED_YELLOW, false, false};
TBuzzer gtBuzzerWhite    = {PIN_BUZZER_INPUT_WHITE, PIN_BUZZER_LED_WHITE, false, false};

TBuzzer *gaptBuzzerList[N_BUZZER] = {&gtBuzzerGreen, &gtBuzzerBlue, &gtBuzzerRed, &gtBuzzerYellow, &gtBuzzerWhite};

void vInitBuzzerPin(TBuzzer *ptBuzzer)
{
    // init input pin
    pinMode(ptBuzzer->iPinInputSwitch, INPUT);
    // init led output pin
    pinMode(ptBuzzer->iPinOutputLED, OUTPUT);
}

void vReadFromInputPin(TBuzzer *ptBuzzer)
{
    ptBuzzer->boStateSwitchInput = digitalRead(ptBuzzer->iPinInputSwitch);
}

void vWriteToLEDPin(TBuzzer *ptBuzzer)
{
    digitalWrite(ptBuzzer->iPinOutputLED, ptBuzzer->boStateLEDOutput);
}

void vSetLEDState(TBuzzer *ptBuzzer, bool boOutputValue)
{
    ptBuzzer->boStateLEDOutput = boOutputValue;
}

bool boIsBuzzerPressed(TBuzzer *ptBuzzer)
{
    return ptBuzzer->boStateSwitchInput;
}