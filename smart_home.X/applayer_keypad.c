#include "Config.h"



char x1[] = "ENTER ur password";
char x2[] = "Accesed";
char x3[] = "Access Denied";

char x4[] = "incorrect";
char x5[] = "Wellcome ....";
char x6[] = "1>>DOOR";
char x7[] = "2>>TEMP";
char x8[] = "3>>LOG OUT";

char x10[] = "1>>OPEN";
char x11[] = "2>>CLOSE";

char x12[] = "0 >>>ReturnHome";
char x13[] = "Temp = ";





char __pass[10];
int __counter = 0;

void app_start_keypad() {

    while (1) {

        LCD_clear_4bit();
        LcdWrite_str_4bit(x1); //enter ur pass....


        for (int i = 0; __pass[i - 1] != '*'; i++) {

            __pass[i] = getKey();
            _delay_ms(10);
            LCD_clear_4bit();
            LcdWrite_str_4bit(__pass);
        }




        int z = check_str_pass(0, __pass);

        if (z == 1) {

            LCD_clear_4bit();
            LcdWrite_str_4bit(x2); //Accessed...
            _delay_ms(1500);
            for (int i = 0; i < 5; i++) {

                __pass[i] = 0;
            }

            break;



        } else {

            __counter++;


            if (__counter == 3) {
                LCD_clear_4bit();
                LcdWrite_str_4bit(x3);
                while (1);
            }
            LCD_clear_4bit();
            LcdWrite_str_4bit(x4);
            _delay_ms(500);
            for (int i = 0; i < 5; i++) {

                __pass[i] = 0;
            }
        }
    }
}
char app_home_keypad() {
    
    char data = 0;

    //Wellcome....
    LCD_clear_4bit();
    LcdWrite_str_4bit(x5);
    _delay_ms(1500);
    //1>>DOOR...
    LCD_clear_4bit();
    LcdWrite_str_4bit(x6);
    //2>>TEMP...
    LCD_goto_4bit(_ROW0, 8);
    LcdWrite_str_4bit(x7);
    //3>>LOG OUT.....
    LCD_goto_4bit(_ROW1, 0);
    LcdWrite_str_4bit(x8);

    data = getKey();

    return data;
}
// return >>> 0 >>>> return home
// return >>> 1 >>>> success

int app_options_keypad(char option) {


    if (option == '1') {
        
        //DOOR........

        app_Door_keypad();

        return 0;
    } else if (option == '2') {
        
        //TeMP...........

        app_Temp_Keypad();

        return 0;

    } else if (option == '3') {

        //LOG OUT OPTION....

        return 1;
    }
    return 0;
}
int app_Door_keypad() {

    char data;
    //Open......
    LCD_clear_4bit();
    LcdWrite_str_4bit(x10);   
    //Close.....
    LCD_goto_4bit(_ROW0, 8);
    LcdWrite_str_4bit(x11);
    //Return home......
    LCD_goto_4bit(_ROW1, 0);
    LcdWrite_str_4bit(x12);
    
    data = getKey();
    
    if (data == '1') {
        
        uart_send('1');
       

    } else if (data == '2') {

        uart_send('2');
       
    } else if (data == '0') {
        return 0;
    }
    return 1;
}



int app_Temp_Keypad(){
    init_Timer(Normal_mode, CS_prescal_1024);
    Timer_Int_Enable(INT_TOV);
    while(1){
        char data;
        int temp = Lm_35();
        //Temperature = num
        LCD_clear_4bit();
        LcdWrite_str_4bit(x13);
        //Display num...................
        LCD_goto_4bit(_ROW0, 8);
        LcdWrite_num_4bit(temp);
        //Return home......
        LCD_goto_4bit(_ROW1, 0);
        LcdWrite_str_4bit(x12);
        if(temp >= 28){
            //set buzzer............
            uart_send('3');
            
        }else{
            uart_send('4');
            
        }
        
        
        data = getKey();
        
        if (data == '0') {
            
            init_Timer(Normal_mode, CS_Timer_off);
            Timer_Int_Disable(INT_TOV);
            
            return 0;
        }
        
        
    }
    
}


int Lm_35() {
    int data = 0;
    int volt = 0;
    int temp = 0;
    init_ADC(_CH0, _AVCC, Right_Adjusted, _PRE128);
    Start_Conversion();
    data = ADC_READ_Right();
    volt = (data * 5); //mv 
    temp = (volt / 10);
   
    return temp;
    
    
}