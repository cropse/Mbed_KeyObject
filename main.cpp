

#include "mbed.h"
#include "KeyPanel.h"
#include "KeyProcess.h"
#include "KeyIR.h"
#include "LED.h"


Serial pc(SERIAL_TX, SERIAL_RX);
//IR KEY Configure
uint8_t IRKeyMap[]=
{
    0x0a,0x08,0x1e,0x1f
};
// Use Panel Key is oks
// KeyName bPanelKeyValue[]=
// {
//     KEY_POWER_KEY, KEY_VOL_UP_KEY, KEY_VOL_DOWN_KEY, KEY_MODE_KEY
// };

//End

PinName bPanelKeyMap[]=
{
    A5,A4,A3,A2
};
KeyName bPanelKeyValue[]=
{
    KEY_POWER_KEY, KEY_VOL_UP_KEY, KEY_VOL_DOWN_KEY, KEY_MODE_KEY
};

//int a=0,d,g,h,y,r,e,w;
//const int ok[] = {1,2,3,4,5,6,7,8,9};
//PinName okk = USER_BUTTON;
void GEN_Key_Process(void);
Timer t;
int i;
KeyProcess Process;

int main() 
{
    KeyPanel PanelKey(bPanelKeyMap,bPanelKeyValue,sizeof(bPanelKeyMap));
    KeyIR IRKey(D3,0x00ff,IRKeyMap,bPanelKeyValue,sizeof(IRKeyMap));
    
    pc.printf("GO!!!!!");
    
    
    // while(0)
    // {
    //     if(IRKey.read())
    //     {
    //         //if(IRKey.)
    //         //for(int i=0;i<=10;i++)
    //         //    pc.printf("%x ",IRKey.buf[i]);
    //         for(int i =0; i<=16 ;i++)
    //           pc.printf("%x ",IRKey.buf[i]);
    //         pc.printf("%d ",IRKey.state);
    //         pc.printf("%x \r\n",IRKey.value);
            
    //         //pc.printf("Process is %d \r\n",Process.State);
    //         //pc.printf("%d",KeyIR.format);
    //         //pc.printf("\r\n ");
    //     }
    // }
    
    
    
    while(1)
    {
    
        if(IRKey.read())
          Process.Key(IRKey.value,IRKey.state);
        else if(PanelKey.read())
          Process.Key(PanelKey.value,PanelKey.state);
        else
          Process.Key(KEY_NO_KEY,NO_KEY);

        switch(Process.Value)
        {
            case KEY_POWER_KEY:
                Process.Trigger(FIRST_KEY,100);
                Process.Trigger(TRANS_KEY_ONCE,2000);
                
            break;
            case KEY_VOL_UP_KEY:
                Process.Trigger(HOLD_KEY,1000,500);
            break;
            case KEY_VOL_DOWN_KEY:
                Process.Trigger(FIRST_KEY,500);
                Process.Trigger(RELEASE_KEY);
            break;
            case KEY_MODE_KEY:
                Process.Trigger(FIRST_KEY,500);
                Process.Trigger(HOLD_KEY,2000,500);
            default:
            break;
        }
        
        Process.process();
        if(Process.ProcessState)
            GEN_Key_Process();
        //pc.printf("the %d is trigger by %d \r\n",Process.Value,Process.ProcessState);     
            
        
    }
}


void GEN_Key_Process(void)
{
    switch(Process.Value)
    {
        case KEY_POWER_KEY:
            if(Process.ProcessState == TRANS_KEY_ONCE)
                pc.printf("HOLD_POWER_ONCE is trigged\r\n");
            else
                pc.printf("KEY_POWER_KEY is trigged\r\n");
        break;
        case KEY_VOL_UP_KEY:
            pc.printf("KEY_VOL_UP_KEY is trigged\r\n");
        break;
        case KEY_VOL_DOWN_KEY:
            pc.printf("KEY_VOL_DOWN_KEY is trigged\r\n");
        break;
        case KEY_MODE_KEY:
            if(Process.ProcessState == HOLD_KEY)
                pc.printf("HOLD_MODE_KEY is trigged\r\n");
            else
                pc.printf("KEY_MODE_KEY is trigged\r\n");
        default:
        break;
        
    }
 
}

