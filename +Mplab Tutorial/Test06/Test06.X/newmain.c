/*
 * File:   newmain.c
 * Author: Lenovo
 *
 * Created on February 18, 2020, 10:15 AM
 */


#include <xc.h>

void main(void) {
    
    TRISB = 0x0F;
    LATB = 0x0F;
    unsigned int ADCval = 0;
    
    ADCON1bits.PCFG=0x0E;
    ADCON1bits.VCFG=0;
    ADCON0bits.CHS=0;
    ADCON2bits.ADFM=1;
    ADCON2bits.ADCS=0x07;
    ADCON0bits.ADON=1;
    
    while(1){
        ADCON0bits.GO=1;
        while(ADCON0bits.DONE);
        ADCval=ADRESH;
        ADCval=ADCval<<8;
        ADCval|=ADRESL;
        
        if(ADCval<250){
            LATBbits.LATB0=0;
            LATBbits.LATB1=0;
            LATBbits.LATB2=0;
            LATBbits.LATB3=0;
        }
        else if((ADCval >250) && (ADCval<500)){
            LATBbits.LATB0=1;
            LATBbits.LATB1=0;
            LATBbits.LATB2=0;
            LATBbits.LATB3=0;
        }
        else if((ADCval >750) && (ADCval<1000)){
            LATBbits.LATB0=1;
            LATBbits.LATB1=1;
            LATBbits.LATB2=1;
            LATBbits.LATB3=0;
        }
        else{
            LATBbits.LATB0=1;
            LATBbits.LATB1=1;
            LATBbits.LATB2=1;
            LATBbits.LATB3=1;
        }
    }
    
    
}
