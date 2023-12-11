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
#include <stdlib.h>
#include <string.h> 
#include <xc.h>

uint8_t nwkSKey[16] = {0xCB, 0x1E, 0x88, 0x5D, 0x5D, 0xF1, 0x12, 0xD5, 0x08,
0xCC, 0xB9, 0xD1, 0xD4, 0x4B, 0x1E, 0xDF};
uint8_t appSKey[16] = {0x96, 0x23, 0x5A, 0x1F, 0x9A, 0xE1, 0x60, 0x36, 0x81,
0xC4, 0xE4, 0xB5, 0x54, 0xC3, 0xCA, 0xB5};
uint32_t devAddr = 0x3DEF5E47;

int testassign;   //char di
int testassign2;

int fourthdigit; 
int thirddigit; 
int seconddigit; 
int firstdigit; 

int resultdata2send;

char tosend[5];

int first1decimal; 
int first2decimal; 
int first3decimal; 
int first4decimal; 
int first5decimal; 

char testtest[5] = "12345";

uint8_t counter = 0; 
int countera;
int n;

char dataxstr[];
char sub[64];

char hexNum[] = "1A";
int cout;

int hexadecimalToDecimal(char hexVal[]);

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
    
    LORAWAN_Init(RxData, RxJoinResponse);
    
    LORAWAN_SetNetworkSessionKey(nwkSKey);
    LORAWAN_SetApplicationSessionKey(appSKey);
    LORAWAN_SetDeviceAddress(devAddr);
    LORAWAN_Join(ABP);
    TRISA = 0xF0;
    countera=0;
    while (1)
    {
        LORAWAN_Mainloop();
        
        if (TMR5_HasOverflowOccured())
        {
            counter ++;
            
            TMR5IF = 0;
            
        }
        
        if (counter == 2)
        {   
            LATA=0xFF;
            
            EUSART1_Write(0b00000011);//03
            EUSART1_Write(0b00000011);//03
            EUSART1_Write(0b00000000);//00
            EUSART1_Write(0b01000111);//47
            EUSART1_Write(0b00000000);//00
            EUSART1_Write(0b00000001);//01
            EUSART1_Write(0b00110101);//35
            EUSART1_Write(0b11111101);//FD
            
            EUSART1_Write(0b00000011);//03
            EUSART1_Write(0b00000011);//03
            EUSART1_Write(0b00000000);//00
            
            LATA=0xF0;
            
            __delay_ms(5000);
            
            testassign = dataxstr[3];
            testassign2 = dataxstr[4];
            
            fourthdigit = (testassign / 16);
            thirddigit = (testassign % 16);
            seconddigit = (testassign2 / 16);
            firstdigit = (testassign2 % 16);
            
            resultdata2send = (fourthdigit*16*16*16) + (thirddigit*16*16) + (seconddigit*16) + firstdigit;
            
            first1decimal = (resultdata2send % 10);
            first2decimal = (resultdata2send % 100)/10;
            first3decimal = (resultdata2send % 1000)/100;
            first4decimal = (resultdata2send % 10000)/1000;
            first5decimal = (resultdata2send % 100000)/10000;
            
            char first1decimalc = first1decimal+48;
            char first2decimalc = first2decimal+48;
            char first3decimalc = first3decimal+48;
            char first4decimalc = first4decimal+48;
            char first5decimalc = first5decimal+48;
   
   tosend[4] = first1decimalc;
   tosend[3] = first2decimalc;
   tosend[2] = first3decimalc;
   tosend[1] = first4decimalc;
   tosend[0] = first5decimalc;
            
            //tosend[] = {};
            
            //testassign3 = dataxstr[3]+""+dataxstr[4];
            
            //cout = (int)testassign;
            //cout = hexadecimalToDecimal((hex)cout); 
            //cout = (int)testassign; 
            
            //LORAWAN_Send(UNCNF, 2, "new", 3);
            LORAWAN_Send(UNCNF, 2, tosend, 5);
            
            counter = 0;
        }
    }
}

// Function to convert hexadecimal to decimal 
int hexadecimalToDecimal(char hexVal[]) 
{    
    int len = strlen(hexVal); 
      
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
      
    int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            dec_val += (hexVal[i] - 55)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 