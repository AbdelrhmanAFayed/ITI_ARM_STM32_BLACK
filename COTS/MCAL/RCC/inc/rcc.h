#ifndef RCC_H_
#define RCC_H_


/*Includes*/

/*Defintions*/
#define DEF_TIMEOUT 500




/*type def*/
typedef enum
{
    MRCC_OK,
    MRCC_NOK,
    MRCC_NULL_PTR,
    MRCC_TIMEOUT,
    MRCC_INVALID_ARG,
    MRCC_HSI_USED,
    MRCC_HSE_USED,
    MRCC_PLL_USED,
    MRCC_HSI_DISABLED,
    MRCC_HSE_DISABLED,
    MRCC_PLL_DISABLED,
    MRCC_HSI_ENABLED,
    MRCC_HSE_ENABLED,
    MRCC_PLL_ENABLED
}MRCC_enuErrorStatus_t;

typedef enum
{
    MRCC_HSI,
    MRCC_HSE,
    MRCC_PLL
}MRCC_enuClockSource_t;

typedef enum
{
    MRCC_CLK_ON,
    MRCC_CLK_OFF
}MRCC_enuClockState_t;



/*Functions*/

MRCC_enuErrorStatus_t MRCC_enuEnableClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc);

MRCC_enuErrorStatus_t MRCC_enuDisableClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc);

MRCC_enuErrorStatus_t RCC_enuGetClkStatus(MRCC_enuClockSource_t Copy_enuClkSrc,MRCC_enuClockState_t* State_ret);

MRCC_enuErrorStatus_t MRCC_enuSelectClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc);






#endif