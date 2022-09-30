/*
 * MDIO_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef MDIO_MDIO_INTERFACE_H_
#define MDIO_MDIO_INTERFACE_H_

#include"../../LIB/LSTD_TYPES.h"
/*=============================================================================================*/

typedef enum {
	PORTA_ID = 0,
	PORTB_ID,
	PORTC_ID,
	PORTD_ID
}port_type;

typedef enum {
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7

}pin_type;

typedef enum{
	LOW = 0,
	HIGH
}value_type;

typedef enum{
	INPUT = 0,
	OUTPUT
}direction_type;

/*=============================================================================================*/
/*prototypes*/

void 		MDIO_void_setpin_value(port_type port , pin_type pin , value_type value);
void 		MDIO_void_toggle_pin(port_type port , pin_type pin);
void 		MDIO_void_setpin_direction(port_type port, pin_type pin, direction_type direction);

value_type 	MDIO_value_type_getpin_value(port_type port, pin_type pin);

void 		MDIO_void_setport_value(port_type port , u8 copy_u8_value);
void 		MDIO_void_setport_direction(port_type port , direction_type direction);
/*=============================================================================================*/

#endif /* MDIO_MDIO_INTERFACE_H_ */
