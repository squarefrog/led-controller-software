#include "LightStripController.h"

#include <FastLED.h>

#include "Constants.h"
#include "Persistence.h"

CRGB leds[NUM_LEDS];

LightStripController::LightStripController()
{
    Persistence persistence;
    model = persistence.loadModel();
}

void LightStripController::setup()
{
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    // If your power supply does not have enough headroom to power all your
    // LEDs, you can limit the max power.
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 4000);

    // Initialise the LEDs to black
    for (int i = 0; i <= NUM_LEDS; i++)
    {
        leds[i] = CRGB::Black;
    }

    FastLED.show();
}

void LightStripController::loop()
{
}

bool LightStripController::getIsOn()
{
    return model.isOn;
}

void LightStripController::setIsOn(bool isOn)
{
    model.isOn = isOn;
}

int LightStripController::getHue()
{
    return model.hue;
}

void LightStripController::setHue(int hue)
{
    int constrained = constrain(hue, 0, 360);
    model.hue = constrained;
    updateLEDStrip();
}

byte LightStripController::getSaturation()
{
    return model.saturation;
}

void LightStripController::setSaturation(byte saturation)
{
    byte constrained = constrain(saturation, 0, 100);
    model.saturation = constrained;
    updateLEDStrip();
}

byte LightStripController::getBrightness()
{
    return model.brightness;
}

void LightStripController::setBrightness(byte brightness)
{
    byte constrained = constrain(brightness, 0, 100);
    model.brightness = constrained;
    updateLEDStrip();
}

String LightStripController::getName()
{
    return model.name;
}

void LightStripController::setName(String name)
{
    strncpy(model.name, name.c_str(), sizeof(model.name));
    Serial.println("Set name: " + name + "(" + model.name + ")");
}

void LightStripController::saveDefaultColour()
{
    Persistence persistence;
    persistence.saveModel(model);
}

int LightStripController::scaledValue(int value, int input, int output)
{
    float multiplier = float(input) / float(output);
    float result = round(multiplier * float(value));
    return int(result);
}

void LightStripController::updateLEDStrip()
{
    // HomeKit defines hue, saturation and brightness values differently to
    // what FastLED expects, so scale the values appropriately.
    byte hue = scaledValue(model.hue, 360, 255);
    byte saturation = scaledValue(model.saturation, 255, 100);
    byte brightness = scaledValue(model.brightness, 255, 100);

    for (int i = 0; i <= NUM_LEDS; i++)
    {
        leds[i] = CHSV(hue, saturation, brightness);
    }

    FastLED.show();
}
