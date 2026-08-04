/*********************************************************************
 * @file        FMKHRT.h
 * @brief       Offer API to interface with High Resoltion Timer.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      mba
 * @date        02/03/2025
 * @version     1.0
 */
  
#ifndef FMKHRT_CONFIGSPECIFIC_H_INCLUDED
#define FMKHRT_CONFIGSPECIFIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "FMK_CFG/FMKCFG_ConfigFiles/FMKCPU_ConfigPublic.h"
    #include "../FMKCFG_ConfigFiles/FMKHRT_ConfigPublic.h"
    #include "FMK_HAL/FMK_HRT/Src/FMK_HRT.h"
    #include "TypeCommon.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************

    // ********************************************************************
    // *                      Types
    // ********************************************************************
    //-----------------------------ENUM TYPES-----------------------------//
    /* CAUTION : Automatic generated code section for Enum: Start */
    /**
    * @brief High Resolution Timer Instance Number.
    */
    typedef enum
    {
        FMKHRT_HIGH_RES_TIMER_1 = 0,                  /**< Timer Resolution  0 */
    
        FMKHRT_HIGH_RES_TIMER_NB,
    } t_eFMKHRT_HighResIstc;

    /**
    * @brief High Resolution Slave Timer Number.
    */
    typedef enum
    {
        FMKHRT_HRTIM_SLAVE_1 = 0,                  /**< Timer Slave A */
        FMKHRT_HRTIM_SLAVE_2,                        /**< Timer Slave B */
        FMKHRT_HRTIM_SLAVE_3,                        /**< Timer Slave C */
        FMKHRT_HRTIM_SLAVE_4,                        /**< Timer Slave D */
        FMKHRT_HRTIM_SLAVE_5,                        /**< Timer Slave E */
        FMKHRT_HRTIM_SLAVE_6,                        /**< Timer Slave F */
    
        FMKHRT_HRTIM_SLAVE_NB,
    } t_eFMKHRT_HighResSlvTim;

    /**
    * @brief High Resolution Timer Channel.
    */
    typedef enum
    {
        FMKHRT_HRTIM_CHANNEL_1 = 0,                  /**< Channel 1 */
        FMKHRT_HRTIM_CHANNEL_2,                        /**< Channel 2 */
    
        FMKHRT_HRTIM_CHANNEL_NB,
    } t_eFMKHRT_HrTimChannel;

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
    //                      Public functions - Prototyupes
    //********************************************************************************
    /**
    *
    *	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
    *
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    *  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
    */
    t_eReturnCode FMKHRT_GetTimerInfoFromLine( t_eFMKHRT_HighResLine f_HrLine_e,
                                                t_eFMKHRT_HighResIstc * f_HrTimIstc_pe,
                                                t_eFMKHRT_HighResSlvTim * f_HrSlvTim_pe,
                                                t_eFMKHRT_HrTimChannel  * f_HrChnl_pe);

    t_eReturnCode FMKHRT_Set_SpecificCalibration(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                 t_uint32 f_timeout_u32);

    t_eReturnCode FMKHRT_Get_BspTimerIndexSpecific(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                   t_uint32 *f_bspTimerIdx_pu32);

    t_eReturnCode FMKHRT_Get_BspTimerResetIndexSpecific(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                        t_uint32 *f_bspTimerResetIdx_pu32);

    t_eReturnCode FMKHRT_Get_BspTimerUpdateIndexSpecific(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                         t_uint32 *f_bspTimerUpdateIdx_pu32);

    t_eReturnCode FMKHRT_Get_PrescalerRatioSpecific(t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                    t_uint32 *f_PscRatio_pu32);

    t_eReturnCode FMKHRT_Get_SlaveTimerFreqSpecific(t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                    t_uint16 f_hrtimFreqMHz_u16,
                                                    t_uint16 *f_slvFreqMHz_pu16);
    /**
    *
    *   @brief    Return the effective HRTIM kernel clock multiplier for the selected MCU family.
    *
    *   @param[in]  f_hrTimClkPort_e         : HRTIM RCC clock port.
    *   @param[in]  f_busFreqMHz_u16         : bus/kernel source frequency in MHz.
    *   @param[in]  f_ahbFreqMHz_u16         : AHB/HCLK frequency in MHz.
    *   @param[out] f_multiplier_pu8         : resulting multiplier to apply on bus frequency.
    *
    *  @retval RC_OK                         @ref RC_OK
    *  @retval RC_ERROR_PTR_NULL             @ref RC_ERROR_PTR_NULL
    *  @retval RC_ERROR_PARAM_INVALID        @ref RC_ERROR_PARAM_INVALID
    */
    t_eReturnCode FMKHRT_Get_TimerClockMultiplierSpecific(t_eFMKCPU_ClockPort f_hrTimClkPort_e,
                                                          t_uint16 f_busFreqMHz_u16,
                                                          t_uint16 f_ahbFreqMHz_u16,
                                                          t_uint8 *f_multiplier_pu8);

    t_eReturnCode FMKHRT_Get_EnumTimerIdxSpecific(t_uint32 f_bspTimIdx_u32,
                                                  t_eFMKHRT_HighResSlvTim *f_timSlv_pe);

    t_eReturnCode FMKHRT_Get_BspOutputChannelSpecific(t_eFMKHRT_HighResSlvTim f_slvTim_e,
                                                      t_eFMKHRT_HrTimChannel f_chnl_e,
                                                      t_uint32 *f_bspOutputChnl_pu32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStart( HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                    t_uint32 f_timerIdx_u32,
                                                    t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStop(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                      t_uint32 f_timerIdx_u32,
                                                      t_uint32 f_timerChnl_u32);
    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStart_IT(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                          t_uint32 f_timerIdx_u32,
                                                          t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStop_IT(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                         t_uint32 f_timerIdx_u32,
                                                         t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStart_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                           t_uint32 f_timerIdx_u32,
                                                           t_uint32 f_timerChnl_u32,
                                                           t_uint32 f_srcAddress_u32,
                                                           t_uint32 f_destAddress_u32,
                                                           t_uint32 f_size_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleBaseStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                          t_uint32 f_timerIdx_u32,
                                                          t_uint32 f_timerChnl_u32,
                                                          t_uint32 f_srcAddress_u32,
                                                          t_uint32 f_destAddress_u32,
                                                          t_uint32 f_size_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStart(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                         t_uint32 f_timerIdx_u32,
                                                         t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStop(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                        t_uint32 f_timerIdx_u32,
                                                        t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStart_IT(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStop_IT(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                           t_uint32 f_timerIdx_u32,
                                                           t_uint32 f_timerChnl_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStart_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32,
                                                            t_uint32 f_srcAddress_u32,
                                                            t_uint32 f_destAddress_u32,
                                                            t_uint32 f_size_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_WaveformStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32,
                                                            t_uint32 f_srcAddress_u32,
                                                            t_uint32 f_destAddress_u32,
                                                            t_uint32 f_size_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimplePWMStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32,
                                                            t_uint32 f_srcAddress_u32,
                                                            t_uint32 f_destAddress_u32,
                                                            t_uint32 f_size_u32); 

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleOCStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32,
                                                            t_uint32 f_srcAddress_u32,
                                                            t_uint32 f_destAddress_u32,
                                                            t_uint32 f_size_u32);

    HAL_StatusTypeDef FMKHRT_HAL_HRTIM_SimpleCaptureStop_DMA(HRTIM_HandleTypeDef *f_bspIstc_ps,
                                                            t_uint32 f_timerIdx_u32,
                                                            t_uint32 f_timerChnl_u32,
                                                            t_uint32 f_srcAddress_u32,
                                                            t_uint32 f_destAddress_u32,
                                                            t_uint32 f_size_u32);                                                                                                                   
    
#endif // FMKHRT_CONFIGSPECIFIC_H_INCLUDED
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
