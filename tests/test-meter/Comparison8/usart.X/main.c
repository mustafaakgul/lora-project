
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart1.h"
#include <stdio.h> 
#include <string.h> 

uint8_t nwkSKey[16] = {0xCB, 0x1E, 0x88, 0x5D, 0x5D, 0xF1, 0x12, 0xD5, 0x08,
0xCC, 0xB9, 0xD1, 0xD4, 0x4B, 0x1E, 0xDF};
uint8_t appSKey[16] = {0x96, 0x23, 0x5A, 0x1F, 0x9A, 0xE1, 0x60, 0x36, 0x81,
0xC4, 0xE4, 0xB5, 0x54, 0xC3, 0xCA, 0xB5};
uint32_t devAddr = 0x3DEF5E47;

int counterx;
char dataxstr[];
char sub[100];  //old 1024

void substring(char [], char[], int, int);

void RxData(uint8_t* pData, uint8_t dataLength, OpStatus_t status)
{}
void RxJoinResponse(bool status)
{}

void usart_txc(unsigned char c)
 {
     while(0 == PIR1bits.TX1IF)
    {
    }
         TXREG = c;
     
 }

char UART_Data_Ready()
{
  return PIR1bits.RC1IF;
}
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    TRISA = 0xF0;
    counterx=0;
    
    while (1)
    {
        if(counterx <1){
            LATA=0xFF;
            EUSART1_Write(0b10101111);
            EUSART1_Write(0b00111111);
            EUSART1_Write(0b00100001);
            EUSART1_Write(0b10001101);
            EUSART1_Write(0b00001010);
            
            EUSART1_Write(0b00101110);
            EUSART1_Write(0b00110000);
            EUSART1_Write(0b00110000);
            
            LATA=0xF0;
            
            __delay_ms(2000);
            
            LATA=0xFF;
                //SPBRG1 = 0xA0;
                //SPBRGH1 = 0x01;
            EUSART1_Write(0b00101110);
            EUSART1_Write(0b00110000);
            EUSART1_Write(0b00110000);
            EUSART1_Write(0b10110111);
            EUSART1_Write(0b10001101);
            EUSART1_Write(0b00001010);
            
            EUSART1_Write(0x61);
            EUSART1_Write(0x61);
            EUSART1_Write(0x61);
            LATA=0xF0;
            
            counterx++;
            __delay_ms(2000);
            __delay_ms(2000);
            __delay_ms(2000);
            __delay_ms(2000);

            substring(dataxstr, sub, 30, 10);

        }
    }
}

void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}