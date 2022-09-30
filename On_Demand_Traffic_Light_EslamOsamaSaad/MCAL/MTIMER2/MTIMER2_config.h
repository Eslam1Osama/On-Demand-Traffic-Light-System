/*
 * MTIMER2_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MTIMER2_MTIMER2_CONFIG_H_
#define MCAL_MTIMER2_MTIMER2_CONFIG_H_

/*============================*/
/*Timer2 Prescaler options*/
/*============================*/
/*
  1- N0_PRESCALLING
  2- PRECALER_BY_8
  3- PRECALER_BY_64
  4- PRECALER_BY_256
  5- PRECALER_BY_1024
  6- EVENT_FALLING_EDGE
  7- EXTERNAL_EVENT_RISING_EDGE
*/
#define TIMER2_PRESCALER PRECALER_BY_8
/*============================*/
/*timer0 mode options*/
/*
 1- TIMER2_OVF_MODE
 2- TIMER2_CTC_MODE
 3- TIMER2_PHASE_CORRECT_PWM_MODE
 4- TIMER2_FAST_PWM_MODE
 */
#define TIMER2_MODE TIMER2_CTC_MODE
/*=================================*/
/*Compare match output mode options*/
/*=================================*/
/*
  Compare match output mode options for CTC mode

 1- OC2_DISCONNECTED
 2- TOGGLE_OC2
 3- CLEAR_OC2
 4- SET_OC2
===============================================================
 Compare match output mode options for phase correct PWM mode

1- ON_COMPARE_MATCH_CLEAR_OC2_UPCOUNT_SET_OC2_DOWNCOUNT
2- ON_COMPARE_MATCH_SET_OC2_UPCOUNT_CLEAR_OC2_DOWNCOUNT
===============================================================
Compare match output mode options for fast PWM mode

1- ON_COMPARE_MATCH_CLEAR_OC2_SET_OC2_AT_BOTTOM
2- ON_COMPARE_MATCH_SET_OC2_CLEAR_OC2_AT_BOTTOM
===============================================================
*/
#define OC2_MODE OC2_DISCONNECTED

/*=============================================================*/
#define TIMER2_OCR2_VALUE 249

#define TIMER2_TCNT2_VALUE 0
/*=============================================================*/
#define TIMER2_NUM_OVF 2000
/*=============================================================*/

#endif /* MCAL_MTIMER2_MTIMER2_CONFIG_H_ */
