#include <avr/io.h>
#include "Config.h"



int main(void) {
    
    


    Init_Buzzer(); 
    init_uart(9600, Rx_enable, Tx_enable);



    

    while (1) {
        
        applayer_Slave();
    }
}