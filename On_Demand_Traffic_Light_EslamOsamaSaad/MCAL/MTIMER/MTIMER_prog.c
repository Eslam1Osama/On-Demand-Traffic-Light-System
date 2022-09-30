/*
 * MTIMER_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include<math.h>

#include"MTIMER_private.h"
#include"MTIMER_config.h"

void MTIMER_TIMER0_void_Init()
{
#if TIMER0_MODE == TIMER0_OVF_MODE
	/*As start we are going to work with normal mode (overflow)*/
	CLEAR_BIT(MTIMER_TCCR0 , WGM01);
	CLEAR_BIT(MTIMER_TCCR0 , WGM00);

	/*===============================================================*/
	/*for OVERFLOW interrupt*/
	/*Enable PIE (peripheral interrupt enable) overflow interrupt*/
	SET_BIT(MTIMER_TIMSK , TOIE0);
	/*===============================================================*/

#elif TIMER0_MODE == TIMER0_CTC_MODE
	/*Select CTC mode (Clear on compare match)*/
	SET_BIT(MTIMER_TCCR0 , WGM01);
	CLEAR_BIT(MTIMER_TCCR0 , WGM00);

	/*===============================================================*/
	/*for CTC interrupt*/
	/*Enable PIE (peripheral interrupt enable) CTC interrupt*/
	//SET_BIT(MTIMER_TIMSK , OCIE0);
	/*===============================================================*/
	/*Select OC0 pin mode*/
	#if OC0_MODE == OC0_DISCONNECTED
		CLEAR_BIT(MTIMER_TCCR0 , COM00);
		CLEAR_BIT(MTIMER_TCCR0 , COM01);

	#elif OC0_MODE == TOGGLE_OC0
		SET_BIT(MTIMER_TCCR0 , COM00);
		CLEAR_BIT(MTIMER_TCCR0 , COM01);

	#elif OC0_MODE == CLEAR_OC0
		CLEAR_BIT(MTIMER_TCCR0 , COM00);
		SET_BIT(MTIMER_TCCR0 , COM01);

	#elif OC0_MODE == SET_OC0
		SET_BIT(MTIMER_TCCR0 , COM00);
		SET_BIT(MTIMER_TCCR0 , COM01);

	#else
		#error "OC0 mode is not valid "

	#endif

#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM_MODE
	/*Select Fast PWM (pulse width modulation)*/
	CLEAR_BIT(MTIMER_TCCR0 , WGM01);
	SET_BIT(MTIMER_TCCR0 , WGM00);
	/*===============================================================*/
	/*Select OC0 pin mode*/
	#if OC0_MODE == ON_COMPARE_MATCH_CLEAR_OC0_UPCOUNT_SET_OC0_DOWNCOUNT
		CLEAR_BIT(MTIMER_TCCR0 , COM00);
		SET_BIT(MTIMER_TCCR0 , COM01);

	#elif OC0_MODE == ON_COMPARE_MATCH_SET_OC0_UPCOUNT_CLEAR_OC0_DOWNCOUNT
		SET_BIT(MTIMER_TCCR0 , COM00);
		SET_BIT(MTIMER_TCCR0 , COM01);

	#else
		#error "OC0 mode is not valid "

	#endif

#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
	/*Select Fast PWM (pulse width modulation)*/
	SET_BIT(MTIMER_TCCR0 , WGM01);
	SET_BIT(MTIMER_TCCR0 , WGM00);
	/*===============================================================*/
	/*Select OC0 pin mode*/
	#if OC0_MODE == ON_COMPARE_MATCH_CLEAR_OC0_SET_OC0_AT_BOTTOM
		CLEAR_BIT(MTIMER_TCCR0 , COM00);
		SET_BIT(MTIMER_TCCR0 , COM01);

	#elif OC0_MODE == ON_COMPARE_MATCH_SET_OC0_CLEAR_OC0_AT_BOTTOM
		SET_BIT(MTIMER_TCCR0 , COM00);
		SET_BIT(MTIMER_TCCR0 , COM01);

	#else
		#error "OC0 mode is not valid "

	#endif

#else
	#error "your TIMER0 mode is not valid "

#endif

	/*prescaler division factor setting*/
	MTIMER_TCCR0 &= PRESCALER_MASK;
	MTIMER_TCCR0 |= TIMER_PRESCALER;

}

void MTIMER_void_Set_Preload_or_OCR0_Value(u8 Copy_u8value)
{
#if TIMER0_MODE == TIMER0_OVF_MODE
	MTIMER_TCNT0 = Copy_u8value;

#elif TIMER0_MODE == TIMER0_CTC_MODE
	MTIMER_OCR0 = Copy_u8value;

#elif TIMER0_MODE == TIMER0_PHASE_CORRECT_PWM_MODE
	MTIMER_OCR0 = Copy_u8value;

#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
	MTIMER_OCR0 = Copy_u8value;

#endif
}

void MTIMER_void_check_OVF_or_CTC_flag()
{
#if TIMER0_MODE == TIMER0_OVF_MODE
	while(GET_BIT(MTIMER_TIFR , TOV0) == 0);

#elif TIMER0_MODE == TIMER0_CTC_MODE
	while(GET_BIT(MTIMER_TIFR , OCF0) == 0);

#endif
}

void MTIMER_void_clear_TOV0_or_OCF0()
{
#if TIMER0_MODE == TIMER0_OVF_MODE
	SET_BIT(MTIMER_TIFR , TOV0);

#elif TIMER0_MODE == TIMER0_CTC_MODE
	SET_BIT(MTIMER_TIFR , OCF0);

#endif
}

void MTIMER_void_start_counting()
{
	/*prescaler division factor setting*/
	MTIMER_TCCR0 &= PRESCALER_MASK;
	MTIMER_TCCR0 |= TIMER_PRESCALER;
}

void MTIMER_void_stop_counting()
{
	//Timer stop
	MTIMER_TCCR0 &= PRESCALER_MASK;
}

void MTIMER_void_delay()
{
#if TIMER0_MODE == TIMER0_OVF_MODE
	MTIMER_void_Set_Preload_or_OCR0_Value(TIMER_PRESCALER);

#elif TIMER0_MODE == TIMER0_CTC_MODE
	MTIMER_void_Set_Preload_or_OCR0_Value(TIMER0_OCR0_VALUE);
#endif
	MTIMER_void_start_counting();

	//busy waiting
	MTIMER_void_check_OVF_or_CTC_flag();

	MTIMER_void_clear_TOV0_or_OCF0();

	MTIMER_void_stop_counting();
}
