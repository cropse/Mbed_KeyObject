/** @file KeyProcess.h
  * @brief  All the keytype enter to this Object, parser Key trigger type 

  * @author Cropse
  * @update date 2015/9/16 */
#ifndef MBED_KEYPROCESS_H
#define MBED_KEYPROCESS_H
#include "mbed.h"
#include "System.h"
#include "KeyPanel.h"
#include "ReceiverIR.h"
#include "KeyIR.h"

class KeyProcess
{

    public:
        KeyProcess()
        {Delay_flag=1;}
//    template<class T>
        void Key(KeyName value, Key_State state)
        {
            for(i=0 ;i<=10;i++)
                TriggerFlag[i]=false;            
//            if(KeyType.read())
//            {
            Value=value;
            State=state;
                //PreState=KeyType.prestate;
//            }
        }      
        
        void Trigger(Key_State flag)//RELEASE
            {
                TriggerFlag[flag]=1;
            }
        
        void Trigger(Key_State flag,uint16_t Times)//FIRST,TRANS_ONE,HOLD
            {
                TriggerFlag[flag]=1;
                if(flag==TRANS_KEY_ONCE)
                    WaitTimes=Times;
                else if(flag == HOLD_KEY)
                    WaitTimes=CycleTimes=Times;
                else
                    DelayTimes=Times;
            }
        void Trigger(Key_State flag,uint16_t WaitTimes,uint16_t CycleTimes)//HOLD,TRANS_REPEAT
            {
                this->WaitTimes=WaitTimes;
                this->CycleTimes=CycleTimes;
                TriggerFlag[flag]=1;
            }                    
        void TriggerTime(uint16_t DelayTimes,uint16_t CycleTimes);
        void process();
        uint8_t ProcessState;
        KeyName Value;
        Key_State State;        
        Key_State PreState; 

    private:
        bool Delay_flag;
        bool Trans_flag;//before
        bool TriggerFlag[10];//after
        int i;
        
        uint16_t WaitTimes;
        uint16_t DelayTimes;
        uint16_t CycleTimes;
        
        Timeout Delay;
        Timer Cycle;
        
        void DelayTimeOut()
            {Delay_flag=1;}        

};
#endif