/*
 * HPUSH_BUTTON_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"

#include"../../MCAL/MDIO/MDIO_interface.h"

#include"HPUSH_BUTTON_config.h"

void HPUSH_BUTTON_void_init(u8 buttonPort,u8 buttonPin)
{
	MDIO_void_setpin_direction(buttonPort , buttonPin , INPUT);

	//Activation for poll up resistor
	MDIO_void_setpin_value(buttonPort , buttonPin , HIGH);
}
value_type HPUSH_BUTTON_void_read(u8 buttonPort,u8 buttonPin)
{
	return MDIO_value_type_getpin_value(buttonPort , buttonPin);
}

