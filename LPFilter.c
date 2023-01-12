#include <stdio.h>
#include "LPFilter.h"

signed int Efx_LpFilterFac1(signed int input1,signed int input2,signed int input3 )
{
    signed int y_before = input1, x_n = input2, fac = input3 , y;

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

