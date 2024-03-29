/*******************************************************************************************************************
 * CPU.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "CPU.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*......................................................................................
 * name:                CPU_enmSleep
 * description:         makes the MCU enter Idle mode, stopping the CPU but
 *						allowing SPI, USART, Analog Comparator, ADC,
 *						Two-wire Serial Interface, Timer/Counters, Watchdog,
 *						and the interrupt system to continue operating.
 *						Idle mode enables the MCU to wake up from external triggered
 *						interrupts as well as internal ones like the Timer Overflow
 *						and USART Transmit Complete interrupts.
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              function status
 * remarks:             none
 * example:             none
 *......................................................................................*/
CPU_enmStatus_t CPU_enmSleep(void)
{
    CPU_enmStatus_t Sleep_l_enmReturnValue = CPU_OK;
    /*........................................*/
#if(CPU_ERROR_DETECT == 1)
    /* check for any error */

    /* report the error if any */
    if(Sleep_l_enmReturnValue != CPU_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (CPU_ERROR_DETECT == 1) */
    /*........................................*/
    {
        /* IDLE mode */
        CLEAR_BIT(uint8_t, REG(volatile uint8_t*, MCUCR_REG_ADDR), SM0_BIT);
        CLEAR_BIT(uint8_t, REG(volatile uint8_t*, MCUCR_REG_ADDR), SM1_BIT);
        CLEAR_BIT(uint8_t, REG(volatile uint8_t*, MCUCR_REG_ADDR), SM2_BIT);
        /* enable sleep mode */
        SET_BIT(uint8_t, REG(volatile uint8_t*, MCUCR_REG_ADDR), SE_BIT);
    }
    return Sleep_l_enmReturnValue;
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
