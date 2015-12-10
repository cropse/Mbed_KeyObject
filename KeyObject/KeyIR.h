#ifndef MBED_KEYIR_H
#define MBED_KEYIR_H
#include "mbed.h"
#include "System.h"
#include "ReceiverIR.h"

class KeyIR :public ReceiverIR
{
    public:
        KeyIR(PinName pin,uint16_t Address,uint8_t map[],KeyName map_value[],uint8_t len);
        uint8_t read();
        
        KeyName value;
        Key_State state;
        uint8_t buf[16];

    private:
        //ReceiverIR ir_rx(PinName pin);
        RemoteIR::Format format;
        uint8_t NumKey;
        
        int bitlength;

        uint16_t Address;
        KeyName map_value[20];
        uint8_t map[20];
        
};
#endif