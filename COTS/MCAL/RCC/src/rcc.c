

#include "STD_TYPES.h"
#include "rcc.h"
#include "rcc_priv.h"
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

MRCC_enuErrorStatus_t MRCC_enuSelectClkSRC(MRCC_enuClockSource_t Copy_enuClkSrc)
{

}