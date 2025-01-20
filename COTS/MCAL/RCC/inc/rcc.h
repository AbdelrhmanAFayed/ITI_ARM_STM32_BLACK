#ifndef RCC_H_
#define RCC_H_


/*Includes*/

/*Defintions*/
#define DEF_TIMEOUT 500




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

    /*Perphrials Controlled by AHB2*/
    MRCC_OTGFS,

    /*Perphrials Controlled by APB1*/
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

    /*Perphrials Controlled by APB2*/
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
    MRCC_TIM11

}MRCC_enuClockPerph_t;

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

MRCC_enuErrorStatus_t RCC_enuDisPeriphal(MRCC_enuClockPerph_t Copy_enuClkPreph);

MRCC_enuErrorStatus_t RCC_enuEnPeriphal(MRCC_enuClockPerph_t Copy_enuClkPreph);





#endif