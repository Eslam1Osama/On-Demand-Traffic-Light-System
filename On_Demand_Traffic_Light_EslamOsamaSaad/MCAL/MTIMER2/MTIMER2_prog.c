/*
 * MTIMER2_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"

#include"MTIMER2_private.h"
#include"MTIMER2_config.h"

void MTIMER2_TIMER2_void_Init()
{
#if TIMER2_MODE == TIMER2_OVF_MODE
	/*As start we are going to work with normal mode (overflow)*/
	CLEAR_BIT(MTIMER2_TCCR2 , WGM21);
	CLEAR_BIT(MTIMER2_TCCR2 , WGM20);

	/*===============================================================*/
	/*for OVERFLOW interrupt*/
	/*Enable PIE (peripheral interrupt enable) overflow interrupt*/
	SET_BIT(MTIMER2_TIMSK , TOIE2);
	/*===============================================================*/

#elif TIMER2_MODE == TIMER2_CTC_MODE
	/*Select CTC mode (Clear on compare match)*/
	SET_BIT(MTIMER2_TCCR2 , WGM21);
	CLEAR_BIT(MTIMER2_TCCR2 , WGM20);

	/*===============================================================*/
	/*for CTC interrupt*/
	/*Enable PIE (peripheral interrupt enable) CTC interrupt*/
	//SET_BIT(MTIMER2_TIMSK , OCIE2);
	/*===============================================================*/
	/*Select OC2 pin mode*/
	#if OC2_MODE == OC2_DISCONNECTED
		CLEAR_BIT(MTIMER2_TCCR2 , COM20);
		CLEAR_BIT(MTIMER2_TCCR2 , COM21);

	#elif OC2_MODE == TOGGLE_OC2
		SET_BIT(MTIMER2_TCCR2 , COM20);
		CLEAR_BIT(MTIMER2_TCCR2 , COM21);

	#elif OC2_MODE == CLEAR_OC2
		CLEAR_BIT(MTIMER2_TCCR2 , COM20);
		SET_BIT(MTIMER2_TCCR2 , COM21);

	#elif OC2_MODE == SET_OC2
		SET_BIT(MTIMER2_TCCR2 , COM20);
		SET_BIT(MTIMER2_TCCR2 , COM21);

	#else
		#error "OC2 mode is not valid "

	#endif

#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM_MODE
	/*Select Fast PWM (pulse width modulation)*/
	CLEAR_BIT(MTIMER2_TCCR2 , WGM21);
	SET_BIT(MTIMER2_TCCR2 , WGM20);
	/*===============================================================*/
	/*Select OC2 pin mode*/
	#if OC2_MODE == ON_COMPARE_MATCH_CLEAR_OC2_UPCOUNT_SET_OC2_DOWNCOUNT
		CLEAR_BIT(MTIMER2_TCCR2 , COM20);
		SET_BIT(MTIMER2_TCCR2 , COM21);

	#elif OC2_MODE == ON_COMPARE_MATCH_SET_OC2_UPCOUNT_CLEAR_OC2_DOWNCOUNT
		SET_BIT(MTIMER2_TCCR2 , COM20);
		SET_BIT(MTIMER2_TCCR2 , COM21);

	#else
		#error "OC2 mode is not valid "

	#endif

#elif TIMER2_MODE == TIMER2_FAST_PWM_MODE
	/*Select Fast PWM (pulse width modulation)*/
	SET_BIT(MTIMER2_TCCR2 , WGM21);
	SET_BIT(MTIMER2_TCCR2 , WGM20);
	/*===============================================================*/
	/*Select OC2 pin mode*/
	#if OC2_MODE == ON_COMPARE_MATCH_CLEAR_OC2_SET_OC2_AT_BOTTOM
		CLEAR_BIT(MTIMER2_TCCR2 , COM20);
		SET_BIT(MTIMER2_TCCR2 , COM21);

	#elif OC2_MODE == ON_COMPARE_MATCH_SET_OC2_CLEAR_OC2_AT_BOTTOM
		SET_BIT(MTIMER2_TCCR2 , COM20);
		SET_BIT(MTIMER2_TCCR2 , COM21);

	#else
		#error "OC2 mode is not valid "

	#endif

#else
	#error "your TIMER2 mode is not valid "

#endif

	/*prescaler division factor setting*/
	MTIMER2_TCCR2 &= PRESCALER_MASK;
	MTIMER2_TCCR2 |= TIMER2_PRESCALER;

}

void MTIMER2_void_Set_Preload_or_OCR2_Value(u8 Copy_u8value)
{
#if TIMER2_MODE == TIMER2_OVF_MODE
	MTIMER2_TCNT2 = Copy_u8value;

#elif TIMER2_MODE == TIMER2_CTC_MODE
	MTIMER2_OCR2 = Copy_u8value;

#elif TIMER2_MODE == TIMER2_PHASE_CORRECT_PWM_MODE
	MTIMER2_OCR2 = Copy_u8value;

#elif TIMER2_MODE == TIMER2_FAST_PWM_MODE
	MTIMER2_OCR2 = Copy_u8value;


#endif
}

void MTIMER2_void_check_OVF_or_CTC_flag()
{
#if TIMER2_MODE == TIMER2_OVF_MODE
	while(GET_BIT(MTIMER2_TIFR , TOV2) == 0);

#elif TIMER2_MODE == TIMER2_CTC_MODE
	while(GET_BIT(MTIMER2_TIFR , OCF2) == 0);

#endif
}

void MTIMER2_void_clear_TOV2_or_OCF2()
{
#if TIMER2_MODE == TIMER2_OVF_MODE
	SET_BIT(MTIMER2_TIFR , TOV2);

#elif TIMER2_MODE == TIMER2_CTC_MODE
	SET_BIT(MTIMER2_TIFR , OCF2);

#endif
}

void MTIMER2_void_start_counting()
{
	/*prescaler division factor setting*/
	MTIMER2_TCCR2 &= PRESCALER_MASK;
	MTIMER2_TCCR2 |= TIMER2_PRESCALER;
}

void MTIMER2_void_stop_counting()
{
	//Timer stop
	MTIMER2_TCCR2 &= PRESCALER_MASK;
}

void MTIMER2_void_delay()
{
#if TIMER2_MODE == TIMER2_OVF_MODE
	MTIMER2_void_Set_Preload_or_OCR2_Value(TIMER2_PRESCALER);

#elif TIMER2_MODE == TIMER2_CTC_MODE
	MTIMER2_void_Set_Preload_or_OCR2_Value(TIMER2_OCR2_VALUE);
#endif
	MTIMER2_void_start_counting();

	//busy waiting
	MTIMER2_void_check_OVF_or_CTC_flag();

	MTIMER2_void_clear_TOV2_or_OCF2();

	MTIMER2_void_stop_counting();
}
