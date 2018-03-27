/*
 * This class enables saving and loading a light strip model to the EEPROM.
 */

#ifndef PERSISTENCE_h
#define PERSISTENCE_h

#include <Arduino.h>
#include "lightstripmodel.h"

class Persistence {
    public:
        void saveModel(LightStrip model);
        LightStrip loadModel();
};

#endif
