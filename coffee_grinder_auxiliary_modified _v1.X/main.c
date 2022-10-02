/**
 * @Company:
 *  PARMIS-SMARTHOME
 * 
 * @Start_Date:
 *  18/08/1400
 *  
 * @END_Date:  
 *  15/09/1400  
 *  
 * @File_Name:
 *  coffee_grinder_auxiliary_modified.c
 * 
 * @Version:
 *  v.3.2
 * 
 * @Summary:
 *  
 * 
 * @Description:    
 *  
 * 
 * @Authors:
 *  Eng.Hamid.Manouchehri and Eng.Ali.Tavakoli
 */

/*************************************************
 ****************< Auxiliary MCU >****************
 *************************************************/

#include "mcc_generated_files/mcc.h"

//******************************************************************************< ENUMERATOR >

enum {
    RX_7SEG_ON = 11,
    RX_7SEG_OFF = 12,
    RX_MEM_1 = 21,
    RX_MEM_2 = 22,
    RX_MEM_3 = 23,
    RX_MEM_4 = 24,
    RX_7SEG_MANUAL = 30,
    RX_7SEG_SET_ZERO = 31,
    RX_7SEG_SHOW_TIME = 32,
    RX_7SEG_STORE_TIME = 33,
    RX_7SEG_STORE_INITIAL_VALUE = 35,
    RX_SELECT_DIGIT = 41,
    RX_END_SELECT_DIGIT = 42,
    RX_INCREASE_DIGIT = 43,
    RX_SET_DISPLAY_VALUE = 45,
    RX_START_DECREASE = 62,
    RX_STOP_DECREASE = 63,
    RX_START_INCREASE = 64,
    RX_STOP_INCREASE_SET_MANUAL = 65,
    RX_7SEG_SHOW_MASS = 66,
    RX_7SEG_STORE_MASS = 67,
    TX_7SEG_REACHED_999 = 68,
    RX_7SEG_STORE_MEM_1 = 111,
    RX_7SEG_SET_MEM_1 = 112,
    RX_7SEG_STORE_MEM_2 = 121,
    RX_7SEG_SET_MEM_2 = 122,
    RX_7SEG_STORE_MEM_3 = 131,
    RX_7SEG_SET_MEM_3 = 132,
    RX_7SEG_STORE_MEM_4 = 141,
    RX_7SEG_SET_MEM_4 = 142

};

//******************************************************************************< MACRO >

#define BLINK_DELAY                             8 // 8 * 65.536(ms) ~ 0.5(s)

/**************************** Added by Tavakoli *******************************/
typedef enum {
    position_yekan = 1,
    position_dahegan = 10,
    position_sadegan = 100
} digit_position_t;

digit_position_t g_digit_num;

typedef struct {
    //Position specifies digit is yekan or dahegan and so
    const digit_position_t position;
    uint8_t value;
    uint8_t seven_segment_maping;
    unsigned show : 1;
} digit_t;

digit_t g_yekan = {position_yekan};
digit_t g_dahegan = {position_dahegan};
digit_t g_sadegan = {position_sadegan};
digit_t *gp_selected_digit = NULL; //No digit is selected at startup.

inline void init_digit(void);
void select_digit(void);
inline void end_select_digit(void);
inline void increase_digit(void);
inline void decrease_digit(void);
inline void display_refresh(void);
inline void blink_digit(void);
inline uint16_t get_display_value(void);
void set_display_value(uint16_t value);

/************************** End added by Tavakoli ****************************/
//******************************************************************************< FUNCTION DECLARATION >
inline void TX_Command(uint8_t);
inline uint8_t RX_Command(void);
inline void handle_received_commands(void);
inline void decrease_num(void);
inline void increase_num_automatic(void);
inline void set_display_value_manual(void);

//******************************************************************************< GLOBAL VARIABLE >

__eeprom uint16_t ge_memory_mass[4];
__eeprom uint16_t ge_time_ms;

uint16_t g_memory_mass[4];
uint16_t g_current_num_on_7segs;

uint8_t g_7seg_table[10] = {0x3F, 0x06, 0x5B, 0x4F,
    0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F}; // 0-9
uint8_t middle_line_7seg = 0x40; // Unique 7-segment display for manual mode: (---)

uint16_t g_decrease_delay = 10; // Default: 10 * 10(ms) = 100(ms)
uint16_t g_increase_delay = 10; // Default: 10 * 10(ms) = 100(ms)
uint16_t g_setted_value;

uint16_t g_mass;
uint16_t g_time_ms = 100;
uint16_t g_time_ms_backup;

//******************************************************************************< MAIN >

void main(void) {

    SYSTEM_Initialize();
    init_digit();

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    TMR1_SetInterruptHandler(blink_digit); // Period: 65.536(ms)
    TMR2_SetInterruptHandler(display_refresh); // Period: 5(ms)
    TMR4_SetInterruptHandler(decrease_num); // Period: 10(ms)
    TMR6_SetInterruptHandler(increase_num_automatic); // Period: 10(ms)

    while (1) {

        handle_received_commands();

    }
}

//******************************************************************************< FUNCTION DEFINITION >
/**************************** Added by Tavakoli ******************************/

/*********************************************************************
 * Function:        void init_digit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Call this function to initialize digits struct. This
 *                      function must be called once at startup.
 *
 * Note:            None
 ********************************************************************/
inline void
init_digit(void) {

    for (register uint8_t i = 0; i < 4; i++) {

        g_memory_mass[i] = ge_memory_mass[i];

    }

    g_time_ms = ge_time_ms;

    PIN_COM_1_SetLow();
    PIN_COM_2_SetLow();
    PIN_COM_3_SetLow();

    TMR2_StopTimer(); // Stop '7-seg' refresh

    g_yekan.value = 0;
    g_yekan.seven_segment_maping = g_7seg_table[g_yekan.value];
    g_yekan.show = true;

    g_dahegan.value = 0;
    g_dahegan.seven_segment_maping = g_7seg_table[g_dahegan.value];
    g_dahegan.show = true;

    g_sadegan.value = 0;
    g_sadegan.seven_segment_maping = g_7seg_table[g_sadegan.value];
    g_sadegan.show = true;

}

/*********************************************************************
 * Function:        void select_digit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function select a digit and must be called when the
 *                      event that selects the digits is triggered. If no digit
 *                      is selected already, the yekan digit will be select,
 *                      otherwise the digits are selected In rotation.
 *
 * Note:            
 ********************************************************************/
void
select_digit(void) {

    digit_t* buffer = gp_selected_digit;
    gp_selected_digit = NULL;

    if (NULL == buffer) // If no digit select yet
    {

        gp_selected_digit = &g_yekan;
    } else {

        // Only to ensure that the previous selected digit show.
        buffer->show = true;

        switch (buffer->position) {

            case position_yekan:

                gp_selected_digit = &g_dahegan;
                break;
            case position_dahegan:

                gp_selected_digit = &g_sadegan;
                break;
            case position_sadegan:

                gp_selected_digit = &g_yekan;
                break;
        }
    }
    // If you disable(stop) timer at blink_digit() function, you must re-enable
    //  (start) timer here.
}

/*********************************************************************
 * Function:        void end_select_digit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Use this function to exit from digit select mode.
 *
 * Note:            None
 ********************************************************************/
inline void
end_select_digit(void) {

    digit_t* buffer = gp_selected_digit;
    gp_selected_digit = NULL;
    buffer->show = true;
}

/*********************************************************************
 * Function:        void increase_digit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Use this function to increase value of selected digit. This
 *                      function is safe, you don't need to check either a digit
 *                      is selected or no.
 *
 * Note:            None
 ********************************************************************/
inline void
increase_digit(void) {

    if (NULL != gp_selected_digit) {

        gp_selected_digit->value++;

        if (10 == gp_selected_digit->value) {

            gp_selected_digit->value = 0;
        }

        gp_selected_digit->seven_segment_maping =
                g_7seg_table[gp_selected_digit->value];
    }
}

/*********************************************************************
 * Function:        void decrease_digit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Use this function to decrease value of selected digit. This
 *                      function is safe, you don't need to check either a digit
 *                      is selected or no.
 *
 * Note:            None
 ********************************************************************/
inline void
decrease_digit(void) {

    if (NULL != gp_selected_digit) {

        if (0 == gp_selected_digit->value) {

            gp_selected_digit->value = 9;
        } else {

            gp_selected_digit->value--;
        }

        gp_selected_digit->seven_segment_maping =
                g_7seg_table[gp_selected_digit->value];
    }
}

/*********************************************************************
 * Function:        void display_refresh(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function must be called periodically (e.g. from timer 
 *                      interrupt) to refresh the display. You must determine
 *                      call-interval and on_time value by experiment.
 *
 * Note:            You may need to change this function a little because i
 *                      don't access to schematic.
 ********************************************************************/
inline void
display_refresh(void) {

    static digit_position_t pos = position_yekan;

    switch (pos) {

        case position_yekan:

            PIN_COM_3_SetLow();

            if (true == g_yekan.show) {

                LATC = g_yekan.seven_segment_maping;
                PIN_COM_1_SetHigh();
            }

            pos = position_dahegan;
            break;
        case position_dahegan:

            PIN_COM_1_SetLow();

            if (true == g_dahegan.show) {

                LATC = g_dahegan.seven_segment_maping;
                PIN_COM_2_SetHigh();
            }

            pos = position_sadegan;
            break;
        case position_sadegan:

            PIN_COM_2_SetLow();

            if (true == g_sadegan.show) {

                LATC = g_sadegan.seven_segment_maping;
                PIN_COM_3_SetHigh();
            }

            pos = position_yekan;
            break;
        default:

            pos = position_yekan;
            break;
    }
}

/*********************************************************************
 * Function:        void blink_digit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is used to blink the selected digit. This
 *                      function must be called periodically with your desire 
 *                      interval. The interval determines blinking speed.
 *
 * Note:            None
 ********************************************************************/
inline void
blink_digit(void) {

    static uint8_t blink_counter;

    blink_counter++;

    if (BLINK_DELAY == blink_counter) {

        if (NULL != gp_selected_digit) {

            gp_selected_digit->show ^= 1;
        }
        //You can disable timer which is associated to digit blink at this point (to
        // reduce MCU overhead) by uncomment 'else' block and call proper function.
        // If you disable timer, you must re-enable it at select_digit() function.
        /*
         else 
         {
         Disable timer function.
         }
         */
        blink_counter = 0;
    }
}

/*********************************************************************
 * Function:        uint16_t  get_display_value(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Use this function to get value that is shown on display.
 *
 * Note:            None
 ********************************************************************/
inline uint16_t
get_display_value(void) {

    return (g_yekan.value + ((uint16_t) g_dahegan.value * g_dahegan.position) +
            ((uint16_t) g_sadegan.value * g_sadegan.position));
}

/*********************************************************************
 * Function:        void set_display_value(uint16_t value)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        To change display value use this function.
 *
 * Note:            None
 ********************************************************************/
void
set_display_value(uint16_t value) {

    uint16_t buffer = value;

    if (value <= 999) {

        g_sadegan.value = buffer / g_sadegan.position;
        buffer %= g_sadegan.position;

        g_dahegan.value = buffer / g_dahegan.position;

        g_yekan.value = buffer % g_dahegan.position;

        g_sadegan.seven_segment_maping = g_7seg_table[g_sadegan.value];
        g_dahegan.seven_segment_maping = g_7seg_table[g_dahegan.value];
        g_yekan.seven_segment_maping = g_7seg_table[g_yekan.value];
    }
}

/************************** End added by Tavakoli ****************************/

inline void TX_Command(uint8_t txData) {

    if (EUSART_is_tx_ready()) {

        EUSART_Write(txData);
    }
}

inline uint8_t RX_Command(void) {

    uint8_t buffer;

    if (EUSART_is_rx_ready()) {

        buffer = EUSART_Read();
        return buffer;
    }
}

inline void handle_received_commands(void) {

    static uint8_t rxData;

    if (EUSART_is_rx_ready()) {

        rxData = RX_Command(); // impossible to call RX_Command() inside '()' directly

        switch (rxData) {

            case RX_7SEG_ON: //                                                 < Turn-on 7-segs >

                TMR2_StartTimer();
                break;

            case RX_7SEG_OFF: //                                                < Turn-off 7-segs >

                TMR2_StopTimer();
                TMR4_StopTimer();
                TMR6_StopTimer();
                PIN_COM_1_SetLow();
                PIN_COM_2_SetLow();
                PIN_COM_3_SetLow();
                break;

            case RX_SELECT_DIGIT: //                                            < Select Digit >

                select_digit();
                break;

            case RX_END_SELECT_DIGIT: //                                        < End Select Digit >

                end_select_digit();
                break;

            case RX_INCREASE_DIGIT: //                                          < Increase Digit >

                increase_digit();
                break;

            case RX_7SEG_MANUAL: //                                             < Manual >

                set_display_value_manual();
                break;

            case RX_7SEG_SET_ZERO: //                                           < Set Zero >

                set_display_value(0);
                break;

            case RX_7SEG_STORE_MASS: //                                         < Store Mass >

                g_mass = get_display_value();
                break;


            case RX_7SEG_SHOW_MASS: //                                          < Show Mass >

                set_display_value(g_mass);
                break;


            case RX_7SEG_STORE_TIME: //                                         < Store Time_ms >

                g_time_ms = get_display_value();
                ge_time_ms = g_time_ms;
                break;


            case RX_7SEG_SHOW_TIME: //                                          < Show Time_ms >

                set_display_value(g_time_ms); // Show the last set value                
                break;


            case RX_7SEG_STORE_INITIAL_VALUE: //                                < Store First Value 7seg >

                g_setted_value = get_display_value();
                break;


            case RX_START_DECREASE: //                                          < Start Decrease >

                g_decrease_delay = g_time_ms / 10; // tmr4 period = 10(ms)
                TMR4_StartTimer();
                break;


            case RX_STOP_DECREASE: //                                           < Stop Decrease >

                TMR4_StopTimer();
                break;


            case RX_START_INCREASE: //                                          < Start Increase >

                set_display_value(0);
                g_increase_delay = g_time_ms / 10; // tmr6 period = 10(ms)                
                TMR6_StartTimer();
                break;


            case RX_STOP_INCREASE_SET_MANUAL: //                                < Stop Increase >

                TMR6_StopTimer();
                set_display_value_manual();
                break;


            case RX_7SEG_STORE_MEM_1: //                                        < Store Memory_1 >

                ge_memory_mass[0] = g_mass;
                g_memory_mass[0] = g_mass;
                break;


            case RX_7SEG_SET_MEM_1: //                                          < Set Memory_1 >

                g_time_ms_backup = g_time_ms;
                set_display_value(g_memory_mass[0]);
                break;


            case RX_7SEG_STORE_MEM_2: //                                        < Store Memory_2 >

                ge_memory_mass[1] = g_mass;
                g_memory_mass[1] = g_mass;
                break;


            case RX_7SEG_SET_MEM_2: //                                          < Set Memory_2 >

                g_time_ms_backup = g_time_ms;
                set_display_value(g_memory_mass[1]);
                break;


            case RX_7SEG_STORE_MEM_3: //                                        < Store Memory_3 >

                ge_memory_mass[2] = g_mass;
                g_memory_mass[2] = g_mass;
                break;


            case RX_7SEG_SET_MEM_3: //                                          < Set Memory_3 >

                g_time_ms_backup = g_time_ms;
                set_display_value(g_memory_mass[2]);
                break;


            case RX_7SEG_STORE_MEM_4: //                                        < Store Memory_4 >

                ge_memory_mass[3] = g_mass;
                g_memory_mass[3] = g_mass;
                break;


            case RX_7SEG_SET_MEM_4: //                                          < Set Memory_4 >

                set_display_value(g_memory_mass[3]);
                break;


            default:
                //Do nothing
                break;
        } // End of switch()
    } // End of main if()
}

inline void decrease_num(void) {

    static uint8_t tmr4_counter;

    tmr4_counter++;

    if (g_decrease_delay == tmr4_counter) {

        select_digit(); // First digit is selected
        decrease_digit();
        end_select_digit();

        if (0x6F == g_7seg_table[g_yekan.value]) {

            select_digit();
            select_digit(); // Second digit is selected
            decrease_digit();
            end_select_digit();

            if (0x6F == g_7seg_table[g_dahegan.value]) {

                select_digit();
                select_digit();
                select_digit(); // Third digit is selected
                decrease_digit();
                end_select_digit();
            }
        }

        if ((0x3F == g_sadegan.seven_segment_maping) &&
                (0x3F == g_dahegan.seven_segment_maping) &&
                (0x3F == g_yekan.seven_segment_maping)) { // Reached 000

            TMR4_StopTimer();
            set_display_value(g_setted_value);
        }

        tmr4_counter = 0;
    }
}

inline void increase_num_automatic(void) {

    static uint8_t tmr6_counter;

    tmr6_counter++;

    if (g_increase_delay == tmr6_counter) {

        select_digit(); // First digit is selected
        increase_digit();
        end_select_digit();

        if (0x3F == g_7seg_table[g_yekan.value]) {

            select_digit();
            select_digit(); // Second digit is selected
            increase_digit();
            end_select_digit();

            if (0x3F == g_7seg_table[g_dahegan.value]) {

                select_digit();
                select_digit();
                select_digit(); // Third digit is selected
                increase_digit();
                end_select_digit();
            }
        }

        if ((0x6F == g_sadegan.seven_segment_maping) &&
                (0x6F == g_dahegan.seven_segment_maping) &&
                (0x6F == g_yekan.seven_segment_maping)) { // Reached 999

            TMR6_StopTimer();
            set_display_value(0);
            set_display_value_manual();
            TX_Command(TX_7SEG_REACHED_999);
        }

        tmr6_counter = 0;
    }
}

inline void increase_num_manual(void) {

    static uint8_t tmr6_counter;

    tmr6_counter++;

    if (g_increase_delay == tmr6_counter) {

        select_digit(); // First digit is selected
        increase_digit();
        end_select_digit();

        if (0x6F == g_7seg_table[g_yekan.value]) {

            select_digit();
            select_digit(); // Second digit is selected
            increase_digit();
            end_select_digit();

            if (0x3F == g_7seg_table[g_dahegan.value]) {

                select_digit();
                select_digit();
                select_digit(); // Third digit is selected
                increase_digit();
                end_select_digit();
            }
        }

        if ((0x6F == g_sadegan.seven_segment_maping) &&
                (0x6F == g_dahegan.seven_segment_maping) &&
                (0x6F == g_yekan.seven_segment_maping)) { // Reached 999

            TMR6_StopTimer();
            set_display_value(0);
            set_display_value_manual();
            TX_Command(TX_7SEG_REACHED_999);
        }

        tmr6_counter = 0;
    }
}

inline void set_display_value_manual(void) {

    g_sadegan.seven_segment_maping = middle_line_7seg;
    g_dahegan.seven_segment_maping = middle_line_7seg;
    g_yekan.seven_segment_maping = middle_line_7seg;
}

