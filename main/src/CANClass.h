#pragma once

// define all constants
#define FRAME_SIZE 2

#define REG_HEARTBEAT_HBN 0x02  //Heartbeat Handbox Nano

#define REG_HB_IN 0x70    //Handbox input
#define BIT_MANUAL 0
#define BIT_SEMI 1
#define BIT_AUTO 2
#define BIT_F1 4
#define BIT_F2 5
#define BIT_F3 6
#define BIT_F4 7

#define REG_HB_OUT 0x75   //Handbox output

// include all libraries
#include "mcp2515.h"

// define the class
class CANClass {
    public:
        static CANClass& get_instance();
        void init();
        void send_heartbeat_hbn(short heart);
        short read_hb_out();
        void send_hb_in(short hb_in);
    private:
        MCP2515 _sender;
        struct can_frame _frame;
        CANClass();
        CANClass& operator=(const CANClass& other) = delete;
        short _heartbeat_hbn;
        short _hb_in;
        short _hb_out;
        void _send(short reg, short value);
};