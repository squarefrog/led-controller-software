/*
 * This class defines a model object which stores the current state of the
 * light strip.
 */

#ifndef LightStrip_h
#define LightStrip_h

#include "Arduino.h"

class LightStrip {
    public:
        bool getIsOn();
        void setIsOn(bool isOn);

        byte getHue();
        void setHue(byte hue);

        byte getSaturation();
        void setSaturation(byte saturation);

        byte getBrightness();
        void setBrightness(byte saturation);

        String getName();
        void setName(String name);

        void saveDefaultColour();

    private:
        bool _power;
        byte _hue;
        byte _saturation;
        byte _brightness;
        String _name;
};

#endif
