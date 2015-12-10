#ifndef MBED_KEY_CONFIGURE_H
#define MBED_KEY_CONFIGURE_H
/*
enum KEY_FLAG
{
    NO_KEY=0,
    FIRST_KEY,    //  N    
    HOLD_KEY,       //  Hold
    LAST_KEY,       //  p
    PROGRESS_KEY,
    TRANS_KEY_ONCE,
    TRANS_KEY_REPEAT    
};
*/
enum Key_State
{
    NO_KEY=0,
    FIRST_KEY,    //  N    
    HOLD_KEY,       //  Hold
    RELEASE_KEY,       //  p
    MULTI_KEY,
//    PROGRESS_KEY,
    TRANS_KEY_ONCE,
    TRANS_KEY_REPEAT   
};

enum KeyName
{
//IR KEY AREA

    KEY_NO_KEY=0,     KEY_POWER_KEY,  // 00 - 03

//Volume Key Relative
    KEY_VOL_UP_KEY, KEY_VOL_DOWN_KEY,      KEY_MODE_KEY,       KEY_DOWN_KEY,       KEY_UP_KEY,         
    KEY_MUTE_KEY,
//
    KEY_TUNE_DOWN_KEY,  KEY_TUNE_UP_KEY,    KEY_MENU_KEY,           KEY_MEM_KEY,  
    KEY_ENTER_KEY,       KEY_PLAY_PAUSE,     KEY_PRESET_KEY,  // 0C - 0F

    KEY_1_KEY,          KEY_2_KEY,          KEY_3_KEY,              KEY_4_KEY,  // 10 - 13
    KEY_5_KEY,          KEY_6_KEY,          KEY_7_KEY,              KEY_8_KEY,  // 14 - 17
    KEY_9_KEY,          KEY_0_KEY,          KEY_LEARN_KEY,

    KEY_VOLUME_KEY,         KEY_TREBLE_KEY,                  
    KEY_15_KEY,         KEY_16_KEY,         KEY_POWER_DOWN_KEY,         
    KEY_19_KEY,         KEY_20_KEY,

            KEY_SLEEP_KEY,
    KEY_AM_KEY,         KEY_FM_KEY,         KEY_IPOD_KEY,       KEY_AUX_KEY,  
    KEY_OPT_KEY,        KEY_COAX_KEY,           
    KEY_INFO_KEY,       KEY_SNOOZE_KEY,         KEY_ALARM2_SET_KEY,

    KEY_LEFT_KEY,       KEY_RIGHT_KEY,
    
//Transfer Key area
    KEY_ALARM1_SET, KEY_ALARM2_SET, KEY_PRESET_SET,     KEY_MEM_SET, 

//IR Key
    IR_TUNE_UP_KEY, IR_TUNE_DOWN_KEY, IR_SEEK_UP_KEY,   IR_SEEK_DOWN_KEY,

//EQ setting
    KEY_EQ_MENU,        KEY_EQ_UP,          KEY_EQ_DOWN,

//IPOD AREA
    KEY_IPOD_CMD_END,       KEY_IMENU_KEY,      KEY_SELECT_KEY,
    
    KEY_BASS_KEY,
    KEY_ALARM_KEY,
    KEY_TUNE_UP_STATION,    KEY_TUNE_DOWN_STATION,
    KEY_MODE_UP_KEY,        KEY_MODE_DOWN_KEY,  
    
    KEY_ENG_KEY,            KEY_ENG_VOL_LIMIT,  KEY_ENG_ALARM_RESET,    KEY_ENG_ALARM_ADVANCE,
    KEY_CLEAR_ALL,          KEY_CLOCK_FORMAT1,          

    KEY_SET_KEY,       KEY_SETADD_KEY,       KEY_SETSUB_KEY,
    KEY_SAVE_KEY,    KEY_IPOD_OFF_KEY  ,     KEY_POWEROFF_KEY,      KEY_POWERON_KEY,    

    KEY_SUB_UP, KEY_SUB_DOWN,       KEY_BT_KEY      ,KEY_PAIRING_KEY    ,KEY_TWSPAIRING_KEY,
    KEY_TWS_KEY ,KEY_BOOST_KEY
};
#endif