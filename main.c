/*******************************************************************************************************************
 * ADC challenge
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "DIO.h"
#include "Timer.h"
#include "SOS.h"

void fn(void)
{
	DIO_enmFlip(DIO_LED_0_1_2);
}
sint32_t main(void);
sint32_t main(void)
{
	DIO_enmInit();
	Timer_enmInit();
    while(1)
    {
		fn();
		Timer_enmDelayBlocking(TIMER_GENERAL_DELAY, TIMER_PERIOD_1_MILLI_SECOND, 1000);
    }
}
