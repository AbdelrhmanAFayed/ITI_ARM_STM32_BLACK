

#include "STD_TYPES.h"
#include "rcc.h"
#include "rcc_priv.h"
#include "rcc_cfg.h"
#include "BIT_MATH.h"




/*RCC struct of registers*/
RCC_MAP* RCC = (RCC_MAP*)RCC_BASE;

/*
* @brief: This function enables the specific clk source given
*
* @param: The function takes an enum type of the available clks Copy_enuClkSrc
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_TIMEOUT: timeout while waiting for the clk src to be enabled and stable
*           MRCC_INVALID_ARG: an invalid input clk src is given
*           MRCC_HSI_ENABLED: the HSI is given while is already enabled
*           MRCC_HSE_ENABLED: the HSE is given while is already enabled
*           MRCC_PLL_ENABLED: the PLL is given while is already enabled
*/

MRCC_enuErrorStatus_t MRCC_enuEnableClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK; /*Local variable to store error status */
    uint32_t Local_u32Timeout = DEF_TIMEOUT;                      /*Timeout variable to quit loop if clk doesn't init*/

    switch(Copy_enuClkSrc)   /*switching to the clk src to be enabled*/
    {
        case MRCC_HSI :

        if( IS_MASK_SET((RCC->CR), MASK_HSI_RDY) )   /*checks if the HSI src is already enabled*/
        {
            Local_enuErrorStatus = MRCC_HSI_ENABLED ; 

        }
        else
        {
            SET_MASK((RCC->CR), MASK_HSI_ON) ; /*enables the HSI src*/
            Local_u32Timeout = DEF_TIMEOUT; 
            while( IS_MASK_CLEAR((RCC->CR), MASK_HSI_RDY) && Local_u32Timeout)
            {
                    Local_u32Timeout-- ;
            }
            if(Local_u32Timeout == 0)
            {
                Local_enuErrorStatus = MRCC_TIMEOUT ;
            }
        }

        break;
        case MRCC_HSE:
        if( IS_MASK_SET((RCC->CR), MASK_HSE_RDY) )  /*checks if the HSE src is already enabled*/
        {
             Local_enuErrorStatus = MRCC_HSE_ENABLED ;  

        }
        else
        {
            SET_MASK((RCC->CR), MASK_HSE_ON) ; /*enables the HSE src*/
            Local_u32Timeout = DEF_TIMEOUT; 
            while( IS_MASK_CLEAR((RCC->CR), MASK_HSE_RDY) && Local_u32Timeout) /*checking if the clk is ready*/
            {
                    Local_u32Timeout-- ;
            }
            if(Local_u32Timeout == 0)
            {
                Local_enuErrorStatus = MRCC_TIMEOUT ;
            }
            
        }

        break; 
        case MRCC_PLL: 
        if( IS_MASK_SET((RCC->CR), MASK_PLL_RDY) ) /*checks if the PLL src is already enabled*/
        {
             Local_enuErrorStatus = MRCC_PLL_ENABLED ;

        }
        else
        {
            SET_MASK((RCC->CR), MASK_PLL_ON) ; /*enables the PLL src*/
            Local_u32Timeout = 500; 
            while( IS_MASK_CLEAR((RCC->CR), MASK_PLL_RDY) && Local_u32Timeout) /*checking if the clk is ready*/
            {
                    Local_u32Timeout-- ;
            }
            if(Local_u32Timeout == 0)
            {
                Local_enuErrorStatus = MRCC_TIMEOUT ;
            }
        }

        break;

        default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }

    return Local_enuErrorStatus;
    

}

/*
* @brief: This function disables the specific clk source given
*
* @param: The function takes an enum type of the available clks Copy_enuClkSrc
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input clk src is given
*           MRCC_HSI_DISABLED: the HSI is given while is already disabled
*           MRCC_HSE_DISABLED: the HSE is given while is already disabled
*           MRCC_PLL_DISABLED: the PLL is given while is already disabled
*/

MRCC_enuErrorStatus_t MRCC_enuDisableClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */
    

    switch(Copy_enuClkSrc)   /*switching to the clk src to be disabled*/
    {
        case MRCC_HSI :

        if( IS_MASK_CLEAR((RCC->CR), MASK_HSI_RDY) )   /*checks if the HSI src is already disabled*/
        {
            Local_enuErrorStatus = MRCC_HSI_DISABLED ; 

        }
        else
        {
            CLEAR_MASK((RCC->CR), MASK_HSI_ON) ; /*disables the HSI src*/
            
        }

        break;
        case MRCC_HSE:
        if( IS_MASK_CLEAR((RCC->CR), MASK_HSE_RDY) )  /*checks if the HSE src is already disabled*/
        {
             Local_enuErrorStatus = MRCC_HSE_DISABLED ;  

        }
        else
        {
            CLEAR_MASK((RCC->CR), MASK_HSE_ON) ; /*disables the HSE src*/
            
        }

        break; 
        case MRCC_PLL: 
        if( IS_MASK_CLEAR((RCC->CR), MASK_PLL_RDY) ) /*checks if the PLL src is already disabled*/
        {
             Local_enuErrorStatus = MRCC_PLL_DISABLED ;

        }
        else
        {
            CLEAR_MASK((RCC->CR), MASK_PLL_ON) ; /*disables the PLL src*/
            
        }

        break;

        default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }

    return Local_enuErrorStatus;

}

/*
* @brief: gets the state of a given clk source 
*
* @param: takes an enum type of the available clks Copy_enuClkSrc
*         and a ptr to store the state of the clk        
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_NULL_PTR: the ptr given points to NULL
*           MRCC_INVALID_ARG: an invalid input clk src is given
*/
MRCC_enuErrorStatus_t RCC_enuGetClkStatus(MRCC_enuClockSource_t Copy_enuClkSrc,MRCC_enuClockState_t* State_ret)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */
    MRCC_enuClockState_t  Local_enuClkState = MRCC_CLK_OFF ;

    switch(Copy_enuClkSrc)   /*switching to the clk src to be checked*/
    {
        case MRCC_HSI :

        if( IS_MASK_SET((RCC->CR), MASK_HSI_RDY) )  /*checks state of HSI*/
        {
            Local_enuClkState = MRCC_CLK_ON ;
        }
        else
        {
            Local_enuClkState = MRCC_CLK_OFF ;
            
        }

        break;
        case MRCC_HSE:
        if( IS_MASK_SET((RCC->CR), MASK_HSE_RDY) )  /*checks state of HSE*/
        {
             Local_enuClkState = MRCC_CLK_ON ;
        }
        else
        {
            Local_enuClkState = MRCC_CLK_OFF ;
            
        }

        break; 
        case MRCC_PLL: 
        if( IS_MASK_SET((RCC->CR), MASK_PLL_RDY) )  /*checks state of PLL*/
        {
             Local_enuClkState = MRCC_CLK_ON ;
        }
        else
        {
            Local_enuClkState = MRCC_CLK_OFF ;
            
        }

        break;

        default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }
    
    if(State_ret == NULL_PTR) /*checking for NULL ptr before writing*/
    {
        Local_enuErrorStatus = MRCC_NULL_PTR;
    }
    else 
    {
        *State_ret = Local_enuClkState ;
    }
    return Local_enuErrorStatus;

}


/*
* @brief: Enables the specific periphral given for the AHB1 Bus 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_GPIOA,MRCC_GPIOB,MRCC_GPIOC,MRCC_GPIOD,MRCC_GPIOE,MRCC_GPIOH,MRCC_CRC,MRCC_DMA1,MRCC_DMA2                                Controlled by AHB1
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/


MRCC_enuErrorStatus_t RCC_enuEnPeriphalAHB1(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    switch (Copy_enuClkPreph)
    {
        /*switches and enables the periphral*/
        /*GPIO Connected to AHB1*/
    case MRCC_GPIOA    :
            SET_MASK((RCC->AHB1ENR), MASK_GPIOA_EN); /*enables the periphral*/
    break;
    
    case MRCC_GPIOB    :
            SET_MASK((RCC->AHB1ENR), MASK_GPIOB_EN); /*enables the periphral*/
    break;
    
    case MRCC_GPIOC    :
            SET_MASK((RCC->AHB1ENR), MASK_GPIOC_EN); /*enables the periphral*/
    break;
    
    case MRCC_GPIOD    :
            SET_MASK((RCC->AHB1ENR), MASK_GPIOD_EN); /*enables the periphral*/
    break;
    
    case MRCC_GPIOE    :
            SET_MASK((RCC->AHB1ENR), MASK_GPIOE_EN); /*enables the periphral*/
    break;

    case MRCC_GPIOH    :
            SET_MASK((RCC->AHB1ENR), MASK_GPIOH_EN); /*enables the periphral*/
    break;    
    
    /*CRC*/
    case MRCC_CRC    :
            SET_MASK((RCC->AHB1ENR), MASK_CRC_EN); /*enables the periphral*/
    break;

    /*DMA1 & DMA2*/
    case MRCC_DMA1    :
            SET_MASK((RCC->AHB1ENR), MASK_DMA1_EN); /*enables the periphral*/
    break;

    case MRCC_DMA2    :
            SET_MASK((RCC->AHB1ENR), MASK_DMA2_EN); /*enables the periphral*/
    break;

    default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
    break;
    }


    return Local_enuErrorStatus;
}


/*
* @brief: Enables the specific periphral given for the AHB2 Bus (only OTGFS is available) 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_OTGFS                                                                                                                    Controlled by AHB2                                       
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/

MRCC_enuErrorStatus_t RCC_enuEnPeriphalAHB2(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    if(Copy_enuClkPreph == MRCC_OTGFS) /*checks if the periphral is OTGFS*/
    {
        SET_MASK((RCC->AHB2ENR), MASK_OTGFS_EN); /*enables the periphral*/
    }
    else
    {
        Local_enuErrorStatus = MRCC_INVALID_ARG;
    }

    return Local_enuErrorStatus;
}


/*
* @brief: Enables the specific periphral given for the APB1 Bus 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_TIM2,MRCC_TIM3,MRCC_TIM4,MRCC_TIM5,MRCC_WWDG,MRCC_SPI2,MRCC_SPI3,MRCC_USART2,MRCC_I2C1,MRCC_I2C2,MRCC_I2C3,MRCC_PWR      Controlled by APB1
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/


MRCC_enuErrorStatus_t RCC_enuEnPeriphalAPB1(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    switch (Copy_enuClkPreph)
    {
        /*Timers connected to APB1*/
    case MRCC_TIM2    :
            SET_MASK((RCC->APB1ENR), MASK_TIM2_EN); /*enables the periphral*/
    break;

    case MRCC_TIM3    :
            SET_MASK((RCC->APB1ENR), MASK_TIM3_EN); /*enables the periphral*/
    break;

    case MRCC_TIM4    :
            SET_MASK((RCC->APB1ENR), MASK_TIM4_EN); /*enables the periphral*/
    break;

    case MRCC_TIM5    :
            SET_MASK((RCC->APB1ENR), MASK_TIM5_EN); /*enables the periphral*/
    break;

        /*Window Watchdog*/
    case MRCC_WWDG    :
            SET_MASK((RCC->APB1ENR), MASK_WWDG_EN); /*enables the periphral*/
    break;

        /*SPI connected to APB1*/
    case MRCC_SPI2    :
            SET_MASK((RCC->APB1ENR), MASK_SPI2_EN); /*enables the periphral*/
    break;

    case MRCC_SPI3    :
            SET_MASK((RCC->APB1ENR), MASK_SPI3_EN); /*enables the periphral*/   
    break;

        /*USART connected to APB1*/
    case MRCC_USART2    :
            SET_MASK((RCC->APB1ENR), MASK_USART2_EN); /*enables the periphral*/
    break;

        /*I2C connected to APB1*/
    case MRCC_I2C1    :
            SET_MASK((RCC->APB1ENR), MASK_I2C1_EN); /*enables the periphral*/
    break;

    case MRCC_I2C2    :
            SET_MASK((RCC->APB1ENR), MASK_I2C2_EN); /*enables the periphral*/   
    break;

    case MRCC_I2C3    :
            SET_MASK((RCC->APB1ENR), MASK_I2C3_EN); /*enables the periphral*/   
    break;

        /*Power connected to APB1*/
    case MRCC_PWR    :
            SET_MASK((RCC->APB1ENR), MASK_PWR_EN); /*enables the periphral*/    
    break;

    default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }


}

/*
* @brief: Enables the specific periphral given  for the APB2 Bus
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_TIM1,MRCC_USART1,MRCC_USART6,MRCC_ADC1,MRCC_SDIO,MRCC_SPI1,MRCC_SPI4,MRCC_SYSCFG,MRCC_TIM9,MRCC_TIM10,MRCC_TIM11         Controlled by APB2
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/

MRCC_enuErrorStatus_t RCC_enuEnPeriphalAPB2(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    switch (Copy_enuClkPreph)
    {
        /*Timer1 connected to APB2*/
    case MRCC_TIM1    :
            SET_MASK((RCC->APB2ENR), MASK_TIM1_EN); /*enables the periphral*/
    break;
    
        /*USART connected to APB2*/
    case MRCC_USART1    :
            SET_MASK((RCC->APB2ENR), MASK_USART1_EN); /*enables the periphral*/
    break;
        case MRCC_USART6    :
            SET_MASK((RCC->APB2ENR), MASK_USART6_EN); /*enables the periphral*/
    break;
    
        /*ADC connected to APB2*/
    case MRCC_ADC1    :
            SET_MASK((RCC->APB2ENR), MASK_ADC1_EN); /*enables the periphral*/
    break;
    
        /*SDIO connected to APB2*/
        case MRCC_SDIO    :
            SET_MASK((RCC->APB2ENR), MASK_SDIO_EN); /*enables the periphral*/
    break;
    
        /*SPI connected to APB2*/
    case MRCC_SPI1    :
            SET_MASK((RCC->APB2ENR), MASK_SPI1_EN); /*enables the periphral*/
    break;
    case MRCC_SPI4    :
            SET_MASK((RCC->APB2ENR), MASK_SPI4_EN); /*enables the periphral*/
    break;

        /*System Configuration connected to APB2*/
    case MRCC_SYSCFG    :
            SET_MASK((RCC->APB2ENR), MASK_SYSCFG_EN); /*enables the periphral*/ 
    break;
    
        /*Timers connected to APB2*/
    case MRCC_TIM9    :
            SET_MASK((RCC->APB2ENR), MASK_TIM9_EN); /*enables the periphral*/
    break;
    case MRCC_TIM10    :
            SET_MASK((RCC->APB2ENR), MASK_TIM10_EN); /*enables the periphral*/
    break;
    case MRCC_TIM11    :
            SET_MASK((RCC->APB2ENR), MASK_TIM11_EN); /*enables the periphral*/
    break;

    default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }


    return Local_enuErrorStatus;
}

/*
* @brief: Disables the specific periphral given for the AHB1 Bus 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_GPIOA,MRCC_GPIOB,MRCC_GPIOC,MRCC_GPIOD,MRCC_GPIOE,MRCC_GPIOH,MRCC_CRC,MRCC_DMA1,MRCC_DMA2                                Controlled by AHB1
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/


MRCC_enuErrorStatus_t RCC_enuDisPeriphalAHB1(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    switch (Copy_enuClkPreph)
    {
        /*switches and disables the periphral*/
        /*GPIO Connected to AHB1*/
    case MRCC_GPIOA    :
            CLER_MASK((RCC->AHB1ENR), MASK_GPIOA_EN); /*disables the periphral*/
    break;
    
    case MRCC_GPIOB    :
            CLER_MASK((RCC->AHB1ENR), MASK_GPIOB_EN); /*disables the periphral*/
    break;
    
    case MRCC_GPIOC    :
            CLER_MASK((RCC->AHB1ENR), MASK_GPIOC_EN); /*disables the periphral*/
    break;
    
    case MRCC_GPIOD    :
            CLER_MASK((RCC->AHB1ENR), MASK_GPIOD_EN); /*disables the periphral*/
    break;
    
    case MRCC_GPIOE    :
            CLER_MASK((RCC->AHB1ENR), MASK_GPIOE_EN); /*disables the periphral*/
    break;

    case MRCC_GPIOH    :
            CLER_MASK((RCC->AHB1ENR), MASK_GPIOH_EN); /*disables the periphral*/
    break;    
    
    /*CRC*/
    case MRCC_CRC    :
            CLER_MASK((RCC->AHB1ENR), MASK_CRC_EN); /*disables the periphral*/
    break;

    /*DMA1 & DMA2*/
    case MRCC_DMA1    :
            CLER_MASK((RCC->AHB1ENR), MASK_DMA1_EN); /*disables the periphral*/
    break;

    case MRCC_DMA2    :
            CLER_MASK((RCC->AHB1ENR), MASK_DMA2_EN); /*disables the periphral*/
    break;

    default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
    break;
    }


    return Local_enuErrorStatus;
}


/*
* @brief: Disables the specific periphral given for the AHB2 Bus (only OTGFS is available) 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_OTGFS                                                                                                                    Controlled by AHB2                                       
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/

MRCC_enuErrorStatus_t RCC_enuDisPeriphalAHB2(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    if(Copy_enuClkPreph == MRCC_OTGFS) /*checks if the periphral is OTGFS*/
    {
        CLER_MASK((RCC->AHB2ENR), MASK_OTGFS_EN); /*disables the periphral*/
    }
    else
    {
        Local_enuErrorStatus = MRCC_INVALID_ARG;
    }

    return Local_enuErrorStatus;
}


/*
* @brief: Disables the specific periphral given for the APB1 Bus 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_TIM2,MRCC_TIM3,MRCC_TIM4,MRCC_TIM5,MRCC_WWDG,MRCC_SPI2,MRCC_SPI3,MRCC_USART2,MRCC_I2C1,MRCC_I2C2,MRCC_I2C3,MRCC_PWR      Controlled by APB1
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/


MRCC_enuErrorStatus_t RCC_enuDisPeriphalAPB1(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    switch (Copy_enuClkPreph)
    {
        /*Timers connected to APB1*/
    case MRCC_TIM2    :
            CLER_MASK((RCC->APB1ENR), MASK_TIM2_EN); /*disables the periphral*/
    break;

    case MRCC_TIM3    :
            CLER_MASK((RCC->APB1ENR), MASK_TIM3_EN); /*disables the periphral*/
    break;

    case MRCC_TIM4    :
            CLER_MASK((RCC->APB1ENR), MASK_TIM4_EN); /*disables the periphral*/
    break;

    case MRCC_TIM5    :
            CLER_MASK((RCC->APB1ENR), MASK_TIM5_EN); /*disables the periphral*/
    break;

        /*Window Watchdog*/
    case MRCC_WWDG    :
            CLER_MASK((RCC->APB1ENR), MASK_WWDG_EN); /*disables the periphral*/
    break;

        /*SPI connected to APB1*/
    case MRCC_SPI2    :
            CLER_MASK((RCC->APB1ENR), MASK_SPI2_EN); /*disables the periphral*/
    break;

    case MRCC_SPI3    :
            CLER_MASK((RCC->APB1ENR), MASK_SPI3_EN); /*disables the periphral*/   
    break;

        /*USART connected to APB1*/
    case MRCC_USART2    :
            CLER_MASK((RCC->APB1ENR), MASK_USART2_EN); /*disables the periphral*/
    break;

        /*I2C connected to APB1*/
    case MRCC_I2C1    :
            CLER_MASK((RCC->APB1ENR), MASK_I2C1_EN); /*disables the periphral*/
    break;

    case MRCC_I2C2    :
            CLER_MASK((RCC->APB1ENR), MASK_I2C2_EN); /*disables the periphral*/   
    break;

    case MRCC_I2C3    :
            CLER_MASK((RCC->APB1ENR), MASK_I2C3_EN); /*disables the periphral*/   
    break;

        /*Power connected to APB1*/
    case MRCC_PWR    :
            CLER_MASK((RCC->APB1ENR), MASK_PWR_EN); /*disables the periphral*/    
    break;

    default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }


}

/*
* @brief: Disables the specific periphral given  for the APB2 Bus
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_TIM1,MRCC_USART1,MRCC_USART6,MRCC_ADC1,MRCC_SDIO,MRCC_SPI1,MRCC_SPI4,MRCC_SYSCFG,MRCC_TIM9,MRCC_TIM10,MRCC_TIM11         Controlled by APB2
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/

MRCC_enuErrorStatus_t RCC_enuDisPeriphalAPB2(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */

    switch (Copy_enuClkPreph)
    {
        /*Timer1 connected to APB2*/
    case MRCC_TIM1    :
            CLER_MASK((RCC->APB2ENR), MASK_TIM1_EN); /*disables the periphral*/
    break;
    
        /*USART connected to APB2*/
    case MRCC_USART1    :
            CLER_MASK((RCC->APB2ENR), MASK_USART1_EN); /*disables the periphral*/
    break;
        case MRCC_USART6    :
            CLER_MASK((RCC->APB2ENR), MASK_USART6_EN); /*disables the periphral*/
    break;
    
        /*ADC connected to APB2*/
    case MRCC_ADC1    :
            CLER_MASK((RCC->APB2ENR), MASK_ADC1_EN); /*disables the periphral*/
    break;
    
        /*SDIO connected to APB2*/
        case MRCC_SDIO    :
            CLER_MASK((RCC->APB2ENR), MASK_SDIO_EN); /*disables the periphral*/
    break;
    
        /*SPI connected to APB2*/
    case MRCC_SPI1    :
            CLER_MASK((RCC->APB2ENR), MASK_SPI1_EN); /*disables the periphral*/
    break;
    case MRCC_SPI4    :
            CLER_MASK((RCC->APB2ENR), MASK_SPI4_EN); /*disables the periphral*/
    break;

        /*System Configuration connected to APB2*/
    case MRCC_SYSCFG    :
            CLER_MASK((RCC->APB2ENR), MASK_SYSCFG_EN); /*disables the periphral*/ 
    break;
    
        /*Timers connected to APB2*/
    case MRCC_TIM9    :
            CLER_MASK((RCC->APB2ENR), MASK_TIM9_EN); /*disables the periphral*/
    break;
    case MRCC_TIM10    :
            CLER_MASK((RCC->APB2ENR), MASK_TIM10_EN); /*disables the periphral*/
    break;
    case MRCC_TIM11    :
            CLER_MASK((RCC->APB2ENR), MASK_TIM11_EN); /*disables the periphral*/
    break;

    default:
        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    }


    return Local_enuErrorStatus;
}



/*
* @brief: Enables the specific periphral given 
*
* @param: takes an enum type of the available periphrals Copy_enuClkPreph
*
*         possible periphrals to be enabled:
*         MRCC_GPIOA,MRCC_GPIOB,MRCC_GPIOC,MRCC_GPIOD,MRCC_GPIOE,MRCC_GPIOH,MRCC_CRC,MRCC_DMA1,MRCC_DMA2                                Controlled by AHB1              
*         MRCC_OTGFS                                                                                                                    Controlled by AHB2                                       
*         MRCC_TIM2,MRCC_TIM3,MRCC_TIM4,MRCC_TIM5,MRCC_WWDG,MRCC_SPI2,MRCC_SPI3,MRCC_USART2,MRCC_I2C1,MRCC_I2C2,MRCC_I2C3,MRCC_PWR      Controlled by APB1
*         MRCC_TIM1,MRCC_USART1,MRCC_USART6,MRCC_ADC1,MRCC_SDIO,MRCC_SPI1,MRCC_SPI4,MRCC_SYSCFG,MRCC_TIM9,MRCC_TIM10,MRCC_TIM11         Controlled by APB2
*
* @return: returns error status to indicate the success or type of error occured 
*           possible error status for this function: 
*           MRCC_OK: in case of no error and function was able to enable the desired clk src
*           MRCC_INVALID_ARG: an invalid input preph is given
*           
*/

MRCC_enuErrorStatus_t RCC_enuEnPeriphal(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */
    switch (Copy_enuClkPreph)
    {
        /*switches and returns error if given one of the dummy variables*/
    case MRCC_MAX_PERF_AHB1:
    case MRCC_MAX_PERF_AHB2:
    case MRCC_MAX_PERF_APB1:
    case MRCC_MAX_PERF_APB2:

        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    
    default:
        if(Copy_enuClkPreph < MRCC_MAX_PERF_AHB1) /*checks if the periphral is controlled by AHB1*/
        {
            Local_enuErrorStatus = RCC_enuEnPeriphalAHB1(Copy_enuClkPreph); /*enables the periphral*/
        }
        else if(Copy_enuClkPreph < MRCC_MAX_PERF_AHB2) /*checks if the periphral is controlled by AHB2*/
        {
            Local_enuErrorStatus = RCC_enuEnPeriphalAHB2(Copy_enuClkPreph); /*enables the periphral*/
        }
        else if(Copy_enuClkPreph < MRCC_MAX_PERF_APB1) /*checks if the periphral is controlled by APB1*/
        {
           Local_enuErrorStatus =  RCC_enuEnPeriphalAPB1(Copy_enuClkPreph); /*enables the periphral*/
        }
        else if(Copy_enuClkPreph < MRCC_MAX_PERF_APB2) /*checks if the periphral is controlled by APB2*/
        {
           Local_enuErrorStatus =  RCC_enuEnPeriphalAPB2(Copy_enuClkPreph); /*enables the periphral*/
        }
        else
        {
            Local_enuErrorStatus = MRCC_INVALID_ARG;
        }

        break;
    }

    return Local_enuErrorStatus;

    
}

MRCC_enuErrorStatus_t RCC_enuDisPeriphal(MRCC_enuClockPerph_t Copy_enuClkPreph)
{
    MRCC_enuErrorStatus_t Local_enuErrorStatus = MRCC_OK;          /*Local variable to store error status */
    switch (Copy_enuClkPreph)
    {
        /*switches and returns error if given one of the dummy variables*/
    case MRCC_MAX_PERF_AHB1:
    case MRCC_MAX_PERF_AHB2:
    case MRCC_MAX_PERF_APB1:
    case MRCC_MAX_PERF_APB2:

        Local_enuErrorStatus = MRCC_INVALID_ARG;
        break;
    
    default:
        if(Copy_enuClkPreph < MRCC_MAX_PERF_AHB1) /*checks if the periphral is controlled by AHB1*/
        {
            Local_enuErrorStatus = RCC_enuDisPeriphalAHB1(Copy_enuClkPreph); /*enables the periphral*/
        }
        else if(Copy_enuClkPreph < MRCC_MAX_PERF_AHB2) /*checks if the periphral is controlled by AHB2*/
        {
            Local_enuErrorStatus = RCC_enuDisPeriphalAHB2(Copy_enuClkPreph); /*enables the periphral*/
        }
        else if(Copy_enuClkPreph < MRCC_MAX_PERF_APB1) /*checks if the periphral is controlled by APB1*/
        {
           Local_enuErrorStatus =  RCC_enuDisPeriphalAPB1(Copy_enuClkPreph); /*enables the periphral*/
        }
        else if(Copy_enuClkPreph < MRCC_MAX_PERF_APB2) /*checks if the periphral is controlled by APB2*/
        {
           Local_enuErrorStatus =  RCC_enuDisPeriphalAPB2(Copy_enuClkPreph); /*enables the periphral*/
        }
        else
        {
            Local_enuErrorStatus = MRCC_INVALID_ARG;
        }

        break;
    }

    return Local_enuErrorStatus;

}


MRCC_enuErrorStatus_t MRCC_enuSelectClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc)
{

}
