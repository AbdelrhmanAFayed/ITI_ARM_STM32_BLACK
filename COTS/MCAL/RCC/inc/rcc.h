#ifndef RCC_H_
#define RCC_H_






/*type def*/
typedef enum
{
    MRCC_OK = 0x00,
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
    MRCC_PLL_ENABLED,
    MRCC_Preph_ENABLED,
    MRCC_Preph_DISABLED

}MRCC_enuErrorStatus_t;

typedef enum
{
    MRCC_HSI = 0x00,
    MRCC_HSE,
    MRCC_PLL
}MRCC_enuClockSource_t;

typedef enum
{
    /*Perphrials Controlled by AHB1*/
    MRCC_GPIOA = 0x00,
    MRCC_GPIOB,
    MRCC_GPIOC,
    MRCC_GPIOD,
    MRCC_GPIOE,
    MRCC_GPIOH,
    MRCC_CRC,
    MRCC_DMA1,
    MRCC_DMA2,
    MRCC_MAX_PERF_AHB1, /*ENUM to signify the end of the periphrals controlled by AHB1 */

    /*Periphrials Controlled by AHB2*/
    MRCC_OTGFS, 
    MRCC_MAX_PERF_AHB2,

    /*Periphrials Controlled by APB1*/
    MRCC_TIM2,
    MRCC_TIM3,
    MRCC_TIM4,
    MRCC_TIM5,
    MRCC_WWDG,
    MRCC_SPI2,
    MRCC_SPI3,
    MRCC_USART2,
    MRCC_I2C1,
    MRCC_I2C2,
    MRCC_I2C3,
    MRCC_PWR,
    MRCC_MAX_PERF_APB1, /*ENUM to signify the end of the periphrals controlled by APB1 */

    /*Periphrials Controlled by APB2*/
    MRCC_TIM1,
    MRCC_USART1,
    MRCC_USART6,
    MRCC_ADC1,
    MRCC_SDIO,
    MRCC_SPI1,
    MRCC_SPI4,
    MRCC_SYSCFG,
    MRCC_TIM9,
    MRCC_TIM10,
    MRCC_TIM11,
    MRCC_MAX_PERF_APB2 /*ENUM to signify the end of the periphrals controlled by APB2 */

}MRCC_enuClockPerph_t;

typedef enum
{
    MRCC_CLK_OFF = 0x00,
    MRCC_CLK_ON
}MRCC_enuClockState_t;



/*Functions*/

MRCC_enuErrorStatus_t MRCC_enuEnableClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc);

MRCC_enuErrorStatus_t MRCC_enuDisableClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc);

MRCC_enuErrorStatus_t RCC_enuGetClkStatus(MRCC_enuClockSource_t Copy_enuClkSrc,MRCC_enuClockState_t* State_ret);


MRCC_enuErrorStatus_t RCC_enuDisPeriphal(MRCC_enuClockPerph_t Copy_enuClkPreph);

MRCC_enuErrorStatus_t RCC_enuEnPeriphal(MRCC_enuClockPerph_t Copy_enuClkPreph);

//MRCC_enuErrorStatus_t RCC_enuSetPLLCFG(PLL_Cfg* Add_stPLL);
MRCC_enuErrorStatus_t MRCC_enuSelectClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc);


/*Enable and disable periphal for Bus AHB1*/
MRCC_enuErrorStatus_t RCC_enuEnPeriphalAHB1(MRCC_enuClockPerph_t Copy_enuClkPreph);
MRCC_enuErrorStatus_t RCC_enuDisPeriphalAHB1(MRCC_enuClockPerph_t Copy_enuClkPreph);

/*Enable and disable periphal for Bus AHB2*/
MRCC_enuErrorStatus_t RCC_enuEnPeriphalAHB2(MRCC_enuClockPerph_t Copy_enuClkPreph);
MRCC_enuErrorStatus_t RCC_enuDisPeriphalAHB2(MRCC_enuClockPerph_t Copy_enuClkPreph);

/*Enable and disable periphal for Bus APB1*/
MRCC_enuErrorStatus_t RCC_enuEnPeriphalAPB1(MRCC_enuClockPerph_t Copy_enuClkPreph);
MRCC_enuErrorStatus_t RCC_enuDisPeriphalAPB1(MRCC_enuClockPerph_t Copy_enuClkPreph);

/*Enable and disable periphal for Bus APB2*/
MRCC_enuErrorStatus_t RCC_enuEnPeriphalAPB2(MRCC_enuClockPerph_t Copy_enuClkPreph);
MRCC_enuErrorStatus_t RCC_enuDisPeriphalAPB2(MRCC_enuClockPerph_t Copy_enuClkPreph);






#endif 
