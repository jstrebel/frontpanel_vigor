// version 4.0 - 2024-11-20

// include libraries
#include <Arduino.h>
#include "src/Pinmap.h"
#include "src/CANClass.h"

// define all constants
#define STATE_SEMI 1
#define STATE_AUTO 2
#define STATE_MANUAL 3
#define STATE_ERR 4
const int dt_loop = 100;

unsigned long old_loop_time = 0;
short curr_state = STATE_MANUAL;
short hb_in = 0;


void setup() {
    Serial.begin(115200);
    Serial.println("Hello World!");
    Pinmap::init();
    CANClass::get_instance().init();
}

void loop() {
    if (millis() - old_loop_time > dt_loop) {
        old_loop_time = millis();
        CANClass::get_instance().send_heartbeat_hbn(0x0400);
        
        short hb_out = CANClass::get_instance().read_hb_out();

        switch(curr_state) {
            case STATE_MANUAL:
                hb_in = bitSet(hb_in, BIT_MANUAL);
                hb_in = bitClear(hb_in, BIT_SEMI);
                hb_in = bitClear(hb_in, BIT_AUTO);

                if (digitalRead(PIN_SEMI) == LOW) {
                    curr_state = STATE_SEMI;
                } else if (digitalRead(PIN_AUTO) == LOW) {
                    curr_state = STATE_AUTO;
                }
                break;
            case STATE_SEMI:
                hb_in = bitClear(hb_in, BIT_MANUAL);
                hb_in = bitSet(hb_in, BIT_SEMI);
                hb_in = bitClear(hb_in, BIT_AUTO);

                if (digitalRead(PIN_MAN) == LOW) {
                    curr_state = STATE_MANUAL;
                } else if (digitalRead(PIN_AUTO) == LOW) {
                    curr_state = STATE_AUTO;
                }
                break;
            case STATE_AUTO:
                hb_in = bitClear(hb_in, BIT_MANUAL);
                hb_in = bitClear(hb_in, BIT_SEMI);
                hb_in = bitSet(hb_in, BIT_AUTO);

                if (digitalRead(PIN_SEMI) == LOW) {
                    curr_state = STATE_SEMI;
                } else if (digitalRead(PIN_MAN) == LOW) {
                    curr_state = STATE_MANUAL;
                }
                break;
        }

        CANClass::get_instance().send_hb_in(hb_in);

    }
}