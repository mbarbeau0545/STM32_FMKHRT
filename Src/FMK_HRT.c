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
#include "APP_CFG/ConfigFiles/APPSYS_ConfigPublic.h"
#if defined(APPSYS_MODULE_FMKHRT_ENABLE)
#include "./FMK_HRT.h"
#include "FMK_CFG/FMKCFG_ConfigFiles/FMKHRT_ConfigPrivate.h"

#include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
#include "APP_CTRL/APP_SYS/Src/APP_SYS.h"
#include "3_APP/APP_CTRL/APP_SDM/Src/APP_SDM.h"
// ********************************************************************
// *                      Defines
// ********************************************************************

// ********************************************************************
// *                      Types
// ********************************************************************
/**
* @brief High Resolution Timer Instance Number.
*/
typedef enum 
{
    FMKHRT_RUN_MODE_POLL = 0x00,        /**< High Resolution Timer Slave Running on Polling Mode */
    FMKHRT_RUN_MODE_IT,                 /**< High Resolution Timer Slave Running on Interrupt Mode */
    FMKHRT_RUN_MODE_DMA                 /**< High Resolution Timer Slave Running on DMA Mode */
} t_eFMKHRT_TimRunMode;

/**
* @brief Timer Counter Operating Mode 
*/
typedef enum 
{
    FMKHRT_CTR_OPE_MODE_CONTINOUS = 0x00,
    FMKHRT_CTR_OPE_MODE_SINGLESHOT,
    FMKHRT_CTR_OPE_MODE_SINGLESHOT_RETRIGGER,
} t_eFMKHRT_CtrOpeMode;


/**
* @brief High Resolution Channel status
*/
typedef enum 
{
    FMKHRT_CHNLST_DISACTIVATED = 0x00,
    FMKHRT_CHNLST_ACTIVATED,
} t_eFMKHRT_ChnlState;

/**
* @brief List of bsp Callback 
*/
typedef enum
{
    FMKHRT_BSP_CB_FAULT_1 = 0x00,
    FMKHRT_BSP_CB_FAULT_2,
    FMKHRT_BSP_CB_FAULT_3,
    FMKHRT_BSP_CB_FAULT_4,
    FMKHRT_BSP_CB_FAULT_5,
    FMKHRT_BSP_CB_FAULT_6,
    FMKHRT_BSP_CB_SYSTEM_FAULT,
    FMKHRT_BSP_CB_DLL_CALIB_DONE,
    FMKHRT_BSP_CB_BURST_MODE_PERIOD,
    FMKHRT_BSP_CB_SYNCHRO_EVNT,
    FMKHRT_BSP_CB_REGISTER_UPDATE,
    FMKHRT_BSP_CB_REPETITION_EVNT,
    FMKHRT_BSP_CB_COMPARE_1,
    FMKHRT_BSP_CB_COMPARE_2,
    FMKHRT_BSP_CB_COMPARE_3,
    FMKHRT_BSP_CB_COMPARE_4,
    FMKHRT_BSP_CB_CAPTURE_1,
    FMKHRT_BSP_CB_CAPTURE_2,
    FMKHRT_BSP_CB_DELAYED_PROTECT,
    FMKHRT_BSP_CB_COUNTER_RESET,
    FMKHRT_BSP_CB_OUTPUT_1_SET,
    FMKHRT_BSP_CB_OUTPUT_1_RESET,
    FMKHRT_BSP_CB_OUTPUT_2_SET,
    FMKHRT_BSP_CB_OUTPUT_2_RESET,
    FMKHRT_BSP_CB_BURST_DMA_TRANSER,
    FMKHRT_BSP_CB_ERROR,
} t_eFMKHRT_BspCallbackId;
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */
//-----------------------------ENUM TYPES-----------------------------//


/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
//-----------------------------STRUCT TYPES---------------------------//
/**
* @brief High Resolution Master Timer Information.
*/
typedef struct 
{
    t_eFMKCPU_IRQNType c_IRQNType_e;      /**< Storage for IRQN (Interruption) */
    t_bool isNVICEnable_b;                      /**< Flag to know the NVIC state */
    t_bool isConfigured_b;                      /**< Flag to know if timer is successfully configured */
    t_uint16 timFreqMHz_u16;                    /**< Storage for Timer Frequency */
} t_sFMKHRT_TimMasterInfo;

/**
* @brief Channel Information.
*/
typedef struct 
{
    t_bool isConfigured_b;                      /**< Flag to know if timer is successfully configured */
    t_eFMKHRT_HrTimChannel selfId_e;
    t_eFMKHRT_ChnlState state_e;                /**< Enum to know the state of a channel */
    t_cbFMKHRT_HrLineEvnt * evntCallback_pcb;     
    t_bool isSyncOpeON_b;
} t_sFMKHRT_ChnlInfo;
/**
* @brief High Resolution Slave Timer Information.
*/
typedef struct
{
    t_eFMKHRT_HighResSlvTim selfId_e;
    t_eFMKCPU_IRQNType c_IRQNType_e;                      /**< Storage for IRQN (Interruption) */
    t_eFMKHRT_TimRunMode  runMode_e;                            /**< Storage for timer run mode */
    t_eFMKHRT_HwOpeTimer  HwOpeMode_e;                             /**< Storage for hardware mode  */
    t_sFMKHRT_ChnlInfo chnlInfo_as[FMKHRT_HRTIM_CHANNEL_NB];      /**< Storage for channel Information */
    t_bool isNVICEnable_b;                                      /**< Flag to know the NVIC state */
    t_bool isConfigured_b;                                      /**< Flag to know if timer is successfully configured */
    t_uint16 timFreqMHz_u16;                                    /**< Storage for Timer Frequency */
    t_uint32 minFreqAccept_u32;                                 /**< Min frequency allowed based  timFreqMHz_u16 ARRAMax value*/
    t_uint32 maxFreqAccept_u32;                                 /**< Max frequency allowed based  timFreqMHz_u16 ARRAMax value*/
    t_uint8 maskChnlState_u8;
    t_bool isTimerRunnin_b;
    t_bool SoftSyncMode_b;                                      /**< If set to true, in pulse mode, every channel configured are set & 
                                                                reset at the same time from the softwrare */
} t_sFMKHRT_TimSlaveInfo;


/**
* @brief High Resolution Instance Information.
*/
typedef struct 
{
    t_eFMKCPU_ClockPort c_clkPort_e;                             /**< Storage for RCC clock Port of the instance */
    HRTIM_HandleTypeDef bspItsc_s;                                     /**< Storage for bsp HRTIM instance */
    t_sFMKHRT_TimMasterInfo mstInfo_s;                                 /**< Storage for master timer inforamtion */
    t_sFMKHRT_TimSlaveInfo  slvInfo_as[FMKHRT_HRTIM_SLAVE_NB];         /**< storage for slaves timer inforation */
    t_bool isConfigured_b;                                             /*< Flag to know if the instance is configred */
    t_bool isCalibrate_b;                                              /*< Flag to know if the instance is configred */
    t_bool errDetected_b;                                              /**< Flag to know there is an error active */
    t_uint32 lastCbError_u32;                                          /**< Last time an error occured */
} t_sFMKHRT_HrTimInfo;
/* CAUTION : Automatic generated code section : Start */

/* CAUTION : Automatic generated code section : End */
//-----------------------------TYPEDEF TYPES---------------------------//
/**
* @brief Union of all Hw Mode Cfg
*/
typedef union 
{
    t_sFMKHRT_PwmCfg pwmCfg_s;
} t_uFMHRT_HwModeCfg;

// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************
/**< Module State */
static t_eCyclicModState g_FmkHrtModState_e = STATE_CYCLIC_CFG;

///@brief Variable for High Timer Handler 
static t_sFMKHRT_HrTimInfo g_HrTimInfo_as[FMKHRT_HIGH_RES_TIMER_NB];
/* CAUTION : Automatic generated code section for Variables: Start */

/* CAUTION : Automatic generated code section for Variables: Stop */
/**
* @brief Pulses left manamgent
*/
static t_bool g_isFirqtUG_ab[FMKHRT_HIGH_RES_TIMER_NB][FMKHRT_HRTIM_SLAVE_NB];
static t_uint32 g_SlvChnlTimPulsesRemain_ua32[FMKHRT_HIGH_RES_TIMER_NB][FMKHRT_HRTIM_SLAVE_NB];
static t_eFMKHRT_HrTimChannel g_AllowTimChnlPulse_ae[FMKHRT_HIGH_RES_TIMER_NB][FMKHRT_HRTIM_SLAVE_NB];

t_uint32 g_hrt_start_time_u32 = (t_uint32)0;
t_uint32 g_hrt_end_time_u32 = (t_uint32)0;
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
static t_eReturnCode s_FMKHRT_Operational(void);

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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_SetBspHrTimInit(t_eFMKHRT_HighResIstc f_HrTimIstc_e);

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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_ConfigureSlaveTimer(  t_sFMKHRT_HrTimInfo * f_HrTimInfo_ps,
                                                    t_eFMKHRT_HighResSlvTim f_slvTim_e,
                                                    t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                    t_uint32 f_rqstOutputFrequency_u32,
                                                    t_eFMKHRT_TimHwMode f_HwOpeMode_e);
/**
*
*	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
*
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*/
static t_eReturnCode s_FMKHRT_ConfigureSlaveChannel(t_sFMKHRT_HrTimInfo * f_HrTimInfo_ps,
                                                    t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                    t_eFMKHRT_HrTimChannel f_chnl_e,
                                                    t_eFMKHRT_TimHwMode f_HwOpeMode_e,
                                                    t_uFMHRT_HwModeCfg * f_HwModeCfg_pu);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_SetHwOutputState( t_sFMKHRT_HrTimInfo * f_HrTimInfo_ps,
                                                t_eFMKHRT_HighResSlvTim f_slvTimer_e,
                                                t_eFMKHRT_HrTimChannel f_chnl_e,
                                                t_eFMKHRT_TimRunMode f_runMode_e,
                                                t_eFMKHRT_HwOpeTimer f_HwOpeTimer_e,
                                                t_eFMKHRT_ChnlState f_state_e);

/**
*
*	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
*
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*/
static t_eReturnCode s_FMKHRT_UpdateFrequency(  t_eFMKHRT_HighResIstc f_hrlIscte_e,
                                                t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps,
                                                t_float32 f_freqency_f32);
/**
*
*	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
*
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*/
static t_eReturnCode s_FMKHRT_UpdateDutyCycle(  t_eFMKHRT_HighResIstc f_hrlIscte_e,
                                                t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps,
                                                t_eFMKHRT_HrTimChannel f_chnl_e,
                                                t_uint16 f_dutycyle_u16);
/**
*
*	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
*
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*/
static t_eReturnCode s_FMKHRT_UpdatePulses( t_eFMKHRT_HighResIstc f_hrlIscte_e,
                                            t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps,
                                            t_eFMKHRT_HrTimChannel f_chnl_e,
                                            t_sFMKHRT_PwmOpeVal f_pwmSet_s,
                                            t_uint8 f_maskUpdate_u8);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static void s_FMKHRT_BspCallbackMngmnt( HRTIM_HandleTypeDef * f_bspItsc_ps, 
                                        t_uint32 f_bspTimIdx_u32,
                                        t_eFMKHRT_BspCallbackId f_bspCbId_e);
/**
*
*	@brief     Perform diagnostic when an error is detected.\n
*
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*  @retval RC_OK                             @ref RC_OK
*  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
*  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_PerformDiagnostic(t_eFMKHRT_HighResIstc f_highResTimer_e);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_GetBspTimerIndex( t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                t_uint32 * f_bspTimerIdx_pu32);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_GetBspChannel(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                            t_eFMKHRT_HrTimChannel f_chnl_e,
                                            t_uint32 * f_bspOutputChnl_pu32);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_GetPrescalerRatio(t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                t_uint32 * f_PscRatio_pu32);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_GetBspPolarity(   t_eFMKHRT_LinePolarity f_Polarity_e,
                                                t_uint32 * f_bspPolarity_pu32);
/**
*
*	@brief     Get the HRTIM & Slave Timer & Chhannel from a High Resolution Line.\n
*
*	@param[in]  f_HrTimClkPort_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_InterruptLine_e      : enum value for timer, value from @ref t_eFMKTIM_Timer
*	@param[in]  f_EcdrCdg_ps           : Pointor to Encoder Configuration
*
*  @retval RC_OK                             @ref RC_OK
*  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
*  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_ComputeTimerFreqRange(t_eFMKCPU_ClockPort f_HrTimClkPort_e,
                                                    t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                    t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_GetBspPeriod( t_uint16 f_TimFreqMHz_16,
                                            t_uint32 f_RqstOutFreq_u32,
                                            t_uint32 * f_bspPeriod_pu32);
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
*  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
*/
static t_eReturnCode s_FMKHRT_GetEnumTimeIdxFromBsp(    t_uint32 f_bspTimIdx_u32,
                                                        t_eFMKHRT_HighResSlvTim * f_timSlv_pe);

//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * FMKHRT_Init
 *********************************/
t_eReturnCode FMKHRT_Init(void)
{
    t_uint8 idxHighResTim_u8;
    t_uint8 idxHighSlvTim_u8;
    t_uint8 idxHighChnl_u8;
    t_sFMKHRT_TimSlaveInfo * slvInfo_ps;

    for(idxHighResTim_u8 = (t_uint8)0; idxHighResTim_u8 < FMKHRT_HIGH_RES_TIMER_NB ; idxHighResTim_u8++)
    {
        g_HrTimInfo_as[idxHighResTim_u8].isConfigured_b = (t_bool)False;
        g_HrTimInfo_as[idxHighResTim_u8].c_clkPort_e = 
            c_FmkHrt_HrTimCfg_as[idxHighResTim_u8].c_clkPort_e;
        g_HrTimInfo_as[idxHighResTim_u8].bspItsc_s.Instance = 
        (HRTIM_TypeDef *)c_FmkHrt_HrTimCfg_as[idxHighResTim_u8].bspItsc_ps;
        g_HrTimInfo_as[idxHighResTim_u8].mstInfo_s.c_IRQNType_e = 
            c_FmkHrt_HrTimCfg_as[idxHighResTim_u8].c_MasterIRQNType_e;
         g_HrTimInfo_as[idxHighResTim_u8].errDetected_b = (t_bool)FALSE;
         g_HrTimInfo_as[idxHighResTim_u8].lastCbError_u32 = (t_uint32)0;
        for(idxHighSlvTim_u8 = (t_uint8)0; idxHighSlvTim_u8 < FMKHRT_HRTIM_SLAVE_NB ; idxHighSlvTim_u8++)
        {
            g_isFirqtUG_ab[idxHighResTim_u8][idxHighSlvTim_u8] = (t_bool)TRUE;
            slvInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&g_HrTimInfo_as[idxHighResTim_u8].slvInfo_as[idxHighSlvTim_u8]);
            slvInfo_ps->selfId_e = (t_eFMKHRT_HighResSlvTim)idxHighSlvTim_u8;
            slvInfo_ps->isConfigured_b = False;
            slvInfo_ps->isNVICEnable_b = False;
            slvInfo_ps->timFreqMHz_u16 = (t_uint16)0;
            slvInfo_ps->minFreqAccept_u32 = (t_uint32)0;
            slvInfo_ps->maxFreqAccept_u32 = (t_uint32)0;
            slvInfo_ps->maskChnlState_u8 = (t_uint8)0;
            slvInfo_ps->isTimerRunnin_b = (t_bool)0;
            slvInfo_ps->runMode_e = FMKHRT_RUN_MODE_POLL;
            slvInfo_ps->c_IRQNType_e = c_FmkHrt_HrTimCfg_as[idxHighResTim_u8].c_SlaveTimIRQNType_ae[idxHighSlvTim_u8];
            
            slvInfo_ps->HwOpeMode_e = FMKHRT_HW_OPE_TIM_BASIC;

            g_AllowTimChnlPulse_ae[idxHighResTim_u8][idxHighSlvTim_u8] = FMKHRT_HRTIM_CHANNEL_NB;
            g_SlvChnlTimPulsesRemain_ua32[idxHighResTim_u8][idxHighSlvTim_u8] = (t_uint32)0;

            for(idxHighChnl_u8 = (t_uint8)0; idxHighChnl_u8 < FMKHRT_HRTIM_CHANNEL_NB ; idxHighChnl_u8++)
            {
                slvInfo_ps->chnlInfo_as[idxHighChnl_u8].isConfigured_b = False;
                slvInfo_ps->chnlInfo_as[idxHighChnl_u8].selfId_e = (t_eFMKHRT_HrTimChannel)idxHighChnl_u8;
                slvInfo_ps->chnlInfo_as[idxHighChnl_u8].state_e = FMKHRT_CHNLST_DISACTIVATED;
                slvInfo_ps->chnlInfo_as[idxHighChnl_u8].isSyncOpeON_b = (t_bool)FALSE;
                
            }
        }
    }
    return RC_OK;
}

/*********************************
 * FMKHRT_Cyclic
 *********************************/
t_eReturnCode FMKHRT_Cyclic(void)
{
    t_eReturnCode Ret_e = RC_OK;

    switch (g_FmkHrtModState_e)
    {
        case STATE_CYCLIC_CFG:
        {
            g_FmkHrtModState_e = STATE_CYCLIC_PREOPE;
            break;
        }
        case STATE_CYCLIC_PREOPE:
        {
            g_FmkHrtModState_e = STATE_CYCLIC_OPE;
            break; 
        }
        case STATE_CYCLIC_OPE:
        {
            Ret_e = s_FMKHRT_Operational();
            if(Ret_e < RC_OK)
            {
                g_FmkHrtModState_e = STATE_CYCLIC_ERROR;
            }
            break;
        }
        case STATE_CYCLIC_ERROR:
        {
            break;
        }
        
        case STATE_CYCLIC_BUSY:
        default:
            Ret_e = RC_OK;
            break;
    }
    return Ret_e;
}

/*********************************
 * FMKHRT_GetState
 *********************************/
t_eReturnCode FMKHRT_GetState(t_eCyclicModState *f_State_pe)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_State_pe == (t_eCyclicModState *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        *f_State_pe = g_FmkHrtModState_e;
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_SetState
 *********************************/
t_eReturnCode FMKHRT_SetState(t_eCyclicModState f_State_e)
{

    g_FmkHrtModState_e = f_State_e;

    return RC_OK;
}

/*********************************
 * FMKHRT_ConfigurePwmLine
 *********************************/
t_eReturnCode FMKHRT_ConfigurePwmLine(  t_eFMKHRT_HighResLine f_HRLine_e, 
                                        t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                        t_sFMKHRT_PwmCfg f_PwmCfg_s,
                                        t_cbFMKHRT_HrLineEvnt * f_pulseEvntCb_pcb)
{
    t_eReturnCode Ret_e = RC_OK;
    t_eFMKHRT_HighResIstc hrTimIstc_e;
    t_eFMKHRT_HighResSlvTim hrSlvTim_e;
    t_eFMKHRT_HrTimChannel hrChnl_e;
    t_sFMKHRT_TimSlaveInfo * slvInfo_ps;
    t_uFMHRT_HwModeCfg hwModeCfg_u;

    if(f_HRLine_e >= FMKHRT_HR_LINE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    //---- Get Information about Timer -----//
    if(Ret_e == RC_OK) 
    {   
        Ret_e = FMKHRT_GetTimerInfoFromLine(  f_HRLine_e,
                                                &hrTimIstc_e,
                                                &hrSlvTim_e,
                                                &hrChnl_e);
    }
    //----- Configure the High Res Timer Instance if not done yet ----//
    if(Ret_e == RC_OK)
    {
        if(g_HrTimInfo_as[hrTimIstc_e].isConfigured_b == (t_bool)False)
        {
            Ret_e = s_FMKHRT_SetBspHrTimInit(hrTimIstc_e);
        }
    }       
    //----- Configure Timer In Pwm Mode of not done yet----//
    if(Ret_e == RC_OK)
    {
        slvInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e]);
        //----- Configure Slave Timer if not done Yet ----//
        if(slvInfo_ps->isConfigured_b == (t_bool)False)
        {
            Ret_e = s_FMKHRT_ConfigureSlaveTimer(   (&g_HrTimInfo_as[hrTimIstc_e]),
                                                    hrSlvTim_e,
                                                    f_CpuFreqMulDiv_e,
                                                    f_PwmCfg_s.frequency_f32,
                                                    FMKHRT_HW_MODE_PWM);
            if(Ret_e == RC_OK)
            {
                slvInfo_ps->isConfigured_b = (t_bool)True;
            }
        }
        //----- Configure Channel In Pwm Mode ----//
        if(Ret_e == RC_OK)
        {  
            hwModeCfg_u.pwmCfg_s.deadTime_u32  = f_PwmCfg_s.deadTime_u32;
            hwModeCfg_u.pwmCfg_s.polarity_e  = f_PwmCfg_s.polarity_e;
            hwModeCfg_u.pwmCfg_s.frequency_f32 = f_PwmCfg_s.frequency_f32; // not used

            Ret_e = s_FMKHRT_ConfigureSlaveChannel( (&g_HrTimInfo_as[hrTimIstc_e]),
                                                    hrSlvTim_e,
                                                    hrChnl_e,
                                                    FMKHRT_HW_MODE_PWM,
                                                    (&hwModeCfg_u));
            if(Ret_e == RC_OK)    
            {
                //---- once the software sync is enable by a channel it 
                //      cannot be disable by another channel configuration ----//
                if(f_PwmCfg_s.enableSyncPulseChnlOpe_b == (t_bool)TRUE)
                {
                    slvInfo_ps->SoftSyncMode_b = f_PwmCfg_s.enableSyncPulseChnlOpe_b;
                }
                slvInfo_ps->chnlInfo_as[hrChnl_e].isConfigured_b = (t_bool)True;
                slvInfo_ps->chnlInfo_as[hrChnl_e].evntCallback_pcb = 
                                            (t_cbFMKHRT_HrLineEvnt *)(f_pulseEvntCb_pcb);
                slvInfo_ps->HwOpeMode_e = FMKHRT_HW_OPE_TIM_WFC;
                slvInfo_ps->runMode_e = FMKHRT_RUN_MODE_POLL;
            }
        }
    }
    if(Ret_e < RC_OK)
    {
        ASSERT((t_uint16)Ret_e);
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_SetPwmLineWaveform
 *********************************/
t_eReturnCode FMKHRT_SetPwmLineWaveform(t_eFMKHRT_HighResLine f_HRLine_e, 
                                        t_sFMKHRT_PwmOpeVal f_PwmOpe_s,
                                        t_uint8 f_maskUpdate_u8)
{
    t_eReturnCode Ret_e = RC_OK;
    t_eFMKHRT_HighResIstc hrTimIstc_e;
    t_eFMKHRT_HighResSlvTim hrSlvTim_e;
    t_eFMKHRT_HrTimChannel hrChnl_e;
    t_sFMKHRT_TimSlaveInfo * slvTimInfo_ps;
    t_eFMKHRT_ChnlState setChnlState_e = FMKHRT_CHNLST_DISACTIVATED;
    

    if(f_HRLine_e >= FMKHRT_HR_LINE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    if(g_FmkHrtModState_e != STATE_CYCLIC_OPE)
    {
        Ret_e = RC_WARNING_BUSY;
    }
    //---- Get Information about Timer -----//
    if(Ret_e == RC_OK) 
    {   
        Ret_e = FMKHRT_GetTimerInfoFromLine(  f_HRLine_e,
                                                &hrTimIstc_e,
                                                &hrSlvTim_e,
                                                &hrChnl_e);
    }
    //----- Check Configuration -----//
    if(Ret_e == RC_OK)
    {
        if((g_HrTimInfo_as[hrTimIstc_e].isConfigured_b == (t_bool)False)
        || (g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e].isConfigured_b == (t_bool)False)
        || (g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e].chnlInfo_as[hrChnl_e].isConfigured_b == (t_bool)False))
        {
            ASSERT((t_uint16)Ret_e);
            Ret_e = RC_ERROR_WRONG_CONFIG;
        }
        else if(g_HrTimInfo_as[hrTimIstc_e].bspItsc_s.Lock == HAL_LOCKED)
        {
            Ret_e = RC_WARNING_BUSY;
        }
    }
    if(Ret_e == RC_OK)
    {
        slvTimInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e]);

        //---- Update Stuff Depending On Mask Update ----//
        if(GETBIT(f_maskUpdate_u8, FMKHRT_BIT_PWM_FREQUENCY) == BIT_IS_SET_8B)
        {
            Ret_e = s_FMKHRT_UpdateFrequency(   hrTimIstc_e,
                                                slvTimInfo_ps,
                                                f_PwmOpe_s.frequency_f32);
            if(Ret_e == RC_OK)
            {
                setChnlState_e = slvTimInfo_ps->chnlInfo_as[hrChnl_e].state_e;
            }
        }
        if((GETBIT(f_maskUpdate_u8, FMKHRT_BIT_PWM_DUTYCYCLE) == BIT_IS_SET_8B)
        && f_PwmOpe_s.dutyCycle_u16 != (t_uint16)0)
        {
            setChnlState_e = FMKHRT_CHNLST_ACTIVATED;
            Ret_e = s_FMKHRT_UpdateDutyCycle(   hrTimIstc_e,
                                                slvTimInfo_ps,
                                                hrChnl_e,
                                                f_PwmOpe_s.dutyCycle_u16);
                
        }
        if(GETBIT(f_maskUpdate_u8, FMKHRT_BIT_PWM_NB_PULSES) == BIT_IS_SET_8B)
        {
            Ret_e = s_FMKHRT_UpdatePulses(  hrTimIstc_e,
                                            slvTimInfo_ps,
                                            hrChnl_e,
                                            f_PwmOpe_s,
                                            f_maskUpdate_u8);   
        }
        else
        {
            if((Ret_e == RC_OK)
            && (setChnlState_e != slvTimInfo_ps->chnlInfo_as[hrChnl_e].state_e))
            {
                slvTimInfo_ps->chnlInfo_as[hrChnl_e].isSyncOpeON_b = (t_bool)FALSE;
                Ret_e = s_FMKHRT_SetHwOutputState(  &g_HrTimInfo_as[hrTimIstc_e],
                                                    slvTimInfo_ps->selfId_e,
                                                    hrChnl_e,
                                                    slvTimInfo_ps->runMode_e,
                                                    slvTimInfo_ps->HwOpeMode_e,
                                                    FMKHRT_CHNLST_ACTIVATED);
            }
        }
    }
    if(Ret_e < RC_OK)
    {
        ASSERT((t_uint16)Ret_e);
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_SetPwmLineWaveform
 *********************************/
t_eReturnCode FMKHRT_GetPwmLineWaveform(t_eFMKHRT_HighResLine f_HRLine_e, 
                                        t_sFMKHRT_PwmOpeVal * f_PwmVal_ps,
                                        t_uint8 f_maskUpdate_u8)
{
    t_eReturnCode Ret_e = RC_OK;
    t_eFMKHRT_HighResIstc hrTimIstc_e;
    t_eFMKHRT_HighResSlvTim hrSlvTim_e;
    t_eFMKHRT_HrTimChannel hrChnl_e;
    t_uint32 bspPeriod_u32;
    t_uint32 bspTimerIdx_u32;
    t_uint32 bspCompareUnit_u32 = HRTIM_COMPAREUNIT_1;
    t_uint32 bspCompareUnitVal_u32 = (t_uint32)0;
    t_sFMKHRT_TimSlaveInfo * slvTimInfo_ps;
    

    if((f_HRLine_e >= FMKHRT_HR_LINE_NB)
    || (f_PwmVal_ps == (t_sFMKHRT_PwmOpeVal *)NULL))
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    if(g_FmkHrtModState_e != STATE_CYCLIC_OPE)
    {
        Ret_e = RC_WARNING_BUSY;
    }
    //---- Get Information about Timer -----//
    if(Ret_e == RC_OK) 
    {   
        Ret_e = FMKHRT_GetTimerInfoFromLine(  f_HRLine_e,
                                                &hrTimIstc_e,
                                                &hrSlvTim_e,
                                                &hrChnl_e);
    }
    //----- Check Configuration -----//
    if(Ret_e == RC_OK)
    {
        if((g_HrTimInfo_as[hrTimIstc_e].isConfigured_b == (t_bool)False)
        || (g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e].isConfigured_b == (t_bool)False)
        || (g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e].chnlInfo_as[hrChnl_e].isConfigured_b == (t_bool)False))
        {
            Ret_e = RC_ERROR_WRONG_CONFIG;
            ASSERT((t_uint16)Ret_e);
        }
    }
    //----- Get Timer Index -----//
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKHRT_GetBspTimerIndex(hrSlvTim_e, (&bspTimerIdx_u32));
    }
    if(Ret_e == RC_OK)
    {
        slvTimInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&g_HrTimInfo_as[hrTimIstc_e].slvInfo_as[hrSlvTim_e]);

        //----- compute stuff for later ----//
        bspPeriod_u32 = __HAL_HRTIM_GETPERIOD(  (&g_HrTimInfo_as[hrTimIstc_e].bspItsc_s),
                                                        bspTimerIdx_u32);
        //---- Get the Compare Unit Channel ----//
        ((hrChnl_e == FMKHRT_HRTIM_CHANNEL_1) ? 
                (bspCompareUnit_u32 = HRTIM_COMPAREUNIT_1) : 
                (bspCompareUnit_u32 = HRTIM_COMPAREUNIT_2));
        
        bspCompareUnitVal_u32 = __HAL_HRTIM_GETCOMPARE( (&g_HrTimInfo_as[hrTimIstc_e].bspItsc_s),
                                                            bspTimerIdx_u32,
                                                            bspCompareUnit_u32);
        //---- Update Stuff Depending On Mask Update ----//
        if(GETBIT(f_maskUpdate_u8, FMKHRT_BIT_PWM_FREQUENCY) == BIT_IS_SET_8B)
        {
            f_PwmVal_ps->frequency_f32 =  ((t_float32)((t_float32)slvTimInfo_ps->timFreqMHz_u16) / ((t_float32)bspPeriod_u32));
        }
        if(GETBIT(f_maskUpdate_u8, FMKHRT_BIT_PWM_DUTYCYCLE) == BIT_IS_SET_8B)
        {     
            f_PwmVal_ps->dutyCycle_u16 = (t_uint16)((((t_float32)bspCompareUnitVal_u32 / (t_float32)bspPeriod_u32) 
                                                            * (t_float32)FMKHRT_PWM_MAX_DUTY_CYLCE));

        }
        if(GETBIT(f_maskUpdate_u8, FMKHRT_BIT_PWM_NB_PULSES) == BIT_IS_SET_8B)
        {
            Ret_e = RC_WARNING_NO_OPERATION;   
        }
    }
    if(Ret_e < RC_OK)
    {
        ASSERT((t_uint16)Ret_e);
    }

    return Ret_e;
}

/*********************************
 * FMKHRT_PRIVATE_GetHandleTypeDef
 *********************************/
HRTIM_HandleTypeDef * FMKHRT_PRIVATE_GetHandleTypeDef(t_eFMKHRT_HighResLine f_HRLine_e)
{
    if(g_HrTimInfo_as[f_HRLine_e].isConfigured_b == (t_bool)False)
    {
        ASSERT((t_uint16)0);
    }

    return (HRTIM_HandleTypeDef *)(&g_HrTimInfo_as[f_HRLine_e].bspItsc_s);
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
 * s_FMKHRT_Operational
 *********************************/
static t_eReturnCode  s_FMKHRT_Operational(void)
{
    t_eReturnCode Ret_e;
    t_uint8 idxHrtim_u8;
    t_sFMKHRT_HrTimInfo * hrtimInfo_ps;

    Ret_e = RC_OK;
    for(idxHrtim_u8 = (t_uint8)0 ; idxHrtim_u8 < FMKHRT_HIGH_RES_TIMER_NB ; idxHrtim_u8++)
    {
        hrtimInfo_ps = (t_sFMKHRT_HrTimInfo *)(&g_HrTimInfo_as[idxHrtim_u8]);

        if(hrtimInfo_ps->isConfigured_b == (t_bool)TRUE)
        {
            if(hrtimInfo_ps->errDetected_b == (t_bool)TRUE)
            {
                Ret_e = s_FMKHRT_PerformDiagnostic(idxHrtim_u8);
            }
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
            if(hrtimInfo_ps->isCalibrate_b == (t_bool)FALSE)
            {
                (void)HAL_HRTIM_DLLCalibrationStart(&hrtimInfo_ps->bspItsc_s, FMKHRT_BASIC_CALIBRATION);
                (void)HAL_HRTIM_PollForDLLCalibration(&hrtimInfo_ps->bspItsc_s, 500);
            }
#endif // FMKCPU_STM32_ECU_FAMILY_G4
        }
    }
    return Ret_e;
}

/*********************************
 * FMKHRT_GetTimerInfoFromLine
 *********************************/
static t_eReturnCode s_FMKHRT_SetBspHrTimInit( t_eFMKHRT_HighResIstc f_HrTimIstc_e)
{
    t_eReturnCode Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    HRTIM_HandleTypeDef * bspHrTimIsct_ps;

    if(f_HrTimIstc_e >= FMKHRT_HIGH_RES_TIMER_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        //---- Enable Clock Register ----//
        Ret_e = FMKCPU_Set_HwClock( g_HrTimInfo_as[f_HrTimIstc_e].c_clkPort_e,
                                    FMKCPU_CLOCKPORT_OPE_ENABLE);
    }
    if(Ret_e == RC_OK)
    {
        bspHrTimIsct_ps = (HRTIM_HandleTypeDef *)(&g_HrTimInfo_as[f_HrTimIstc_e].bspItsc_s);

        //----- Set to Default Init For now ----//
        bspHrTimIsct_ps->Init.HRTIMInterruptResquests = HRTIM_IT_NONE;
        bspHrTimIsct_ps->Init.SyncOptions = HRTIM_SYNCOPTION_NONE;

        //---- Call Bsp Init of the Instance timer ----//
        bspRet_e = HAL_HRTIM_Init(bspHrTimIsct_ps);
        
        //---- Set Interruption enable for Calibration ----//
        if(bspRet_e == HAL_OK)
        {
            Ret_e = FMKCPU_Set_NVICState(g_HrTimInfo_as[f_HrTimIstc_e].mstInfo_s.c_IRQNType_e,
                                        FMKCPU_NVIC_OPE_ENABLE);
        }
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
        //---- Set the calibration for Instance Timer ----//
        if((bspRet_e == HAL_OK) && (Ret_e == RC_OK))
        {
            //---- We do it in interrupt mode, and we finish configuration in Callback ----//
            bspRet_e = HAL_HRTIM_DLLCalibrationStart(bspHrTimIsct_ps, FMKHRT_BASIC_CALIBRATION);
            bspRet_e = HAL_HRTIM_PollForDLLCalibration(bspHrTimIsct_ps, 500);
        }
#endif // FMKCPU_STM32_ECU_FAMILY_G4
        if(bspRet_e != HAL_OK)
        {
            Ret_e = RC_ERROR_WRONG_RESULT;
            ASSERT((t_uint16)Ret_e);
        }
        //---- HR Timer Configuration Done ----//
        if(Ret_e == RC_OK)
        {
            g_HrTimInfo_as[f_HrTimIstc_e].isConfigured_b = (t_bool)True;
        }
    }
    if(Ret_e < RC_OK)
    {
        ASSERT((t_uint16)Ret_e);
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_ConfigureSlaveTimer
 *********************************/
static t_eReturnCode s_FMKHRT_ConfigureSlaveTimer(  t_sFMKHRT_HrTimInfo * f_HrTimInfo_ps,
                                                    t_eFMKHRT_HighResSlvTim f_slvTim_e,
                                                    t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                    t_uint32 f_rqstOutputFrequency_u32,
                                                    t_eFMKHRT_TimHwMode f_HwOpeMode_e)
{
    t_eReturnCode Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    HRTIM_TimerCfgTypeDef bspTimCfgSpec_s;
    HRTIM_TimeBaseCfgTypeDef bspTimBaseCfg_s;
    t_sFMKHRT_TimSlaveInfo * slvInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&f_HrTimInfo_ps->slvInfo_as[f_slvTim_e]);
    t_uint32 bspPscRatio_u32 = (t_uint32)0;
    t_uint32 bspPeriod_u32 = (t_uint32)0;
    t_uint32 bspTimIdx_u32;
    
    //----- Arg Already Verify ----//
    if(f_HrTimInfo_ps ==(t_sFMKHRT_HrTimInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        //---- Time Base Configuration ----//

        //---- Get Prescaler Ration From CPU Run Frequency and User Need ----//
        Ret_e = s_FMKHRT_GetPrescalerRatio(f_CpuFreqMulDiv_e, (&bspPscRatio_u32));

        //---- Compute Timer Frequency for later used ----//
        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKHRT_ComputeTimerFreqRange( f_HrTimInfo_ps->c_clkPort_e,
                                                    f_CpuFreqMulDiv_e, 
                                                    slvInfo_ps);
        }

        //---- Get ARR register ----//
        if(Ret_e == RC_OK)
        {
            if(f_rqstOutputFrequency_u32 > slvInfo_ps->maxFreqAccept_u32)
            {
                f_rqstOutputFrequency_u32 = slvInfo_ps->maxFreqAccept_u32;
            }
            else if(f_rqstOutputFrequency_u32 < slvInfo_ps->minFreqAccept_u32)
            {
                f_rqstOutputFrequency_u32 = slvInfo_ps->minFreqAccept_u32;
            }

            Ret_e = s_FMKHRT_GetBspPeriod(  slvInfo_ps->timFreqMHz_u16, 
                                            f_rqstOutputFrequency_u32,
                                            (&bspPeriod_u32));
        }
        //---- Get Bsp Timer Index ----//
        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKHRT_GetBspTimerIndex(f_slvTim_e, (&bspTimIdx_u32));
        }

        //---- Copy Data ----//>
        bspTimBaseCfg_s.Mode = HRTIM_MODE_CONTINUOUS;
        bspTimBaseCfg_s.Period = bspPeriod_u32;
        bspTimBaseCfg_s.PrescalerRatio = bspPscRatio_u32;
        bspTimBaseCfg_s.RepetitionCounter = (t_uint32)0;

        bspRet_e = HAL_HRTIM_TimeBaseConfig((&f_HrTimInfo_ps->bspItsc_s),
                                            bspTimIdx_u32,
                                            &bspTimBaseCfg_s);
    }
    //---- Specific Slave Timer Configuration ----//
    if((Ret_e == RC_OK) && (bspRet_e == HAL_OK))
    {
        switch (f_HwOpeMode_e)
        {
            case FMKHRT_HW_MODE_PWM:
            case FMKHRT_HW_MODE_ADC_PWM:
            case FMKHRT_HW_MODE_HALF_BRIDGE:
            case FMKHRT_HW_MODE_FULL_BRIDGE:
            {
                //----- Configure Slave Timer for PWM purpose ----//
                bspTimCfgSpec_s.DMARequests = HRTIM_TIM_DMA_NONE;
                bspTimCfgSpec_s.DMASrcAddress = 0x00;
                bspTimCfgSpec_s.DMADstAddress = 0x00;
                bspTimCfgSpec_s.DMASize = 0x00;
                bspTimCfgSpec_s.HalfModeEnable = HRTIM_HALFMODE_DISABLED;
                bspTimCfgSpec_s.StartOnSync = HRTIM_SYNCSTART_DISABLED;
                bspTimCfgSpec_s.ResetOnSync = HRTIM_SYNCRESET_DISABLED;
                bspTimCfgSpec_s.DACSynchro = HRTIM_DACSYNC_NONE;
                bspTimCfgSpec_s.PreloadEnable = HRTIM_PRELOAD_DISABLED;
                bspTimCfgSpec_s.UpdateGating = HRTIM_UPDATEGATING_INDEPENDENT;
                bspTimCfgSpec_s.BurstMode = HRTIM_TIMERBURSTMODE_MAINTAINCLOCK;
                bspTimCfgSpec_s.RepetitionUpdate = HRTIM_UPDATEONREPETITION_ENABLED;
                bspTimCfgSpec_s.ResetUpdate = HRTIM_TIMUPDATEONRESET_DISABLED;
                bspTimCfgSpec_s.InterruptRequests = HRTIM_TIM_IT_NONE;
                bspTimCfgSpec_s.PushPull = HRTIM_TIMPUSHPULLMODE_DISABLED;
                bspTimCfgSpec_s.FaultEnable = HRTIM_TIMFAULTENABLE_NONE;
                bspTimCfgSpec_s.FaultLock = HRTIM_TIMFAULTLOCK_READWRITE;
                bspTimCfgSpec_s.DeadTimeInsertion = HRTIM_TIMDEADTIMEINSERTION_DISABLED;
                bspTimCfgSpec_s.DelayedProtectionMode = HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DISABLED;
                bspTimCfgSpec_s.UpdateTrigger= HRTIM_TIMUPDATETRIGGER_NONE;
                bspTimCfgSpec_s.ResetTrigger = HRTIM_TIMRESETTRIGGER_NONE;
                break;
            }
            case FMKHRT_HW_MODE_NB:
            default:
            {
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
            }
        }
        if(Ret_e == RC_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformTimerConfig(   (&f_HrTimInfo_ps->bspItsc_s),
                                                        bspTimIdx_u32,
                                                        (&bspTimCfgSpec_s));
        }
        if(bspRet_e != HAL_OK)
        {
            Ret_e = RC_ERROR_WRONG_RESULT;
            ASSERT((t_uint16)Ret_e);
        }
        
    }
    
    return Ret_e;
}

/*********************************
 * s_FMKHRT_ConfigureSlaveChannel
 *********************************/
static t_eReturnCode s_FMKHRT_ConfigureSlaveChannel(t_sFMKHRT_HrTimInfo * f_HrTimInfo_ps,
                                                    t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                    t_eFMKHRT_HrTimChannel f_chnl_e,
                                                    t_eFMKHRT_TimHwMode f_HwOpeMode_e,
                                                    t_uFMHRT_HwModeCfg * f_HwModeCfg_pu)
{
    t_eReturnCode Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    HRTIM_OutputCfgTypeDef bspOutCfg_s;
    t_sFMKHRT_TimSlaveInfo * slvInfo_ps;
    t_uint32 bspPolarity_u32;
    t_uint32 bspChannel_u32;
    t_uint32 bspTimerIdx_u32;
    //----- Arg Already Verify ----//

    slvInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&f_HrTimInfo_ps->slvInfo_as[f_hrSlvTim_e]);

    if(slvInfo_ps->chnlInfo_as[f_chnl_e].isConfigured_b == (t_bool)True)
    {
        Ret_e = RC_ERROR_ALREADY_CONFIGURED;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKHRT_GetBspChannel(f_hrSlvTim_e, f_chnl_e, (&bspChannel_u32));
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKHRT_GetBspTimerIndex(f_hrSlvTim_e, &bspTimerIdx_u32);
    }
    if(Ret_e == RC_OK)
    {
        //---- For All Configuration ----//
        ((f_chnl_e == FMKHRT_HRTIM_CHANNEL_1) ? 
            (bspOutCfg_s.ResetSource = HRTIM_OUTPUTRESET_TIMCMP1) : 
            (bspOutCfg_s.ResetSource = HRTIM_OUTPUTRESET_TIMCMP2));

        //---- Specific Config ----// 
        switch (f_HwOpeMode_e)
        {
            case FMKHRT_HW_MODE_PWM:
            {
                Ret_e = s_FMKHRT_GetBspPolarity(f_HwModeCfg_pu->pwmCfg_s.polarity_e,
                                                (&bspPolarity_u32));
                if(Ret_e == RC_OK)
                {
                    bspOutCfg_s.Polarity = bspPolarity_u32;
                    bspOutCfg_s.SetSource = HRTIM_OUTPUTSET_TIMPER;
                    bspOutCfg_s.IdleMode = HRTIM_OUTPUTIDLEMODE_NONE;
                    bspOutCfg_s.IdleLevel = HRTIM_OUTPUTIDLELEVEL_INACTIVE;
                    bspOutCfg_s.FaultLevel = HRTIM_OUTPUTFAULTLEVEL_NONE;
                    bspOutCfg_s.ChopperModeEnable = HRTIM_OUTPUTCHOPPERMODE_DISABLED;
                    bspOutCfg_s.BurstModeEntryDelayed = HRTIM_OUTPUTBURSTMODEENTRY_REGULAR;
                }
                break;
            }
            case FMKHRT_HW_MODE_ADC_PWM:
            {
                bspOutCfg_s.Polarity = bspPolarity_u32;
                bspOutCfg_s.SetSource = HRTIM_OUTPUTSET_TIMPER;
                bspOutCfg_s.IdleMode = HRTIM_OUTPUTIDLEMODE_NONE;
                bspOutCfg_s.IdleLevel = HRTIM_OUTPUTIDLELEVEL_INACTIVE;
                bspOutCfg_s.FaultLevel = HRTIM_OUTPUTFAULTLEVEL_NONE;
                bspOutCfg_s.ChopperModeEnable = HRTIM_OUTPUTCHOPPERMODE_DISABLED;
                bspOutCfg_s.BurstModeEntryDelayed = HRTIM_OUTPUTBURSTMODEENTRY_REGULAR;
                break;
            }
            case FMKHRT_HW_MODE_HALF_BRIDGE:
            {
                bspOutCfg_s.Polarity = bspPolarity_u32;
                bspOutCfg_s.SetSource = HRTIM_OUTPUTSET_TIMPER;
                bspOutCfg_s.IdleMode = HRTIM_OUTPUTIDLEMODE_NONE;
                bspOutCfg_s.IdleLevel = HRTIM_OUTPUTIDLELEVEL_INACTIVE;
                bspOutCfg_s.FaultLevel = HRTIM_OUTPUTFAULTLEVEL_NONE;
                bspOutCfg_s.ChopperModeEnable = HRTIM_OUTPUTCHOPPERMODE_DISABLED;
                bspOutCfg_s.BurstModeEntryDelayed = HRTIM_OUTPUTBURSTMODEENTRY_REGULAR;
                break;
            }
            case FMKHRT_HW_MODE_FULL_BRIDGE:
            {
                bspOutCfg_s.Polarity = bspPolarity_u32;
                bspOutCfg_s.SetSource = HRTIM_OUTPUTSET_TIMPER;
                bspOutCfg_s.IdleMode = HRTIM_OUTPUTIDLEMODE_NONE;
                bspOutCfg_s.IdleLevel = HRTIM_OUTPUTIDLELEVEL_INACTIVE;
                bspOutCfg_s.FaultLevel = HRTIM_OUTPUTFAULTLEVEL_NONE;
                bspOutCfg_s.ChopperModeEnable = HRTIM_OUTPUTCHOPPERMODE_DISABLED;
                bspOutCfg_s.BurstModeEntryDelayed = HRTIM_OUTPUTBURSTMODEENTRY_REGULAR;
                break;
            }
            case FMKHRT_HW_MODE_NB:
            default:
            {
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
            }
        }
        if(Ret_e == RC_OK)
        {
            bspRet_e = HAL_HRTIM_WaveformOutputConfig(  (&f_HrTimInfo_ps->bspItsc_s),
                                                        bspTimerIdx_u32,
                                                        bspChannel_u32,
                                                        (&bspOutCfg_s));
            if(bspRet_e != HAL_OK)
            {
                Ret_e = RC_ERROR_WRONG_RESULT;
                ASSERT((t_uint16)Ret_e);
            }
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_SetHwOutputState
 *********************************/
static t_eReturnCode s_FMKHRT_SetHwOutputState( t_sFMKHRT_HrTimInfo * f_HrTimInfo_ps,
                                                t_eFMKHRT_HighResSlvTim f_slvTimer_e,
                                                t_eFMKHRT_HrTimChannel f_chnl_e,
                                                t_eFMKHRT_TimRunMode f_runMode_e,
                                                t_eFMKHRT_HwOpeTimer f_HwOpeTimer_e,
                                                t_eFMKHRT_ChnlState f_state_e)
{
    t_eReturnCode Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_sFMKHRT_TimSlaveInfo * slvTimInfo_ps;
    t_uint32 bspTimerIdx_u32;
    t_uint32 bspChannel_u32;

    if(f_HrTimInfo_ps == (t_sFMKHRT_HrTimInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if((f_chnl_e >= FMKHRT_HRTIM_CHANNEL_NB)
    || (f_HwOpeTimer_e >= FMKHRT_HW_OPE_TIM_NB))
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    //---- get bsp information ----//
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKHRT_GetBspTimerIndex(f_slvTimer_e, (&bspTimerIdx_u32));

        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKHRT_GetBspChannel(f_slvTimer_e, f_chnl_e, (&bspChannel_u32));
        }
    }

    if(Ret_e == RC_OK)
    {
        slvTimInfo_ps = (t_sFMKHRT_TimSlaveInfo *)(&f_HrTimInfo_ps->slvInfo_as[f_slvTimer_e]);

        
        //----- update channel state only if it's configured as so ----//
        if(f_state_e == FMKHRT_CHNLST_ACTIVATED)
        {
            if(f_runMode_e == slvTimInfo_ps->runMode_e)
            {
                slvTimInfo_ps->maskChnlState_u8 |= (t_uint8)(1 << (t_uint8)f_chnl_e);
            }
            if((f_runMode_e != FMKHRT_RUN_MODE_POLL)
            && (slvTimInfo_ps->isNVICEnable_b == (t_bool)False))
            {
                Ret_e = FMKCPU_Set_NVICState(slvTimInfo_ps->c_IRQNType_e, FMKCPU_NVIC_OPE_ENABLE);

                if(Ret_e == RC_OK)
                {
                    slvTimInfo_ps->isNVICEnable_b = (t_bool)True;
                }
            }
            switch(f_runMode_e)
            {
                case FMKHRT_RUN_MODE_POLL:
                    bspRet_e = c_FMKHRT_HwOpe_apf.
                                HwOpeStart_apf[f_HwOpeTimer_e].
                                    HwOpePoll_pcb(  (&f_HrTimInfo_ps->bspItsc_s),
                                                    bspTimerIdx_u32,
                                                    bspChannel_u32);
                    break;
                case FMKHRT_RUN_MODE_IT:
                    bspRet_e = c_FMKHRT_HwOpe_apf.
                                    HwOpeStart_apf[f_HwOpeTimer_e].
                                        HwOpeIT_pcb(  (&f_HrTimInfo_ps->bspItsc_s),
                                                        bspTimerIdx_u32,
                                                        bspChannel_u32);
                    break;
                case FMKHRT_RUN_MODE_DMA:
                    #warning("Didn't Implement DMA Operation on HRTIM")
                    bspRet_e = c_FMKHRT_HwOpe_apf.
                                    HwOpeStart_apf[f_HwOpeTimer_e].
                                        HwOpeDMA_pcb(  (&f_HrTimInfo_ps->bspItsc_s),
                                                        bspTimerIdx_u32,
                                                        bspChannel_u32,
                                                        (t_uint32)0,
                                                        (t_uint32)0,
                                                        (t_uint32)0);
                    break;
                default:
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
            }
        }
        else 
        {
            if(f_runMode_e == slvTimInfo_ps->runMode_e)
            {
                slvTimInfo_ps->maskChnlState_u8 &= ~(t_uint8)(1 << (t_uint8)f_chnl_e);
            }
            if((f_runMode_e != FMKHRT_RUN_MODE_POLL)
            && (slvTimInfo_ps->isNVICEnable_b == (t_bool)True))
            {
                Ret_e = FMKCPU_Set_NVICState(slvTimInfo_ps->c_IRQNType_e, FMKCPU_NVIC_OPE_DISABLE);

                if(Ret_e == RC_OK)
                {
                    slvTimInfo_ps->isNVICEnable_b = (t_bool)False;
                }
            }
            switch(f_runMode_e)
            {
                case FMKHRT_RUN_MODE_POLL:
                    bspRet_e = c_FMKHRT_HwOpe_apf.
                                HwOpeStop_apf[f_HwOpeTimer_e].
                                    HwOpePoll_pcb(  (&f_HrTimInfo_ps->bspItsc_s),
                                                    bspTimerIdx_u32,
                                                    bspChannel_u32);
                    break;
                case FMKHRT_RUN_MODE_IT:
                    bspRet_e = c_FMKHRT_HwOpe_apf.
                                    HwOpeStop_apf[f_HwOpeTimer_e].
                                        HwOpeIT_pcb(  (&f_HrTimInfo_ps->bspItsc_s),
                                                        bspTimerIdx_u32,
                                                        bspChannel_u32);
                    break;
                case FMKHRT_RUN_MODE_DMA:
                    bspRet_e = c_FMKHRT_HwOpe_apf.
                                    HwOpeStop_apf[f_HwOpeTimer_e].
                                        HwOpeDMA_pcb(  (&f_HrTimInfo_ps->bspItsc_s),
                                                        bspTimerIdx_u32,
                                                        bspChannel_u32,
                                                        (t_uint32)0,
                                                        (t_uint32)0,
                                                        (t_uint32)0);
                    break;
                default:
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
            }
        }
        if(bspRet_e != HAL_OK)
        {
            Ret_e = RC_ERROR_WRONG_RESULT;
            ASSERT((t_uint16)Ret_e);
        }
        //----- Update Only when it's the HwMode of the timer -----//
        if((f_HwOpeTimer_e == slvTimInfo_ps->HwOpeMode_e) && (Ret_e == RC_OK))
        {
            slvTimInfo_ps->chnlInfo_as[f_chnl_e].state_e = f_state_e;
            slvTimInfo_ps->isTimerRunnin_b =
                    (slvTimInfo_ps->maskChnlState_u8 == (t_uint16)0)? False : True;
                    
        }
    }
    

    return Ret_e;    
}

/*********************************
 * s_FMKHRT_UpdateFrequency
 *********************************/
static t_eReturnCode s_FMKHRT_UpdateFrequency(  t_eFMKHRT_HighResIstc f_hrlIscte_e,
                                                t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps,
                                                t_float32 f_freqency_f32)
{
    t_eReturnCode Ret_e;
    t_uint32 bspPeriod_u32;
    t_uint32 bspTimerIdx_u32 = (t_uint32)0;

    if(f_slvInfo_ps == (t_sFMKHRT_TimSlaveInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)0);
    }
    else if (f_hrlIscte_e >= FMKHRT_HIGH_RES_TIMER_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else 
    {
        Ret_e = s_FMKHRT_GetBspTimerIndex(f_slvInfo_ps->selfId_e, (&bspTimerIdx_u32));
        if(Ret_e == RC_OK)
        {
            if((t_uint32)f_freqency_f32 > f_slvInfo_ps->maxFreqAccept_u32)
            {
                ASSERT((t_uint16)f_freqency_f32);
                f_freqency_f32 = f_slvInfo_ps->maxFreqAccept_u32;
            }
            else if((t_uint32)f_freqency_f32 < f_slvInfo_ps->minFreqAccept_u32)
            {
                ASSERT((t_uint16)f_freqency_f32);
                f_freqency_f32 = f_slvInfo_ps->minFreqAccept_u32;
            }

            Ret_e = s_FMKHRT_GetBspPeriod(  f_slvInfo_ps->timFreqMHz_u16, 
                                            (t_uint32)f_freqency_f32,
                                            (&bspPeriod_u32)); 
            if(Ret_e == RC_OK)
            {       
                __HAL_HRTIM_SETPERIOD((&g_HrTimInfo_as[f_hrlIscte_e].bspItsc_s),
                                        bspTimerIdx_u32,
                                        (bspPeriod_u32));
            }
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_UpdateDutyCycle
 *********************************/
static t_eReturnCode s_FMKHRT_UpdateDutyCycle(  t_eFMKHRT_HighResIstc f_hrlIscte_e,
                                                t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps,
                                                t_eFMKHRT_HrTimChannel f_chnl_e,
                                                t_uint16 f_dutycyle_u16)
{
    t_eReturnCode Ret_e;
    t_uint32 bspCompareUnitVal_u32;
    t_uint32 bspCompareUnit_u32;
    t_uint32 bspPeriod_u32;
    t_uint32 bspTimerIdx_u32 = (t_uint32)0;

    if(f_slvInfo_ps == (t_sFMKHRT_TimSlaveInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)0);
    }
    else if ((f_hrlIscte_e >= FMKHRT_HIGH_RES_TIMER_NB)
    ||      ((f_dutycyle_u16 > FMKHRT_PWM_MAX_DUTY_CYLCE)))
    {
        ASSERT((t_uint16)f_dutycyle_u16);
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    else
    {
        Ret_e = s_FMKHRT_GetBspTimerIndex(f_slvInfo_ps->selfId_e, &bspTimerIdx_u32);
        if(Ret_e == RC_OK)
        {
            bspPeriod_u32 = __HAL_HRTIM_GETPERIOD(  (&g_HrTimInfo_as[f_hrlIscte_e].bspItsc_s),
                                                    bspTimerIdx_u32);
            bspCompareUnitVal_u32 = (t_uint32)(bspPeriod_u32  * (t_uint32)f_dutycyle_u16 
                                                    / FMKHRT_PWM_MAX_DUTY_CYLCE);
            
            ((f_chnl_e == FMKHRT_HRTIM_CHANNEL_1) ? 
                (bspCompareUnit_u32 = HRTIM_COMPAREUNIT_1) : 
                (bspCompareUnit_u32 = HRTIM_COMPAREUNIT_2));
            
            __HAL_HRTIM_SETCOMPARE( (&g_HrTimInfo_as[f_hrlIscte_e].bspItsc_s),
                                    bspTimerIdx_u32,
                                    HRTIM_COMPAREUNIT_1,
                                    (bspCompareUnitVal_u32 - 1));
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_UpdatePulses
 *********************************/
static t_eReturnCode s_FMKHRT_UpdatePulses( t_eFMKHRT_HighResIstc f_hrlIscte_e,
                                            t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps,
                                            t_eFMKHRT_HrTimChannel f_chnl_e,
                                            t_sFMKHRT_PwmOpeVal f_pwmSet_s,
                                            t_uint8 f_maskUpdate_u8)
{
    t_eReturnCode Ret_e;
    t_uint8 idxChnl_u8;
    t_uint8 startIdx_u8;
    t_uint8 endIdx_u8;
    t_uint16 nbPulses_u16;
    t_uint32 bspTImerIdx_u32 = (t_uint32)0;
    t_eFMKHRT_HrTimChannel AllowPulseChnl_e;

    if(f_slvInfo_ps == (t_sFMKHRT_TimSlaveInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)0);
    }
    else if((f_hrlIscte_e >= FMKHRT_HIGH_RES_TIMER_NB)
    ||      (f_chnl_e >= FMKHRT_HRTIM_CHANNEL_NB))
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)f_hrlIscte_e);
    }
    else if((g_AllowTimChnlPulse_ae[f_hrlIscte_e][f_slvInfo_ps->selfId_e] !=
                                                    FMKHRT_HRTIM_CHANNEL_NB)
    &&      (g_AllowTimChnlPulse_ae[f_hrlIscte_e][f_slvInfo_ps->selfId_e] !=
                                                    f_chnl_e)
    &&      (f_slvInfo_ps->SoftSyncMode_b == (t_bool)FALSE))
    {
        Ret_e = RC_ERROR_NOT_ALLOWED;
        ASSERT((t_uint16)0);
    }
    else
    {
        Ret_e = RC_OK;
        if(f_slvInfo_ps->SoftSyncMode_b == (t_bool)TRUE)
        {
            startIdx_u8 = (t_uint8)FMKHRT_HRTIM_CHANNEL_1;
            endIdx_u8 = (t_uint8)FMKHRT_HRTIM_CHANNEL_NB;
        }
        else 
        {
            g_AllowTimChnlPulse_ae[f_hrlIscte_e][f_slvInfo_ps->selfId_e] =
                                                                    f_chnl_e;
            startIdx_u8 = (t_uint8)f_chnl_e;
            endIdx_u8 = (startIdx_u8 + (t_uint8)1);
        }

        AllowPulseChnl_e = g_AllowTimChnlPulse_ae[f_hrlIscte_e][f_slvInfo_ps->selfId_e];
        //---- we want to stop the genration of the pulse
        //      if timer running and user wants to stop it nbPulses = 0 
        //      if timer running user wants to set another set pulse and not wait this 
        //      this current burst pulse is done ----//
        if(((f_slvInfo_ps->isTimerRunnin_b == (t_bool)TRUE)
        && (f_slvInfo_ps->SoftSyncMode_b == (t_bool)FALSE)
        && (AllowPulseChnl_e != FMKHRT_HRTIM_CHANNEL_NB)
        && (GETBIT(f_slvInfo_ps->maskChnlState_u8,
                AllowPulseChnl_e) == BIT_IS_SET_16B))
        || ((f_slvInfo_ps->isTimerRunnin_b == (t_bool)TRUE)
        && (f_pwmSet_s.nbPulses_u16 == (t_uint16)0)))
        {
            Ret_e = s_FMKHRT_SetHwOutputState(  (&g_HrTimInfo_as[f_hrlIscte_e]),
                                                f_slvInfo_ps->selfId_e,
                                                f_chnl_e,
                                                FMKHRT_RUN_MODE_IT,
                                                FMKHRT_HW_OPE_TIM_BASIC,
                                                FMKHRT_CHNLST_DISACTIVATED);
            for(idxChnl_u8 = startIdx_u8 ; 
            (idxChnl_u8 < endIdx_u8) 
            && (Ret_e == RC_OK) ; 
            idxChnl_u8++)
            {
                if(((f_slvInfo_ps->chnlInfo_as[idxChnl_u8].isConfigured_b == (t_bool)TRUE)
                && (f_slvInfo_ps->chnlInfo_as[idxChnl_u8].selfId_e == f_chnl_e))
                || ((f_slvInfo_ps->chnlInfo_as[idxChnl_u8].isConfigured_b == (t_bool)TRUE)
                && (f_slvInfo_ps->chnlInfo_as[idxChnl_u8].isSyncOpeON_b == (t_bool)TRUE)))
                {
                    Ret_e = s_FMKHRT_SetHwOutputState(  (&g_HrTimInfo_as[f_hrlIscte_e]),
                                                        f_slvInfo_ps->selfId_e,
                                                        idxChnl_u8,
                                                        f_slvInfo_ps->runMode_e,
                                                        f_slvInfo_ps->HwOpeMode_e,
                                                        FMKHRT_CHNLST_DISACTIVATED);
                }
            }
        }
        //--- if the timer is not running, no matter the SoftSyncMode and 
        //          pulse are > 0, we enter
        //     if the soft mode is ON but the timer is running for another channel 
        //     and pulses are > 0 we also enter ----// 
        if( ((f_slvInfo_ps->isTimerRunnin_b == (t_bool)FALSE)
                && (f_pwmSet_s.nbPulses_u16 > (t_uint16)0))
        || (((f_slvInfo_ps->isTimerRunnin_b == (t_bool)TRUE)
                && (f_slvInfo_ps->SoftSyncMode_b == (t_bool)FALSE)
                && (AllowPulseChnl_e != FMKHRT_HRTIM_CHANNEL_NB)
        //                                      [the pulses channel]
                && (f_slvInfo_ps->chnlInfo_as[AllowPulseChnl_e].state_e ==
                                                FMKHRT_CHNLST_DISACTIVATED))
                && (f_pwmSet_s.nbPulses_u16 > (t_uint16)0)))
        {
            if(f_pwmSet_s.nbPulses_u16 >= CST_MAX_UINT_8BIT)
            {
                nbPulses_u16 = (CST_MAX_UINT_8BIT - (t_uint16)1);
                g_SlvChnlTimPulsesRemain_ua32[f_hrlIscte_e][f_slvInfo_ps->selfId_e] = 
                                                                            (t_uint32)(f_pwmSet_s.nbPulses_u16 - (t_uint16)CST_MAX_UINT_8BIT);
            }
            else 
            {
                nbPulses_u16 = (f_pwmSet_s.nbPulses_u16 - (t_uint16)1);
                g_SlvChnlTimPulsesRemain_ua32[f_hrlIscte_e][f_slvInfo_ps->selfId_e] = (t_uint32)0;
            }
            
            Ret_e = s_FMKHRT_GetBspTimerIndex(f_slvInfo_ps->selfId_e, &bspTImerIdx_u32);
            if(Ret_e != RC_OK)
            {
                ASSERT((t_uint16)Ret_e);
            }
            else 
            {
                g_HrTimInfo_as[f_hrlIscte_e].bspItsc_s.Instance->
                        sTimerxRegs[bspTImerIdx_u32].REPxR = nbPulses_u16; // could be 0 doesn't matter

                // __HAL_HRTIM_TIMER_CLEAR_IT(&g_HrTimInfo_as[f_hrlIscte_e].bspItsc_s,
                //                             bspTImerIdx_u32,
                //                             HRTIM_TIM_IT_REP);
                // __HAL_HRTIM_TIMER_CLEAR_FLAG(&g_HrTimInfo_as[f_hrlIscte_e].bspItsc_s,
                //                             bspTImerIdx_u32,
                //                             HRTIM_TIM_FLAG_REP);
                //---- Reset Basic Timer Genration for RCR ----//
                Ret_e = s_FMKHRT_SetHwOutputState(  (&g_HrTimInfo_as[f_hrlIscte_e]),
                                                    f_slvInfo_ps->selfId_e,
                                                    FMKHRT_HRTIM_CHANNEL_1, // not used
                                                    FMKHRT_RUN_MODE_IT,
                                                    FMKHRT_HW_OPE_TIM_BASIC,
                                                    FMKHRT_CHNLST_ACTIVATED);
                //---- set all slave channel which are configured to on ----//
                for(idxChnl_u8 = (t_uint8)startIdx_u8 ; 
                (idxChnl_u8 < endIdx_u8) 
                && (Ret_e == RC_OK) ;
                idxChnl_u8++)
                {
                    if(f_slvInfo_ps->chnlInfo_as[idxChnl_u8].isConfigured_b == TRUE)
                    {
                        f_slvInfo_ps->chnlInfo_as[idxChnl_u8].isSyncOpeON_b = (t_bool)TRUE;
                        Ret_e = s_FMKHRT_SetHwOutputState(  (&g_HrTimInfo_as[f_hrlIscte_e]),
                                                            f_slvInfo_ps->selfId_e,
                                                            idxChnl_u8,
                                                            f_slvInfo_ps->runMode_e,
                                                            f_slvInfo_ps->HwOpeMode_e,
                                                            FMKHRT_CHNLST_ACTIVATED);
                    }
                }
                //FMKCPU_GetTick(&g_hrt_start_time_u32);
                //FMKSRL_LOG("Pulse start at %d\r\n", g_hrt_start_time_u32);
            }
        }
    }
    
    return Ret_e;
}

/*********************************
 * s_FMKHRT_BspCallbackMngmnt
 *********************************/
static void s_FMKHRT_BspCallbackMngmnt( HRTIM_HandleTypeDef * f_bspItsc_ps, 
                                        t_uint32 f_bspTimIdx_u32,
                                        t_eFMKHRT_BspCallbackId f_bspCbId_e)
{
    t_eReturnCode Ret_e = RC_OK;
    t_uint8 idxChnl_u8 = (t_uint8)0;
    t_uint8 idxHrIsct_u8 = (t_uint8)0;
    t_uint32 remainPulses_u32;
    t_bool isMasterTrigg_b = False;
    t_eFMKHRT_HighResIstc HrTimIstc_e = FMKHRT_HIGH_RES_TIMER_NB;
    t_eFMKHRT_HighResSlvTim slvTim_e;
    t_sFMKHRT_TimSlaveInfo * slvInfo_ps;

    //----- Find Timer Instance ----//
    for(idxHrIsct_u8 = (t_uint8)0 ; idxHrIsct_u8 < (t_uint8)FMKHRT_HIGH_RES_TIMER_NB ; idxHrIsct_u8++)
    {
        if((&g_HrTimInfo_as[idxHrIsct_u8].bspItsc_s) == (HRTIM_HandleTypeDef *)f_bspItsc_ps)
        {
            HrTimIstc_e = (t_eFMKHRT_HighResIstc)idxHrIsct_u8;
            break;
        }
    }

    if(HrTimIstc_e != FMKHRT_HIGH_RES_TIMER_NB)
    {
        //---- Found Slave Timer ----//
        Ret_e = s_FMKHRT_GetEnumTimeIdxFromBsp( f_bspTimIdx_u32,
                                                &slvTim_e);

        //---- It means Master Triggered the Interruption ----//
        if(Ret_e == RC_WARNING_NO_OPERATION)
        {
            isMasterTrigg_b = (t_bool)True;
        }
        else 
        {
            slvInfo_ps = (t_sFMKHRT_TimSlaveInfo * )(&g_HrTimInfo_as[HrTimIstc_e].slvInfo_as[slvTim_e]);
        }
        if(Ret_e == RC_OK)
        {
            
            switch (f_bspCbId_e)
            {
                case FMKHRT_BSP_CB_REPETITION_EVNT:
                {
                    if(isMasterTrigg_b == (t_bool)False)
                    {    
                        /*if(g_isFirqtUG_ab[idxHrIsct_u8][slvTim_e] == (t_bool)TRUE)
                        {
                            g_isFirqtUG_ab[idxHrIsct_u8][slvTim_e] = FALSE;
                            return;
                        }*/
                        //---- See if it rest pulses to set ----//
                        //FMKCPU_GetTick(&g_hrt_end_time_u32);
                        //FMKSRL_LOG("Pulse done at  %d\r\n", g_hrt_end_time_u32);
                        remainPulses_u32 = g_SlvChnlTimPulsesRemain_ua32[HrTimIstc_e][slvTim_e];
                        //FMKSRL_LOG("Pulse left %d", remainPulses_u32);

                        if(remainPulses_u32 > (t_uint32)0)
                        {
                            if(remainPulses_u32 > (2 * (CST_MAX_UINT_8BIT + 1)))
                            {
                                //FMKSRL_LOG("Set %d\r\n", (CST_MAX_UINT_8BIT - 1));
                                g_HrTimInfo_as[HrTimIstc_e].bspItsc_s.Instance->
                                    sTimerxRegs[f_bspTimIdx_u32].REPxR = (CST_MAX_UINT_8BIT - (t_uint32)1);
                                g_SlvChnlTimPulsesRemain_ua32[HrTimIstc_e][slvTim_e] -= (t_uint32)(CST_MAX_UINT_8BIT);
                            }
                            else if(remainPulses_u32 > (t_uint32)CST_MAX_UINT_8BIT)
                            {
                                //FMKSRL_LOG("Set last pulses %d", (remainPulses_u32 - CST_MAX_UINT_8BIT));
                                g_HrTimInfo_as[HrTimIstc_e].bspItsc_s.Instance->
                                    sTimerxRegs[f_bspTimIdx_u32].REPxR = (remainPulses_u32 - (CST_MAX_UINT_8BIT + (t_uint32)1));
                                g_SlvChnlTimPulsesRemain_ua32[HrTimIstc_e][slvTim_e] = (t_uint32)(remainPulses_u32 - (t_uint32)CST_MAX_UINT_8BIT);
                            }
                            else // remain pulse = 0, the last burst pulse will be now load,
                            //      do nothing
                            {
                                //FMKSRL_LOG("Wait last pulse to applied %d \r\n", g_hrt_end_time_u32);
                                g_SlvChnlTimPulsesRemain_ua32[HrTimIstc_e][slvTim_e] = (t_uint32)0;
                            }
                            //---- update register ---//
                            //(void)HAL_HRTIM_SoftwareUpdate(&g_HrTimInfo_as[HrTimIstc_e].bspItsc_s, f_bspTimIdx_u32);                            
                        }
                        else 
                        {
                            //---- Stop Basic Timer IT ----//
                            //FMKCPU_GetTick(&g_hrt_end_time_u32);
                            //FMKSRL_LOG("Pulse Finished at  %d\r\n", g_hrt_end_time_u32);
                            // __HAL_HRTIM_TIMER_CLEAR_IT(&g_HrTimInfo_as[HrTimIstc_e].bspItsc_s,
                            //                             f_bspTimIdx_u32,
                            //                             HRTIM_TIM_IT_REP);
                            // __HAL_HRTIM_TIMER_CLEAR_FLAG(&g_HrTimInfo_as[HrTimIstc_e].bspItsc_s,
                            //                                 f_bspTimIdx_u32,
                            //                                 HRTIM_TIM_FLAG_REP);
                            Ret_e = s_FMKHRT_SetHwOutputState((&g_HrTimInfo_as[HrTimIstc_e]),
                                                                slvTim_e,
                                                                idxChnl_u8, // not use
                                                                FMKHRT_RUN_MODE_IT,
                                                                FMKHRT_HW_OPE_TIM_BASIC,
                                                                FMKHRT_CHNLST_DISACTIVATED);
                            //--- first shut down channel ----//
                            for(idxChnl_u8 = (t_uint8)0 ; 
                            (idxChnl_u8 < FMKHRT_HRTIM_CHANNEL_NB)
                            && (Ret_e >= RC_OK) ; 
                            idxChnl_u8++)
                            {
                                if((slvInfo_ps->chnlInfo_as[idxChnl_u8].isConfigured_b == (t_bool)TRUE)
                                && (slvInfo_ps->chnlInfo_as[idxChnl_u8].isSyncOpeON_b == (t_bool)TRUE))
                                {
                                    Ret_e = s_FMKHRT_SetHwOutputState((&g_HrTimInfo_as[HrTimIstc_e]),
                                                                        slvTim_e,
                                                                        idxChnl_u8,
                                                                        slvInfo_ps->runMode_e,
                                                                        slvInfo_ps->HwOpeMode_e,
                                                                        FMKHRT_CHNLST_DISACTIVATED);
                                }
                            }
                            //---- lock channel to prevent user do stuff inside 
                            //      callback ----//
                            g_HrTimInfo_as->bspItsc_s.Lock = HAL_LOCKED; 
                            //--- then call user ----//
                            for(idxChnl_u8 = (t_uint8)0 ; 
                            idxChnl_u8 < FMKHRT_HRTIM_CHANNEL_NB ; 
                            idxChnl_u8++)
                            {
                                if((slvInfo_ps->chnlInfo_as[idxChnl_u8].isConfigured_b == (t_bool)TRUE)
                                && (slvInfo_ps->chnlInfo_as[idxChnl_u8].isSyncOpeON_b == (t_bool)TRUE)
                                && (slvInfo_ps->chnlInfo_as[idxChnl_u8].evntCallback_pcb != NULL_FUNCTION))
                                {
                                    slvInfo_ps->chnlInfo_as[idxChnl_u8].
                                                        evntCallback_pcb(   c_FMkHrt_ChnlLineMapp_ae[HrTimIstc_e][slvTim_e][idxChnl_u8],
                                                                            FMKHRT_HR_LINE_EVNT_CB_PULSE_FINISH);
                                }
                            }
                            g_HrTimInfo_as->bspItsc_s.Lock = HAL_UNLOCKED;
                        }                            
                        
                    }
                    break;
                }
                case FMKHRT_BSP_CB_DLL_CALIB_DONE:
                {
                    g_HrTimInfo_as[HrTimIstc_e].isCalibrate_b = (t_bool)True;
                    break;
                }
                case FMKHRT_BSP_CB_FAULT_1:
                case FMKHRT_BSP_CB_FAULT_2:
                case FMKHRT_BSP_CB_FAULT_3:
                case FMKHRT_BSP_CB_FAULT_4:
                case FMKHRT_BSP_CB_FAULT_5:
                case FMKHRT_BSP_CB_FAULT_6:
                case FMKHRT_BSP_CB_SYSTEM_FAULT:
                case FMKHRT_BSP_CB_BURST_MODE_PERIOD:
                case FMKHRT_BSP_CB_SYNCHRO_EVNT:
                case FMKHRT_BSP_CB_REGISTER_UPDATE:
                case FMKHRT_BSP_CB_COMPARE_1:
                case FMKHRT_BSP_CB_COMPARE_2:
                case FMKHRT_BSP_CB_COMPARE_3:
                case FMKHRT_BSP_CB_COMPARE_4:
                case FMKHRT_BSP_CB_CAPTURE_1:
                case FMKHRT_BSP_CB_CAPTURE_2:
                case FMKHRT_BSP_CB_DELAYED_PROTECT:
                case FMKHRT_BSP_CB_COUNTER_RESET:
                case FMKHRT_BSP_CB_OUTPUT_1_SET:
                case FMKHRT_BSP_CB_OUTPUT_1_RESET:
                case FMKHRT_BSP_CB_OUTPUT_2_SET:
                case FMKHRT_BSP_CB_OUTPUT_2_RESET:
                case FMKHRT_BSP_CB_BURST_DMA_TRANSER:
                case FMKHRT_BSP_CB_ERROR:
                default:
                {
                    //---- Nothing to do for now -----//
                    break;
                }
            }
        }
        if(Ret_e < RC_OK)
        {
            ASSERT((t_uint16)Ret_e);
        }       
    }

    return;
}

/*********************************
 * s_FMKHRT_GetBspTimerIndex
 *********************************/
static t_eReturnCode s_FMKHRT_PerformDiagnostic(t_eFMKHRT_HighResIstc f_highResTimer_e)
{
    t_eReturnCode Ret_e;
    t_sFMKHRT_HrTimInfo * highTimerInfo_ps;
    t_uint32 currentTime_u32;

    if(f_highResTimer_e >= FMKHRT_HIGH_RES_TIMER_NB)
    {
        ASSERT((t_uint16)0);
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    else 
    {
        FMKCPU_GetTick(&currentTime_u32);
        highTimerInfo_ps = (t_sFMKHRT_HrTimInfo *)(&g_HrTimInfo_as[f_highResTimer_e]);
        //---- there is no ErrorCode field in bsp instance 
        //      if an error occured it can be the DMA so check for master  & 
        //      slave the DMA error code, as we don't currently used it we just check the state ----//
        if((highTimerInfo_ps->bspItsc_s.State != HAL_HRTIM_STATE_READY)
        || (highTimerInfo_ps->bspItsc_s.State != HAL_HRTIM_STATE_BUSY)
        || (highTimerInfo_ps->errDetected_b == TRUE))
        {
            APPSDM_ReportDiagEvnt(  APPSDM_DIAG_ITEM_FMK_HRT_OPE_ERROR,
                                    APPSDM_DIAG_ITEM_REPORT_FAIL,
                                    (t_uint16)f_highResTimer_e,
                                    (t_uint16)highTimerInfo_ps->bspItsc_s.State);

            if((currentTime_u32 - highTimerInfo_ps->lastCbError_u32) > (t_uint32)100)
            {
                highTimerInfo_ps->errDetected_b = FALSE;
            }
        }
        else 
        {
            APPSDM_ReportDiagEvnt(  APPSDM_DIAG_ITEM_FMK_HRT_OPE_ERROR,
                                    APPSDM_DIAG_ITEM_REPORT_PASS,
                                    (t_uint16)f_highResTimer_e,
                                    (t_uint16)0);
            highTimerInfo_ps->errDetected_b = (t_bool)FALSE;
        }
    }

    return Ret_e;
}
/*********************************
 * s_FMKHRT_GetBspTimerIndex
 *********************************/
static t_eReturnCode s_FMKHRT_GetBspTimerIndex( t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                                t_uint32 * f_bspTimerIdx_pu32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_hrSlvTim_e >= FMKHRT_HRTIM_SLAVE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    if(f_bspTimerIdx_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        // flag automatic generated code 
        switch(f_hrSlvTim_e)
        {
            case FMKHRT_HRTIM_SLAVE_1:
                *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_A;
                break;
            case FMKHRT_HRTIM_SLAVE_2:
                *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_B;
                break;
            case FMKHRT_HRTIM_SLAVE_3:
                *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_C;
                break;
            case FMKHRT_HRTIM_SLAVE_4:
                *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_D;
                break;
            case FMKHRT_HRTIM_SLAVE_5:
                *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_E;
                break;
// idem code specific gen code
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
            case FMKHRT_HRTIM_SLAVE_6:
                *f_bspTimerIdx_pu32 = HRTIM_TIMERINDEX_TIMER_F;
                break;
#endif // FMKCPU_STM32_ECU_FAMILY_G4
            case FMKHRT_HRTIM_SLAVE_NB:
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_GetPrescalerRatio
 *********************************/
static t_eReturnCode s_FMKHRT_GetPrescalerRatio(t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                t_uint32 * f_PscRatio_pu32)
{
    t_eReturnCode Ret_e = RC_OK;
    
    if((f_PscRatio_pu32 == (t_uint32 *)NULL)
    && (f_CpuFreqMulDiv_e >= FMKHRT_FREQRANGE_DIVMUL_NB))
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        switch(f_CpuFreqMulDiv_e)
        {
            case FMKHRT_FREQRANGE_DIV_4:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_DIV4;
                break;
            case FMKHRT_FREQRANGE_DIV_2:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_DIV2;
                break;
            case FMKHRT_FREQRANGE_DIV_1:
                *f_PscRatio_pu32 = HRTIM_PRESCALERRATIO_DIV1;
                break;
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
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
#endif // FMKCPU_STM32_ECU_FAMILY_G4
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;

        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_GetBspPeriod
 *********************************/
static t_eReturnCode s_FMKHRT_GetBspPeriod( t_uint16 f_TimFreqMHz_16,
                                            t_uint32 f_RqstOutFreq_u32,
                                            t_uint32 * f_bspPeriod_pu32)
{
    t_eReturnCode Ret_e = RC_OK;
    t_uint32 bspPeriod_u32;
    if(f_bspPeriod_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        if(f_RqstOutFreq_u32 > (t_uint32)0)
        {
            bspPeriod_u32 = (t_uint32)(((t_uint32)f_TimFreqMHz_16 * CST_MHZ_TO_HZ) 
                                            / (t_uint32)f_RqstOutFreq_u32);
            
            if(bspPeriod_u32 > CST_MAX_UINT_16BIT)
            {
                *f_bspPeriod_pu32 = (t_uint32)CST_MAX_UINT_16BIT;
                ASSERT((t_uint16)0);
            }
            else 
            {
                *f_bspPeriod_pu32 = (bspPeriod_u32 - (t_uint32)1);
            }
        }
        else 
        {
            Ret_e = RC_ERROR_PARAM_INVALID;
            ASSERT((t_uint16)(f_RqstOutFreq_u32));
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_ComputeTimerFreqRange
 *********************************/
static t_eReturnCode s_FMKHRT_ComputeTimerFreqRange(t_eFMKCPU_ClockPort f_HrTimClkPort_e,
                                                    t_eFMKHRT_FreqMulDiv f_CpuFreqMulDiv_e,
                                                    t_sFMKHRT_TimSlaveInfo * f_slvInfo_ps)

{
    t_eReturnCode Ret_e = RC_OK;
    t_eFMKCPU_SysClkOsc oscTimerSrc_e;
    t_uint16 hrtimFreqMHz_u16 = (t_uint16)0;
    t_uint16 SysFreqMHz_u16 = (t_uint16)0;
    t_uint16 slvFreqMHz_u16;

    if(f_slvInfo_ps == (t_sFMKHRT_TimSlaveInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_GetOscRccSrc(f_HrTimClkPort_e, &oscTimerSrc_e);

        if(Ret_e == RC_OK)
        {
            Ret_e = FMKCPU_GetSysClkValue(oscTimerSrc_e, &hrtimFreqMHz_u16);
        }
        if(Ret_e == RC_OK)
        {
            Ret_e = FMKCPU_GetSysClkValue(FMKCPU_SYS_CLOCK_SYSTEM, &SysFreqMHz_u16);
        }
        if(Ret_e == RC_OK)
        {
            //---- see documentation fore more info, but basically 
            //      the basic timer frequency is double whenever the sysclck value of the bus for 
            //      the timer is < to the sys clock ----//
            if(SysFreqMHz_u16 > hrtimFreqMHz_u16)
            {
                hrtimFreqMHz_u16 = (t_uint32)((t_uint32)2 * (t_uint32)hrtimFreqMHz_u16);
            }
        }

    }
    if(Ret_e == RC_OK)
    {
        //----- In theory we don't passed 0xFFFF in value even with 500 MHz system.
        switch(f_CpuFreqMulDiv_e)
        {
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
            case FMKHRT_FREQRANGE_MUL_32:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 * (t_uint16)32);
                break;
            case FMKHRT_FREQRANGE_MUL_16:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 * (t_uint16)16);
                break;
            case FMKHRT_FREQRANGE_MUL_8:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 * (t_uint16)8);
                break;
            case FMKHRT_FREQRANGE_MUL_4:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 * (t_uint16)4);
                break;
            case FMKHRT_FREQRANGE_MUL_2:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 * (t_uint16)2);
                break;
#endif // FMKCPU_STM32_ECU_FAMILY_G4
            case FMKHRT_FREQRANGE_DIV_1:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16);
                break;
            case FMKHRT_FREQRANGE_DIV_2:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 / (t_uint16)2);
                break;
            case FMKHRT_FREQRANGE_DIV_4:
                slvFreqMHz_u16 = (t_uint16)(hrtimFreqMHz_u16 / (t_uint16)4);
                break;
            default:
                slvFreqMHz_u16 = (t_uint16)0;
                Ret_e = RC_ERROR_NOT_SUPPORTED;
        }
        if(Ret_e == RC_OK)
        {
            f_slvInfo_ps->minFreqAccept_u32 = (t_uint32)((t_uint32)(slvFreqMHz_u16  * CST_MHZ_TO_HZ)/ 
                                                                    FMKHRT_PWM_MAX_ARR_VALUE);
            f_slvInfo_ps->maxFreqAccept_u32 = (t_uint32)((t_uint32)(slvFreqMHz_u16 * CST_MHZ_TO_HZ)/ 
                                                                    FMKHRT_PWM_MIN_ARR_VALUE);
            f_slvInfo_ps->timFreqMHz_u16 = slvFreqMHz_u16;
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_GetEnumTimeIdxFromBsp
 *********************************/
static t_eReturnCode s_FMKHRT_GetEnumTimeIdxFromBsp(    t_uint32 f_bspTimIdx_u32,
                                                        t_eFMKHRT_HighResSlvTim * f_timSlv_pe)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_timSlv_pe == (t_eFMKHRT_HighResSlvTim *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        switch (f_bspTimIdx_u32)
        {
            case HRTIM_TIMERINDEX_TIMER_A:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_1;
                break;
            case HRTIM_TIMERINDEX_TIMER_B:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_2;
                break;
            case HRTIM_TIMERINDEX_TIMER_C:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_3;
                break;
            case HRTIM_TIMERINDEX_TIMER_D:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_4;
                break;
            case HRTIM_TIMERINDEX_TIMER_E:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_5;
                break;
// make this in code gen
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
            case HRTIM_TIMERINDEX_TIMER_F:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_6;
                break;
#endif
            case HRTIM_TIMERINDEX_MASTER:
            default:
                *f_timSlv_pe = FMKHRT_HRTIM_SLAVE_NB;
                Ret_e = RC_WARNING_NO_OPERATION;
                break;
        }
    }

    return Ret_e;
}

/*********************************
 * s_FMKHRT_GetBspPolarity
 *********************************/
static t_eReturnCode s_FMKHRT_GetBspPolarity(   t_eFMKHRT_LinePolarity f_Polarity_e,
                                                t_uint32 * f_bspPolarity_pu32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_Polarity_e >= FMKHRT_LINE_POLARITY_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    if(f_bspPolarity_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        if(f_Polarity_e == FMKHRT_LINE_POLARITY_LOW)
        {
            *f_bspPolarity_pu32 = HRTIM_OUTPUTPOLARITY_LOW;
        }
        else if(f_Polarity_e == FMKHRT_LINE_POLARITY_HIGH)
        {
            *f_bspPolarity_pu32 = HRTIM_OUTPUTPOLARITY_HIGH;
        }
        else 
        {
            Ret_e = RC_ERROR_NOT_ALLOWED;
            *f_bspPolarity_pu32 = (t_uint32)0;
            ASSERT((t_uint16)Ret_e);
        }
    }

    return Ret_e;
}
/*********************************
 * s_FMKHRT_GetBspChannel
 *********************************/
static t_eReturnCode s_FMKHRT_GetBspChannel(t_eFMKHRT_HighResSlvTim f_hrSlvTim_e,
                                            t_eFMKHRT_HrTimChannel f_chnl_e,
                                            t_uint32 * f_bspOutputChnl_pu32)
{
    t_eReturnCode Ret_e = RC_OK;

    if((f_hrSlvTim_e >= FMKHRT_HRTIM_SLAVE_NB)
    || (f_chnl_e >= FMKHRT_HRTIM_CHANNEL_NB))
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)Ret_e);
    }
    if(f_bspOutputChnl_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)Ret_e);
    }
    if(Ret_e == RC_OK)
    {
        switch(f_hrSlvTim_e)
        {
            case FMKHRT_HRTIM_SLAVE_1:
            {
                if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TA1;
                }
                else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TA2;
                }
                else 
                {
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    *f_bspOutputChnl_pu32 = (t_uint32)0;
                }
                
                break;
            }
            case FMKHRT_HRTIM_SLAVE_2:
            {
                if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TB1;
                }
                else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TB2;
                }
                else 
                {
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    *f_bspOutputChnl_pu32 = (t_uint32)0;
                }
                
                break;
            }
            case FMKHRT_HRTIM_SLAVE_3:
            {
                if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TC1;
                }
                else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TC2;
                }
                else 
                {
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    *f_bspOutputChnl_pu32 = (t_uint32)0;
                }
                
                break;
            }
            case FMKHRT_HRTIM_SLAVE_4:
            {
                if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TD1;
                }
                else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TD2;
                }
                else 
                {
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    *f_bspOutputChnl_pu32 = (t_uint32)0;
                }
                
                break;
            }
            case FMKHRT_HRTIM_SLAVE_5:
            {
                if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TE1;
                }
                else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TE2;
                }
                else 
                {
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    *f_bspOutputChnl_pu32 = (t_uint32)0;
                }
                
                break;
            }
#if defined(FMKCPU_STM32_ECU_FAMILY_G4)
            case FMKHRT_HRTIM_SLAVE_6:
            {
                if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_1)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TF1;
                }
                else if(f_chnl_e == FMKHRT_HRTIM_CHANNEL_2)
                {
                    *f_bspOutputChnl_pu32 = HRTIM_OUTPUT_TF2;
                }
                else 
                {
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    *f_bspOutputChnl_pu32 = (t_uint32)0;
                }
                break;
            }
#endif // FMKCPU_STM32_ECU_FAMILY_G4
            case FMKHRT_HRTIM_SLAVE_NB:
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
        }
    }

    return Ret_e;
}
//************************************************************************************
// Bsp Callback Managment 
//************************************************************************************
/**
 * @brief Callback called Counter reach 0.
 */
void HAL_HRTIM_RepetitionEventCallback(HRTIM_HandleTypeDef *hhrtim,
                                              uint32_t TimerIdx)
{
    s_FMKHRT_BspCallbackMngmnt( hhrtim, 
                                TimerIdx, 
                                FMKHRT_BSP_CB_REPETITION_EVNT);

    return;
}
/**
 * @brief Callback called whenever the calibration is done.
 */
void HAL_HRTIM_DLLCalibrationReadyCallback(HRTIM_HandleTypeDef *hhrtim)
{
    t_uint8 idxHrIsct_u8 = (t_uint8)0;
    t_eFMKHRT_HighResIstc HrTimIstc_e = FMKHRT_HIGH_RES_TIMER_NB;

    //----- Find Timer Instance ----//
    for(idxHrIsct_u8 = (t_uint8)0 ; idxHrIsct_u8 < (t_uint8)FMKHRT_HIGH_RES_TIMER_NB ; idxHrIsct_u8++)
    {
        if((&g_HrTimInfo_as[idxHrIsct_u8].bspItsc_s) == (HRTIM_HandleTypeDef *)hhrtim)
        {
            HrTimIstc_e = (t_eFMKHRT_HighResIstc)idxHrIsct_u8;
            break;
        }
    }
    if(HrTimIstc_e != FMKHRT_HIGH_RES_TIMER_NB)
    {
        g_HrTimInfo_as[HrTimIstc_e].isCalibrate_b = (t_bool)True;
    }

    return;
}

/**
 * @brief Callback called whenever an error occured.
 */
void HAL_HRTIM_ErrorCallback(HRTIM_HandleTypeDef *hhrtim)
{
    t_uint8 idxHrIsct_u8 = (t_uint8)0;
    t_eFMKHRT_HighResIstc HrTimIstc_e = FMKHRT_HIGH_RES_TIMER_NB;

    //----- Find Timer Instance ----//
    for(idxHrIsct_u8 = (t_uint8)0 ; idxHrIsct_u8 < (t_uint8)FMKHRT_HIGH_RES_TIMER_NB ; idxHrIsct_u8++)
    {
        if((&g_HrTimInfo_as[idxHrIsct_u8].bspItsc_s) == (HRTIM_HandleTypeDef *)hhrtim)
        {
            HrTimIstc_e = (t_eFMKHRT_HighResIstc)idxHrIsct_u8;
            break;
        }
    }
    if(HrTimIstc_e != FMKHRT_HIGH_RES_TIMER_NB)
    {   
        g_HrTimInfo_as[HrTimIstc_e].errDetected_b = (t_bool)TRUE;
        FMKCPU_GetTick(&g_HrTimInfo_as[HrTimIstc_e].lastCbError_u32);
    }
}

#endif // APPSYS_MODULE_FMKHRT_ENABLE
//************************************************************************************
// End of File
//************************************************************************************

/**
 *
 *	@brief
 *	@note
 *
 *
 *	@param[in] 
 *	@param[out]
 *	 
 *
 *
 */
