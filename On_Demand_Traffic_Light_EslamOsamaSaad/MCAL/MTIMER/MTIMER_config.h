/*
 * MTIMER_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MTIMER_MTIMER_CONFIG_H_
#define MCAL_MTIMER_MTIMER_CONFIG_H_
/*============================*/
/*Timer0 Prescaler options*/
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
#define TIMER_PRESCALER PRECALER_BY_8
/*============================*/
#define TIMER_PRELOAD 0
/*============================*/
/*timer0 mode options*/
/*
 1- TIMER0_OVF_MODE
 2- TIMER0_CTC_MODE
 */
#define TIMER0_MODE TIMER0_CTC_MODE
/*======================================*/
/*Compare match output mode options*/

/*
 1- OC0_DISCONNECTED
 2- TOGGLE_OC0
 3- CLEAR_OC0
 4- SET_OC0
*/
#define OC0_MODE OC0_DISCONNECTED
/*======================================*/

#define TIMER0_OCR0_VALUE 249

#define TIMER0_NUM_OVF 15625

#define CLK_SYS_freq 8

#endif /* MCAL_MTIMER_MTIMER_CONFIG_H_ */
