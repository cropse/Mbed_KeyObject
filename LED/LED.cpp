#include "mbed.h"
#include "LED.h"

LED::LED(PinName pin):PwmOut(pin)
{
    value=0;
}

void LED::flash(float cycle)
{
    T.attach(this,&LED::flashing,cycle);
}

void LED::flashing()
{
    value=!value;
    write(value);
}
void LED::breath()
{
    value=1;
    FadeAmount=0.05;
    T.attach(this,&LED::breathing,0.1);
}
void LED::breathing()
{
    value-=FadeAmount;
    if(value<=0 || value>=1)
        FadeAmount=-FadeAmount;
    write(value);
}