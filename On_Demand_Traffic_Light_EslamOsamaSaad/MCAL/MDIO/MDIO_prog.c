/*
 * MDIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MDIO_private.h"
#include"MDIO_interface.h"

void MDIO_void_setpin_value(port_type port , pin_type pin , value_type value)
{
	if(value == HIGH)
	{
		switch(port)
		{
			case PORTA_ID: SET_BIT(PORTA , pin); break;
			case PORTB_ID: SET_BIT(PORTB , pin); break;
			case PORTC_ID: SET_BIT(PORTC , pin); break;
			case PORTD_ID: SET_BIT(PORTD , pin); break;
		}
	}

	else if(value == LOW)
	{
		switch(port)
		{
			case PORTA_ID: CLEAR_BIT(PORTA , pin); break;
			case PORTB_ID: CLEAR_BIT(PORTB , pin); break;
			case PORTC_ID: CLEAR_BIT(PORTC , pin); break;
			case PORTD_ID: CLEAR_BIT(PORTD , pin); break;
		}
	}

}
void MDIO_void_toggle_pin(port_type port , pin_type pin)
{
	switch(port)
	{
		case PORTA_ID: TOGGLE_BIT(PORTA , pin); break;
		case PORTB_ID: TOGGLE_BIT(PORTB , pin); break;
		case PORTC_ID: TOGGLE_BIT(PORTC , pin); break;
		case PORTD_ID: TOGGLE_BIT(PORTD , pin); break;
	}
}

void MDIO_void_setpin_direction(port_type port, pin_type pin, direction_type direction)
{
	if(direction == OUTPUT)
	{
		switch(port)
		{
			case PORTA_ID: SET_BIT(DDRA , pin); break;
			case PORTB_ID: SET_BIT(DDRB , pin); break;
			case PORTC_ID: SET_BIT(DDRC , pin); break;
			case PORTD_ID: SET_BIT(DDRD , pin); break;
		}
	}

	else if(direction == INPUT)
	{
		switch(port)
		{
			case PORTA_ID: CLEAR_BIT(DDRA , pin); break;
			case PORTB_ID: CLEAR_BIT(DDRB , pin); break;
			case PORTC_ID: CLEAR_BIT(DDRC , pin); break;
			case PORTD_ID: CLEAR_BIT(DDRD , pin); break;
		}
	}

}

value_type MDIO_value_type_getpin_value(port_type port, pin_type pin)
{
	value_type ret_value;
	switch(port)
	{
		case PORTA_ID: ret_value = GET_BIT(PINA , pin); break;
		case PORTB_ID: ret_value = GET_BIT(PINB , pin); break;
		case PORTC_ID: ret_value = GET_BIT(PINC , pin); break;
		case PORTD_ID: ret_value = GET_BIT(PIND , pin); break;
	}
	return ret_value;
}

void MDIO_void_setport_value(port_type port , u8 copy_u8_value)
{
	switch(port)
	{
	 	case PORTA_ID: PORTA = copy_u8_value; break;
		case PORTB_ID: PORTB = copy_u8_value; break;
		case PORTC_ID: PORTC = copy_u8_value; break;
		case PORTD_ID: PORTD = copy_u8_value; break;
	}
}

void MDIO_void_setport_direction(port_type port , direction_type direction)
{
	if(direction == OUTPUT)
	{
		switch(port)
		{
			case PORTA_ID: DDRA = 0XFF; break;
			case PORTB_ID: DDRB = 0XFF; break;
			case PORTC_ID: DDRC = 0XFF; break;
			case PORTD_ID: DDRD = 0XFF; break;
		}
	}

	if(direction == INPUT)
	{
		switch(port)
		{
			case PORTA_ID: DDRA = 0X00; break;
			case PORTB_ID: DDRB = 0X00; break;
			case PORTC_ID: DDRC = 0X00; break;
			case PORTD_ID: DDRD = 0X00; break;
		}
	}

}
