/*
 * File:   Blinky.c
 * Author: Lenovo
 *
 * Created on February 13, 2020, 11:49 AM
 */


#include <xc.h>

void main(void) {
    unsigned int i;
    TRISB = 0xF0; //rb0-3 output, 4-7 input
    
    while(1){
        
        LATB = 0xF0; //make the pins low
        for(i = 0;i<1000;i++);
        LATB = 0xFF; //make the pins high
        for(i = 0;i<1000;i++);
        
    }
    //return;
}
