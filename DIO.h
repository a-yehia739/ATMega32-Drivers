/*******************************************************************************************************************
 * DIO.h
 *
 * Created: 9/2019
 * Author:  Ahmed Yehia
 *******************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_
/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "CommonHeaders.h"
#include "DIO_cfg.h"
/*******************************************************************************************************************
 * definition(s)
 *******************************************************************************************************************/
typedef enum
{
    DIO_OK,
    DIO_NOT_OK
}DIO_enmStatus_t;
typedef enum
{
    DIO_PORT_A,
    DIO_PORT_B,
    DIO_PORT_C,
    DIO_PORT_D
}DIO_enmPortNumber_t;
typedef enum
{
    DIO_PIN_0 = (0x01u),
    DIO_PIN_1 = (0x02u),
    DIO_PIN_2 = (0x04u),
    DIO_PIN_3 = (0x08u),
    DIO_PIN_4 = (0x10u),
    DIO_PIN_5 = (0x20u),
    DIO_PIN_6 = (0x40u),
    DIO_PIN_7 = (0x80u)
}DIO_enmPinNumber_t;
typedef enum
{
    DIO_DIRECTION_IN = (0x00u),
    DIO_DIRECTION_OUT = (0xFFu)
}DIO_enmDirection_t;

#define DIO_LEVEL_LOW               (0u)
#define DIO_LEVEL_HIGH              ((uint8_t)(~0u))

#define DIO_NUMBER_OF_PORT_PINS     (8u)
/*******************************************************************************************************************
 * type definition(s)
 *******************************************************************************************************************/
typedef struct 
{
    DIO_enmPortNumber_t m_enmPortNumber;
    uint8_t m_u8Mask;
    DIO_enmDirection_t m_enmDirection;
}DIO_strConfiguration_t;
typedef struct
{
    volatile uint8_t *m_u8PortRegister_ptr;
    volatile const uint8_t *m_u8PinRegister_ptr;
    volatile uint8_t *m_u8DirectionRegister_ptr;
    volatile uint8_t m_u8LeastSignificantPinNumber;
}DIO_strPrivateConfiguration_t;
/*******************************************************************************************************************
 * external variable(s)
 *******************************************************************************************************************/
extern const DIO_strConfiguration_t DIO_strConfiguration_arr[DIO_NUMBER_OF_PINS];
/*******************************************************************************************************************
 * external function prototype(s)
 *******************************************************************************************************************/
extern DIO_enmStatus_t DIO_enmInit(void);
extern DIO_enmStatus_t DIO_enmRead(DIO_enmName_t a_enmName, uint8_t *a_u8Value_ptr);
extern DIO_enmStatus_t DIO_enmWrite(DIO_enmName_t a_enmName, uint8_t a_u8Value);
extern DIO_enmStatus_t DIO_enmFlip(DIO_enmName_t a_enmName);
#endif /* DIO_H_ */
