#include "constants.h"
#include "lightstripcontroller.h"

CRGB leds[NUM_LEDS];

void LightStripController::setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    // If your power supply does not have enough headroom to power all your
    // LEDs, you can limit the max power.
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 4000);
}

void LightStripController::loop() {
}

bool LightStripController::getIsOn() {
    return model.isOn;
}

void LightStripController::setIsOn(bool isOn) {
    model.isOn = isOn;
}

int LightStripController::getHue() {
    return model.hue;
}

void LightStripController::setHue(int hue) {
    int constrained = constrain(hue, 0, 360);
    model.hue = constrained;
    updateLEDStrip();
}

byte LightStripController::getSaturation() {
    return model.saturation;
}

void LightStripController::setSaturation(byte saturation) {
    byte constrained = constrain(saturation, 0, 100);
    model.saturation = constrained;
    updateLEDStrip();
}

byte LightStripController::getBrightness() {
    return model.brightness;
}

void LightStripController::setBrightness(byte brightness) {
    byte constrained = constrain(brightness, 0, 100);
    model.brightness = constrained;
    updateLEDStrip();
}

String LightStripController::getName() {
    return model.name;
}

void LightStripController::setName(String name) {
    model.name = name;
}

void LightStripController::saveDefaultColour() {
}

int LightStripController::scaledValue(int value, int input, int output) {
    float multiplier = float(input) / float(output);
    float result = round(multiplier * float(value));
    return int(result);
}

void LightStripController::updateLEDStrip() {
    // HomeKit defines hue, saturation and brightness values differently to
    // what FastLED expects, so scale the values appropriately.
    byte hue = scaledValue(model.hue, 360, 255);
    byte saturation = scaledValue(model.saturation, 100, 255);
    byte brightness = scaledValue(model.brightness, 100, 255);

    for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CHSV(hue, saturation, brightness);
    }

    FastLED.show();
}
