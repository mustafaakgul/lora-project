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
#include <xc.h>

#define WDT_Enable() (WDTCONbits.SWDTEN = 1)
#define WDT_Disable() (WDTCONbits.SWDTEN = 0)
//#define abcdef()( CONFIG2Hbits.WDPS=1111 )

// Choose Activation Method ABP == 1; OTAA == 0; 
uint8_t activationMethod = 0;

uint8_t nwkSKey[16] = {0xCB, 0x1E, 0x88, 0x5D, 0x5D, 0xF1, 0x12, 0xD5, 0x08,
0xCC, 0xB9, 0xD1, 0xD4, 0x4B, 0x1E, 0xDF};
uint8_t appSKey[16] = {0x96, 0x23, 0x5A, 0x1F, 0x9A, 0xE1, 0x60, 0x36, 0x81,
0xC4, 0xE4, 0xB5, 0x54, 0xC3, 0xCA, 0xB5};
uint32_t devAddr = 0x3DEF5E47;
// Data to be send
uint8_t data[8]          	= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// Time counter 
uint8_t counter = 0; 

// ADC variables 
uint32_t adcResult = 0; 
uint32_t adcVoltage = 0;

// Function prototypes 
void RxData(uint8_t* pData, uint8_t dataLength, OpStatus_t status) { }
void RxJoinResponse(bool status) { }

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("\rSYSINIT!");         
    
    //LORAWAN_Reset(ISM_EU868);
    LORAWAN_Init(RxData, RxJoinResponse);
    
    
    
        // Activation Method ABP
        LORAWAN_SetNetworkSessionKey(nwkSKey);
        LORAWAN_SetApplicationSessionKey(appSKey);
        LORAWAN_SetDeviceAddress(devAddr);
        // Issue Join
        LORAWAN_Join(ABP);
        printf("\rABP Joined!");
    
           
        
        TRISA = 0x00;
        //LATA=0
        
        
        unsigned int i;
        
        //WDTCON.WDTPS = 0b01011;
        //WDTPS = 0b01110;
       // CONFIG2Hbits.WDPS=1111;
        //abcdef();
        
        OSCCONbits.SCS = 0b11;
        OSCCONbits.IDLEN = 0;
        
        //SLEEP();
       
    while (1)
    { 
        //SLEEP 0000000000000011
        //LATA = 0xFF; //make the pins high
        //LATB = 0xF0; //make the pins low
        //for(i = 0;i<1000;i++);
        //LATB = 0xFF; //make the pins high
        
        // Add your application code
        LORAWAN_Mainloop();
        
        // All other function calls of the user-defined
        // application must be made here
        
        if (TMR5_HasOverflowOccured())  							//Has T5 Overflowed?
        {
            counter ++;
            
            //adcResult = ADC_GetConversion(channel_AN0);           	// Read ADC Result when conversion is done
            //adcVoltage = 3.25513*adcResult;
            
            TMR5IF = 0;                 							//Clear the T5 overflow flag
            
            /*LATA=0xFF;
            __delay_ms(2000);
            LATA=0x00;*/
            
            LATAbits.LATA0=1;
            __delay_ms(2000);
            LATAbits.LATA0=0;
            
            
        }
        
        if (counter == 4)
        {   

            //data[6] = (uint16_t) adcVoltage >> 8;
            //data[7] = (uint16_t) adcVoltage & 0xFF;
            
            //data[6] = 0x12;
            //data[7] = 0x34;
            
            LORAWAN_Send(UNCNF, 2, "lora1", 5);
            
            counter = 0;
            
            
        }    
        
        //SLEEP();
        //WDT_Enable();
        /*SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        SLEEP();
        
        WDT_Enable();*/
        
    }
}
/**
 End of File
*/