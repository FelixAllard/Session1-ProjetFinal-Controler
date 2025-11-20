#include <Arduino.h>

#include "ButtonHandler.h"
#include "CommunicationGateway.h"
#include "LibRobus.h"



void setup() {
    BoardInit();
    delay(500);
    Serial.begin(115200);
    InitializeButtons();
    InitializeCommunicationGateway();
}

void loop() {
    UpdateButtonStatus();
    UpdateCommunicationGateway();
}
