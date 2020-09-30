/*
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: GAMING
 */

#include  <avr/interrupt.h>
#include <avr/io.h>

#include "../Infra_Structure/Common_Macros.h"
#include "../Infra_Structure/Std_Types.h"
#include "../Infra_Structure/AVR_Reg.h"

#include "../EXTI_Driver/EXTI.h"
#include "../UART_Driver/UART.h"

static uint8_t Mail_Box=0;

ISR(INT0_vect)
{
	if(Mail_Box<10)
	{
		Mail_Box++;
		UART_sendByte(Mail_Box);
	}

}
ISR(INT1_vect)
{
	if(Mail_Box>0)
	{
		Mail_Box--;
		UART_sendByte(Mail_Box);
	}
}


int main()
{
	Str_EXTI_Configuration_t Int_0;
	Str_EXTI_Configuration_t Int_1;
	str_UartConfg_t Uart_0;

	Uart_0.u8_DataBits=UART_8_BIT_MODE;
	Uart_0.u8_FlagAction=UART_POLLING;
	Uart_0.u32_BaudRate=9600;

	Int_0.EXTI_Number=INT_0;
	Int_0.INT_Sense_Control=INT_FALLING_EDGE;

	Int_1.EXTI_Number=INT_1;
	Int_1.INT_Sense_Control=INT_FALLING_EDGE;

	UART_init(&Uart_0);

	EXTI_Init(&Int_0);
	EXTI_Init(&Int_1);

	while(1)
	{}
	return 0;
}
