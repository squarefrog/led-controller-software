/*
 * This class interfaces between the physical light strip, and a light strip
 * model which stores the current state.
 */

#ifndef LightStripController_h
#define LightStripController_h

#include <Arduino.h>
#include "lightstrip.h"

class LightStripController {
    public:
        void setup();

        bool getIsOn();
        void setIsOn(bool isOn);

        byte getHue();
        void setHue(int hue);

        byte getSaturation();
        void setSaturation(int saturation);

        byte getBrightness();
        void setBrightness(int saturation);

        String getName();
        void setName(String name);

        void saveDefaultColour();

    private:
        LightStrip model;
};

#endif
