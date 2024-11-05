#ifndef DATATYPES_H
#define DATATYPES_H

#include "custom_datatypes.h"

typedef struct {
    int iPinInputSwitch;
    int iPinOutputLED;
    bool boStateSwitchInput;
    bool boStateLEDOutput;
} TBuzzer;

extern TBuzzer gtBuzzerGreen;
extern TBuzzer gtBuzzerBlue;
extern TBuzzer gtBuzzerRed;
extern TBuzzer gtBuzzerYellow;
extern TBuzzer gtBuzzerWhite;

void vInitBuzzerPins(TBuzzer *ptBuzzerPin);

void vReadFromInputPin(TBuzzer *ptBuzzer);

void vWriteToLEDPin(TBuzzer *ptBuzzer);

void boSetLEDState(TBuzzer *ptBuzzer, bool boOutputValue);

bool boIsBuzzerPressed(TBuzzer *ptBuzzer);

#endif
