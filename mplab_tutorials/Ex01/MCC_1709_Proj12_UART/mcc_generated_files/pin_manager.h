/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB?Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB?Code Configurator - v2.25.2
        Device            :  PIC16F1709
        Version           :  1.01
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TX aliases
#define TX_TRIS               TRISB4
#define TX_LAT                LATB4
#define TX_PORT               RB4
#define TX_WPU                WPUB4
#define TX_ANS                ANSB4
#define TX_SetHigh()    do { LATB4 = 1; } while(0)
#define TX_SetLow()   do { LATB4 = 0; } while(0)
#define TX_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define TX_GetValue()         RB4
#define TX_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define TX_SetPullup()    do { WPUB4 = 1; } while(0)
#define TX_ResetPullup()   do { WPUB4 = 0; } while(0)
#define TX_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define TX_SetDigitalMode()   do { ANSB4 = 0; } while(0)
// get/set RX aliases
#define RX_TRIS               TRISB6
#define RX_LAT                LATB6
#define RX_PORT               RB6
#define RX_WPU                WPUB6
#define RX_SetHigh()    do { LATB6 = 1; } while(0)
#define RX_SetLow()   do { LATB6 = 0; } while(0)
#define RX_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define RX_GetValue()         RB6
#define RX_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define RX_SetPullup()    do { WPUB6 = 1; } while(0)
#define RX_ResetPullup()   do { WPUB6 = 0; } while(0)
// get/set LED aliases
#define LED_TRIS               TRISB7
#define LED_LAT                LATB7
#define LED_PORT               RB7
#define LED_WPU                WPUB7
#define LED_SetHigh()    do { LATB7 = 1; } while(0)
#define LED_SetLow()   do { LATB7 = 0; } while(0)
#define LED_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define LED_GetValue()         RB7
#define LED_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define LED_SetPullup()    do { WPUB7 = 1; } while(0)
#define LED_ResetPullup()   do { WPUB7 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */