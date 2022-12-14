/*
    MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:

    You may use this software, and any derivatives created by any person or
    entity by or on your behalf, exclusively with Microchip's products.
    Microchip and its subsidiaries ("Microchip"), and its licensors, retain all
    ownership and intellectual property rights in the accompanying software and
    in all derivatives hereto.

    This software and any accompanying information is for suggestion only. It
    does not modify Microchip's standard warranty for its products.  You agree
    that you are solely responsible for testing the software and determining
    its suitability.  Microchip has no obligation to modify, test, certify, or
    support the software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP'S
    PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
    (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
    INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
    ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL
    LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED
    THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF
    THESE TERMS.
*/
#ifndef MTOUCH_CONFIG_H
#define MTOUCH_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include "mtouch_sensor.h"
#include "mtouch_button.h"

/*
 * =======================================================================
 * Application / Configuration Settings
 * =======================================================================
 */
    #define MTOUCH_SENSORS          9u
    #define MTOUCH_BUTTONS          9u
    #define MTOUCH_DEBUG_COMM_ENABLE      1u

    /* 
     * =======================================================================
     * Sensor Parameters
     * =======================================================================
     */

    
 
    /*** T_1 ***/
    #define MTOUCH_S0_ADCON0_SENSOR              ( 0x0<<2 | 0x1 )
    #define MTOUCH_S0_REF_ADCON0                 ( 0x8<<2 | 0x1 )
    #define MTOUCH_S0_LAT                        LATA
    #define MTOUCH_S0_TRIS                       TRISA
    #define MTOUCH_S0_PIN                        0
    #define MTOUCH_S0_REF_LAT                    LATC
    #define MTOUCH_S0_REF_PIN                    6
    #define MTOUCH_S0_GUARD_LAT                  LAT
    #define MTOUCH_S0_GUARD_PIN                  
    #define MTOUCH_S0_PRECHARGE_TIME             16u
    #define MTOUCH_S0_ACQUISITION_TIME           8u
    #define MTOUCH_S0_SWITCH_TIME                0u
    #define MTOUCH_S0_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S0_OVERSAMPLING               32u
    /*** T_2 ***/
    #define MTOUCH_S1_ADCON0_SENSOR              ( 0x1<<2 | 0x1 )
    #define MTOUCH_S1_REF_ADCON0                 ( 0x0<<2 | 0x1 )
    #define MTOUCH_S1_LAT                        LATA
    #define MTOUCH_S1_TRIS                       TRISA
    #define MTOUCH_S1_PIN                        1
    #define MTOUCH_S1_REF_LAT                    LATA
    #define MTOUCH_S1_REF_PIN                    0
    #define MTOUCH_S1_GUARD_LAT                  LAT
    #define MTOUCH_S1_GUARD_PIN                  
    #define MTOUCH_S1_PRECHARGE_TIME             16u
    #define MTOUCH_S1_ACQUISITION_TIME           8u
    #define MTOUCH_S1_SWITCH_TIME                0u
    #define MTOUCH_S1_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S1_OVERSAMPLING               32u
    /*** T_3 ***/
    #define MTOUCH_S2_ADCON0_SENSOR              ( 0x2<<2 | 0x1 )
    #define MTOUCH_S2_REF_ADCON0                 ( 0x1<<2 | 0x1 )
    #define MTOUCH_S2_LAT                        LATA
    #define MTOUCH_S2_TRIS                       TRISA
    #define MTOUCH_S2_PIN                        2
    #define MTOUCH_S2_REF_LAT                    LATA
    #define MTOUCH_S2_REF_PIN                    1
    #define MTOUCH_S2_GUARD_LAT                  LAT
    #define MTOUCH_S2_GUARD_PIN                  
    #define MTOUCH_S2_PRECHARGE_TIME             16u
    #define MTOUCH_S2_ACQUISITION_TIME           8u
    #define MTOUCH_S2_SWITCH_TIME                0u
    #define MTOUCH_S2_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S2_OVERSAMPLING               32u
    /*** T_4 ***/
    #define MTOUCH_S3_ADCON0_SENSOR              ( 0x3<<2 | 0x1 )
    #define MTOUCH_S3_REF_ADCON0                 ( 0x2<<2 | 0x1 )
    #define MTOUCH_S3_LAT                        LATA
    #define MTOUCH_S3_TRIS                       TRISA
    #define MTOUCH_S3_PIN                        4
    #define MTOUCH_S3_REF_LAT                    LATA
    #define MTOUCH_S3_REF_PIN                    2
    #define MTOUCH_S3_GUARD_LAT                  LAT
    #define MTOUCH_S3_GUARD_PIN                  
    #define MTOUCH_S3_PRECHARGE_TIME             16u
    #define MTOUCH_S3_ACQUISITION_TIME           8u
    #define MTOUCH_S3_SWITCH_TIME                0u
    #define MTOUCH_S3_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S3_OVERSAMPLING               32u
    /*** T_8 ***/
    #define MTOUCH_S4_ADCON0_SENSOR              ( 0x4<<2 | 0x1 )
    #define MTOUCH_S4_REF_ADCON0                 ( 0x3<<2 | 0x1 )
    #define MTOUCH_S4_LAT                        LATC
    #define MTOUCH_S4_TRIS                       TRISC
    #define MTOUCH_S4_PIN                        0
    #define MTOUCH_S4_REF_LAT                    LATA
    #define MTOUCH_S4_REF_PIN                    4
    #define MTOUCH_S4_GUARD_LAT                  LAT
    #define MTOUCH_S4_GUARD_PIN                  
    #define MTOUCH_S4_PRECHARGE_TIME             16u
    #define MTOUCH_S4_ACQUISITION_TIME           8u
    #define MTOUCH_S4_SWITCH_TIME                0u
    #define MTOUCH_S4_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S4_OVERSAMPLING               32u
    /*** T_7 ***/
    #define MTOUCH_S5_ADCON0_SENSOR              ( 0x5<<2 | 0x1 )
    #define MTOUCH_S5_REF_ADCON0                 ( 0x4<<2 | 0x1 )
    #define MTOUCH_S5_LAT                        LATC
    #define MTOUCH_S5_TRIS                       TRISC
    #define MTOUCH_S5_PIN                        1
    #define MTOUCH_S5_REF_LAT                    LATC
    #define MTOUCH_S5_REF_PIN                    0
    #define MTOUCH_S5_GUARD_LAT                  LAT
    #define MTOUCH_S5_GUARD_PIN                  
    #define MTOUCH_S5_PRECHARGE_TIME             16u
    #define MTOUCH_S5_ACQUISITION_TIME           8u
    #define MTOUCH_S5_SWITCH_TIME                0u
    #define MTOUCH_S5_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S5_OVERSAMPLING               32u
    /*** T_6 ***/
    #define MTOUCH_S6_ADCON0_SENSOR              ( 0x6<<2 | 0x1 )
    #define MTOUCH_S6_REF_ADCON0                 ( 0x5<<2 | 0x1 )
    #define MTOUCH_S6_LAT                        LATC
    #define MTOUCH_S6_TRIS                       TRISC
    #define MTOUCH_S6_PIN                        2
    #define MTOUCH_S6_REF_LAT                    LATC
    #define MTOUCH_S6_REF_PIN                    1
    #define MTOUCH_S6_GUARD_LAT                  LAT
    #define MTOUCH_S6_GUARD_PIN                  
    #define MTOUCH_S6_PRECHARGE_TIME             16u
    #define MTOUCH_S6_ACQUISITION_TIME           8u
    #define MTOUCH_S6_SWITCH_TIME                0u
    #define MTOUCH_S6_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S6_OVERSAMPLING               32u
    /*** T_5 ***/
    #define MTOUCH_S7_ADCON0_SENSOR              ( 0x7<<2 | 0x1 )
    #define MTOUCH_S7_REF_ADCON0                 ( 0x6<<2 | 0x1 )
    #define MTOUCH_S7_LAT                        LATC
    #define MTOUCH_S7_TRIS                       TRISC
    #define MTOUCH_S7_PIN                        3
    #define MTOUCH_S7_REF_LAT                    LATC
    #define MTOUCH_S7_REF_PIN                    2
    #define MTOUCH_S7_GUARD_LAT                  LAT
    #define MTOUCH_S7_GUARD_PIN                  
    #define MTOUCH_S7_PRECHARGE_TIME             16u
    #define MTOUCH_S7_ACQUISITION_TIME           8u
    #define MTOUCH_S7_SWITCH_TIME                0u
    #define MTOUCH_S7_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S7_OVERSAMPLING               32u
    /*** T_9 ***/
    #define MTOUCH_S8_ADCON0_SENSOR              ( 0x8<<2 | 0x1 )
    #define MTOUCH_S8_REF_ADCON0                 ( 0x7<<2 | 0x1 )
    #define MTOUCH_S8_LAT                        LATC
    #define MTOUCH_S8_TRIS                       TRISC
    #define MTOUCH_S8_PIN                        6
    #define MTOUCH_S8_REF_LAT                    LATC
    #define MTOUCH_S8_REF_PIN                    3
    #define MTOUCH_S8_GUARD_LAT                  LAT
    #define MTOUCH_S8_GUARD_PIN                  
    #define MTOUCH_S8_PRECHARGE_TIME             16u
    #define MTOUCH_S8_ACQUISITION_TIME           8u
    #define MTOUCH_S8_SWITCH_TIME                0u
    #define MTOUCH_S8_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S8_OVERSAMPLING               32u
    #define MTOUCH_SENSOR_ACTIVE_THRESHOLD               100u  

    /* 
     * =======================================================================
     * Button Parameters
     * =======================================================================
     */

    #define MTOUCH_BUTTON_READING_GAIN              ((uint8_t)2u)
    #define MTOUCH_BUTTON_BASELINE_GAIN             ((uint8_t)4u)
    #define MTOUCH_BUTTON_BASELINE_INIT             ((mtouch_button_baselinecounter_t)16u)
    #define MTOUCH_BUTTON_BASELINE_RATE             ((mtouch_button_baselinecounter_t)64u)
    #define MTOUCH_BUTTON_BASELINE_HOLD             ((mtouch_button_baselinecounter_t)1024u)
    #define MTOUCH_BUTTON_NEGATIVEDEVIATION         ((mtouch_button_statecounter_t)64u)
    #define MTOUCH_BUTTON_PRESSTIMEOUT              ((mtouch_button_statecounter_t)59990u)

    #define MTOUCH_BUTTON_SENSOR_Button0             T_1
    #define MTOUCH_BUTTON_SENSOR_Button1             T_2
    #define MTOUCH_BUTTON_SENSOR_Button2             T_3
    #define MTOUCH_BUTTON_SENSOR_Button3             T_4
    #define MTOUCH_BUTTON_SENSOR_Button4             T_8
    #define MTOUCH_BUTTON_SENSOR_Button5             T_7
    #define MTOUCH_BUTTON_SENSOR_Button6             T_6
    #define MTOUCH_BUTTON_SENSOR_Button7             T_5
    #define MTOUCH_BUTTON_SENSOR_Button8             T_9

    #define MTOUCH_BUTTON_THRESHOLD_Button0          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button1          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button2          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button3          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button4          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button5          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button6          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button7          100u
    #define MTOUCH_BUTTON_THRESHOLD_Button8          100u
    
    #define MTOUCH_BUTTON_SCALING_Button0            1u
    #define MTOUCH_BUTTON_SCALING_Button1            1u
    #define MTOUCH_BUTTON_SCALING_Button2            1u
    #define MTOUCH_BUTTON_SCALING_Button3            1u
    #define MTOUCH_BUTTON_SCALING_Button4            1u
    #define MTOUCH_BUTTON_SCALING_Button5            1u
    #define MTOUCH_BUTTON_SCALING_Button6            1u
    #define MTOUCH_BUTTON_SCALING_Button7            1u
    #define MTOUCH_BUTTON_SCALING_Button8            1u

    #define MTOUCH_BUTTON_COMMON_HYSTERESIS         HYST_50_PERCENT
    





#endif // MTOUCH_CONFIG_H
/**
 End of File
*/
