/*
 * MEXTI_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

//=============================================
/*mode of enabling ISR()*/
#define RISING_EDGE		1
#define FALLING_EDGE	2
#define ANY_CHANGE		3
#define LOW_LEVEL		4
//=============================================
/*Interrupt ID*/
#define INT2 5
#define INT0 6
#define INT1 7
//=================================================
void MEXTI_void_enable(u8 INT);
void MEXTI_void_disable(u8 INT);
void MEXTI_void_intialization(u8 INT , u8 Mode);


void MEXTI_void_setCallBack_INT0(void (*ptr) (void));
void MEXTI_void_setCallBack_INT1(void (*ptr) (void));
void MEXTI_void_setCallBack_INT2(void (*ptr) (void));
//===================================================
#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
