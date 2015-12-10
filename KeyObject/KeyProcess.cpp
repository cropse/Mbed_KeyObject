#include "KeyProcess.h"
#include "mbed.h"
#include "Key_Configure.h"

//bool KeyProcess::delay_timeout=1;

void KeyProcess::TriggerTime(uint16_t DelayTimes,uint16_t CycleTimes)
{
    this->DelayTimes=DelayTimes;this->CycleTimes=CycleTimes;
}

void KeyProcess::process() 
{
    if(!State)//NO KEY
    {
        //Cycle.stop();
        return;
    }

    if(State==FIRST_KEY)
    {
        Trans_flag=1;
        Cycle.reset();
        
        if(Delay_flag && TriggerFlag[FIRST_KEY])
        {
            // First Key set Timer
            Delay_flag=0;
            Cycle.start();
            Delay.attach(this,&KeyProcess::DelayTimeOut,DelayTimes/1000.0f);
                
            ProcessState=FIRST_KEY;
            //FIRST
        }
        else
            ProcessState=NO_KEY;
    }
    else if((TriggerFlag[HOLD_KEY]||TriggerFlag[TRANS_KEY_ONCE]||TriggerFlag[TRANS_KEY_REPEAT])
        && State==HOLD_KEY 
        && ((Cycle.read_ms()>=WaitTimes && Trans_flag) || (Cycle.read_ms()>=CycleTimes && !Trans_flag)) )
    {
        if(Trans_flag && TriggerFlag[TRANS_KEY_ONCE])//Got problem Here
        {
            ProcessState=TRANS_KEY_ONCE;
            
            //State=NO_KEY;
            //return;
        }
        else if(TriggerFlag[HOLD_KEY])
        {
            ProcessState=HOLD_KEY;
            //HOLD KEY
        }
        else if(TriggerFlag[TRANS_KEY_REPEAT])
        {
            ProcessState=TRANS_KEY_REPEAT;                
        }
        else
            ProcessState=NO_KEY;        
        
        Cycle.reset();
        Trans_flag=0;       
        
    }
    else if(TriggerFlag[RELEASE_KEY] && State==RELEASE_KEY)
    {
        ProcessState=RELEASE_KEY;
        //Cycle.reset();
        //t.stop();
    }
    else
        ProcessState=NO_KEY;
    
    State=NO_KEY;
}