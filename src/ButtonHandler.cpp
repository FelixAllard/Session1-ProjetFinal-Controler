//
// Created by dan23 on 19/11/2025.
//

#include "ButtonHandler.h"
#include <librobus.h>

#include "CommunicationGateway.h"

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
    CheckButtonA();
    CheckButtonB();
    CheckButtonC();
    CheckButtonD();
}



void CheckButtonA() {
    bool buttonState = digitalRead(pinButtonA);
    if (buttonState == LOW) {
        if (!ButtonA_WasPressed) {
            PressAButton();
        }
    }
    ButtonA_WasPressed = buttonState;
}

void CheckButtonB() {
}

void CheckButtonC() {
}

void CheckButtonD() {
}
