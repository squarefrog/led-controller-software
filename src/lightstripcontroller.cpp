#include "lightstripcontroller.h"

void LightStripController::setup() {
}

bool LightStripController::getIsOn() {
    return model.isOn;
}

void LightStripController::setIsOn(bool isOn) {
    model.isOn = isOn;
}

// HomeKit defines the Hue range as 0-360, however FastLED requires a range of
// 0-255, so conversion is needed when setting/getting.
byte LightStripController::getHue() {
    int converted = round((360 / 255) * model.hue);
    return converted;
}

void LightStripController::setHue(int hue) {
    int constrained = constrain(hue, 0, 360);
    byte converted = round((255 / 360) * constrained);
    model.hue = converted;
}

byte LightStripController::getSaturation() {
    return model.saturation;
}

void LightStripController::setSaturation(int saturation) {
    byte constrained = constrain(saturation, 0, 100);
    model.saturation = constrained;
}

byte LightStripController::getBrightness() {
    return model.brightness;
}

void LightStripController::setBrightness(int brightness) {
    byte constrained = constrain(brightness, 0, 100);
    model.brightness = constrained;
}

String LightStripController::getName() {
    return model.name;
}

void LightStripController::setName(String name) {
    model.name = name;
}

void LightStripController::saveDefaultColour() {
}
