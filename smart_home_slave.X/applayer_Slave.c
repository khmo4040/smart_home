#include "Config.h"



char Data;


void applayer_Slave(){
    Data = uart_receive();
        
        

        switch(Data){
            case '1':
                SetPinDir(_PB, PB3, OUT);
                init_Timer(FPWM_mode, CS_prescal_1024);
                Compare_Match_Mode(COM_Clear_FPWM);
                Set_OC(38); //>>>>>>>>  servo (90)
                _delay_ms(1500);
                init_Timer(Normal_mode, CS_prescal_1024);
                break;
                
            case '2':
                SetPinDir(_PB, PB3, OUT);
                init_Timer(FPWM_mode, CS_prescal_1024);
                Compare_Match_Mode(COM_Clear_FPWM);
                Set_OC(22); //>>>>>>>>  servo (0)
                _delay_ms(1500);
                init_Timer(Normal_mode, CS_prescal_1024);
                break;
                
            case '3':
                Set_Buzzer(ON);
                break;
                
            case '4':
                Set_Buzzer(OFF);
                break;
                
            default:
                break;
        }
}
