
#include "STD_TYPES.h"

/*REGISTERS*/
#define RCC_BASE                (0x40023800ULL)
/*access masks*/

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


