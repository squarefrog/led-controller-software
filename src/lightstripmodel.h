/*
 * This class defines a model object which stores the current state of the
 * light strip.
 */

#ifndef LightStrip_h
#define LightStrip_h

#include <Arduino.h>

class LightStrip {
    public:
        bool isOn;
        byte hue;
        byte saturation;
        byte brightness;
        String name;
};

#endif
