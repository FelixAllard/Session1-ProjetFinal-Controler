//
// Created by xilef on 11/18/2025.
//

#include "CommunicationGateway.h"

#include <Arduino.h>
#include <HardwareSerial.h>

const String targetMessage = "ARDUINO_SERIAL_MEGACONNECTION";
bool unityConnected = false;
unsigned long lastBeat = 0;

void InitializeCommunicationGateway() {
    while (!Serial) {}

    Serial.println("READY");
}

void UpdateCommunicationGateway() {
    unsigned long now = millis();

    // --- HANDSHAKE MODE ---
    if (!unityConnected) {
        if (now - lastBeat >= 500) {  // send handshake every 0.5 sec
            Serial.println(targetMessage);
            lastBeat = now;
        }
    }

    // --- CONNECTED MODE ---
    if (unityConnected) {
        if (now - lastBeat >= 1000) {  // heartbeat every 1s
            Serial.println("ALIVE");
            lastBeat = now;
        }
    }

    // --- PROCESS INCOMING ---
    if (Serial.available()) {
        String msg = Serial.readStringUntil('\n');
        msg.trim();

        if (msg == "CONNECTED") {
            unityConnected = true;
            Serial.println("OK");
        }

        if (msg == "PING") {
            Serial.println("PONG");
        }
    }
}

void PressUpButton() {
}

void Send_PressAButton() {
    Serial.println("BUTTON_A");
}

void Send_PressBButton() {
    Serial.println("BUTTON_B");
}

void Send_PressCButton() {
    Serial.println("BUTTON_C");
}

void Send_PressDButton() {
    Serial.println("BUTTON_D");
}

