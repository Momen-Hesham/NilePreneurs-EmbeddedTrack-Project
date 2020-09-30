/*
 * EXTI.c
 *
 *  Created on: Sep 6, 2020
 *      Author: GAMING
 */
#include "avr/io.h"
#include "../Infra_Structure/AVR_Reg.h"
#include "../Infra_Structure/Common_Macros.h"
#include "../Infra_Structure/Std_Types.h"
#include"EXTI.h"

uint8_t EXTI_Init(Str_EXTI_Configuration_t* INT_Ptr)
{
	switch(INT_Ptr->EXTI_Number)
	{
	case INT_0:
	{
		CLR_BIT(DDRD,2);
		CLR_BIT(SREG,I_BIT);
		SET_BIT(GICR,GICR_INT0);
		switch(INT_Ptr->INT_Sense_Control)
		{
		case INT_FALLING_EDGE:
		{
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
		}break;
		case INT_RISING_EDGE:
		{
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
		}break;

		case INT_LOGICAL_CHANGE:
		{
			CLR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
		}break;

		case INT_LOW_LEVEL:
		{
			CLR_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
		}break;
		default:
			return ERROR_NOK;
		}
		SET_BIT(SREG,I_BIT);
	}break;
	case INT_1:
	{
		CLR_BIT(DDRD,3);
		CLR_BIT(SREG,I_BIT);
		SET_BIT(GICR,GICR_INT1);
		switch(INT_Ptr->INT_Sense_Control)
		{
		case INT_FALLING_EDGE:
		{
			SET_BIT(MCUCR,MCUCR_ISC11);
			CLR_BIT(MCUCR,MCUCR_ISC10);
		}break;
		case INT_RISING_EDGE:
		{
			SET_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
		}break;

		case INT_LOGICAL_CHANGE:
		{
			CLR_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
		}break;

		case INT_LOW_LEVEL:
		{
			CLR_BIT(MCUCR,MCUCR_ISC11);
			CLR_BIT(MCUCR,MCUCR_ISC10);
		}break;
		default:
			return ERROR_NOK;
		}
		SET_BIT(SREG,I_BIT);
	}break;
	case INT_2:
	{
		CLR_BIT(DDRB,2);
		CLR_BIT(SREG,I_BIT);
		SET_BIT(GICR,GICR_INT1);
		switch(INT_Ptr->INT_Sense_Control)
		{
		case INT_FALLING_EDGE:
		{
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
		}break;
		case INT_RISING_EDGE:
		{
			SET_BIT(MCUCSR,MCUCSR_ISC2);
		}break;
		default:
			return ERROR_NOK;
		}
		SET_BIT(SREG,I_BIT);
	}break;
	default:
		return ERROR_NOK;

	}
	return ERROR_OK;


}
