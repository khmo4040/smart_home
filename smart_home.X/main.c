#include <avr/io.h>
#include "Config.h"


char x22[] = "0 >>>ReturnHome";

char x21[] = "Temp = ";

ISR(TIMER0_OVF_vect) {

    static int x = 0;
    
    x++;
    
    if (x == 62 * sec) {
        x = 0;
        
        int temp = Lm_35();
        if(temp >= 28){
            //set buzzer............
            uart_send('3');
        }else{
            uart_send('4');
        }
        
        
        /*
        if (temp != temp1){
            //Temperature = num
            LCD_clear_4bit();
            LcdWrite_str_4bit(x21);
            //Display num...................
            LCD_goto_4bit(_ROW0, 8);
            LcdWrite_num_4bit(temp);
            //Return home......
            LCD_goto_4bit(_ROW1, 0);
            LcdWrite_str_4bit(x22);
            
            
        }
        temp1=temp;
         */
     
        
    }

}



int main(void) {
    
    write_EEPROM_num(0, 1111);
    init_keypad();

    init_uart(9600, Rx_enable, Tx_enable);

    
    Init_Lcd_4bit();
    _delay_ms(10);





    int __f = 1;

    while (1) {

        if (__f == 1)
            app_start_keypad();

        char option = app_home_keypad();

        __f = app_options_keypad(option);



    }
}