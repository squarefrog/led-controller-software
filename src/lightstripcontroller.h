/*
 * This class interfaces between the physical light strip, and a light strip
 * model which stores the current state.
 */

#ifndef LightStripController_h
#define LightStripController_h

#include <Arduino.h>
#include "FastLED.h"
#include "lightstripmodel.h"

class LightStripController {
    public:
        void setup();
        void loop();

        bool getIsOn();
        void setIsOn(bool isOn);

        int getHue();
        void setHue(int hue);

        byte getSaturation();
        void setSaturation(byte saturation);

        byte getBrightness();
        void setBrightness(byte saturation);

        String getName();
        void setName(String name);

        void saveDefaultColour();

    private:
        LightStrip model;
        int scaledValue(int value, int input, int output);
};

#endif
