#include "LightStripModel.h"

LightStrip::LightStrip()
{
    isOn = true;
    hue = 0;
    saturation = 100;
    brightness = 100;
    strncpy(name, "Light Strip", sizeof(name));
}
