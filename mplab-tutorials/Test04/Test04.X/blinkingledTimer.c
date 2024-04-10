/*
 * File:   blinkingledTimer.c
 * Author: Lenovo
 *
 * Created on February 17, 2020, 11:46 AM
 */


#include <xc.h>


//RESULT IN LOGIC ANALYSER  square wave at output pin

void main(void) {
    
    
    ADCON1 = 0xFF;
    TRISB = 0xF0;
    LATB = 0xF0;
    
    T0CONbits.TMR0ON=0; //timer 0 stopped
    T0CONbits.T08BIT = 0 //enable 16 bit mode
    T0CONbits.T0CS=0;//internal clock source
    T0CONbits.PSA=0;//prescalar not assigned
   // T0CONbits.TOPS=100;
    INTCONbits.TMR0IF=0;//CLEAR the overflow flg
    
    TMR0H=0x3C; //insert reload value
    TMR0L=0xB0;
    
    T0CONbits.TMR0ON=1;//timerstarted
    
    while(!INTCONbits.TMR0IF==0){ //WA?T 4 T?MER OVERFLOW
        TMR0H=0x3C;
        TMR0L=0xB0;
        LATB^=0xOF;
        INTCONbits.TMR0IF=0;
    }
}
