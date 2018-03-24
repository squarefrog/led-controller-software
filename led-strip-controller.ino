/*
 *  This sketch allows control of a WS2812B LED strip
 */

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

// https://github.com/tzapu/WiFiManager
#include <WiFiManager.h>

void setup() {
    Serial.begin(115200);

    // Setup WiFi
    Serial.print("Initialise WiFiManager...");
    WiFiManager wifiManager;
    wifiManager.autoConnect("LEDControlAP");
    Serial.print("Connected to WiFi");
    Serial.println(WiFi.localIP());
}

void loop() {
}
