/********************************************************/
/********************************************************/
/*************		Author: Hatim Saad		*************/
/*************		Layer:  HAL				*************/
/*************		HWC:    CLCD			*************/
/*************		Version:1.0				*************/
/********************************************************/
/********************************************************/

#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define CLEAR_DISPLAY 1

void CLCD_voidInit(void);

void CLCD_voidSendCommand(uint8_t Copy_u8Command);

void CLCD_voidSendData(uint8_t Copy_u8Data);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidWriteNumber(uint32_t Copy_u32Number);

void CLCD_voidGoToXY(uint8_t Copy_u8XPos, uint8_t Copy_u8YPos);

/* Copy_u8PatternNumber must be between 0 and 7 */
void CLCD_voidWriteSpecialChar(uint8_t* Copy_pu8Pattern, uint8_t Copy_u8PatternNumber);

void CLCD_voidDispSpecialChar(uint8_t Copy_u8PatternNumber, uint8_t Copy_u8XPos, uint8_t Copy_u8YPos);

#endif
