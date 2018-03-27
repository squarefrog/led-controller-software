#include "lightstripmodel.h"

LightStrip::LightStrip(void) {
    this->isOn = true;
    this->hue = 255;
    this->saturation = 100;
    this->brightness = 100;
    this->name = "Light Strip";
}
