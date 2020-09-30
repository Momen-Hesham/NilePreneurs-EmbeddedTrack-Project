

#include  <avr/interrupt.h>
#include  <avr/io.h>
#include "../Infra_Structure/Common_Macros.h"
#include "../Infra_Structure/Std_Types.h"
#include "../Infra_Structure/AVR_Reg.h"
#include "../PWM_Driver/PWM.h"
#include "../UART_Driver/UART.h"
#include "../UART_Driver/UART_cfg.h"
#include "../LCD_Driver/LCD_interface.h"
#include "../Dio_Driver/DIO.h"
volatile uint8_t R_Data;
char c[]="Duty Cycle = ";


ISR(USART_RXC_vect)
{
	R_Data = UDR;
	PWM_Speed(R_Data);
	CLCD_voidSendCommand(CLEAR_DISPLAY);
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString(c);
	CLCD_voidGoToXY(1,1);
	CLCD_voidWriteNumber(R_Data*10);
	CLCD_voidSendString(" %");

}




int main()
{

	DIO_u8Init_PORT(DIRECTION_PORT0,DIO_OUTPUT);

	DIO_u8Init_PIN(PIN_B0,DIO_OUTPUT);
	DIO_u8Init_PIN(PIN_B1,DIO_OUTPUT);
	DIO_u8Init_PIN(PIN_B2,DIO_OUTPUT);

	str_UartConfg_t Uart_0;

	Uart_0.u8_DataBits=UART_8_BIT_MODE;
	Uart_0.u8_FlagAction=UART_INTERRUPT;
	Uart_0.u32_BaudRate=9600;
	UART_init(&Uart_0);
	PWM_init();
	CLCD_voidInit();



	while(1)
	{}
	return 0;
}

