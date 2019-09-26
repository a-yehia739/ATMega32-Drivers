/*******************************************************************************************************************
 * CommonMacros.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 * note:    This file violates MISRA rule (19.7/A)
 *          "A function should be used in preference to a function-like macro"
 *          in order to achieve faster running-time performance
 *******************************************************************************************************************/
#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include"StandardTypes.h"
/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
#define REG(TYPE, ADDR)                     ((*(volatile (TYPE) *) (ADDR)))

#define GET_BIT(TYPE, REG, BIT)             ((TYPE)((REG) >> (BIT)) & 1u)
#define SET_BIT(TYPE, REG, BIT)             ((REG) |= (TYPE)(1u << (BIT)))
#define CLEAR_BIT(TYPE, REG, BIT)           ((REG) &= (TYPE)(~(TYPE)(1u << (BIT))))
#define TOGGLE_BIT(TYPE, REG, BIT)          ((REG) ^= (TYPE)(1u << (BIT)))

#define WRITE_REG(TYPE, REG, MASK, VALUE)   ((REG) = ((REG) & (TYPE)(~(MASK))) | ((VALUE) & (MASK)))
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
#endif /* COMMONMACROS_H_ */
