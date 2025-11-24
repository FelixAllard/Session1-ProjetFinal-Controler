#include "CommunicationGateway.h"
#include <Arduino.h>

const String targetMessage = "ARDUINO_SERIAL_MEGACONNECTION";
bool unityConnected = false;
unsigned long lastBeat = 0;
unsigned long lastHandshake = 0;
const unsigned long handshakeInterval = 1000; // 500ms

void InitializeCommunicationGateway() {
    Serial.begin(115200);
    delay(100); // small delay for boards like Uno/Nano

    Serial.println("READY!!!");
    Serial.println(targetMessage); // first handshake
}

void UpdateCommunicationGateway() {
    unsigned long now = millis();

    // -------- HANDSHAKE MODE --------
    if (!unityConnected && now - lastHandshake >= handshakeInterval)
    {
        Serial.println(targetMessage);  // repeat handshake
        lastHandshake = now;
        Serial.println("[DEBUG] Sent handshake");
    }

    // -------- CONNECTED MODE --------
    if (unityConnected && now - lastBeat >= 1000)
    {
        Serial.println("ALIVE");
        lastBeat = now;
        Serial.println("[DEBUG] Sent heartbeat");
    }

    // -------- READ INCOMING --------
    while (Serial.available())
    {
        String msg = Serial.readStringUntil('\n');
        msg.trim();

        if (msg == "CONNECTED")
        {
            unityConnected = true;
            Serial.println("OK");
            Serial.println("[DEBUG] Received CONNECTED, unityConnected = true");
        }

        if (msg == "PING")
        {
            Serial.println("PONG");
            Serial.println("[DEBUG] Received PING");
        }
    }
}
// Button send functions
void Send_PressAButton() { Serial.println("BUTTON_A"); }
void Send_PressBButton() { Serial.println("BUTTON_B"); }
void Send_PressCButton() { Serial.println("BUTTON_C"); }
void Send_PressDButton() { Serial.println("BUTTON_D"); }
