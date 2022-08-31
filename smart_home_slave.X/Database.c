#include "Config.h"





int check_str_pass(unsigned int address, char *Input_password) {
    char user[4];
    int f = 0;
    for (int i = 0; i < 4; i++) {
        user [i] = read_EEPROM(address);
        address++;
    }
    for (int j = 0; user[j] != '\0' && f == 0; j++) {
        if (user[j] != Input_password[j]) {
            f = 1;
        } else {
            f = 0;
        }
    }
    if (f == 0) {
        return 1;
    }
    return 0;
}


