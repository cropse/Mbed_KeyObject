/** @file KeyIR.h
  * @brief  Base On RemoteIR, Only for NEC protocol

  * @author Cropse
  * @update date 2015/9/16 */
#ifndef MBED_KEYIR_H
#define MBED_KEYIR_H
#include "mbed.h"
#include "System.h"
#include "ReceiverIR.h"

class KeyIR :public ReceiverIR
{
    public:
/** @brief Init Key Pin.

  * Annouce object
  * @param param_out None
  * @param param_in  
    pin: IR Interrupt Pin
    Address: IR Remote Codec mapping address
    map[]: address of each key list
    map_value[]: mapping the KeyName with map[]
    len: length of map[] list
  * @return . */        
        KeyIR(PinName pin,uint16_t Address,uint8_t map[],KeyName map_value[],uint8_t len);
        
/** @brief read Key.

  * Scan and return result
  * @param param_out
  * @param param_in  
  * @return   
    1:trigger Key
    0:No key triggered. */        
        uint8_t read();

/** @brief Result after read().

  * Send value & state to KeyProcess
    Process.Key(PanelKey.value,PanelKey.state);
  * @param param_out
  * @param param_in  
  * @return . */          
        KeyName value;
        Key_State state;

//  Debug test
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