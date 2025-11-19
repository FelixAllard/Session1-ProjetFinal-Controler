#include <Arduino.h>

#include "LibRobus.h"


const String targetMessage = "ARDUINO_SERIAL_MEGACONNECTION_CONTROLLER_INITILIAZER_20050412_RADAR";

bool unityConnected = false;

void setup() {
    BoardInit();
    delay(500);
    Serial.begin(115200);
    while (!Serial) { ; } // wait for serial port on Leonardo/Micro

    Serial.println("Arduino ready!");
}

void loop() {
    // Continuously send target message until Unity confirms connection
    if (!unityConnected) {
        Serial.println(targetMessage);
        delay(200);
    }

    // Read incoming messages from Unity
    if (Serial.available() > 0) {
        String incoming = Serial.readStringUntil('\n');
        incoming.trim();

        Serial.print("Received from Unity: ");
        Serial.println(incoming);

        // Unity can confirm connection
        if (incoming == "CONNECTED") {
            unityConnected = true;
            Serial.println("Unity confirmed connection.");
        }

        // Example command response
        if (incoming == "PING") {
            Serial.println("PONG");
        }
    }
}
