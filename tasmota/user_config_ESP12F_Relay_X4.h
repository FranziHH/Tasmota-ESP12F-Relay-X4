/* additional config for ESP12F-Relay-X4 */

// only Test if include works
// #error "Board was not recognized"

#define USE_WEB_STATUS_LINE_WIFI

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

#define USER_TEMPLATE_DISPLAY
#define USER_TEMPLATE_SENSOR
#define DISPLAY_MODE "DisplayMode 1; "
#define CODE_IMAGE_STR_APPEND " [FW]"
// Change, if timezone is unwanted
#define USER_BACKLOG_TIMEZONE "; timezone 99"

#ifdef FIRMWARE_SENSORS
    #ifdef CFG_BMP280_AHT20
        #define USER_RULE1 "on System#Boot do RuleTimer1 10 endon on Rules#Timer=1 do Backlog displaytext [l1c4T] [l1c14t]; RuleTimer1 10 endon on tele-BMP280#Temperature do DisplayText [l3c1]Temp  :   %value% C~20~20 endon on tele-BMP280#Pressure do DisplayText [l4c1]Press : %value% hPa~20~20 endon on tele-AHT2X#Temperature do DisplayText [l6c1]Temp  :   %value% C~20~20 endon on tele-AHT2X#Humidity do DisplayText [l7c1]Hum   :   %value% %~20~20 endon on tele-AHT2X#dewpoint do DisplayText [l8c1]DPoint:    %value% C~20~20 endon"
        #ifdef USE_AHT2x
            #undef USE_AHT2x
        #endif
        #define USE_AHT2x
        // https://tasmota.github.io/docs/AHT2x/#troubleshooting
        #define USER_BACKLOG_SENSOR "I2CDriver12 0; I2CDriver43 1"

        #ifdef DISPLAY_MODE
            #undef DISPLAY_MODE
        #endif
        #define DISPLAY_MODE "DisplayMode 0; DisplayFont 0; Rule1 1; RuleTimer1 1; TelePeriod 15; "

        #ifdef CODE_IMAGE_STR_APPEND
            #undef CODE_IMAGE_STR_APPEND
        #endif
        #define CODE_IMAGE_STR_APPEND " BMPAHT"

        #ifdef USER_TEMPLATE_SENSOR
            #undef USER_TEMPLATE_SENSOR
        #endif
        #define USER_TEMPLATE_SENSOR " BMP280/AHT20"
    #else
        #ifdef CODE_IMAGE_STR_APPEND
            #undef CODE_IMAGE_STR_APPEND
        #endif
        #define CODE_IMAGE_STR_APPEND " Sensor"

        #ifdef USER_TEMPLATE_SENSOR
            #undef USER_TEMPLATE_SENSOR
        #endif
        #define USER_TEMPLATE_SENSOR " Sensor"
    #endif
    
#endif

#ifdef CFG_DISPLAY
    //Display prepared
    #ifdef USER_TEMPLATE_DISPLAY
        #undef USER_TEMPLATE_DISPLAY
    #endif
    #define USER_TEMPLATE_DISPLAY " Display"

    #define CODE_IMAGE_STR "ESP12F-Relay-X4 Display" CODE_IMAGE_STR_APPEND
#elif CFG_SH1106
    //SH1106 1,3'' OLED
    #ifdef USER_TEMPLATE_DISPLAY
        #undef USER_TEMPLATE_DISPLAY
    #endif
    #define USER_TEMPLATE_DISPLAY " SH1106"

    #define USER_RULE3 ":H,SH1106,128,64,1,I2C,3c,*,*,* :S,0,2,1,0,30,20 :I AE D5,80 A8,3f D3,00 40 8D,14 20,00 A1 C8 DA,12 81,CF D9F1 DB,40 A4 A6 AF :o,AE :O,AF :A,00,10,40,00,02 :i,A6,A7"
    #ifdef USER_BACKLOG_SENSOR
        #define USER_BACKLOG "DisplayModel 17; " DISPLAY_MODE USER_BACKLOG_SENSOR USER_BACKLOG_TIMEZONE
    #else
        #define USER_BACKLOG "DisplayModel 17; " DISPLAY_MODE USER_BACKLOG_TIMEZONE
    #endif
    #define CODE_IMAGE_STR "ESP12F-Relay-X4 SSH1106" CODE_IMAGE_STR_APPEND
#elif CFG_SSD1306
    //SSD1306 0,96'' OLED
    #ifdef USER_TEMPLATE_DISPLAY
        #undef USER_TEMPLATE_DISPLAY
    #endif
    #define USER_TEMPLATE_DISPLAY " SSD1306"

    #define USER_RULE3 ":H,SSD1306,128,64,1,I2C,3c,*,*,* :S,0,2,1,0,30,20 :I AE D5,80 A8,3F D3,00 40 8D,14 20,00 A1 C8 DA,12 81,9F D9,F1 DB,40 A4 A6 AF :o,AE :O,AF :A,00,10,40,00,00 :i,A6,A7"
    #ifdef USER_BACKLOG_SENSOR
        #define USER_BACKLOG "DisplayModel 17; " DISPLAY_MODE USER_BACKLOG_SENSOR USER_BACKLOG_TIMEZONE
    #else
        #define USER_BACKLOG "DisplayModel 17; " DISPLAY_MODE USER_BACKLOG_TIMEZONE
    #endif
    #define CODE_IMAGE_STR "ESP12F-Relay-X4 SSD1306" CODE_IMAGE_STR_APPEND
#else
    #define CODE_IMAGE_STR "ESP12F-Relay-X4" CODE_IMAGE_STR_APPEND
#endif

#if MY_LANGUAGE == de_DE
    #define USER_TEMPLATE "{\"NAME\":\"ESP12F-Relay-X4" USER_TEMPLATE_DISPLAY USER_TEMPLATE_SENSOR"\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relais1|WebButton2 Relais2|WebButton3 Relais3|WebButton4 Relais4|WebButton5 Display\"}"
#else
    #define USER_TEMPLATE "{\"NAME\":\"ESP12F-Relay-X4" USER_TEMPLATE_DISPLAY USER_TEMPLATE_SENSOR"\",\"GPIO\":[640,5730,608,1,1,320,1,1,225,224,226,227,1,1],\"FLAG\":0,\"BASE\":18,\"CMND\":\"WebButton1 Relay1|WebButton2 Relay2|WebButton3 Relay3|WebButton4 Relay4|WebButton5 Display\"}"
#endif
