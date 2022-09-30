/*
 * HLED_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"

#include"../../MCAL/MDIO/MDIO_interface.h"

#include"HLED_config.h"

void HLED_void_enable()
{
	//for vehicles
	MDIO_void_setpin_direction(LED_VECH_PORT , LED_VECH_R , OUTPUT);
	MDIO_void_setpin_direction(LED_VECH_PORT , LED_VECH_G , OUTPUT);
	MDIO_void_setpin_direction(LED_VECH_PORT , LED_VECH_Y , OUTPUT);

	//for Pedestrian
	MDIO_void_setpin_direction(LED_PED_PORT , LED_PED_R , OUTPUT);
	MDIO_void_setpin_direction(LED_PED_PORT , LED_PED_G , OUTPUT);
	MDIO_void_setpin_direction(LED_PED_PORT , LED_PED_Y , OUTPUT);
}
void HLED_void_switch_on(u8 led_port , u8 led_pin)
{
	MDIO_void_setpin_value(led_port , led_pin , HIGH);
}
void HLED_void_switch_off(u8 led_port , u8 led_pin)
{
	MDIO_void_setpin_value(led_port , led_pin , LOW);
}
void HLED_void_toggle(u8 led_port , u8 led_pin)
{
	MDIO_void_toggle_pin(led_port , led_pin);
}
