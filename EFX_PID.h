#ifndef _PID_H
#define _PID_H

unsigned char typedef uint8;
char typedef boolean;
signed char typedef sint8;
signed int typedef sint16;
unsigned int typedef uint16;
signed long int typedef sint32;
unsigned long int typedef uint32;

//EFX040:
typedef struct Efx_StatePT1_Type
{
    sint32 X1;
    sint32 Y1;
} Efx_StatePT1_Type;

typedef struct Efx_StateDT1Typ1_Type
{
    sint32 X1;
    sint32 X2;
    sint32 Y1;
} Efx_StateDT1Typ1_Type;

typedef struct Efx_StateDT1Typ2_Type
{
    sint32 X1;
    sint32 Y1;

} Efx_StateDT1Typ2_Type;

typedef struct Efx_StatePD_Type
{
    sint32 X1;
    sint32 Y1;
} Efx_StatePD_Type;

typedef struct Efx_ParamPD_Type
{
    sint32 K_C;
    sint32 Tv_C;
} Efx_ParamPD_Type;

typedef struct Efx_StateI_Type
{
    sint32 X1;
    sint32 Y1;
}Efx_StateI_Type;

typedef struct Efx_StatePI_Type
{
    sint32 X1;
    sint32 Y1;
}Efx_StatePI_Type;

typedef struct Efx_ParamPI_Type
{
    sint32 K_C;
    sint32 Tnrec_C;
}Efx_ParamPI_Type;

typedef struct Efx_StatePID_Type
{
    sint32 X1;
    sint32 X2;
    sint32 Y1;
} Efx_StatePID_Type;

typedef struct Efx_ParamPID_Type
{
   sint32 K_C;
   sint32 Tv_C;
   sint32 Tnrec_C;
} Efx_ParamPID_Type;

typedef struct Efx_Limits_Type
{
    sint32 Min_C;
    sint32 Max_C;
} Efx_Limits_Type;








#endif