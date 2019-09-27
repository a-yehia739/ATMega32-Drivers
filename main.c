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
    uint8_t x= 0;
	DIO_enmInit();
	DIO_enmWrite(DIO_LED_0_1_2, 0b101u);
	DIO_enmRead(DIO_LED_0_1_2, &x);
	if(x == 0b101u)
	{
		DIO_enmWrite(DIO_LED_3, DIO_LEVEL_HIGH);
	}
    while(1)
    {
    }
}
