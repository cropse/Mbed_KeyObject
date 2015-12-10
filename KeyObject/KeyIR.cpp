//#include "ReceiverIR.h"
#include "mbed.h"
#include "Key_Configure.h"
#include "KeyIR.h"

KeyIR::KeyIR(PinName pin,uint16_t Address,uint8_t map[],KeyName map_value[],uint8_t len): ReceiverIR(pin)
    {
//        ReceiverIR ir_rx(pin);
        
        this->Address=Address;

        NumKey=len;
        for(int i=0; i<NumKey; i++)
        {
            this->map_value[i] = map_value[i];
            this->map[i] = map[i];
        }
        
        //*this->map = map;
    }
    
uint8_t KeyIR::read()
    {
//        return KeyIR::getState();
        if(KeyIR::getState() != KeyIR::Received)
            return 0;
        
        memset(buf, 0x00, sizeof(buf));
        bitlength=KeyIR::getData(&format, &buf[0], sizeof(buf) * 8);
        
            switch(format)
            {
                case RemoteIR::NEC:
                    state = FIRST_KEY;
                    
                    break;
                case RemoteIR::NEC_REPEAT:
                    state = HOLD_KEY;
                    
                    break;
                default:
                    state = NO_KEY;
            }

        if(state==FIRST_KEY)
        {
            if(Address>>8==buf[0] && (Address&0xff)==buf[1])
            {
                for(int i=0; i<NumKey; i++)
                {
                    if(map[i]==buf[2])
                    {
                        value=map_value[i];
                        return state;
                    }
                }
                state=NO_KEY;
                value=KEY_NO_KEY;
            }
            else
            {
                state=NO_KEY;
                value=KEY_NO_KEY;
            }
        }
        else
            return state;
            
        return 0;
    }