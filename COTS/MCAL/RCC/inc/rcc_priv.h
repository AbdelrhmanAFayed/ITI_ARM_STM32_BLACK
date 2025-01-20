
#include "STD_TYPES.h"


/*Register map*/
typedef struct 
{
    volatile uint32_t CR;        /*Address offset 0x00*/
    volatile uint32_t PLL_CFGR;  /*Address offset 0x04*/
    volatile uint32_t CFGR;      /*Address offset 0x08*/
    volatile uint32_t CIR;       /*Address offset 0x0C*/
    volatile uint32_t AHB1RSTR;  /*Address offset 0x10*/
    volatile uint32_t AHB2RSTR;  /*Address offset 0x14*/

    uint32_t RESERVED0;             /*RESERVED 0x18*/
    uint32_t RESERVED1;             /*RESERVED 0x1C*/
    
    volatile uint32_t APB1RSTR;  /*Address offset 0x20*/
    volatile uint32_t APB2RSTR;  /*Address offset 0x24*/
    
    uint32_t RESERVED2;             /*RESERVED 0x28*/
    uint32_t RESERVED3;             /*RESERVED 0x2C*/
    
    volatile uint32_t AHB1ENR;   /*Address offset 0x30*/
    volatile uint32_t AHB2ENR;   /*Address offset 0x34*/
    
    uint32_t RESERVED4;             /*RESERVED 0x38*/
    uint32_t RESERVED5;             /*RESERVED 0x3C*/
    
    volatile uint32_t APB1ENR;   /*Address offset 0x40*/
    volatile uint32_t APB2ENR;   /*Address offset 0x44*/
    
    uint32_t RESERVED6;             /*RESERVED 0x48*/
    uint32_t RESERVED7;             /*RESERVED 0x4C*/
    
    volatile uint32_t AHB1LPENR; /*Address offset 0x50*/
    volatile uint32_t AHB2LPENR; /*Address offset 0x54*/
    
    uint32_t RESERVED8;             /*RESERVED 0x58*/
    uint32_t RESERVED9;             /*RESERVED 0x5C*/

    volatile uint32_t APB1LPENR; /*Address offset 0x60*/
    volatile uint32_t APB2LPENR; /*Address offset 0x64*/
    
    uint32_t RESERVED10;            /*RESERVED 0x68*/
    uint32_t RESERVED11;            /*RESERVED 0x6C*/
    
    volatile uint32_t BDCR;      /*Address offset 0x70*/
    volatile uint32_t CSR;       /*Address offset 0x74*/
    
    uint32_t RESERVED12;            /*RESERVED 0x78*/
    uint32_t RESERVED13;            /*RESERVED 0x7C*/
    
    volatile uint32_t SSCGR;     /*Address offset 0x80*/
    volatile uint32_t PLLI2SCFGR;/*Address offset 0x84*/
    
    uint32_t RESERVED14;            /*RESERVED 0x88*/
    
    volatile uint32_t DCKCFGR;   /*Address offset 0x8C*/

} RCC_MAP;


/*REGISTERS*/
#define RCC_BASE                (0x40023800ULL)
/*access masks*/

/*CR register*/
#define MASK_HSI_ON         (0x00000001ULL)
#define MASK_HSI_RDY        (0x00000002ULL)

#define MASK_HSITRIM        (0x000000F8ULL)
#define MASK_HSICAL         (0x0000FF00ULL)
#define MASK_HSE_ON         (0x00010000ULL)
#define MASK_HSE_RDY        (0x00020000ULL)
#define MASK_HSE_BYP        (0x00040000ULL)
#define MASK_CSS_ON         (0x00080000ULL)

#define MASK_PLL_ON         (0x01000000ULL)
#define MASK_PLL_RDY        (0x02000000ULL)
#define MASK_PLLI2S_ON      (0x04000000ULL)
#define MASK_PLLI2S_RDY     (0x08000000ULL)

/*PLLCFGR register*/

/*CFGR register*/

/*CIR register*/

/*AHB1RSTR register*/

/*AHB2RSTR register*/

/*APB1RSTR register*/

/*APB2RSTR register*/


/*AHB1ENR register*/
#define MASK_GPIOA_EN       (0x00000001ULL)
#define MASK_GPIOB_EN       (0x00000002ULL)
#define MASK_GPIOC_EN       (0x00000004ULL)
#define MASK_GPIOD_EN       (0x00000008ULL)
#define MASK_GPIOE_EN       (0x00000010ULL)

#define MASK_GPIOH_EN       (0x00000080ULL)

#define MASK_CRC_EN         (0x00001000ULL)

#define MASK_DMA1_EN        (0x00200000ULL)
#define MASK_DMA2_EN        (0x00400000ULL)

/*AHB2ENR register*/

#define MASK_OTGFS_EN       (0x00000080ULL)

/*APB1ENR register*/
#define MASK_TIM2_EN        (0x00000001ULL)
#define MASK_TIM3_EN        (0x00000002ULL)
#define MASK_TIM4_EN        (0x00000004ULL)
#define MASK_TIM5_EN        (0x00000008ULL)

#define MASK_WWDG_EN        (0x00000800ULL)

#define MASK_SPI2_EN        (0x00004000ULL)
#define MASK_SPI3_EN        (0x00008000ULL)

#define MASK_USART2_EN      (0x00020000ULL)

#define MASK_I2C1_EN        (0x00200000ULL)
#define MASK_I2C2_EN        (0x00400000ULL)
#define MASK_I2C3_EN        (0x00800000ULL)

#define MASK_PWR_EN         (0x10000000ULL)

/*APB2ENR register*/

#define MASK_SYSCFG_EN      (0x00000001ULL)

#define MASK_USART1_EN      (0x00000010ULL)
#define MASK_USART6_EN      (0x00000020ULL)

#define MASK_ADC1_EN        (0x00000100ULL)

#define MASK_SDIO_EN        (0x00000800ULL)
#define MASK_SPI1_EN        (0x00001000ULL)
#define MASK_SPI4_EN        (0x00002000ULL)
#define MASK_SYSCFG_EN      (0x00004000ULL)

#define MASK_TIM9_EN        (0x00010000ULL)
#define MASK_TIM10_EN       (0x00020000ULL)
#define MASK_TIM11_EN       (0x00040000ULL)

/*AHB1LBENR regidter*/

#define MASK_GPIOA_LPEN     (0x00000001ULL)
#define MASK_GPIOB_LPEN     (0x00000002ULL)
#define MASK_GPIOC_LPEN     (0x00000004ULL)
#define MASK_GPIOD_LPEN     (0x00000008ULL)
#define MASK_GPIOE_LPEN     (0x00000010ULL)

#define MASK_GPIOH_LPEN     (0x00000080ULL)

#define MASK_CRC_LPEN       (0x00001000ULL)

#define MASK_FLITF_LPEN     (0x00008000ULL)
#define MASK_SRAM1_LPEN     (0x00010000ULL)

#define MASK_DMA1_LPEN      (0x00200000ULL)
#define MASK_DMA2_LPEN      (0x00400000ULL)

/*AHB2LPENR register*/

#define MASK_OTGFS_LPEN     (0x00000080ULL)

/*APB1LPENR register*/

#define MASK_TIM2_LPEN      (0x00000001ULL)
#define MASK_TIM3_LPEN      (0x00000002ULL)
#define MASK_TIM4_LPEN      (0x00000004ULL)
#define MASK_TIM5_LPEN      (0x00000008ULL)

#define MASK_WWDG_LPEN      (0x00000800ULL)

#define MASK_SPI2_LPEN      (0x00004000ULL)
#define MASK_SPI3_LPEN      (0x00008000ULL)

#define MASK_USART2_LPEN    (0x00020000ULL)

#define MASK_I2C1_LPEN      (0x00200000ULL)
#define MASK_I2C2_LPEN      (0x00400000ULL)
#define MASK_I2C3_LPEN      (0x00800000ULL)

#define MASK_PWR_LPEN       (0x10000000ULL)

/*APB2LPENR register*/

#define MASK_TIM1_LPEN      (0x00000001ULL)

#define MASK_USART1_LPEN    (0x00000010ULL)
#define MASK_USART6_LPEN    (0x00000020ULL)

#define MASK_ADC1_LPEN      (0x00000100ULL)

#define MASK_SDIO_LPEN      (0x00000800ULL)
#define MASK_SPI1_LPEN      (0x00001000ULL)
#define MASK_SPI4_LPEN      (0x00002000ULL)
#define MASK_SYSCFG_LPEN    (0x00004000ULL)

#define MASK_TIM9_LPEN      (0x00010000ULL)
#define MASK_TIM10_LPEN     (0x00020000ULL)
#define MASK_TIM11_LPEN     (0x00040000ULL)

/*BDCR register*/

#define MASK_LSE_ON         (0x00000001ULL)
#define MASK_LSE_RDY        (0x00000002ULL)
#define MASK_LSE_BYP        (0x00000004ULL)

#define MASK_RTCSEL         (0x00000300ULL)

#define MASK_RTCEN          (0x00008000ULL)
#define MASK_BDRST          (0x00010000ULL)

/*CSR register*/

#define MASK_LSI_ON         (0x00000001ULL)
#define MASK_LSI_RDY        (0x00000002ULL)

#define MASK_RMVF           (0x01000000ULL)
#define MASK_BORRSTF        (0x02000000ULL)
#define MASK_PINRSTF        (0x04000000ULL)
#define MASK_PORRSTF        (0x08000000ULL)
#define MASK_SFTRSTF        (0x10000000ULL)
#define MASK_IWDGRSTF       (0x20000000ULL)
#define MASK_WWDGRSTF       (0x40000000ULL)
#define MASK_LPWRRSTF       (0x80000000ULL)

/*SSCGR register*/

/*PLLI2SCFGR register*/

/*DCKCFGR register*/