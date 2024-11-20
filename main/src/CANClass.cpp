#include "CANClass.h"

// define the constructor
CANClass::CANClass() : _sender(10) {
    _frame.can_id = 0;
    _frame.can_dlc = FRAME_SIZE;
    _frame.data[0] = 0;
    _frame.data[1] = 0;
    _hb_in = 0;
    _hb_out = 0;
}

// define all functions
CANClass& CANClass::get_instance() {
    static CANClass instance;
    return instance;
}

void CANClass::init() {
    _sender.reset();
    _sender.setBitrate(CAN_125KBPS);
    _sender.setNormalMode();
}

void CANClass::send_heartbeat_hbn(short heart) {
    _send(REG_HEARTBEAT_HBN, heart);
}

short CANClass::read_hb_out() {
    if (_sender.readMessage(&_frame) == MCP2515::ERROR_OK) {
        if (_frame.can_id == REG_HB_OUT) {
            _hb_out = _frame.data[0] | (_frame.data[1] << 8);
        }
    }
    return _hb_out;
}

void CANClass::send_hb_in(short hb_in) {
    _hb_in = hb_in;
    _send(REG_HB_IN, hb_in);
}

void CANClass::_send(short reg, short data) {
    _frame.can_id = reg;
    _frame.data[0] = data & 0xFF;
    _frame.data[1] = (data >> 8) & 0xFF;
    _sender.sendMessage(&_frame);
}