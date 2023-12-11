/**
  Generated Main Source File
  Company:
    Microchip Technology Inc.
  File Name:
    main.c
  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs
  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18LF46K22
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart1.h"
#include <stdio.h> 
#include <string.h> 

uint8_t nwkSKey[16] = {0xCB, 0x1E, 0x88, 0x5D, 0x5D, 0xF1, 0x12, 0xD5, 0x08,
0xCC, 0xB9, 0xD1, 0xD4, 0x4B, 0x1E, 0xDF};
uint8_t appSKey[16] = {0x96, 0x23, 0x5A, 0x1F, 0x9A, 0xE1, 0x60, 0x36, 0x81,
0xC4, 0xE4, 0xB5, 0x54, 0xC3, 0xCA, 0xB5};
uint32_t devAddr = 0x3DEF5E47;

uint8_t counter = 0; 
uint8_t datax;
uint8_t dataxsolved;

int datatobesolved;
int n;

int bitStatusbefore1;
int bitStatusbefore2;
int bitStatusbefore3;
int bitStatusbefore4;
int bitStatusbefore5;
int bitStatusbefore6;
int bitStatusbefore7;

int bitStatus;
int bitStatus1;
int bitStatus2;
int bitStatus3;
int bitStatus4;
int bitStatus5;
int bitStatus6;
int bitStatus7;

int dataresult;

//char datax;
char dataxstr[];
//char stringserial[];
char readurt[8];
char character;




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
  
 void usart_txs(unsigned char *s)
 {
     // Takes a string and transmits each character one by one.
     // s++ increments the pointer address until the end of the string.
     while(*s)
     {
         usart_txc(*s);
         s++;
     }
 }
void UART_Read_Text(char *Output, unsigned int length)
{
  unsigned int i;
  for(i=0;i<length;i++)
  {
      Output[i] = EUSART1_Read();
  }
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
/*
    //LORAWAN_Reset(ISM_EU868);
    LORAWAN_Init(RxData, RxJoinResponse);
    LORAWAN_SetNetworkSessionKey(nwkSKey);
    LORAWAN_SetApplicationSessionKey(appSKey);
    LORAWAN_SetDeviceAddress(devAddr);
    LORAWAN_Join(ABP);
    
    TRISA = 0xF0;*/
    
    /*LATA = 0xFF;
    usart_txs("/?!\r\n");
    LATA = 0xF0;
    for(int i=0;i<10;i++){
        datax = EUSART1_Read();
        strncat(dataxstr, &datax, 1);
    }*/
    
    /*for(int k=0;k<100;k++){
        dataxstr[k] = 0x31;
    }*/
    TRISA = 0xF0;
    LATA=0xFF;
    EUSART1_Write(0b10101111);
    EUSART1_Write(0b00111111);
    EUSART1_Write(0b00100001);
    EUSART1_Write(0b10001101);
    EUSART1_Write(0b00001010);
    LATA=0xF0;
    
    /*for(int j =0;j<512;j++){
                datax = EUSART1_Read();
                if(datax){
                datatobesolved = datax;
                bitStatusbefore1 = (datatobesolved >> 0) & 1;
                bitStatusbefore2 = (datatobesolved >> 1) & 1;
                bitStatusbefore3 = (datatobesolved >> 2) & 1;
                bitStatusbefore4 = (datatobesolved >> 3) & 1;
                bitStatusbefore5 = (datatobesolved >> 4) & 1;
                bitStatusbefore6 = (datatobesolved >> 5) & 1;
                bitStatusbefore7 = (datatobesolved >> 6) & 1;

                bitStatus1 = bitStatusbefore1<<0;
                bitStatus2 = bitStatusbefore2<<1;
                bitStatus3 = bitStatusbefore3<<2;
                bitStatus4 = bitStatusbefore4<<3;
                bitStatus5 = bitStatusbefore5<<4;
                bitStatus6 = bitStatusbefore6<<5;
                bitStatus7 = bitStatusbefore7<<6;

                dataresult = bitStatus7 | bitStatus6 | bitStatus5 | bitStatus4 | bitStatus3 | bitStatus2 | bitStatus1;
     
                strncat(dataxstr, &dataresult, 1);}
                }*/
    
    while (1)
    {
            LATA=0xFF;
            EUSART1_Write(0b10101111);
            EUSART1_Write(0b00111111);
            EUSART1_Write(0b00100001);
            EUSART1_Write(0b10001101);
            EUSART1_Write(0b00001010);
            LATA=0xF0;
            
            for(int j =0;j<1000;j++){
                datax = EUSART1_Read();
                if(datax != 0x00){
                datatobesolved = datax;
                bitStatusbefore1 = (datatobesolved >> 0) & 1;
                bitStatusbefore2 = (datatobesolved >> 1) & 1;
                bitStatusbefore3 = (datatobesolved >> 2) & 1;
                bitStatusbefore4 = (datatobesolved >> 3) & 1;
                bitStatusbefore5 = (datatobesolved >> 4) & 1;
                bitStatusbefore6 = (datatobesolved >> 5) & 1;
                bitStatusbefore7 = (datatobesolved >> 6) & 1;

                bitStatus1 = bitStatusbefore1<<0;
                bitStatus2 = bitStatusbefore2<<1;
                bitStatus3 = bitStatusbefore3<<2;
                bitStatus4 = bitStatusbefore4<<3;
                bitStatus5 = bitStatusbefore5<<4;
                bitStatus6 = bitStatusbefore6<<5;
                bitStatus7 = bitStatusbefore7<<6;

                dataresult = bitStatus7 | bitStatus6 | bitStatus5 | bitStatus4 | bitStatus3 | bitStatus2 | bitStatus1;
                for(int delay=0;delay<3000;delay++){
                    
                }
                strncat(dataxstr, &dataresult, 1);}
                }
            /*
            if (TMR5_HasOverflowOccured())  							//Has T5 Overflowed?
            {
                counter ++;
                TMR5IF = 0;                 							//Clear the T5 overflow flag
            }

            if (counter == 1)
            {   
                LATA=0xFF;
                EUSART1_Write(0b10101111);
                EUSART1_Write(0b00111111);
                EUSART1_Write(0b00100001);
                EUSART1_Write(0b10001101);
                EUSART1_Write(0b00001010);
                LATA=0xF0;
                counter = 0;
                
                for(int j =0;j<1000;j++){
                datax = EUSART1_Read();
                if(datax){
                datatobesolved = datax;
                bitStatusbefore1 = (datatobesolved >> 0) & 1;
                bitStatusbefore2 = (datatobesolved >> 1) & 1;
                bitStatusbefore3 = (datatobesolved >> 2) & 1;
                bitStatusbefore4 = (datatobesolved >> 3) & 1;
                bitStatusbefore5 = (datatobesolved >> 4) & 1;
                bitStatusbefore6 = (datatobesolved >> 5) & 1;
                bitStatusbefore7 = (datatobesolved >> 6) & 1;

                bitStatus1 = bitStatusbefore1<<0;
                bitStatus2 = bitStatusbefore2<<1;
                bitStatus3 = bitStatusbefore3<<2;
                bitStatus4 = bitStatusbefore4<<3;
                bitStatus5 = bitStatusbefore5<<4;
                bitStatus6 = bitStatusbefore6<<5;
                bitStatus7 = bitStatusbefore7<<6;

                dataresult = bitStatus7 | bitStatus6 | bitStatus5 | bitStatus4 | bitStatus3 | bitStatus2 | bitStatus1;
                strncat(dataxstr, &dataresult, 1);}
                }
            }*/   
            
            //__delay_ms(2000);
            /*EUSART1_Write(0b10101111);
            EUSART1_Write(0b00111111);
            EUSART1_Write(0b00100001);
            EUSART1_Write(0b10001101);
            EUSART1_Write(0b00001010);*/
            
            /*for(int j = 0; j<20; j++){
            datax = EUSART1_Read();
            datatobesolved = datax;
            bitStatusbefore1 = (datatobesolved >> 0) & 1;
            bitStatusbefore2 = (datatobesolved >> 1) & 1;
            bitStatusbefore3 = (datatobesolved >> 2) & 1;
            bitStatusbefore4 = (datatobesolved >> 3) & 1;
            bitStatusbefore5 = (datatobesolved >> 4) & 1;
            bitStatusbefore6 = (datatobesolved >> 5) & 1;
            bitStatusbefore7 = (datatobesolved >> 6) & 1;
            bitStatus1 = bitStatusbefore1<<0;
            bitStatus2 = bitStatusbefore2<<1;
            bitStatus3 = bitStatusbefore3<<2;
            bitStatus4 = bitStatusbefore4<<3;
            bitStatus5 = bitStatusbefore5<<4;
            bitStatus6 = bitStatusbefore6<<5;
            bitStatus7 = bitStatusbefore7<<6;
            dataresult = bitStatus7 | bitStatus6 | bitStatus5 | bitStatus4 | bitStatus3 | bitStatus2 | bitStatus1;
            strncat(dataxstr, &dataresult, 1);
            }*/
            
    }
}