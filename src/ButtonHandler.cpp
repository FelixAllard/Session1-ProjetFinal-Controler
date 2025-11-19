//
// Created by dan23 on 19/11/2025.
//

#include "ButtonHandler.h"
#include <librobus.h>

bool ButtonA_WasPressed = false;
bool ButtonB_WasPressed = false;
bool ButtonC_WasPressed = false;
bool ButtonD_WasPressed = false;

void InitializeButtons() {
    pinMode(pinButtonA, INPUT_PULLUP);
    pinMode(pinButtonB, INPUT_PULLUP);
    pinMode(pinButtonC, INPUT_PULLUP);
    pinMode(pinButtonD, INPUT_PULLUP);
}

void UpdateButtonStatus() {
    if (digitalRead(pinButtonA) == LOW)
        ButtonA_WasPressed = true;
    else
        ButtonA_WasPressed = false;

    if (digitalRead(pinButtonB) == LOW)
        ButtonB_WasPressed = true;
    else
        ButtonB_WasPressed = false;

    if (digitalRead(pinButtonC) == LOW)
        ButtonC_WasPressed = true;
    else
        ButtonC_WasPressed = false;

    if (digitalRead(pinButtonD) == LOW)
        ButtonD_WasPressed = true;
    else
        ButtonD_WasPressed = false;
}

void CheckButtonA()