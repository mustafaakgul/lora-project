/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    UART_Demo.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16F1709
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
unsigned char temp;

void UART_Demo_Initialize(void) 
{
   
    printf("\rPICDEM LAB II - Date 08/11/2015\r\n");  
    printf("UART Communications 8-bit Rx and Tx\r\n\n");
    printf("Keyboard Type H : LED ON   Type L: LED OFF \r\n\n");
    
}

void UART_Demo_Command_INT(void) 
{    
    if(eusartRxCount!=0) 
    {   
       
    temp=EUSART_Read();  // read a byte for RX

    EUSART_Write(temp);  // send a byte to TX  (from Rx)

    switch(temp)    // check command  
    {case 'H':
     case 'h':
        {
            LED_SetHigh();
            printf(" -> LED On!!      \r");             
            break;
        }
     case 'L':
     case 'l':
        {
            LED_SetLow();
            printf(" -> LED Off!!     \r");   
            break;
        }
     default:
        {
            printf(" -> Fail Command!! \r");            
            break;
        }       
    }
    }
    
}
/**
 End of File
 */