/*
 * File:   serialComm.c
 * Author: Lenovo
 *
 * Created on February 17, 2020, 12:58 PM
 */


#include <xc.h>

void main(void) {
    
    
    TRISB = 0xF0;
    LATB = OxF0;
    
    TRISCbits.RC6 = 0;//TX MAKE AS OUTPUT
    TRISCbits.RC7 = 1;//RX AS ?NPUT
    TXSTAbits.TXEN = 1;//ENABLE TRANSMISSON
    TXSTAbits.SYNC=0;//ENABLE ASYNC MODE
    TXSTAbits.BRGH = 0;//LOW SPEED
    RCSTAbits.SPEN = 1;//ENABLE SER?AL P?NS
    BAUDCONbits.BRG16=1;//16 B?T BAUD RATE MODE
    
    SPBRG=25;  //9600  BAUD
    SPBRGH=0;
    
    while(1){
        TXREG = 'a'; //=0x41;
        while(!TXSTAbits.TRMT);
    }
    
    
}
