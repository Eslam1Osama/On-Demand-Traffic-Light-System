/*
 * MTIMER2_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MTIMER2_MTIMER2_INTERFACE_H_
#define MCAL_MTIMER2_MTIMER2_INTERFACE_H_

void MTIMER2_TIMER2_void_Init();
void MTIMER2_void_Set_Preload_or_OCR2_Value(u8 Copy_u8value);
void MTIMER2_void_check_OVF_or_CTC_flag(void);
void MTIMER2_void_clear_TOV2_or_OCF2(void);
void MTIMER2_void_start_counting(void);
void MTIMER2_void_stop_counting(void);
void MTIMER2_void_delay(void);


#endif /* MCAL_MTIMER2_MTIMER2_INTERFACE_H_ */
