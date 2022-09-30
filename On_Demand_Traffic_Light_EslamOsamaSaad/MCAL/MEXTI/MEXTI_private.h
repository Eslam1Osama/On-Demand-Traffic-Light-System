/*
 * MEXTI_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

//=============================================
/*Enabling external interrupt registers*/
//=============================================
#define EXTI_SREG (*((volatile u8*) 0x5F)) // to use GIE bit
#define I_BIT 7 // GIE bit
//=============================================
#define EXTI_GICR (*((volatile u8*) 0x5B)) // to enable one of this externale interrupts
#define INT2 5
#define INT0 6
#define INT1 7
//=============================================
#define EXTI_GIFR (*((volatile u8*) 0x5A)) // to use INTF flags
#define INTF2 5
#define INTF0 6
#define INTF1 7
//=============================================
#define EXTI_MCUCR (*((volatile u8*) 0x55)) // for INT0 and INT1 to decide in which change to enable ISR()
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
//=============================================
#define EXTI_MCUCSR (*((volatile u8*) 0x54))// for INT2 to decide in which change to enable ISR()
#define ISC2 6
//=============================================

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
