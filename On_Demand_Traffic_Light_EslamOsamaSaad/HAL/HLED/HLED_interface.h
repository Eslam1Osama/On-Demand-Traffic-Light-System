/*
 * HLED_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef HAL_HLED_HLED_INTERFACE_H_
#define HAL_HLED_HLED_INTERFACE_H_

void HLED_void_enable(void);
void HLED_void_switch_on(u8 led_port , u8 led_pin);
void HLED_void_switch_off(u8 led_port , u8 led_pin);
void HLED_void_toggle(u8 led_port , u8 led_pin);

#endif /* HAL_HLED_HLED_INTERFACE_H_ */
