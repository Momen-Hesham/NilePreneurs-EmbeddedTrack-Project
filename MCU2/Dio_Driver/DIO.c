/*
 * dio.c
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */
#include "avr/io.h"
#include "../Infra_Structure/AVR_Reg.h"
#include "../Infra_Structure/Common_Macros.h"
#include "../Infra_Structure/Std_Types.h"
#include "DIO.h"
#include "Dio_Cfg.h"
//#define NULL 0
#ifndef NULL
#define NULL   ((void *) 0)
#endif
/*______________________________________________________________________________________________*/
/*Description: Set PORT Direction (INPUT or OUTPUT)
 * Input     : Copy_u8PortNB (PORT Number) ,  Copy_u8Dir (PORT Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PORT(uint8_t Copy_u8PortNB,uint8_t Copy_u8Dir)
{
	/* Implement Your Code */
	switch(Copy_u8Dir){
	case DIO_OUTPUT:
		switch(Copy_u8PortNB){
		case DIRECTION_PORT0:DDRA=0xff;break;
		case DIRECTION_PORT1:DDRB=0xff;break;
		case DIRECTION_PORT2:DDRC=0xff;break;
		case DIRECTION_PORT3:DDRD=0xff;break;
		default:return ERROR;
		}
		break;
	case DIO_INPUT:
		switch(Copy_u8PortNB){
		case DIRECTION_PORT0:DDRA=0;break;
		case DIRECTION_PORT1:DDRB=0;break;
		case DIRECTION_PORT2:DDRC=0;break;
		case DIRECTION_PORT3:DDRD=0;break;
		default:return ERROR;
		}
		break;
	default:return ERROR;
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/

/*Description: Set PIN Direction (INPUT or OUTPUT)
 * Input     :Copy_u8PinNB (PIN Number) ,  Copy_u8Dir (PIN Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PIN(uint8_t Copy_u8PinN,uint8_t Copy_u8Dir)
{
	/* Implement Your Code */
	if(Copy_u8PinN > 30){/***************************************************************************************************************************/
		return ERROR;
	}
	if(Copy_u8Dir!=DIO_OUTPUT && Copy_u8Dir!=DIO_INPUT){
		return ERROR;
	}
	if(Copy_u8Dir==DIO_OUTPUT){/*********************************************************************************************************************/
		if(Copy_u8PinN >= PIN_A0  && Copy_u8PinN <= PIN_A7){
			SET_BIT(DDRA,Copy_u8PinN);
		}
		else if(Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7){
			SET_BIT(DDRB,(Copy_u8PinN-8));
		}
		else if(Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7){
			SET_BIT(DDRC,(Copy_u8PinN-16));
		}
		else{
			SET_BIT(DDRD,(Copy_u8PinN-24));
		}
	}
	if(Copy_u8Dir==DIO_INPUT){
		if (Copy_u8PinN >= PIN_A0 && Copy_u8PinN <= PIN_A7) {
			CLR_BIT(DDRA,Copy_u8PinN);
		}
		else if (Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7) {
			CLR_BIT(DDRB,(Copy_u8PinN-8));
		}
		else if (Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7) {
			CLR_BIT(DDRC,(Copy_u8PinN-16));
		}
		else {
			CLR_BIT(DDRD,(Copy_u8PinN-24));
		}
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/

/*Description: Set PORT Value (from 0 to 255)
 * Input     : Copy_u8PortNB (PORT Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortValue(uint8_t Copy_u8PortNB,uint8_t Copy_u8Value)
{
	/* Implement Your Code */
	switch(Copy_u8PortNB){
	case VALUE_PORT0: PORTA=Copy_u8Value; break;
	case VALUE_PORT1: PORTB=Copy_u8Value; break;
	case VALUE_PORT2: PORTC=Copy_u8Value; break;
	case VALUE_PORT3: PORTD=Copy_u8Value; break;
	default: return ERROR;
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Set PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinNB (PIN Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinValue(uint8_t Copy_u8PinN,uint8_t Copy_u8Value)
{
	/* Implement Your Code */
	if(Copy_u8PinN>30){
		return ERROR;
	}
	if(Copy_u8Value!=DIO_LOW&&Copy_u8Value!=DIO_HIGH){
		return ERROR;
	}
	if (Copy_u8Value == DIO_HIGH) {/*********************************************************************************************************************/
		if (Copy_u8PinN >= PIN_A0 && Copy_u8PinN <= PIN_A7) {
			SET_BIT(PORTA, Copy_u8PinN);
		}
		else if (Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7) {
			SET_BIT(PORTB,(Copy_u8PinN - 8));
		}
		else if (Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7) {
			SET_BIT(PORTC,(Copy_u8PinN - 16));
		}
		else {
			SET_BIT(PORTD,(Copy_u8PinN - 24));
		}
	}
	if (Copy_u8Value == DIO_LOW) {
		if (Copy_u8PinN >= PIN_A0 && Copy_u8PinN <= PIN_A7) {
			CLR_BIT(PORTA,(Copy_u8PinN));
		}
		else if (Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7) {
			CLR_BIT(PORTB,(Copy_u8PinN - 8));
		}
		else if (Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7) {
			CLR_BIT(PORTC,(Copy_u8PinN - 16));
		}
		else {
			CLR_BIT(PORTD,(Copy_u8PinN - 24));
		}
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Get PORT Value
 * Input     :  Copy_u8PortNB (PORT Number),*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPortValue(uint8_t Copy_u8PortNB,uint8_t *Copy_u8Value)
{
	/* Implement Your Code */
	if (Copy_u8Value == NULL)
	{
		return ERROR;
	}
	switch(Copy_u8PortNB){
		case VALUE_PORT0:
			*Copy_u8Value = PINA;
			break;
		case VALUE_PORT1:
			*Copy_u8Value = PINB;
			break;
		case VALUE_PORT2:
			*Copy_u8Value = PINC;
			break;
		case VALUE_PORT3:
			*Copy_u8Value = PIND;
			break;
		default:return ERROR;
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Get PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinN (PIN Number) ,*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPinValue(uint8_t Copy_u8PinN,uint8_t *Copy_u8Value)
{
	/* Implement Your Code */
	if (Copy_u8Value == NULL)
	{
		return ERROR;
	}
	if(Copy_u8PinN>30){
		return ERROR;
	}
	if (Copy_u8PinN >= PIN_A0 && Copy_u8PinN <= PIN_A7) {
		*Copy_u8Value=GET_BIT(PINA,Copy_u8PinN);
	}
	else if (Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7) {
		*Copy_u8Value=GET_BIT(PINB,(Copy_u8PinN-8));
	}
	else if (Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7) {
		*Copy_u8Value=GET_BIT(PINC,(Copy_u8PinN-16));
	}
	else{
		*Copy_u8Value=GET_BIT(PIND,(Copy_u8PinN-24));
	}
	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     :  Copy_u8PortNB (PORT Number),Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortInputType(uint8_t Copy_u8PortNB,uint8_t Copy_u8InputType)
{
	/* Implement Your Code */
	switch(Copy_u8InputType){
	case 1:
		switch(Copy_u8InputType){
		case VALUE_PORT0:
		{
			if(DDRA == 0x00)
				PORTA = 0xff;
			else

				return ERROR;
		}break;
		case VALUE_PORT1:
		{
			if (DDRB == 0x00)
				PORTB = 0xff;
			else

				return ERROR;
		}break;
		case VALUE_PORT2:
		{
			if (DDRC == 0x00)
				PORTC = 0xff;
			else

				return ERROR;
		}break;
		case VALUE_PORT3:
		{
			if (DDRD == 0x00)
				PORTD = 0xff;
			else

				return ERROR;
		}break;
		}
		break;
	case 0:
		switch (Copy_u8InputType) {
		case VALUE_PORT0:
		{
			if (DDRA == 0x00)
				PORTA = 0x00;
			else

				return ERROR;
		}break;
		case VALUE_PORT1:
		{
			if (DDRB == 0x00)
				PORTB = 0x00;
			else

				return ERROR;
		}break;
		case VALUE_PORT2:
		{
			if (DDRC == 0x00)
				PORTC = 0x00;
			else

				return ERROR;
		}break;
		case VALUE_PORT3:
		{
			if (DDRD == 0x00)
				PORTD = 0x00;
			else

				return ERROR;
		}break;
		}
		break;
	default:return ERROR;
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     : Copy_u8PinN(PIN NO) ,Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinInputType(uint8_t Copy_u8PinN,uint8_t Copy_u8InputType)
{
	/* Implement Your Code */
	if( Copy_u8PinN>30 ){
		return ERROR;
	}
	if(Copy_u8InputType!=1 && Copy_u8InputType!=0){
		return ERROR;
	}
	if(Copy_u8InputType==1){
		if (Copy_u8PinN >= PIN_A0 && Copy_u8PinN <= PIN_A7) {
			if(!GET_BIT(DDRA,Copy_u8PinN))
				SET_BIT(PORTA,Copy_u8PinN);
			else
				return ERROR;
		}
		else if (Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7) {
			if (!GET_BIT(DDRB,(Copy_u8PinN-8)))
				SET_BIT(PORTB,(Copy_u8PinN-8));
			else
				return ERROR;
		}
		else if (Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7) {
			if (!GET_BIT(DDRC,(Copy_u8PinN - 16)))
				SET_BIT(PORTC,(Copy_u8PinN - 16));
			else
				return ERROR;
		}
		else{
			if (!GET_BIT(DDRD,(Copy_u8PinN - 24)))
				SET_BIT(PORTD,(Copy_u8PinN - 24));
			else
				return ERROR;
		}
	}
	if(Copy_u8InputType==0){
		if (Copy_u8PinN >= PIN_A0 && Copy_u8PinN <= PIN_A7) {
			if (!GET_BIT(DDRA, Copy_u8PinN))
				CLR_BIT(PORTA, Copy_u8PinN);
			else
				return ERROR;
			}
		else if (Copy_u8PinN >= PIN_B0 && Copy_u8PinN <= PIN_B7) {
			if (!GET_BIT(DDRB,(Copy_u8PinN - 8)))
				CLR_BIT(PORTB,(Copy_u8PinN - 8));
			else
				return ERROR;
			}
		else if (Copy_u8PinN >= PIN_C0 && Copy_u8PinN <= PIN_C7) {
			if (!GET_BIT(DDRC,(Copy_u8PinN - 16)))
				CLR_BIT(PORTC,(Copy_u8PinN - 16));
			else
				return ERROR;
		}
		else{
			if (!GET_BIT(DDRD,(Copy_u8PinN - 24)))
				CLR_BIT(PORTD,(Copy_u8PinN - 24));
			else
				return ERROR;
			}
	}
	return NO_ERROR;
}
