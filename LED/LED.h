#ifndef MBED_LED_H
#define MBED_LED_H
#include "mbed.h"

class LED : public PwmOut
{
    public:
        LED(PinName pin);
        void breath();
        void flash(float cycle);
    
    
        /* A shorthand for write*/
    
        LED& operator= (float value) {
            write(value);
            return *this;
        }
                     
        LED& operator= (LED& rhs) {
            write(rhs.read());
            return *this;
        }
     
        /** An operator shorthand for read()
         */
        operator float() {
            return read();
        }
        
        private:
            Ticker T;
            float value;
            float FadeAmount;
            void flashing();
            void breathing();

};

#endif