/********************************************************/
/********************************************************/
/*************		Author: Hatim Saad		*************/
/*************		Layer:  HAL				*************/
/*************		HWC:    CLCD			*************/
/*************		Version:1.0				*************/
/********************************************************/
/********************************************************/

#include "../Infra_Structure/Std_Types.h"
#include "../Infra_Structure/Common_Macros.h"
#include <util/delay.h>

#include "../Dio_Driver/DIO.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void CLCD_voidSendCommand(uint8_t Copy_u8Command){
	/* Set RS pin to low for command */
	DIO_u8SetPinValue(CLCD_RS_PIN, DIO_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_RW_PIN, DIO_LOW);

	/*Set command to data pins*/
#if (EIGHT_BIT_MODE==CLCD_MODE)
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);

#elif (FOUR_BIT_MODE==CLCD_MODE)
	DIO_u8SetPinValue(CLCD_D7_PIN, ((Copy_u8Command&0b10000000)>>7));
	DIO_u8SetPinValue(CLCD_D6_PIN, ((Copy_u8Command&0b01000000)>>6));
	DIO_u8SetPinValue(CLCD_D5_PIN, ((Copy_u8Command&0b00100000)>>5));
	DIO_u8SetPinValue(CLCD_D4_PIN, ((Copy_u8Command&0b00010000)>>4));

	/* Send first half Enable pulse */
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_LOW);

	DIO_u8SetPinValue(CLCD_D7_PIN, ((Copy_u8Command&0b00001000)>>3));
	DIO_u8SetPinValue(CLCD_D6_PIN, ((Copy_u8Command&0b00000100)>>2));
	DIO_u8SetPinValue(CLCD_D5_PIN, ((Copy_u8Command&0b00000010)>>1));
	DIO_u8SetPinValue(CLCD_D4_PIN, (Copy_u8Command&0b00000001));

#endif

	/*Send Enable pulse*/
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_LOW);
}

void CLCD_voidSendData(uint8_t Copy_u8Data){
	/* Incrementing Address Counter and Checking Increment to next line */
	Local_u8AddressCounter++;
	if(Local_u8AddressCounter==17){
		CLCD_voidGoToXY(1,1);
	}

	/* Set RS pin to high for data */
	DIO_u8SetPinValue(CLCD_RS_PIN, DIO_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_RW_PIN, DIO_LOW);

#if (EIGHT_BIT_MODE==CLCD_MODE)
	/*Set command to data data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);

#elif (FOUR_BIT_MODE==CLCD_MODE)
	/* Tranfer Data twice in 1 instriction cycle */
	DIO_u8SetPinValue(CLCD_D7_PIN, ((Copy_u8Data&0b10000000)<<7));
	DIO_u8SetPinValue(CLCD_D6_PIN, ((Copy_u8Data&0b01000000)<<6));
	DIO_u8SetPinValue(CLCD_D5_PIN, ((Copy_u8Data&0b00100000)<<5));
	DIO_u8SetPinValue(CLCD_D4_PIN, ((Copy_u8Data&0b00010000)<<4));

	/* Send first half Enable pulse */
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_LOW);

	DIO_u8SetPinValue(CLCD_D7_PIN, ((Copy_u8Data&0b00001000)<<3));
	DIO_u8SetPinValue(CLCD_D6_PIN, ((Copy_u8Data&0b00000100)<<2));
	DIO_u8SetPinValue(CLCD_D5_PIN, ((Copy_u8Data&0b00000010)<<1));
	DIO_u8SetPinValue(CLCD_D4_PIN, (Copy_u8Data&0b00000001));

#endif

	/*Send Enable pulse*/
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_E_PIN, DIO_LOW);
}

void CLCD_voidInit(void){
	/* Initializing Address Counter */
	Local_u8AddressCounter=0;

	/* Start of CLCD Initilization */
	_delay_ms(40);
#if (EIGHT_BIT_MODE==CLCD_MODE)
	/*Function Set command: 2 lines , 5*8 Font Size*/
	CLCD_voidSendCommand(0b00111000);

	/*Function set command: Display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear Display*/
	CLCD_voidSendCommand(0b00000001);

#elif (FOUR_BIT_MODE==CLCD_MODE)
	/*Function Set command: 2 lines , 5*8 Font Size*/
	CLCD_voidSendCommand(0b00100010);
	CLCD_voidSendCommand(0b10000000);

	/*Function set command: Display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b11000000);

	/*Clear Display*/
	DIO_u8SetPinValue( CLCD_D7_PIN, DIO_LOW);
	DIO_u8SetPinValue( CLCD_D6_PIN, DIO_LOW);
	DIO_u8SetPinValue( CLCD_D5_PIN, DIO_LOW);
	DIO_u8SetPinValue( CLCD_D4_PIN, DIO_HIGH);

	DIO_u8SetPinValue( CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue( CLCD_E_PIN, DIO_LOW);

#endif
}

void CLCD_voidSendString(const char* Copy_pcString){
	uint8_t Local_u8StringCounter=0;
	while(Copy_pcString[Local_u8StringCounter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8StringCounter]);
		Local_u8StringCounter++;
	}
}

void CLCD_voidGoToXY(uint8_t Copy_u8XPos, uint8_t Copy_u8YPos){
	/*Accesses DDRAM*/
	uint8_t Local_u8Address=0;
	switch(Copy_u8XPos){
	/*First Line Location*/
	case 0:Local_u8Address=Copy_u8YPos; Local_u8AddressCounter=(Copy_u8YPos-1); break;
	/*Second Line Location*/
	case 1:Local_u8Address=Copy_u8YPos+0x40; Local_u8AddressCounter=0; break;
	}
	/*Set Bit 7 for Set DDRAM Address Command then send Command*/
	CLCD_voidSendCommand(Local_u8Address+127);
}

void CLCD_voidWriteSpecialChar(uint8_t* Copy_pu8Pattern, uint8_t Copy_u8PatternNumber){
	uint8_t Local_u8CGRAMAddress=0;
	uint8_t Local_u8Iterator;

	/*Calculate CGRam Address where each block is 8 byte*/
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;

	/*Send CGRam Address command to LCD, with Set Bit 6*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/*Write Patter on CGRam*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
}

void CLCD_voidDispSpecialChar(uint8_t Copy_u8PatternNumber, uint8_t Copy_u8XPos, uint8_t Copy_u8YPos){
	/*Go Back to DDRam to display Pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display Pattern written in CGRam*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}

void CLCD_voidWriteNumber(uint32_t Copy_u32Number){
	uint8_t Local_u8NumberCounter=0;
	uint8_t Local_u8Iterator=0;
	uint32_t Local_u32NumberPower=10;
	do{
		Local_u8NumberCounter++;
		Local_u8Iterator++;
		Local_u32NumberPower=Local_u32NumberPower*10;
	}while((Copy_u32Number/(Local_u32NumberPower/10))>0);
	do{
		CLCD_voidSendData('0'+((Copy_u32Number/(Local_u32NumberPower/100))%10));
		Local_u8NumberCounter--;
		Local_u32NumberPower/=10;
	}while(Local_u8NumberCounter>0);
}
