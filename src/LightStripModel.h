/*
 * This class defines a model object which stores the current state of the
 * light strip.
 */

#ifndef SRC_LIGHTSTRIPMODEL_H
#define SRC_LIGHTSTRIPMODEL_H

#include <Arduino.h>

struct LightStrip
{
    bool isOn;
    int hue;
    byte saturation;
    byte brightness;
    char name[65];
    LightStrip();
};

#endif
