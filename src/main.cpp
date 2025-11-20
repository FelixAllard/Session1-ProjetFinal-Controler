#include <Arduino.h>

#include "CommunicationGateway.h"
#include "LibRobus.h"



void setup() {
    BoardInit();
    delay(500);
    Serial.begin(115200);
    InitializeCommunicationGateway();
}

void loop() {

    UpdateCommunicationGateway();
}
