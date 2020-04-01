
#include "mbed.h"

#include "uLCD_4DGL.h"
PwmOut PWM1(D6);
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main()

{

    uLCD.printf("\n107033137\n"); //Default Green on black text

    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);

    uLCD.color(RED);
uLCD.line(0,0,0,5,RED);
uLCD.line(0,5,5,5,RED);
uLCD.line(5,5,5,0,RED);
uLCD.line(5,0,0,0,RED);
    float dutycycle = 0;
    int flag = 0;
    while(1){

        PWM1.period(0.001);
        PWM1 = dutycycle;
        if(dutycycle==1.0){
            flag = 1;
        }
        else if(dutycycle==0){
            flag = 0;
        }
        if(flag == 0){
            dutycycle+=0.1;
        }
        else if(flag==1){
            dutycycle -= 0.1;
        }  
        wait(1);
    }

}