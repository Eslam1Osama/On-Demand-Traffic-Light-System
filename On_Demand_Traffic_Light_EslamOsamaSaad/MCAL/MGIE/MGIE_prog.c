/*
 * MGIE_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"

#include"MGIE_private.h"

void MGIE_void_enable(void)
{
	/*Enable I_BIT (GIE) bit in SREG*/
	SET_BIT(SREG , I_BIT);
}

void MGIE_void_disable(void)
{
	/*disable I_BIT (GIE) bit in SREG*/
		CLEAR_BIT(SREG , I_BIT);
}
