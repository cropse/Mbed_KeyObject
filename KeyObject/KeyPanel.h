/** @file KeyPanel.h
  * @brief  Normal key input scan Key

  * @author Cropse
  * @update date 2015/9/16 */
#ifndef MBED_KEYPANEL_H
#define MBED_KEYPANEL_H
#include "mbed.h"
#include "System.h"



class KeyPanel
{
    public:
/** @brief Init Key Pin.

  * Annouce object
  * @param param_out None
  * @param param_in  
    *map: address of each key list
    *map_value: mapping the KeyName with map[]
    len: length of map[] list
  * @return . */     
        KeyPanel(PinName *map,KeyName *map_value,uint8_t len);

/** @brief read Key.

  * Scan and return result
  * @param param_out
  * @param param_in  
  * @return   
    1:trigger Key
    0:No key triggered. */         
        uint8_t read();
/**
*   Setting trigger key is HI or LOW
*   default is HI
*/      
        void setTrigger(bool trigger){KeyPanel::trigger = trigger;}

/** @Trans Multi Key.

  * trans two multi Key to one KeyName
  * @param param_out
    value: trans key result
  * @param param_in 
    value1: Key which suppose to combine
    value2: Key which suppose to combine
    transfer: KeyName transfer, update to KeyPanel::value
  * @return */
        void transMultiKey(KeyName value1,KeyName value2,KeyName transfer);

/** @brief Result after read().

  * Send value & state to KeyProcess
    Process.Key(PanelKey.value,PanelKey.state);
  * @param param_out
  * @param param_in  
  * @return . */
        KeyName value;
        Key_State state;


    private:
        Key_State prestate;
        KeyName value_multi;
        uint8_t count;
        uint8_t NumKey;
        
        KeyName prevalue;
        KeyName* map_value;
        PinName* map;

        static bool Multi_enable;
        static bool trigger;
};

#endif