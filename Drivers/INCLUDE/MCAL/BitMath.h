/*
 * BitMath.h
 *
 * Created: 2024/08/24 4:35:41 PM
 *  Author: Home
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(reg,pin) reg|=(1<<pin)
#define ClrBit(reg,pin) reg&=(~(1<<pin))
#define GetBit(reg,pin) (reg>>pin)&(1)
#define TogBit(reg,bit) reg=reg^(1<<bit)


#endif /* BITMATH_H_ */