/*
 * File:   test.c
 * Author: Lenovo
 *
 * Created on February 17, 2020, 9:38 AM
 */


#include <xc.h>

void main(void) {
    
    //SWITCH LED ON OFF
    
    //TRISB = 0x01;  //rb0 is input and others output
    //TRISB |=0x01;  //rb0 is input and others are unaffected
    //TRISB &= 0b11111101; //rb1 is putput and others unaffected
    //TRISB &= 0xFD; //
    //TRISB&= ~(0x02);  //~0x02 is 0xFD rb1 is output
    /*
    TRISB |= 0x01;
    TRISB &= ~(0x02);
    
    while(1){
        
        if(PORTB & 0x01){
            LATB &= (0x02); //led off
        }
        else{
            LATB |= 0x02; //led is on
        }
        
    }*/
    
    
    TRISB = 0x01; //rb0 is pin input and all other pins are unaffected
    ADCON1 = 0x0F; //assign port b as digital IO
    LATB = (0x00); //make led off
    
    while(1){
        if(PORTBbits.RB0 ==0){   //if(RB0 == 0)
            LATB = (0x02);
        }
        else{
            LATB = (0x00);
        }
    }
    
}
