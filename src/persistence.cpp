#include <EEPROM.h>
#include "persistence.h"

/*
 * An enumeration which sets the starting address location of values in EEPROM.
 */
enum AddressLocation {
    hasSavedAddress,
    dataAddress
};

void Persistence::saveModel(LightStrip model) {
    EEPROM.write(hasSavedAddress, 1);
    EEPROM.put(dataAddress, model);
}

LightStrip Persistence::loadModel() {
    LightStrip model;

    // If no model saved, return a default model.
    if (!(bool)EEPROM.read(hasSavedAddress)) {
        return model;
    }

    EEPROM.get(dataAddress, model);
    return model;
}
