/*
 * MDIO_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MDIO_MDIO_PRIVATE_H_
#define MDIO_MDIO_PRIVATE_H_

/*===============================*/
/*Memory mapping*/
/*===============================*/
/*For PORTs*/
#define PORTA (*((volatile u8*) 0x3B))
#define PORTB (*((volatile u8*) 0x38))
#define PORTC (*((volatile u8*) 0x35))
#define PORTD (*((volatile u8*) 0x32))
/*===============================*/
/*For DDRs*/
#define DDRA (*((volatile u8*) 0x3A))
#define DDRB (*((volatile u8*) 0x37))
#define DDRC (*((volatile u8*) 0x34))
#define DDRD (*((volatile u8*) 0x31))
/*===============================*/
/*For PINs*/
#define PINA (*((volatile u8*) 0x39))
#define PINB (*((volatile u8*) 0x36))
#define PINC (*((volatile u8*) 0x33))
#define PIND (*((volatile u8*) 0x30))
/*===============================*/

#endif /* MDIO_MDIO_PRIVATE_H_ */
