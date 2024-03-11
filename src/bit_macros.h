/*
 * bit_macros.h
 *
 *  Created on: Feb 29, 2024
 *      Author: cotti
 */

#ifndef BIT_MACROS_H_
#define BIT_MACROS_H_

#define BIT_CLEAR(reg, value, pos) { reg &= ~(value << pos); }
#define BIT_SET(reg, value, pos)   { reg |= (value << pos); }
#define BIT_GET(reg, pos, bits)    { (reg >> pos) & bits; }


#endif /* BIT_MACROS_H_ */
