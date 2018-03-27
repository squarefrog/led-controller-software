/*
 * This class enables saving and loading a light strip model to the EEPROM.
 */

#ifndef SRC_PERSISTENCE_H
#define SRC_PERSISTENCE_H

#include "lightstripmodel.h"

class Persistence
{
  public:
    void saveModel(LightStrip model);
    LightStrip loadModel();
};

#endif
