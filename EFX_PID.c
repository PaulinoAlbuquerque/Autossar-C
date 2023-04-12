#include <stdio.h>
#include "EFX_PID.h"



//EFX041:
void Efx_PCalc_s32(sint32 X_s32, sint32* P_ps32, sint32 K_s32)
{   //EFX042:
    *P_ps32 = (K_s32 * X_s32)>>16;
}

//EFX525:
void Efx_PCalc(sint32 X_s32, sint32* P_ps32, sint32 K_s32)
{
    //EFX526:
    *P_ps32 = (K_s32 * X_s32)>>16;
}

//EFX044:
void Efx_PSetState(sint32* P_s32, sint16 Y_s16)
{   //EFX045 :
    *P_s32 = Y_s16 << 16;
}

//EFX047 and EFX050:
sint16 Efx_POut_s16(const sint32*  P_ps32)
{
    sint16 Output_value;

    //EFX048:
    Output_value = *P_ps32 >> 16;

    //EFX049:
    if (Output_value >32767) 
    {
        Output_value = 32767;
    }

    if (Output_value < -32767)
    {
        Output_value = -32767;
    }

    return(Output_value);
}

//EFX047 and EFX050:
sint8 Efx_POut_s8(const sint32*  P_ps32)
{
    sint8 Output_value;

    //EFX048:
    Output_value = *P_ps32 >> 16;

    //EFX049:
    if (Output_value > 127) 
    {
        Output_value = 127;
    }

    if (Output_value < -128)
    {
        Output_value = -128;
    }

    return(Output_value);
}


//Falta Efx_PT1Calc!!!

//EFX056:
void Efx_PT1SetState(Efx_StatePT1_Type* const State_cpst, sint32 X1_s32, sint16 Y1_s16)
{   
    //EFX057 :
    State_cpst->Y1 = Y1_s16 << 16;

    //EFX059:
    State_cpst->X1 = X1_s32;
}

//Falta Efx_CalcTeQ_s32!!!

//EFX450:
sint32 Efx_CalcTeQApp_s32( sint32 T1rec_s32, sint32 dT_s32 )
{
    sint32 TeQApp;
    
    //EFX451 :
    TeQApp = 1 - (T1rec_s32 * dT_s32);

    return(TeQApp);
}

//EFX067:
sint16 Efx_PT1Out_s16 ( const Efx_StatePT1_Type * const State_cpst)
{  
   sint16 Output;

   // EFX064 :
   Output = State_cpst->Y1 >> 16 ;

   return(Output);
}

//EFX067:
sint8 Efx_PT1Out_s8(const Efx_StatePT1_Type * const State_cpst)
{   
    sint8 Output;

    //EFX064 :
    Output = State_cpst->Y1 >> 16 ;    

    return(Output);
}

//FALTA Efx_DT1Typ1Calc!!!

//FALTA Efx_DT1Typ2Calc !!!

//EFX077:
void Efx_DT1Typ1SetState( Efx_StateDT1Typ1_Type* const State_cpst, sint32 X1_s32, sint32 X2_s32, sint16 Y1_s16)
{
    //EFX078 :
    State_cpst->Y1 = Y1_s16 << 16;

    //EFX080:
    State_cpst->X1 = X1_s32;
    State_cpst->X2 = X2_s32;
}

//EFX510:
void Efx_DT1Typ2SetState( Efx_StateDT1Typ2_Type* const State_cpst, sint32 X1_s32, sint16 Y1_s16)
{
    //EFX511 :
    State_cpst->Y1 = Y1_s16 << 16;

    //EFX513:
    State_cpst->X1 = X1_s32;
}

//EFX081:
sint16 Efx_DT1Typ1Out_s16(const Efx_StateDT1Typ1_Type * const State_cpst)
{
    sint16 Output;

    //EFX082:
    Output = State_cpst->Y1 >> 16;


    //EFX084:
    if(Output >= 0)
    {
        Output = 32767;
    }
    else
    {
        Output = -32767;

    }

    return(Output);
}

//EFX081:
sint8 Efx_DT1Typ1Out_s16(const Efx_StateDT1Typ1_Type * const State_cpst)
{
    sint8 Output;

    //EFX082:
    Output = State_cpst->Y1 >> 16;

    //EFX084:
    if(Output >= 0)
    {
        Output = 127;
    }
    else
    {
        Output = -127;

    }
    return(Output);
}

//EFX515:
sint16 Efx_DT1Typ2Out_s16(const Efx_StateDT1Typ2_Type * const State_cpst)
{
    sint16 Output;

    //EFX516:
    Output = State_cpst->Y1 >> 16;

    //EFX518:
    if(Output >= 0)
    {
        Output = 32767;
    }
    else
    {
        Output = -32767;
    }

    return(Output);



}

//EFX515:
sint16 Efx_DT1Typ2Out_s16(const Efx_StateDT1Typ2_Type * const State_cpst)
{
    sint16 Output;

    //EFX516:
    Output = State_cpst->Y1 >> 16;

    //EFX518:
    if(Output >= 0)
    {
        Output = 127;
    }
    else
    {
        Output = -127;

    }
    return(Output);
}

//EFX090:
void Efx_PDCalc( sint32 X_s32, Efx_StatePD_Type* const State_cpst, const Efx_ParamPD_Type* const Param_cpst, sint32 dT_s32 )
{
    sint32 Output;

    //EFX090:
    Output = (Param_cpst->K_C * (1+ Param_cpst->Tv_C/dT_s32) * X_s32) - (Param_cpst->K_C * (Param_cpst->Tv_C/dT_s32) * State_cpst->X1);

    //EFX092:
    State_cpst->Y1 = Output;

    //EFX093:
    State_cpst->X1 = X_s32;
}

//EFX095:
void Efx_PDSetState( Efx_StatePD_Type* const State_cpst, sint32 X1_s32, sint16 Y1_s16)
{
    //EFX095:
    State_cpst->Y1 = Y1_s16 << 16;

    //EFX098:
    State_cpst->X1 = X1_s32;

}
//EFX100:

inline void Efx_PDSetParam( Efx_ParamPD_Type* const Param_cpst, sint32 K_s32, sint32 Tv_s32)
{
    //EFX101:
    Param_cpst->K_C = K_s32;

    //EFX102:
    Param_cpst->Tv_C = Tv_s32;

}

//EFX103 and EFX107:
sint16 Efx_PDOut_s16(Efx_StatePD_Type* const State_cpst )
{
    sint16 Output;

    //EFX104 :
    Output = State_cpst->Y1 >> 16;

    //EFX106:
    if (Output > 32767)
        {
            Output = 32767;
        }
    if( Output < -32768) 
        {
            Output = -32768;
        }   

    return(Output);
}

//EFX103 and EFX107:
sint8 Efx_PDOut_s16(Efx_StatePD_Type* const State_cpst )
{
    sint8 Output;

    //EFX104 :
    Output = State_cpst->Y1 >> 16;

    //EFX106:
    if (Output > 127)
        {
            Output = 127;
        }
    if( Output < -128) 
        {
            Output = -128;
        }   

    return(Output);
}

//EFX110:
void Efx_ICalc( sint32 X_s32, Efx_StateI_Type* const State_cpst, sint32 K_s32, sint32 dT_s32)
{   
    sint32 Output;

    //EFX111:
    Output = State_cpst->Y1 + K_s32 * dT_s32 * State_cpst->X1;

    //EFX112:
    State_cpst->Y1 = Output;
    State_cpst->X1 = X_s32;
}

//EFX455:
void Efx_ILimCalc( sint32 X_s32, Efx_StateI_Type* const State_cpst, sint32 K_s32, const Efx_Limits_Type* const Limit_cpst,
sint32 dT_s32)
{   
    sint32 Output_value;

    //EFX456:
    Output_value = State_cpst->Y1 + K_s32 * dT_s32 * State_cpst->X1;

    //EFX457:
    if (Output_value < Limit_cpst->Min_C) 
        Output_value = Limit_cpst->Min_C;
    if (Output_value > Limit_cpst->Max_C)
        Output_value = Limit_cpst->Max_C;

    //EFX458:
    State_cpst->Y1 = Output_value;
    State_cpst->X1 = X_s32;
}

//EFX460:
void Efx_CtrlSetLimit(sint32 Min_s32, sint32 Max_s32, Efx_Limits_Type* const Limit_cpst)
{
    //EFX461:
    Limit_cpst->Min_C = Min_s32;
    Limit_cpst->Max_C = Max_s32;
}

//EFX114:
void Efx_ISetState(Efx_StateI_Type* const State_cpst,sint32 X1_s32,sint16 Y1_s16)
{
    //EFX115:
    State_cpst->Y1 = Y1_s16 << 16;
    //EFX117:
    State_cpst->X1 = X1_s32;
}

//EFX118:
inline sint16 Efx_IOut_s16( Efx_StateI_Type* const State_cpst)
{
    sint16 Output;

    //EFX119:
    Output = State_cpst->Y1 >> 16;

    //EFX121:
    if(Output > 32767)
        Output = 32767;
    if(Output < -32768)
        Output = -32768;
    
    return(Output);

}

//EFX118:
inline sint8 Efx_IOut_s16( Efx_StateI_Type* const State_cpst)
{
    sint8 Output;

    //EFX119:
    Output = State_cpst->Y1 >> 16;

    //EFX121:
    if(Output > 127)
        Output = 127;
    if(Output < -128)
        Output = -128;
    
    return(Output);

}
