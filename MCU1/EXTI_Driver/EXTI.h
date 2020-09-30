/*
 * EXTI.h
 *
 *  Created on: Sep 6, 2020
 *      Author: GAMING
 */

#ifndef EXTI_DRIVER_EXTI_H_
#define EXTI_DRIVER_EXTI_H_

#include "../Infra_structure/AVR_Reg.h"
#include "../Infra_structure/Common_Macros.h"
#include "../Infra_structure/Std_Types.h"
#include "EXTI_cfg.h"

typedef struct
{
  uint8_t EXTI_Number; 			/*INT0, INT1, or INT2*/
  uint8_t INT_Sense_Control;     /*rising edge, falling edge, low level, or any logical change*/
}Str_EXTI_Configuration_t;

uint8_t EXTI_Init(Str_EXTI_Configuration_t* INT_ptr);

#define ERROR_OK     0
#define ERROR_NOK    1
#ifndef MCUCR

#define MCUCR			*((volatile uint8_t *) 0x55)
#endif
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3
#ifndef MCUCSR

#define MCUCSR			*((volatile uint8_t *) 0x54)
#endif
#define MCUCSR_ISC2		6
#ifndef GICR

#define GICR			*((volatile uint8_t *) 0x5B)
#endif
#define GICR_INT2		5
#define GICR_INT0		6
#define GICR_INT1		7
#ifndef GIFR

#define GIFR			*((volatile uint8_t *) 0x5A)
#endif
#define GIFR_INTF2		5
#define GIFR_INTF0		6
#define GIFR_INTF1		7

#endif /* EXTI_DRIVER_EXTI_H_ */
