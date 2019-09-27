/*******************************************************************************************************************
 * DIO.c
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "DIO.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
static DIO_strPrivateConfiguration_t DIO_strPrivateConfiguration_arr[DIO_NUMBER_OF_PINS];
/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*..................................................................................
 * name:                DIO_Init
 * description:         initialize all global variables of the DIO module
 * sync/async:          synchronous
 * reentrancy:          non reentrant
 * parameters (in):     none
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern DIO_enmStatus_t DIO_enmInit(void)
{
    uint8_t Init_l_u8Counter;
    uint8_t Init_l_u8Counter2;

    DIO_enmStatus_t Init_l_enmReturnValue = DIO_OK;
    /*........................................*/
    /*
     * error checking
     */
#if(DIO_ERROR_DETECT == 1)
    /* check for any error */

    /* report the error if any */
    if(Init_l_enmReturnValue != DIO_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (DIO_ERROR_DETECT == 1) */
    /*........................................*/
    {
        for(Init_l_u8Counter = 0u; Init_l_u8Counter < DIO_NUMBER_OF_PINS; Init_l_u8Counter++)
        {
            switch(DIO_strConfiguration_arr[Init_l_u8Counter].m_enmPortNumber)
            {
            case DIO_PORT_A:
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PortRegister_ptr = (uint8_t *)PORTA_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PinRegister_ptr = (uint8_t *)PINA_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8DirectionRegister_ptr = (uint8_t *)DDRA_REG_ADDR;
                break;
            case DIO_PORT_B:
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PortRegister_ptr = (uint8_t *)PORTB_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PinRegister_ptr = (uint8_t *)PINB_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8DirectionRegister_ptr = (uint8_t *)DDRB_REG_ADDR;
                break;
            case DIO_PORT_C:
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PortRegister_ptr = (uint8_t *)PORTC_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PinRegister_ptr = (uint8_t *)PINC_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8DirectionRegister_ptr = (uint8_t *)DDRC_REG_ADDR;
                break;
            case DIO_PORT_D:
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PortRegister_ptr = (uint8_t *)PORTD_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8PinRegister_ptr = (uint8_t *)PIND_REG_ADDR;
                DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8DirectionRegister_ptr = (uint8_t *)DDRD_REG_ADDR;
                break;
            default:
                /* do nothing */
                break;
            }
            WRITE_REG(
                      uint8_t,
                      *(DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8DirectionRegister_ptr),
                      DIO_strConfiguration_arr[Init_l_u8Counter].m_u8Mask,
                      DIO_strConfiguration_arr[Init_l_u8Counter].m_enmDirection
                     );
            DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8LeastSignificantPinNumber = 0u;
            for(Init_l_u8Counter2 = 0u; Init_l_u8Counter2 < DIO_NUMBER_OF_PORT_PINS; Init_l_u8Counter2++)
            {
                if((DIO_strConfiguration_arr[Init_l_u8Counter].m_u8Mask & ((uint8_t)((uint8_t)1u << Init_l_u8Counter2))) != 0u)
                {
                    if(DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8LeastSignificantPinNumber == 0u)
                    {
                        DIO_strPrivateConfiguration_arr[Init_l_u8Counter].m_u8LeastSignificantPinNumber = (uint8_t)Init_l_u8Counter2;
                    }
                }
            }
        }
    }
    return Init_l_enmReturnValue;
}
/*..................................................................................
 * name:                DIO_ReadPin
 * description:         return the value of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     a_enmPinName        =>  pin ID, where the pins in all ports
 *                                          are serializes
 * parameters (inout):  none
 * parameters (out):    none
 * return:              value of a specified pin
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern DIO_enmStatus_t DIO_enmRead(DIO_enmName_t a_enmName, uint8_t *a_u8Value_ptr)
{
    DIO_enmStatus_t Read_l_enmReturnValue = DIO_OK;
    /*........................................*/
    /*
     * error checking
     */
#if(DIO_ERROR_DETECT == 1)
    /* check for any error */

    /* report the error if any */
    if(Read_l_enmReturnValue != DIO_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (DIO_ERROR_DETECT == 1) */
    /*........................................*/
    {
        *(a_u8Value_ptr) = READ_REG(
                                    uint8_t,
                                    *(DIO_strPrivateConfiguration_arr[a_enmName].m_u8PinRegister_ptr),
                                    DIO_strConfiguration_arr[a_enmName].m_u8Mask
                                   );
        *(a_u8Value_ptr) >>= (DIO_strPrivateConfiguration_arr[a_enmName].m_u8LeastSignificantPinNumber);
    }
    return Read_l_enmReturnValue;
}
/*..................................................................................
 * name:                DIO_WritePin
 * description:         set the level of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     PinNum          =>  pin ID, where the pins in all ports
 *                                          are serializes
                        PinValue        =>  low or high
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern DIO_enmStatus_t DIO_enmWrite(DIO_enmName_t a_enmName, uint8_t a_u8Value)
{
    DIO_enmStatus_t Write_l_enmReturnValue = DIO_OK;
    /*........................................*/
    /*
     * error checking
     */
#if(DIO_ERROR_DETECT == 1)
    /* check for any error */

    /* report the error if any */
    if(Write_l_enmReturnValue != DIO_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (DIO_ERROR_DETECT == 1) */
    /*........................................*/
    {
        WRITE_REG(
                  uint8_t,
                  *(DIO_strPrivateConfiguration_arr[a_enmName].m_u8PortRegister_ptr),
                  DIO_strConfiguration_arr[a_enmName].m_u8Mask,
                  (uint8_t)(a_u8Value << DIO_strPrivateConfiguration_arr[a_enmName].m_u8LeastSignificantPinNumber)
                 );
    }
    return Write_l_enmReturnValue;
}
/*..................................................................................
 * name:                DIO_FlipPin
 * description:         flip the level of a specified pin
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     PinNum          =>  pin ID, where the pins in all ports
 *                                          are serializes
 * parameters (inout):  none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern DIO_enmStatus_t DIO_enmFlip(DIO_enmName_t a_enmName)
{
    DIO_enmStatus_t Flip_l_enmReturnValue = DIO_OK;
    /*........................................*/
    /*
     * error checking
     */
#if(DIO_ERROR_DETECT == 1)
    /* check for any error */

    /* report the error if any */
    if(Flip_l_enmReturnValue != DIO_OK)
    {
        DET_vReportError();
    }
    else
#endif /* (DIO_ERROR_DETECT == 1) */
    /*........................................*/
    {
        WRITE_REG(
                  uint8_t,
                  *(DIO_strPrivateConfiguration_arr[a_enmName].m_u8PortRegister_ptr),
                  DIO_strConfiguration_arr[a_enmName].m_u8Mask,
                  (*(DIO_strPrivateConfiguration_arr[a_enmName].m_u8PortRegister_ptr)) ^ 1u
                 );
    }
    return Flip_l_enmReturnValue;
}
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
