/*
 * LBIT_MATH.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: eslam
 */

#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

#define GET_BIT(REG , BIT_NUM) ((REG >> (BIT_NUM)) & 0X01)
#define SET_BIT(REG , BIT_NUM) REG |= (1 << (BIT_NUM))
#define CLEAR_BIT(REG , BIT_NUM) REG &= ~(1 << (BIT_NUM))
#define TOGGLE_BIT(REG , BIT_NUM) REG ^= (1 << (BIT_NUM))

#endif /* LBIT_MATH_H_ */
