#ifndef MBED_KEYPANEL_H
#define MBED_KEYPANEL_H
#include "mbed.h"
#include "System.h"



class KeyPanel
{
    public:
        KeyPanel(PinName *map,KeyName *map_value,uint8_t len);
        uint8_t read();
        void setTrigger(bool trigger){KeyPanel::trigger = trigger;}
        void transMultiKey(KeyName value1,KeyName value2,KeyName transfer);

        KeyName value;
        KeyName value_multi;
        Key_State state;
        Key_State prestate;

    private:
        uint8_t count;
        uint8_t NumKey;
        
        KeyName prevalue;
        KeyName* map_value;
        PinName* map;

        static bool Multi_enable;
        static bool trigger;
};

#endif