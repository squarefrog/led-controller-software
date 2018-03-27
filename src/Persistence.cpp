#include "Persistence.h"

#include <EEPROM.h>

/*
 * An enumeration which sets the starting address location of values in EEPROM.
 */
enum AddressLocation
{
    savedFlagAddress,
    dataAddress
};

void Persistence::saveModel(LightStrip model)
{
    EEPROM.write(savedFlagAddress, 1);
    EEPROM.put(dataAddress, model);
}

LightStrip Persistence::loadModel()
{
    LightStrip model;

    // If no model saved, return a default model.
    bool hasSavedFlag = (bool)EEPROM.read(savedFlagAddress);
    if (!hasSavedFlag)
    {
        return model;
    }

    EEPROM.get(dataAddress, model);

    return model;
}
