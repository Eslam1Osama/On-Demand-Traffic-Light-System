/*
 * MTIMER_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

void MTIMER_TIMER0_void_Init();
void MTIMER_void_Set_Preload_or_OCR0_Value(u8 Copy_u8value);
void MTIMER_void_check_OVF_or_CTC_flag(void);
void MTIMER_void_clear_TOV0_or_OCF0(void);
void MTIMER_void_start_counting(void);
void MTIMER_void_stop_counting(void);
void MTIMER_void_delay(void);

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
