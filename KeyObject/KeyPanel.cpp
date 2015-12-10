#include "KeyPanel.h"
#include "mbed.h"

#include "System.h"


bool KeyPanel::trigger = 0;
bool KeyPanel::Multi_enable = 1;

KeyPanel::KeyPanel(PinName *map,KeyName *map_value,uint8_t len)
    {
        prevalue=KEY_NO_KEY;
        prestate=NO_KEY;
        NumKey=len;
        //assert(sizeof(map)==sizeof(map_value)/sizeof(KeyName));
        this->map = map;
        this->map_value = map_value;
        
    }
    
uint8_t KeyPanel::read()
    {
        value=KEY_NO_KEY;//
        value_multi=KEY_NO_KEY;//
        state=NO_KEY;

        for(char i=0 ; i < NumKey ; i++ )
        {
            //Scan Key one by one
            if(!(trigger ^ DigitalIn(*(map+i)).read()))
            {
                if(value == KEY_NO_KEY)
                    value=*(map_value+i);
                else if(Multi_enable)
                {
                    //scan multi Key
                    value_multi=*(map_value+i);
                    state=MULTI_KEY;
                    prestate=state;
                    return state;
                }
            }
        }
        if(prestate==MULTI_KEY)
            {
                if(!value)
                {
                    count=1;
                    prestate=NO_KEY;
                    prevalue=KEY_NO_KEY;
                }
                state=NO_KEY;
                return state;
            }
        
        if(!prevalue&&!value)
            state=NO_KEY;
        else if(prevalue!=value)
        {
            if(prestate!=HOLD_KEY && prestate!=FIRST_KEY)
                state=FIRST_KEY;
            else
            {
                value=prevalue;
                state=RELEASE_KEY;
                prevalue=KEY_NO_KEY;
                prestate=state;
                wait_ms(1);//debounce for first trigged
                return state;
            }
        }
        else if(prevalue==value)
            state=HOLD_KEY;


        prevalue=value;
        prestate=state;
        
        return state;
    }

void KeyPanel::transMultiKey(KeyName value1,KeyName value2,KeyName transfer)
{   

    if(state!=MULTI_KEY)
    {
        count=1;
        return;
    }

    if((value1==value || value2==value)&&(value1==value_multi || value2==value_multi))
    {
        value=transfer;
        if(count)
        {
            state=FIRST_KEY;
            count=0;
        }
        else
        {
            state=HOLD_KEY;
        }
    }
}