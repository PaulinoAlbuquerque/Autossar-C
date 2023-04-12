#include <stdio.h>
#include "LPFilter.h"



signed int Efx_LpFilterFac1(signed int input1,signed int input2,signed int input3 )
{
    signed int y_before = input1, x_n = input2, fac = input3 , y;
    if (fac > 1 || fac <0)
    {
        printf("Error filter dind't converge\n");
        //return 1;

    }
    y = y_before + (x_n - y_before )*fac;
    if (y == y_before)
    {
        if(((x_n - y_before )*fac) > 0 )
        {
            y = y + 1;
        }
        else 
        {
           if(((x_n - y_before )*fac) < 0 )
           {
             y = y - 1;
           }
        }
    }

    return y;


    

}

union output
{   signed long int total;
    signed int HIGH;
    signed LOW ;
};

//EFX0011
signed long int intEfx_LpFilterFac1_1_s32s16u16_s32(signed long int Yant, signed int xn, int fac)
{
    union output Yn,Ynant;

    Ynant.total = Yant;

    if (xn == Ynant.HIGH )
    {
        Yn.HIGH = Ynant.HIGH;
        Yn.LOW = 0x8000;
    }
    else
    {
        Yn.total = Yant +  ( xn - Ynant.HIGH *fac );
    }
}

//EFX0018
unsigned long int Efx_LpFilter_u32_u32(unsigned long int input, unsigned long int old_output, unsigned long int tau_const, unsigned int recurrence, unsigned char reset, unsigned long int init_val, unsigned char *started)
{
    unsigned long int output; 
    
    //EFX013:
    if(tau_const==0)
    {
        output = input;
    }

    //EFX014 and EFX017:
    if(*started==0 )
    {
        output = init_val;
        *started = 1;
    }
    
    //EFX016:
    if((*started==0) || (reset == 1) )
    {
        output = init_val;
    }

    //EFX015:
    else
    {
        output = old_output*(int)exp((int)(-recurrence/tau_const)) + input*(int)(1 - exp((int)(-recurrence/tau_const)));
    }

    return(output);
}


char RoundOff_for_HPFilter(sint16 Yn_1)
 {   
    char Yn_1_RoundedOff;
    
    //Yn_1>>16 Rounded Off computation 
    if( ((Yn_1>>16)) > -0.5 & (Yn_1>>16) < 0.5)
    {
        Yn_1_RoundedOff = 0;
    }
    
    if( ((Yn_1>>16)) >= 0.5 & (Yn_1>>16) < 1)
    {
        Yn_1_RoundedOff = 1;
    }

    if( ((Yn_1>>16)) >= -1 & (Yn_1>>16) < -0.5)
    {
        Yn_1_RoundedOff = -1;
    }

    return(Yn_1_RoundedOff);
 }
 


//EFX022:
sint16 Efx_HpFilter_u8_s16(sint16 Yn_1, uint8 Xn, uint8 Xn_1, uint16 K)
{
    sint16 Yn;
   
    //EFX023: Yn = Yn_1 - K*(Yn_1>>16) + ( Xn - Xn_1)<<7
    Yn = Yn_1 - K* RoundOff_for_HPFilter(Yn_1) + ( Xn - Xn_1)<<7;

    //EFX024 and EFX025:

    if ((Yn == Yn_1) & (Yn_1 > 0))
    {
        Yn--;
    }
    
    if ((Yn == Yn_1) & (Yn_1 < 0))
    {
        Yn++;
    }
    
    return(Yn);
}

//EFX026:
sint16 Efx_HpFilter_s8_s16(sint16 Yn_1,sint8 Xn, sint8 Xn_1, uint16 K)
{
    sint32 Yn;
   
    //EFX27: Yn = Yn_1 - K*(Yn_1>>16) + ( Xn - Xn_1)<<7
    Yn = Yn_1 - K* RoundOff_for_HPFilter(Yn_1) + ( Xn - Xn_1)<<7;

    //EFX028 and EFX029:

    if ((Yn == Yn_1) & (Yn_1 > 0))
    {
        Yn--;
    }
    
    if ((Yn == Yn_1) & (Yn_1 < 0))
    {
        Yn++;
    }
    
    return(Yn);
}


//EFX030:
sint32 Efx_HpFilter_u16_s32( sint32 Yn_1, uint16 Xn, uint16 Xn_1, uint16 K)

{
    sint32 Yn;
   
    //EFX31: Yn = Yn_1 - K*(Yn_1>>16) + ( Xn - Xn_1)<<7
    Yn = Yn_1 - K* RoundOff_for_HPFilter(Yn_1) + ( Xn - Xn_1)<<7;

    //EFX033 and EFX032:

    if ((Yn == Yn_1) & (Yn_1 > 0))
    {
        Yn--;
    }
    
    if ((Yn == Yn_1) & (Yn_1 < 0))
    {
        Yn++;
    }
    
    return(Yn);
}

