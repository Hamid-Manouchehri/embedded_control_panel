/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1829
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PIN_COM_2 aliases
#define PIN_COM_2_TRIS                 TRISAbits.TRISA0
#define PIN_COM_2_LAT                  LATAbits.LATA0
#define PIN_COM_2_PORT                 PORTAbits.RA0
#define PIN_COM_2_WPU                  WPUAbits.WPUA0
#define PIN_COM_2_ANS                  ANSELAbits.ANSA0
#define PIN_COM_2_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PIN_COM_2_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PIN_COM_2_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PIN_COM_2_GetValue()           PORTAbits.RA0
#define PIN_COM_2_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PIN_COM_2_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PIN_COM_2_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PIN_COM_2_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PIN_COM_2_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define PIN_COM_2_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set PIN_COM_1 aliases
#define PIN_COM_1_TRIS                 TRISBbits.TRISB4
#define PIN_COM_1_LAT                  LATBbits.LATB4
#define PIN_COM_1_PORT                 PORTBbits.RB4
#define PIN_COM_1_WPU                  WPUBbits.WPUB4
#define PIN_COM_1_ANS                  ANSELBbits.ANSB4
#define PIN_COM_1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define PIN_COM_1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define PIN_COM_1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define PIN_COM_1_GetValue()           PORTBbits.RB4
#define PIN_COM_1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define PIN_COM_1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define PIN_COM_1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define PIN_COM_1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define PIN_COM_1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define PIN_COM_1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set PIN_COM_3 aliases
#define PIN_COM_3_TRIS                 TRISBbits.TRISB6
#define PIN_COM_3_LAT                  LATBbits.LATB6
#define PIN_COM_3_PORT                 PORTBbits.RB6
#define PIN_COM_3_WPU                  WPUBbits.WPUB6
#define PIN_COM_3_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define PIN_COM_3_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define PIN_COM_3_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define PIN_COM_3_GetValue()           PORTBbits.RB6
#define PIN_COM_3_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define PIN_COM_3_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define PIN_COM_3_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define PIN_COM_3_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)

// get/set A aliases
#define A_TRIS                 TRISCbits.TRISC0
#define A_LAT                  LATCbits.LATC0
#define A_PORT                 PORTCbits.RC0
#define A_WPU                  WPUCbits.WPUC0
#define A_ANS                  ANSELCbits.ANSC0
#define A_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define A_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define A_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define A_GetValue()           PORTCbits.RC0
#define A_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define A_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define A_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define A_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define A_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define A_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set B aliases
#define B_TRIS                 TRISCbits.TRISC1
#define B_LAT                  LATCbits.LATC1
#define B_PORT                 PORTCbits.RC1
#define B_WPU                  WPUCbits.WPUC1
#define B_ANS                  ANSELCbits.ANSC1
#define B_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define B_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define B_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define B_GetValue()           PORTCbits.RC1
#define B_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define B_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define B_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define B_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define B_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define B_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set C aliases
#define C_TRIS                 TRISCbits.TRISC2
#define C_LAT                  LATCbits.LATC2
#define C_PORT                 PORTCbits.RC2
#define C_WPU                  WPUCbits.WPUC2
#define C_ANS                  ANSELCbits.ANSC2
#define C_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define C_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define C_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define C_GetValue()           PORTCbits.RC2
#define C_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define C_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define C_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define C_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define C_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define C_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set D aliases
#define D_TRIS                 TRISCbits.TRISC3
#define D_LAT                  LATCbits.LATC3
#define D_PORT                 PORTCbits.RC3
#define D_WPU                  WPUCbits.WPUC3
#define D_ANS                  ANSELCbits.ANSC3
#define D_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D_GetValue()           PORTCbits.RC3
#define D_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define D_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define D_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define D_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set E aliases
#define E_TRIS                 TRISCbits.TRISC4
#define E_LAT                  LATCbits.LATC4
#define E_PORT                 PORTCbits.RC4
#define E_WPU                  WPUCbits.WPUC4
#define E_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define E_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define E_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define E_GetValue()           PORTCbits.RC4
#define E_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define E_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define E_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)

// get/set F aliases
#define F_TRIS                 TRISCbits.TRISC5
#define F_LAT                  LATCbits.LATC5
#define F_PORT                 PORTCbits.RC5
#define F_WPU                  WPUCbits.WPUC5
#define F_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define F_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define F_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define F_GetValue()           PORTCbits.RC5
#define F_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define F_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define F_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define F_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)

// get/set G aliases
#define G_TRIS                 TRISCbits.TRISC6
#define G_LAT                  LATCbits.LATC6
#define G_PORT                 PORTCbits.RC6
#define G_WPU                  WPUCbits.WPUC6
#define G_ANS                  ANSELCbits.ANSC6
#define G_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define G_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define G_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define G_GetValue()           PORTCbits.RC6
#define G_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define G_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define G_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define G_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define G_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define G_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set H aliases
#define H_TRIS                 TRISCbits.TRISC7
#define H_LAT                  LATCbits.LATC7
#define H_PORT                 PORTCbits.RC7
#define H_WPU                  WPUCbits.WPUC7
#define H_ANS                  ANSELCbits.ANSC7
#define H_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define H_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define H_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define H_GetValue()           PORTCbits.RC7
#define H_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define H_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define H_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define H_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define H_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define H_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

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