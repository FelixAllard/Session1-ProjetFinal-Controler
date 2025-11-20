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
    bool buttonState = digitalRead(pinButtonA); //Low enfonce high sinon
    if (buttonState == LOW) {
        if (!ButtonA_WasPressed) {
            Send_PressAButton();
        }
    }
    ButtonA_WasPressed = buttonState;
}

void CheckButtonB() {
    bool buttonState = digitalRead(pinButtonB);
    if (buttonState == LOW) {
        if (!ButtonB_WasPressed) {
            Send_PressAButton();
        }
    }
    ButtonB_WasPressed = buttonState;
}

void CheckButtonC() {
    bool buttonState = digitalRead(pinButtonC);
    if (buttonState == LOW) {
        if (!ButtonC_WasPressed) {
            Send_PressAButton();
        }
    }
    ButtonC_WasPressed = buttonState;
}

void CheckButtonD() {
    bool buttonState = digitalRead(pinButtonD);
    if (buttonState == LOW) {
        if (!ButtonD_WasPressed) {
            Send_PressAButton();
        }
    }
    ButtonD_WasPressed = buttonState;
}
