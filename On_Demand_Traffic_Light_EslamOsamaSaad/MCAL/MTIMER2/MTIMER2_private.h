/*
 * MTIMER2_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MTIMER2_MTIMER2_PRIVATE_H_
#define MCAL_MTIMER2_MTIMER2_PRIVATE_H_

//=============================================
/*Enabling TIMER2 registers*/
//=============================================
#define MTIMER2_TIMSK (*((volatile u8*) 0x59))
#define TOIE2 6
#define OCIE2 7
//=============================================
#define MTIMER2_TIFR (*((volatile u8*) 0x58))
#define TOV2 6
#define OCF2 7
//=============================================
#define MTIMER2_TCCR2 (*((volatile u8*) 0x45))
#define CS20  0
#define CS21  1
#define CS22  2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
//=============================================
#define MTIMER2_TCNT2 (*((volatile u8*) 0x44))
//=============================================
#define MTIMER2_OCR2 (*((volatile u8*) 0x43))
//=============================================
#define PRESCALER_MASK 0XF8
//============================================
/*Timer0 Prescaler options*/

#define N0_PRESCALLING					1
#define PRECALER_BY_8					2
#define PRECALER_BY_32					3
#define PRECALER_BY_64					4
#define PRECALER_BY_256					5
#define PRECALER_BY_1024				6
#define EXTERNAL_EVENT_FALLING_EDGE		7
#define EXTERNAL_EVENT_RISING_EDGE		8
//============================================
/*Compare match output mode options for CTC mode*/

#define OC2_DISCONNECTED	1
#define TOGGLE_OC2			2
#define CLEAR_OC2			3
#define SET_OC2				4
//============================================
/*Compare match output mode options for phase correct PWM mode*/

#define ON_COMPARE_MATCH_CLEAR_OC2_UPCOUNT_SET_OC2_DOWNCOUNT	1
#define ON_COMPARE_MATCH_SET_OC2_UPCOUNT_CLEAR_OC2_DOWNCOUNT	2
//===============================================================
/*Compare match output mode options for fast PWM mode*/

#define ON_COMPARE_MATCH_CLEAR_OC2_SET_OC2_AT_BOTTOM	1
#define ON_COMPARE_MATCH_SET_OC2_CLEAR_OC2_AT_BOTTOM	2
//===============================================================
#define TIMER2_OVF_MODE					0
#define TIMER2_PHASE_CORRECT_PWM_MODE 	1
#define TIMER2_CTC_MODE 				2
#define TIMER2_FAST_PWM_MODE			3
//============================================

#endif /* MCAL_MTIMER2_MTIMER2_PRIVATE_H_ */
