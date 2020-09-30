/********************************************************/
/********************************************************/
/*************		Author: Hatim Saad		*************/
/*************		Layer:  HAL				*************/
/*************		HWC:    CLCD			*************/
/*************		Version:1.0				*************/
/********************************************************/
/********************************************************/

#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H

#define EIGHT_BIT_MODE			0
#define FOUR_BIT_MODE			1

#define CLCD_MODE				EIGHT_BIT_MODE

#define CLCD_CTRL_PORT			PORTB
#define CLCD_RS_PIN				PIN_B0
#define CLCD_RW_PIN				PIN_B1
#define CLCD_E_PIN				PIN_B2

/* D0 to D7 starts from PIN0 to PIN7 order for 8-bit mode */
#define CLCD_DATA_PORT 			DIRECTION_PORT0
/* Only do this for 4-bit mode */
#define CLCD_D4_PIN				PIN_A4
#define CLCD_D5_PIN				PIN_A5
#define CLCD_D6_PIN				PIN_A6
#define CLCD_D7_PIN				PIN_A7

#endif
