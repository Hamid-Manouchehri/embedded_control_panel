/* 
 * File:   sound.h
 * Author: Mr.TAVAKOLI
 *
 * Created on June 20, 2018, 10:45 AM
 */

#ifndef SOUND_H
#define	SOUND_H

#ifdef	__cplusplus
extern "C" {
#endif

#define speaker_on_time_d                0.000036               //second
#define instruction_cycle_d             (_XTAL_FREQ / 4)
#define instruction_cycle_periode_d     (1.0 / instruction_cycle_d)
#define sound_loop_periode_d            (13 * instruction_cycle_periode_d)
#define speaker_on_counter_value_d      (speaker_on_time_d / sound_loop_periode_d)
#define pulse_delay_time_out_d                           (( 1.0 / ( _XTAL_FREQ /* / 4.0*/)) * 17.0 )      //17 is number of instruction in "while( -- counter > 0);" loop.
#define sound_pulse_width_d                              (0.000050 / pulse_delay_time_out_d)     //pulse width is 25 us,this macro calculate the index of loop
#define convert_frequence_to_periode_d(frequence)        (((1 / frequence) - 0.000025)/pulse_delay_time_out_d) 
#define create_pulse_d(number_of_pulse,pulse_frequence)  GENERATE_PULSE(number_of_pulse,convert_frequence_to_periode_d)

//Sound mode enum
typedef enum{
            learn_rf_code_is_start,
            learn_rf_code_is_done,
            learn_rf_code_is_abort,
            rf_code_is_remove,
            memory_is_full,
            turn_off,
            turn_on,
            dimmer_is_max,
            dimmer_is_min
}sound_mode_E;


inline void WRITE_SOUND_MODE(sound_mode_E MODE) ;
inline sound_mode_E READ_SOUND_MODE(void) ;
void SET_SOUND_MODE(sound_mode_E MODE) ;
void GENERATE_PULSE(unsigned int NUMBER_OF_PULSE,unsigned int PULSE_PERIODE) ;
void SOUND_CONTROL_FUNCTION(void) ;

#ifdef	__cplusplus
}
#endif

#endif	/* SOUND_H */

