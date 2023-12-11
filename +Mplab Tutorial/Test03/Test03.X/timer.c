/*
 * File:   timer.c
 * Author: Lenovo
 *
 * Created on February 17, 2020, 10:37 AM
 */


#include <xc.h>

void main(void) {
    
    
    TRISB = 0xF0;
    LATB = 0xF0;
    
    T0CONbits.TMR0ON=0; //timer 0 stopped
    T0CONbits.T08BIT = 0 //enable 16 bit mode
    T0CONbits.T0CS=0;//internal clock source
    T0CONbits.PSA=1;//prescalar not assigned
    INTCONbits.TMR0IF=0;//CLEAR the overflow flg
    
    TMR0H=0x3C; //insert reload value
    TMR0L=0xB0;
    
    T0CONbits.TMR0ON=1;//timerstarted
    
    
    while(!INTCONbits.TMR0IF){ //WA?T 4 T?MER OVERFLOW
        TMR0H=0x3C;
        TMR0L=0xB0;
        LATB^=0xOF;
        INTCONbits.TMR0IF=0;
    }
}
