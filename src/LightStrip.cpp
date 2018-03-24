#include "Arduino.h"
#include "LightStrip.h"

bool LightStrip::getPower() {
    return _power;
}

void LightStrip::setPower(bool isOn) {
    _power = isOn;
}

int LightStrip::getHue() {
    return _hue;
}

void LightStrip::setHue(int hue) {
    _hue = hue;
}

byte LightStrip::getSaturation() {
    return _saturation;
}

void LightStrip::setSaturation(byte saturation) {
    _saturation = saturation;
}

byte LightStrip::getBrightness() {
    return _brightness;
}

void LightStrip::setBrightness(byte brightness) {
    _brightness = brightness;
}

String LightStrip::getName() {
    return _name;
}

void LightStrip::setName(String name) {
    _name = name;
}

void LightStrip::saveDefaultColour() {
}
