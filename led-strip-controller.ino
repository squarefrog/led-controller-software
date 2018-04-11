/*
 *  This sketch allows control of a WS2812B LED strip
 */

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

// https://github.com/tzapu/WiFiManager
#include <WiFiManager.h>

#include "src/APIHandler.h"
#include "src/Constants.h"
#include "src/LightStripController.h"

// OTA Updates
#include <ArduinoOTA.h>
ESP8266WebServer server(80);
LightStripController strip;
APIHandler handler(server, strip);

void setup() {
    Serial.begin(115200);

    // Setup light strip controller
    strip.setup();

    // Setup WiFi
    Serial.print("Initialise WiFiManager...");
    WiFiManager wifiManager;
    wifiManager.autoConnect("LEDControlAP");
    Serial.print("Connected to WiFi");
    Serial.println(WiFi.localIP());

    // Setup API handler
    handler.setup();

    ArduinoOTA.begin();
}

void loop() {
    handler.loop();
    strip.loop();
    ArduinoOTA.handle();
}
