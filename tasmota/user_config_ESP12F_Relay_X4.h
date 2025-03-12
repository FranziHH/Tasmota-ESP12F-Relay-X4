/* additional config for ESP12F-Relay-X4 */

// only Test if include works
// #error "Board was not recognized"

#ifdef CODE_IMAGE_STR
  #undef CODE_IMAGE_STR
#endif
// see below
// #define CODE_IMAGE_STR "ESP12F-Relay-X4 ..."

#ifdef MODULE
#undef MODULE
#endif
#define MODULE                 USER_MODULE   // [Module] Select default model (the list is kModuleNiceList() in file tasmota_template.h) USER_MODULE is the TEMPLATE

#ifdef FALLBACK_MODULE
#undef FALLBACK_MODULE
#endif
#define FALLBACK_MODULE        USER_MODULE   // to Select the default model as FALLBACK when the user does a RESET 1 

#ifdef USER_TEMPLATE
#undef USER_TEMPLATE
#endif

#define CODE_IMAGE_STR_APPEND " [FW]"
#ifdef FIRMWARE_SENSORS
    #ifdef USE_AHT2x
        #undef USE_AHT2x
    #endif
    #define USE_AHT2x
    // https://tasmota.github.io/docs/AHT2x/#troubleshooting
    #define USER_BACKLOG_SENSOR "I2CDriver12 0; I2CDriver43 1"

    #ifdef CODE_IMAGE_STR_APPEND
        #undef CODE_IMAGE_STR_APPEND
    #endif
    #define CODE_IMAGE_STR_APPEND " Sensor"
#endif

#ifdef CFG_DISPLAY
    //Display prepared
    #if MY_LANGUAGE == de_DE
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4_Display\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relais1|WebButton2 Relais2|WebButton3 Relais3|WebButton4 Relais4|WebButton5 Display\"}"
    #else
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4_Display\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relay1|WebButton2 Relay2|WebButton3 Relay3|WebButton4 Relay4|WebButton5 Display\"}"
    #endif

    #define CODE_IMAGE_STR "ESP12F-Relay-X4 Display" CODE_IMAGE_STR_APPEND
#elif CFG_SH1106
    //SH1106 1,3'' OLED
    #if MY_LANGUAGE == de_DE
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4_SH1106\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relais1|WebButton2 Relais2|WebButton3 Relais3|WebButton4 Relais4|WebButton5 Display\"}"
    #else
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4_SH1106\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relay1|WebButton2 Relay2|WebButton3 Relay3|WebButton4 Relay4|WebButton5 Display\"}"
    #endif

    #define USER_RULE3 ":H,SH1106,128,64,1,I2C,3c,*,*,* :S,0,2,1,0,30,20 :I AE D5,80 A8,3f D3,00 40 8D,14 20,00 A1 C8 DA,12 81,CF D9F1 DB,40 A4 A6 AF :o,AE :O,AF :A,00,10,40,00,02 :i,A6,A7"
    #ifdef USER_BACKLOG_SENSOR
        #define USER_BACKLOG "DisplayModel 17; DisplayMode 1; " USER_BACKLOG_SENSOR
    #else
        #define USER_BACKLOG "DisplayModel 17; DisplayMode 1"
    #endif
    #define CODE_IMAGE_STR "ESP12F-Relay-X4 SSH1106" CODE_IMAGE_STR_APPEND
#elif CFG_SSD1306
    //SSD1306 0,96'' OLED
    #if MY_LANGUAGE == de_DE
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4_SSD1306\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relais1|WebButton2 Relais2|WebButton3 Relais3|WebButton4 Relais4|WebButton5 Display\"}"
    #else
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4_SSD1306\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relay1|WebButton2 Relay2|WebButton3 Relay3|WebButton4 Relay4|WebButton5 Display\"}"
    #endif

    #define USER_RULE3 ":H,SSD1306,128,64,1,I2C,3c,*,*,* :S,0,2,1,0,30,20 :I AE D5,80 A8,3F D3,00 40 8D,14 20,00 A1 C8 DA,12 81,9F D9,F1 DB,40 A4 A6 AF :o,AE :O,AF :A,00,10,40,00,00 :i,A6,A7"
    #ifdef USER_BACKLOG_SENSOR
        #define USER_BACKLOG "DisplayModel 17; DisplayMode 1; " USER_BACKLOG_SENSOR
    #else
        #define USER_BACKLOG "DisplayModel 17; DisplayMode 1"
    #endif
    #define CODE_IMAGE_STR "ESP12F-Relay-X4 SSD1306" CODE_IMAGE_STR_APPEND
#else
    #if MY_LANGUAGE == de_DE
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4\",\"GPIO\":[1,1,1,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relais1|WebButton2 Relais2|WebButton3 Relais3|WebButton4 Relais4\"}"
    #else
        #define USER_TEMPLATE "{\"NAME\":\"ESP12F_Relay_X4\",\"GPIO\":[1,1,1,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relay1|WebButton2 Relay2|WebButton3 Relay3|WebButton4 Relay4\"}"
    #endif
    
    #define CODE_IMAGE_STR "ESP12F-Relay-X4" CODE_IMAGE_STR_APPEND
#endif
