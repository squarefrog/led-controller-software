/*
 * This class interfaces between the physical light strip, and a light strip
 * model which stores the current state.
 */

#ifndef SRC_LIGHTSTRIPCONTROLLER_H
#define SRC_LIGHTSTRIPCONTROLLER_H

#include "lightstripmodel.h"

class LightStripController
{
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

    LightStripController();

  private:
    LightStrip model;
    int scaledValue(int value, int input, int output);
    void updateLEDStrip();
};

#endif
