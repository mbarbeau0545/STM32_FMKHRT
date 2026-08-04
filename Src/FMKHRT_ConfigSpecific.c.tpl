/*********************************************************************
 * @file        FMKHRT.h
 * @brief       Offer API to interface with High Resoltion Timer.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      mba
 * @date        02/03/2025
 * @version     1.0
 */






// ********************************************************************
// *                      Includes
// ********************************************************************
#include "./FMKHRT_ConfigSpecific.h"
// ********************************************************************
// *                      Defines
// ********************************************************************


// ********************************************************************
// *                      Types
// ********************************************************************
//-----------------------------ENUM TYPES-----------------------------//
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */

//-----------------------------TYPEDEF TYPES---------------------------//
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
/**
*
*	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
*
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*  @retval RC_OK                             @ref RC_OK
*  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
*  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
*  
*/
static t_eReturnCode s_FMKHRTSPEC_GetSlvTimerId(t_uint32 f_slvTimIdx_u32, t_uint32 * f_slvTimId_pu32);

//********************************************************************************
//                      Public functions - Prototypes
//********************************************************************************
/*********************************
 * FMKHRT_GetTimerInfoFromLine
 *********************************/
t_eReturnCode FMKHRT_GetTimerInfoFromLine( t_eFMKHRT_HighResLine f_HrLine_e,
                                                    t_eFMKHRT_HighResIstc * f_HrTimIstc_pe,
                                                    t_eFMKHRT_HighResSlvTim * f_HrSlvTim_pe,
                                                    t_eFMKHRT_HrTimChannel  * f_HrChnl_pe)
{
    t_eReturnCode Ret_e = RC_OK;

    if((f_HrChnl_pe == NULL)
    || (f_HrSlvTim_pe == NULL)
    || (f_HrTimIstc_pe == NULL))
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_HrLine_e)
        {
            /* CAUTION : Automatic generated code section for switch case mapping: Start */
            case FMKHRT_HR_LINE_1:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_1;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_1;                }
                break;
            }
            case FMKHRT_HR_LINE_2:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_1;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_2;                }
                break;
            }
            case FMKHRT_HR_LINE_3:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_2;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_1;                }
                break;
            }
            case FMKHRT_HR_LINE_4:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_2;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_2;                }
                break;
            }
            case FMKHRT_HR_LINE_5:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_3;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_1;                }
                break;
            }
            case FMKHRT_HR_LINE_6:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_3;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_2;                }
                break;
            }
            case FMKHRT_HR_LINE_7:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_4;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_1;                }
                break;
            }
            case FMKHRT_HR_LINE_8:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_4;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_2;                }
                break;
            }
            case FMKHRT_HR_LINE_9:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_5;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_1;                }
                break;
            }
            case FMKHRT_HR_LINE_10:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_5;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_2;                }
                break;
            }
            case FMKHRT_HR_LINE_11:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_6;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_1;                }
                break;
            }
            case FMKHRT_HR_LINE_12:
            {
                if(f_HrTimIstc_pe != (t_eFMKHRT_HighResIstc *)NULL)
                {
                    *f_HrTimIstc_pe = FMKHRT_HIGH_RES_TIMER_1;
                }
                if(f_HrSlvTim_pe != (t_eFMKHRT_HighResSlvTim *)NULL)
                {
                    *f_HrSlvTim_pe = FMKHRT_HRTIM_SLAVE_6;
                }
                if(f_HrChnl_pe != (t_eFMKHRT_HrTimChannel  *)NULL)
                {
                    *f_HrChnl_pe = FMKHRT_HRTIM_CHANNEL_2;                }
                break;
            }
            /* CAUTION : Automatic generated code section for switch case mapping: Stop */
            case FMKHRT_HR_LINE_NB:
            default:
            {
                Ret_e = RC_ERROR_PARAM_INVALID;
            }
        }
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Set_SpecificCalibration
 *********************************/
t_eReturnCode FMKHRT_Set_SpecificCalibration(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                             t_uint32 f_timeout_u32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_bspIstc_ps == (HRTIM_HandleTypeDef *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        HAL_StatusTypeDef bspRet_e = HAL_OK;

        bspRet_e = HAL_HRTIM_DLLCalibrationStart(f_bspIstc_ps, HRTIM_SINGLE_CALIBRATION);
        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_PollForDLLCalibration(f_bspIstc_ps, f_timeout_u32);
        }
        if(bspRet_e != HAL_OK)
        {
            Ret_e = RC_ERROR_WRONG_RESULT;
        }
#else
        (void)f_timeout_u32;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_BspTimerIndexSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_BspTimerIndexSpecific(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                               t_uint32 *f_bspTimerIdx_pu32)
{
    t_eReturnCode Ret_e = RC_ERROR_NOT_SUPPORTED;

    if(f_bspTimerIdx_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        if(f_hrSlvTim_e == FMKHRT_HRTIM_SLAVE_6)
        {
            *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_F;
            Ret_e = RC_OK;
        }
#else
        (void)f_hrSlvTim_e;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_BspTimerResetIndexSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_BspTimerResetIndexSpecific(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                    t_uint32 *f_bspTimerResetIdx_pu32)
{
    t_eReturnCode Ret_e = RC_ERROR_NOT_SUPPORTED;

    if(f_bspTimerResetIdx_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        if(f_hrSlvTim_e == FMKHRT_HRTIM_SLAVE_6)
        {
            *f_bspTimerResetIdx_pu32 = HRTIM_TIMERRESET_TIMER_F;
            Ret_e = RC_OK;
        }
#else
        (void)f_hrSlvTim_e;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_BspTimerUpdateIndexSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_BspTimerUpdateIndexSpecific(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                     t_uint32 *f_bspTimerUpdateIdx_pu32)
{
    t_eReturnCode Ret_e = RC_ERROR_NOT_SUPPORTED;

    if(f_bspTimerUpdateIdx_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        if(f_hrSlvTim_e == FMKHRT_HRTIM_SLAVE_6)
        {
            *f_bspTimerUpdateIdx_pu32 = HRTIM_TIMERUPDATE_F;
            Ret_e = RC_OK;
        }
#else
        (void)f_hrSlvTim_e;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_PrescalerRatioSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_PrescalerRatioSpecific(t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                t_uint32 *f_PscRatio_pu32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_PscRatio_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        switch(f_CpuFreqMulDiv_e)
        {
            case FMKHRT_FREQRANGE_MUL_2:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_MUL2;
                break;
            case FMKHRT_FREQRANGE_MUL_4:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_MUL4;
                break;
            case FMKHRT_FREQRANGE_MUL_8:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_MUL8;
                break;
            case FMKHRT_FREQRANGE_MUL_16:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_MUL16;
                break;
            case FMKHRT_FREQRANGE_MUL_32:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_MUL32;
                break;
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
        }
#else
        (void)f_CpuFreqMulDiv_e;
        Ret_e = RC_ERROR_NOT_SUPPORTED;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_SlaveTimerFreqSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_SlaveTimerFreqSpecific(t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                t_uint16 f_hrtimFreqMHz_u16,
                                                t_uint16 *f_slvFreqMHz_pu16)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_slvFreqMHz_pu16 == (t_uint16 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        switch(f_CpuFreqMulDiv_e)
        {
            case FMKHRT_FREQRANGE_MUL_32:
                *f_slvFreqMHz_pu16 = (t_uint16)(f_hrtimFreqMHz_u16 * (t_uint16)32);
                break;
            case FMKHRT_FREQRANGE_MUL_16:
                *f_slvFreqMHz_pu16 = (t_uint16)(f_hrtimFreqMHz_u16 * (t_uint16)16);
                break;
            case FMKHRT_FREQRANGE_MUL_8:
                *f_slvFreqMHz_pu16 = (t_uint16)(f_hrtimFreqMHz_u16 * (t_uint16)8);
                break;
            case FMKHRT_FREQRANGE_MUL_4:
                *f_slvFreqMHz_pu16 = (t_uint16)(f_hrtimFreqMHz_u16 * (t_uint16)4);
                break;
            case FMKHRT_FREQRANGE_MUL_2:
                *f_slvFreqMHz_pu16 = (t_uint16)(f_hrtimFreqMHz_u16 * (t_uint16)2);
                break;
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
        }
#else
        (void)f_CpuFreqMulDiv_e;
        (void)f_hrtimFreqMHz_u16;
        Ret_e = RC_ERROR_NOT_SUPPORTED;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_TimerClockMultiplierSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_TimerClockMultiplierSpecific(t_eFMKCPU_ClockPort f_hrTimClkPort_e,
                                                      t_uint16 f_busFreqMHz_u16,
                                                      t_uint16 f_ahbFreqMHz_u16,
                                                      t_uint8 *f_multiplier_pu8)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_multiplier_pu8 == (t_uint8 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else if((f_hrTimClkPort_e >= FMKCPU_RCC_CLK_NB)
         || (f_busFreqMHz_u16 == (t_uint16)0)
         || (f_ahbFreqMHz_u16 == (t_uint16)0))
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    else
    {
        *f_multiplier_pu8 = (t_uint8)1;

#if defined(FMKCPU_STM32_ECU_FAMILY_G4) || defined(FMKCPU_STM32_ECU_FAMILY_H7)
        if((f_hrTimClkPort_e == FMKCPU_RCC_CLK_HRTIM1)
        && (f_busFreqMHz_u16 < f_ahbFreqMHz_u16))
        {
            *f_multiplier_pu8 = (t_uint8)2;
        }
#else
        (void)f_hrTimClkPort_e;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_EnumTimerIdxSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_EnumTimerIdxSpecific(t_uint32 f_bspTimIdx_u32,
                                              t_eFMKHRT_HighResSlvTim *f_timSlv_pe)
{
    t_eReturnCode Ret_e = RC_ERROR_NOT_SUPPORTED;

    if(f_timSlv_pe == (t_eFMKHRT_HighResSlvTim *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        if(f_bspTimIdx_u32 == HRTIM_TIMERINDEX_TIMER_F)
        {
            *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_6;
            Ret_e = RC_OK;
        }
#else
        (void)f_bspTimIdx_u32;
#endif
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_Get_BspOutputChannelSpecific
 *********************************/
t_eReturnCode FMKHRT_Get_BspOutputChannelSpecific(t_eFMKHRT_HighResSlvTim f_slvTim_e,
                                                  t_eFMKHRT_HrTimChannel f_chnl_e,
                                                  t_uint32 *f_bspOutputChnl_pu32)
{
    t_eReturnCode Ret_e = RC_ERROR_NOT_SUPPORTED;

    if(f_bspOutputChnl_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    else
    {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        if(f_slvTim_e == FMKHRT_HRTIM_SLAVE_6)
        {
            if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
            {
                *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TF1;
                Ret_e = RC_OK;
            }
            else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
            {
                *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TF2;
                Ret_e = RC_OK;
            }
        }
#else
        (void)f_slvTim_e;
        (void)f_chnl_e;
#endif
    }

    return Ret_e;
}

/****************************************
 * FMKHRT_HAL_HRTIM_SimpleBaseStart
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStart( HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                    t_uint32 f_timerIdx_u32,
                                                    t_uint32 f_timerChnl_u32)
{
    UNUSED(f_timerChnl_u32);
    return HAL_HRTIM_SimpleBaseStart(f_bspIstc_ps, f_timerIdx_u32);
}

/****************************************
 * FMKHRT_HAL_HRTIM_SimpleBaseStart
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStop(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                   t_uint32 f_timerIdx_u32,
                                                   t_uint32 f_timerChnl_u32)
{
    UNUSED(f_timerChnl_u32);
    return HAL_HRTIM_SimpleBaseStop(f_bspIstc_ps, f_timerIdx_u32);
}

/****************************************
 * FMKHRT_HAL_HRTIM_SimpleBaseStart_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStart_IT(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                  t_uint32 f_timerIdx_u32,
                                                  t_uint32 f_timerChnl_u32)
{
    return HAL_HRTIM_SimpleBaseStart_IT(f_bspIstc_ps, f_timerIdx_u32);
}

/****************************************
 * FMKHRT_HAL_HRTIM_SimpleBaseStop_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStop_IT(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                      t_uint32 f_timerIdx_u32,
                                                      t_uint32 f_timerChnl_u32)
{
    return HAL_HRTIM_SimpleBaseStop_IT(f_bspIstc_ps, f_timerIdx_u32);
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStart_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStart_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                      t_uint32 f_timerIdx_u32,
                                                      t_uint32 f_timerChnl_u32,
                                                      t_uint32 f_srcAddress_u32,
                                                      t_uint32 f_destAddress_u32,
                                                      t_uint32 f_size_u32)
{

    return HAL_HRTIM_SimpleBaseStart_DMA(   f_bspIstc_ps, 
                                            f_timerIdx_u32,
                                            f_srcAddress_u32,
                                            f_destAddress_u32,
                                            f_size_u32);
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStop_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStop_DMA(  HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                        t_uint32 f_timerIdx_u32,
                                                        t_uint32 f_timerChnl_u32,
                                                        t_uint32 f_srcAddress_u32,
                                                        t_uint32 f_destAddress_u32,
                                                        t_uint32 f_size_u32)
{
    UNUSED(f_srcAddress_u32);
    UNUSED(f_destAddress_u32);
    UNUSED(f_size_u32);
    return HAL_HRTIM_SimpleBaseStop_DMA(f_bspIstc_ps, f_timerIdx_u32);
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStart
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStart(   HRTIM_HandleTypeDef * f_bspIstc_ps,
                                                        t_uint32 f_timerIdx_u32,
                                                        t_uint32 f_timerChnl_u32)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspslvTimId_u32;

    Ret_e = s_FMKHRTSPEC_GetSlvTimerId(f_timerIdx_u32, &bspslvTimId_u32);

    if(Ret_e == RC_OK)
    {
        bspRet_e =  HAL_HRTIM_WaveformOutputStart(f_bspIstc_ps, f_timerChnl_u32);
        

        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformCounterStart(f_bspIstc_ps, bspslvTimId_u32);
        }
    }
    else 
    {
        //---- not the best way to track the error -----//
        bspRet_e = HAL_ERROR;
    }

    return bspRet_e;
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStop
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStop(HRTIM_HandleTypeDef * f_bspIstc_ps,
                                                t_uint32 f_timerIdx_u32,
                                                t_uint32 f_timerChnl_u32)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspslvTimId_u32;
    t_uint32 currenTIm_u32;

    currenTIm_u32 =  HAL_GetTick();
    Ret_e = s_FMKHRTSPEC_GetSlvTimerId(f_timerIdx_u32, &bspslvTimId_u32);

    if(Ret_e == RC_OK
    && currenTIm_u32 > 0)
    {
        bspRet_e =  HAL_HRTIM_WaveformOutputStop(f_bspIstc_ps, f_timerChnl_u32);
        

        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformCounterStop(f_bspIstc_ps, bspslvTimId_u32);
        }
    }
    else 
    {
        //---- not the best way to track the error -----//
        bspRet_e = HAL_ERROR;
    }

    return bspRet_e;
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStart_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStart_IT(   HRTIM_HandleTypeDef * f_bspIstc_ps,
                                                        t_uint32 f_timerIdx_u32,
                                                        t_uint32 f_timerChnl_u32)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspslvTimId_u32;

    Ret_e = s_FMKHRTSPEC_GetSlvTimerId(f_timerIdx_u32, &bspslvTimId_u32);

    if(Ret_e == RC_OK)
    {
        bspRet_e =  HAL_HRTIM_WaveformOutputStart(f_bspIstc_ps, f_timerChnl_u32);
        

        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformCounterStart_IT(f_bspIstc_ps, bspslvTimId_u32);
        }
    }
    else 
    {
        //---- not the best way to track the error -----//
        bspRet_e = HAL_ERROR;
    }

    return bspRet_e;
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStop_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStop_IT( HRTIM_HandleTypeDef * f_bspIstc_ps,
                                                    t_uint32 f_timerIdx_u32,
                                                    t_uint32 f_timerChnl_u32)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspslvTimId_u32;

    Ret_e = s_FMKHRTSPEC_GetSlvTimerId(f_timerIdx_u32, &bspslvTimId_u32);

    if(Ret_e == RC_OK)
    {
        bspRet_e =  HAL_HRTIM_WaveformOutputStart(f_bspIstc_ps, f_timerChnl_u32);
        

        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformCounterStop_IT(f_bspIstc_ps, bspslvTimId_u32);
        }
    }
    else 
    {
        //---- not the best way to track the error -----//
        bspRet_e = HAL_ERROR;
    }

    return bspRet_e;
}

/****************************************
 * FMKHRT_HAL_HRTIM_WaveformStart_IT
 ***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStart_DMA(   HRTIM_HandleTypeDef * f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32,
                                                            t_uint32 f_srcAddress_u32,
                                                            t_uint32 f_destAddress_u32,
                                                            t_uint32 f_size_u32)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspslvTimId_u32;

    UNUSED(f_srcAddress_u32);
    UNUSED(f_destAddress_u32);
    UNUSED(f_size_u32);

    Ret_e = s_FMKHRTSPEC_GetSlvTimerId(f_timerIdx_u32, &bspslvTimId_u32);

    if(Ret_e == RC_OK)
    {
        bspRet_e =  HAL_HRTIM_WaveformOutputStart(f_bspIstc_ps, f_timerChnl_u32);
        

        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformCounterStart_DMA(f_bspIstc_ps, bspslvTimId_u32);
        }
    }
    else 
    {
        //---- not the best way to track the error -----//
        bspRet_e = HAL_ERROR;
    }

    return bspRet_e;
}

/****************************************
* FMKHRT_HAL_HRTIM_WaveformStop_IT
***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                        t_uint32 f_timerIdx_u32,
                                                        t_uint32 f_timerChnl_u32,
                                                        t_uint32 f_srcAddress_u32,
                                                        t_uint32 f_destAddress_u32,
                                                        t_uint32 f_size_u32)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspslvTimId_u32;

    UNUSED(f_srcAddress_u32);
    UNUSED(f_destAddress_u32);
    UNUSED(f_size_u32);

    Ret_e = s_FMKHRTSPEC_GetSlvTimerId(f_timerIdx_u32, &bspslvTimId_u32);

    if(Ret_e == RC_OK)
    {
        bspRet_e =  HAL_HRTIM_WaveformOutputStart(f_bspIstc_ps, f_timerChnl_u32);
        

        if(bspRet_e == HAL_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformCounterStop_DMA(f_bspIstc_ps, bspslvTimId_u32);
        }
    }
    else 
    {
        //---- not the best way to track the error -----//
        bspRet_e = HAL_ERROR;
    }

    return bspRet_e;
}

/****************************************
* FMKHRT_HAL_HRTIM_SimplePWMStop_DMA
***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimplePWMStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                    t_uint32 f_timerIdx_u32,
                                                    t_uint32 f_timerChnl_u32,
                                                    t_uint32 f_srcAddress_u32,
                                                    t_uint32 f_destAddress_u32,
                                                    t_uint32 f_size_u32)
{
    UNUSED(f_srcAddress_u32);
    UNUSED(f_destAddress_u32);
    UNUSED(f_size_u32);

    return HAL_HRTIM_SimplePWMStop_DMA(f_bspIstc_ps, f_timerIdx_u32, f_timerChnl_u32);
}

/****************************************
* FMKHRT_HAL_HRTIM_SimpleOCStop_DMA
***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleOCStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                    t_uint32 f_timerIdx_u32,
                                                    t_uint32 f_timerChnl_u32,
                                                    t_uint32 f_srcAddress_u32,
                                                    t_uint32 f_destAddress_u32,
                                                    t_uint32 f_size_u32)
{
    UNUSED(f_srcAddress_u32);
    UNUSED(f_destAddress_u32);
    UNUSED(f_size_u32);

    return HAL_HRTIM_SimpleOCStop_DMA(f_bspIstc_ps, f_timerIdx_u32, f_timerChnl_u32);
}


/****************************************
* FMKHRT_HAL_HRTIM_SimpleCaptureStop_DMA
***************************************/
HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleCaptureStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                        t_uint32 f_timerIdx_u32,
                                                        t_uint32 f_timerChnl_u32,
                                                        t_uint32 f_srcAddress_u32,
                                                        t_uint32 f_destAddress_u32,
                                                        t_uint32 f_size_u32)
{
    UNUSED(f_srcAddress_u32);
    UNUSED(f_destAddress_u32);
    UNUSED(f_size_u32);

    return HAL_HRTIM_SimpleCaptureStop_DMA(f_bspIstc_ps, f_timerIdx_u32, f_timerChnl_u32);
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************

/****************************************
* s_FMKHRTSPEC_GetSlvTimerId
***************************************/
static t_eReturnCode s_FMKHRTSPEC_GetSlvTimerId(t_uint32 f_slvTimIdx_u32, t_uint32 * f_slvTimId_pu32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_slvTimId_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        // flag automatic generated code 
        switch(f_slvTimIdx_u32)
        {
            case HRTIM_TIMERINDEX_TIMER_A:
                *f_slvTimId_pu32 = HRTIM_TIMERID_TIMER_A;
                break;
            case HRTIM_TIMERINDEX_TIMER_B:
                *f_slvTimId_pu32 = HRTIM_TIMERID_TIMER_B;
                break;
            case HRTIM_TIMERINDEX_TIMER_C:
                *f_slvTimId_pu32 = HRTIM_TIMERID_TIMER_C;
                break;
            case HRTIM_TIMERINDEX_TIMER_D:
                *f_slvTimId_pu32 = HRTIM_TIMERID_TIMER_D;
                break;
            case HRTIM_TIMERINDEX_TIMER_E:
                *f_slvTimId_pu32 = HRTIM_TIMERID_TIMER_E;
                break;
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
            case HRTIM_TIMERINDEX_TIMER_F:
                *f_slvTimId_pu32 = HRTIM_TIMERID_TIMER_F;
                break;
#endif
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
        }
    }

    return Ret_e;
}


//************************************************************************************
// End of File
//************************************************************************************

/**
 *
 *	@brief
 *	@note   
 *
 *
 *	@params[in] 
 *	@params[out]
 *	 
 *
 *
 */
