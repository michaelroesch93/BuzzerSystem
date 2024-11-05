#ifndef DATATYPES_H
#define DATATYPES_H

#include "custom_datatypes.h"
#include "config.h"

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

extern TBuzzer *gaptBuzzerList[N_BUZZER];

void vInitBuzzerPin(TBuzzer *ptBuzzerPin);

void vReadFromInputPin(TBuzzer *ptBuzzer);

void vWriteToLEDPin(TBuzzer *ptBuzzer);

void vSetLEDState(TBuzzer *ptBuzzer, bool boOutputValue);

bool boIsBuzzerPressed(TBuzzer *ptBuzzer);

#endif
