#include "sound_unit.h"
#include "../mcc_generated_files/mcc.h"

static sound_mode_E SOUND_MODE_e;

/*********************************************************************
 * Function:        inline void WRITE_SOUND_MODE(sound_mode_E MODE)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
inline void WRITE_SOUND_MODE(sound_mode_E MODE) {
    SOUND_MODE_e = MODE;
//    SET_CHANGE_FLAG(sound_mode_change_flag_d);
}

/*********************************************************************
 * Function:        inline sound_mode_E READ_SOUND_MODE(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
inline sound_mode_E READ_SOUND_MODE(void) {
    return(SOUND_MODE_e);
}

/*********************************************************************
 * Function:        void SET_SOUND_MODE(sound_mode_E MODE)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
void SET_SOUND_MODE(sound_mode_E MODE) {
switch(MODE){
    case learn_rf_code_is_start:
        GENERATE_PULSE(200,32);                
        break;
    case learn_rf_code_is_done :
        GENERATE_PULSE(200, 32);
        __delay_ms(50);
        GENERATE_PULSE(200, 32);
        break;
    case learn_rf_code_is_abort:
        GENERATE_PULSE(150,60);
        __delay_ms(50);
        GENERATE_PULSE(150,100);                
        break;
    case rf_code_is_remove:
        GENERATE_PULSE(200, 32);
        __delay_ms(500);
        GENERATE_PULSE(200, 32);
        __delay_ms(500);
        GENERATE_PULSE(200, 32);
        break;
    case memory_is_full:
        GENERATE_PULSE(250, 100);
        __delay_ms(50);
        GENERATE_PULSE(250, 100);
        break;
    case turn_off:
        GENERATE_PULSE(150, 12);
        GENERATE_PULSE(100, 38);                
        GENERATE_PULSE(60, 50); 
        break;
    case turn_on:
        GENERATE_PULSE(40, 50);
        GENERATE_PULSE(50, 38);                
        GENERATE_PULSE(75, 32); 
        break;
    case dimmer_is_max :
    case dimmer_is_min :
        GENERATE_PULSE(500, 20);         
        break;
}
}

/*********************************************************************
 * Function:        void GENERATE_PULSE(unsigned int NUMBER_OF_PULSE,unsigned int PULSE_PERIODE)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
void GENERATE_PULSE(unsigned int NUMBER_OF_PULSE,unsigned int PULSE_PERIODE) {
    unsigned int counter;
    INTERRUPT_GlobalInterruptDisable();
    while(--NUMBER_OF_PULSE > 0){
            BUZZER_SetHigh();
        counter =  (int)speaker_on_counter_value_d * 1;
        while(--counter > 0);
        BUZZER_SetLow();
        counter = PULSE_PERIODE * 2 ;
        while(--counter > 0){
         NOP();NOP();NOP();//NOP();NOP();NOP();NOP();NOP();NOP();   
        }
    }
        BUZZER_SetLow();
    INTERRUPT_GlobalInterruptEnable();

}


/*********************************************************************
 * Function:        void SOUND_CONTROL_FUNCTION(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
void SOUND_CONTROL_FUNCTION(void) {
//    if(IS_CHANGED(sound_mode_change_flag_d,sound_unit_task_d)){
//        CLEAR_CHANGE_FLAG(sound_mode_change_flag_d,sound_unit_task_d);
//        SET_TASK_SLEEP_FLAG(sound_unit_task_d);
  asm("NOP");      
//    }
}

