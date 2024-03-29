/*******************************************************************************************************************
 * Timer_cfg.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
#define TIMER_ERROR_DETECT 1
typedef enum
{
    /*......................................................................................*/
    /* name the timer(s) to be used below */
    TIMER_SYSTICK,
    TIMER_GENERAL_DELAY,
    /*......................................................................................*/
    TIMER_NUMBER_OF_TIMERS
}Timer_enmName_t;
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
#endif /* TIMER_CFG_H_ */
