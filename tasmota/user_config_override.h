/* user defined configs */

// -- Setup your own Wifi settings  ---------------
// #define CFG_PRIVATE
#ifdef CFG_PRIVATE
    #include "user_config_wifi.h"
#endif

#ifdef CFG_ESP12F_Relay_X4
    #include "user_config_ESP12F_Relay_X4.h"
#endif
