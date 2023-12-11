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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
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

/*
                         Main application
 */

uint8_t nwkSKey[16] = {0xCB, 0x1E, 0x88, 0x5D, 0x5D, 0xF1, 0x12, 0xD5, 0x08,
0xCC, 0xB9, 0xD1, 0xD4, 0x4B, 0x1E, 0xDF};
uint8_t appSKey[16] = {0x96, 0x23, 0x5A, 0x1F, 0x9A, 0xE1, 0x60, 0x36, 0x81,
0xC4, 0xE4, 0xB5, 0x54, 0xC3, 0xCA, 0xB5};
uint32_t devAddr = 0x3DEF5E47;
void RxData(uint8_t* pData, uint8_t dataLength, OpStatus_t status)
{}
void RxJoinResponse(bool status)
{}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    LORAWAN_Init(RxData, RxJoinResponse);
    LORAWAN_SetNetworkSessionKey(nwkSKey);
    LORAWAN_SetApplicationSessionKey(appSKey);
    LORAWAN_SetDeviceAddress(devAddr);
    LORAWAN_Join(ABP);
    
    TRISA = 0xF0;
    LATA = 0xFC;
    
    /*
    uint16_t adc_value;
    TRISAbits.TRISA0 = 0; //set output
    TRISAbits.TRISA2 = 1; //set pin as input
    ANCON0bits.ANSEL2 = 0; //set pins as digital
    */

    while (1)
    {
        //////////////////////
        /*
        if(PORTAbits.RA4){
            LATA = 0xFC;
            //LATAbits.LATA0 = 1;  //set the pin as high
        }
        else{
            LATA = 0xF3;
        }*/
        /*
        else{
            LATAbits.LATA0 = 0; //set pin low
            adc_value = adc_convert(1); //aas channel 1
            wait_ms(adc_value>>2);
            LATAbits.LATA0 = 1;
            adc_value = adc_convert(1); //aas channel 1
            wait_ms(adc_value>>2);
        }
         * */
        ///////////////////////////
        
        //----------------------------------------
        //FUTURE OONFIG
        
        //Adaptive Date Rate
        //LORAWAN_SetAdr (true); 
        //bool adrStatus; adrStatus = LORAWAN_GetAdr();
        //----------------------------------------
        
    // Add your application code
    //LORAWAN_Mainloop();
    // All other function calls of the user-defined
    // application must be made here
    //LORAWAN_Send(UNCNF, 2, "LoRax", 5);
        
    __delay_ms(500);
    //printf("gone");
    __delay_ms(500);
    }
}
/**
 End of File
*/