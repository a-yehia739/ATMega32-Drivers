/*******************************************************************************************************************
 * ADC challenge
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "DIO.h"

sint32_t main(void);
sint32_t main(void)
{
    DIO_enmWrite(DIO_LED_0, DIO_LEVEL_HIGH);
    while(1)
    {
    }
}
