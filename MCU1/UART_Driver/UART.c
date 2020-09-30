#include "avr/interrupt.h"
#include "../Infra_Structure/Std_Types.h"
#include "../Infra_Structure/AVR_Reg.h"
#include "../Infra_Structure/Common_Macros.h"
#include "UART.h"
#include "UART_cfg.h"


/*
 * UART.c
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */
volatile uint8_t R_Data;
volatile uint8_t T_Data;


static uint8_t UART_Arr[3];
extern uint8_t UART_init(str_UartConfg_t *uart_config) {

	UART_Arr[0] = uart_config->u32_BaudRate;
	UART_Arr[1] = uart_config->u8_DataBits;
	UART_Arr[2] = uart_config->u8_FlagAction;

	switch (uart_config->u8_DataBits) {
	case UART_5_BIT_MODE:
		SET_BIT(UCSRC, URSEL);
		CLR_BIT(UCSRC, UCSZ0);
		CLR_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
	case UART_6_BIT_MODE:
		SET_BIT(UCSRC, URSEL);
		SET_BIT(UCSRC, UCSZ0);
		CLR_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;

	case UART_7_BIT_MODE:
		SET_BIT(UCSRC, URSEL);
		CLR_BIT(UCSRC, UCSZ0);
		SET_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
	case UART_8_BIT_MODE:
		SET_BIT(UCSRC, URSEL);
		SET_BIT(UCSRC, UCSZ0);
		SET_BIT(UCSRC, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);

		break;
	case UART_9_BIT_MODE:
		SET_BIT(UCSRC, URSEL);
		SET_BIT(UCSRC, UCSZ0);
		SET_BIT(UCSRC, UCSZ1);
		SET_BIT(UCSRB, UCSZ2);

		break;
	default:
		return ERROR_NOK;
	}
	switch ( uart_config->u8_FlagAction) {

	case UART_POLLING:
		SET_BIT(UCSRB, RXEN);
		SET_BIT(UCSRB, TXEN);
		CLR_BIT(UBRRH, URSEL);
		UBRRL = (uint8_t)((((F_CPU) / (16 * UART_Arr[0])) - 1) & 0x000000FF);
		UBRRH = (uint8_t) ( ( ( ( (F_CPU) / (16 * UART_Arr[0])) - 1) & 0x00000F00)>>8 );
		CLR_BIT(UCSRB, RXCIE);
		CLR_BIT(UCSRB, TXCIE);
		CLR_BIT(UCSRB, UDRIE);
		//CLR_BIT(SREG, I);
		break;

	case UART_INTERRUPT:
		SET_BIT(UCSRB, RXEN);
		SET_BIT(UCSRB, TXEN);
		CLR_BIT(UBRRH, URSEL);
		UBRRL = (uint8_t) ( ( ( (F_CPU) / (16 * UART_Arr[0])) - 1) & 0x000000FF);
		UBRRH = (uint8_t) ( ( ( ( (F_CPU) / (16 * UART_Arr[0])) - 1) & 0x00000F00) >>8);
		SET_BIT(UCSRB, RXCIE);
		SET_BIT(UCSRB, TXCIE);
		SET_BIT(UCSRB, UDRIE);
		SET_BIT(SREG, I_BIT);

		break;
	default:
		return ERROR_NOK;
	}
	//SET_BIT(UCSRC,URSEL);
	//CLR_BIT(UCSRC,UMSEL);
	//SET_BIT(UCSRC,USBS);
	//CLR_BIT(UCSRC,UPM0);
	//CLR_BIT(UCSRC,UPM1);

	return ERROR_OK;
}

extern uint8_t UART_sendByte(const uint8_t u8_Data)
{
	switch(UART_Arr[2]){

	case UART_POLLING:

		while(!(BIT_IS_SET(UCSRA,UDRE)) );
		UDR=u8_Data;
		break;

	case UART_INTERRUPT:
		T_Data=u8_Data;
		break;
	default:
		return ERROR_NOK;
	}

	return ERROR_OK;
}

extern uint8_t UART_recieveByte(uint8_t *u8_Data)
{
	switch(UART_Arr[2]){

	case UART_POLLING:

		while(!(BIT_IS_SET(UCSRA,RXC)) );
		*u8_Data=UDR;
		break;

	case UART_INTERRUPT:
		*u8_Data=R_Data;
		break;
	default:
		return ERROR_NOK;
	}

	return ERROR_OK;


}
ISR(USART_UDRE_vect)
{
	UDR=T_Data;

}

ISR(USART_RXC_vect)
{
	R_Data = UDR;
}




