/*
 * MTIMER_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_
//=============================================
/*Enabling TIMER0 registers*/
//=============================================
#define MTIMER_TIMSK (*((volatile u8*) 0x59))
#define TOIE0 0
#define OCIE0 1
//=============================================
#define MTIMER_TIFR (*((volatile u8*) 0x58))
#define TOV0 0
#define OCF0 1
//=============================================
#define MTIMER_TCCR0 (*((volatile u8*) 0x53))
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
//=============================================
#define MTIMER_TCNT0 (*((volatile u8*) 0x52))
//=============================================
#define MTIMER_OCR0 (*((volatile u8*) 0x5C))
//=============================================
#define PRESCALER_MASK 0XF8
//============================================
/*Timer0 Prescaler options*/

#define N0_PRESCALLING					1
#define PRECALER_BY_8					2
#define PRECALER_BY_64					3
#define PRECALER_BY_256					4
#define PRECALER_BY_1024				5
#define EXTERNAL_EVENT_FALLING_EDGE		6
#define EXTERNAL_EVENT_RISING_EDGE		7
//============================================
/*Compare match output mode options*/

#define OC0_DISCONNECTED	1
#define  TOGGLE_OC0			2
#define CLEAR_OC0			3
#define SET_OC0				4
//============================================
#define TIMER0_OVF_MODE 0
#define TIMER0_CTC_MODE 1
//============================================

#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
