#include "PinMap.h"

void Pinmap::init() {
    // define all pinmondes
    pinMode(PIN_MAN, INPUT_PULLUP);
    pinMode(PIN_SEMI, INPUT_PULLUP);
    pinMode(PIN_AUTO, INPUT_PULLUP);
    pinMode(PIN_CALIB, INPUT_PULLUP);
}