//
// Created by xilef on 11/18/2025.
//

#include "CommunicationGateway.h"

#include <Arduino.h>
#include <HardwareSerial.h>

bool upButtonpressed = false;
bool downButtonpressed = false;
bool leftButtonPressed = false;
bool rightButtonPressed = false;
bool enterButtonPressed = false;

const String targetMessage = "ARDUINO_SERIAL_MEGACONNECTION_CONTROLLER_INITILIAZER_20050412_RADAR";


void InitializeCommunicationGateway() {
    while (!Serial) { ; } // wait for serial port (for Leonardo/Micro)

    delay(1000); // allow PC to open port

    // Send the target message multiple times for reliability
    for (int i = 0; i < 5; i++) {
        Serial.println(targetMessage);
        delay(200); // small delay between messages
    }

    Serial.println("Arduino ready!");
}
void Handshake() {
    if (Serial.available() > 0) {
        String incoming = Serial.readStringUntil('\n'); // read until newline
        incoming.trim(); // remove whitespace

        Serial.print("Received from Unity: ");
        Serial.println(incoming);

        // Example: respond to a specific command
        if (incoming == "PING") {
            Serial.println("PONG");
        }
    }
}

void PressUpButton() {
}

void PressDownButton() {
}

void PressLeftButton() {
}

void PressRightButton() {
}

void ReleaseUpButton() {
}

void ReleaseDownButton() {
}

void ReleaseLeftButton() {
}

void ReleaseRightButton() {
}

bool ConnectionInitialized() {
}
