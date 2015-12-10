/** @file Key_Configure.h
  * @brief  Edit Key_Configure.h to add your personal KeyName
    KeyName is base on mbed

  * @author Cropse
  * @update date 2015/9/16 */
#ifndef MBED_KEY_CONFIGURE_H
#define MBED_KEY_CONFIGURE_H

enum Key_State
{
    NO_KEY=0,
    FIRST_KEY,    
    HOLD_KEY,
    RELEASE_KEY,
    MULTI_KEY,
//    PROGRESS_KEY,
    TRANS_KEY_ONCE,
    TRANS_KEY_REPEAT
};

enum KeyName
{
    KEY_NO_KEY=0,     KEY_POWER_KEY,

//Volume Key Relative
    KEY_VOL_UP_KEY, KEY_VOL_DOWN_KEY,      KEY_MODE_KEY,       KEY_DOWN_KEY,       KEY_UP_KEY,         
    KEY_MUTE_KEY,
// Edit Key Name what you like
    KEY_TUNE_DOWN_KEY,  KEY_TUNE_UP_KEY,    KEY_MENU_KEY,           KEY_MEM_KEY,  
    KEY_ENTER_KEY,       KEY_PLAY_PAUSE,     KEY_PRESET_KEY,  // 0C - 0F

    KEY_1_KEY,          KEY_2_KEY,          KEY_3_KEY,              KEY_4_KEY,  // 10 - 13
    KEY_5_KEY,          KEY_6_KEY,          KEY_7_KEY,              KEY_8_KEY,  // 14 - 17
    KEY_9_KEY,          KEY_0_KEY,          
                 
    KEY_15_KEY,         KEY_16_KEY,         KEY_POWER_DOWN_KEY,         
    KEY_19_KEY,         KEY_20_KEY,

    KEY_LEFT_KEY,       KEY_RIGHT_KEY,
    
};
#endif