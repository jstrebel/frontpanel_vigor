#pragma once

// include all necessary libraries
#include <Arduino.h>


// define all arduino io pins
#define PIN_MAN 2    // output D2
#define PIN_SEMI 3   // output D3
#define PIN_AUTO 4    // output D4
#define PIN_CALIB 5   // output D5


// define the class
class Pinmap {
  public:
    static void init();
};