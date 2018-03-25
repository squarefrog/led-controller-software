#include "lightstripcontroller.h"

#define LED_PIN     7
#define NUM_LEDS    150

CRGB leds[NUM_LEDS];

void LightStripController::setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    // If your power supply does not have enough headroom to power all your
    // LEDs, you can limit the max power.
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 4000);
}

void LightStripController::loop() {
    byte hue = model.hue;
    byte brightness = model.brightness;
    byte value = model.saturation;

    for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CHSV(hue, brightness, value);
    }
}

bool LightStripController::getIsOn() {
    return model.isOn;
}

void LightStripController::setIsOn(bool isOn) {
    model.isOn = isOn;
}

// HomeKit defines the Hue range as 0-360, however FastLED requires a range of
// 0-255, so conversion is needed when setting/getting.
int LightStripController::getHue() {
    return scaledValue(model.hue, 360, 255);
}

void LightStripController::setHue(int hue) {
    int constrained = constrain(hue, 0, 360);
    model.hue = scaledValue(constrained, 255, 360);
}

// HomeKit defines the Saturation range as 0-100, however FastLED requires a
// range of 0-255, so conversion is needed when setting/getting.
byte LightStripController::getSaturation() {
    return scaledValue(model.saturation, 255, 100);
}

void LightStripController::setSaturation(byte saturation) {
    byte constrained = constrain(saturation, 0, 100);
    model.saturation = scaledValue(saturation, 100, 255);
}

// HomeKit defines the Brightness range as 0-100, however FastLED requires a
// range of 0-255, so conversion is needed when setting/getting.
byte LightStripController::getBrightness() {
    return scaledValue(model.brightness, 255, 100);
}

void LightStripController::setBrightness(byte brightness) {
    byte constrained = constrain(brightness, 0, 100);
    model.brightness = scaledValue(constrained, 100, 255);
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
