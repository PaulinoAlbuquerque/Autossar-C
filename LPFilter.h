#ifndef _LPFilter_H
#define _LPFilter_H

unsigned char typedef uint8;
char typedef boolean;
signed char typedef sint8;
signed int typedef sint16;
unsigned int typedef uint16;
signed long int typedef sint32;
unsigned long int typedef uint32;

signed int Efx_LpFilterFac1(signed int input1,signed int input2,signed int input3 );
signed long int intEfx_LpFilterFac1_(signed long int Yant, signed int xn, int fac);
unsigned long int Efx_LpFilter_u32_u32(unsigned long int input, unsigned long int old_output, unsigned long int tau_const, unsigned int recurrence, unsigned char reset, unsigned long int init_val, unsigned char *started);
char RoundOff_for_HPFilter(sint16 Yn_1);
sint16 Efx_HpFilter_u8_s16(sint16 Yn_1, uint8 Xn, uint8 Xn_1, uint16 K);
sint16 Efx_HpFilter_s8_s16(sint16 Yn_1,sint8 Xn, sint8 Xn_1, uint16 K);
sint32 Efx_HpFilter_u16_s32( sint32 Yn_1, uint16 Xn, uint16 Xn_1, uint16 K);










#endif
