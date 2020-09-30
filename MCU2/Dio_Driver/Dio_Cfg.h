/*
 * Dio_Cfg.h
 *
 *  Created on: Sep 1, 2020
 *      Author: GAMING
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*
Define DIO Registers for ATMEGA32
________________________________________________________________________
*/

#define NO_OF_PORTS  4                                //define no of ports
#define TOTAL_NO_OF_PINS  32                          //define no of pins in all ports
#define MINIMUM_PIN_NO 0                              //start of pin no
#define MAX_PIN_NO 31                                 //End of pin ni
//___________________________________________________________________________________________________
//____________DDR(DIRECTION)_________________________________________________________________________

#define DIRECTION_PORT0 0        //define direction of first port
#define DIRECTION_PORT1 1              //define direction of second port
#define DIRECTION_PORT2 2              //define direction of third port
#define DIRECTION_PORT3 3              //define direction of fourth port

//____________________________________________________________________________________________________

//____________________________________________________________________________________________________
//____________Value of Port___________________________________________________________________________

#define VALUE_PORT0 0
#define VALUE_PORT1 1
#define VALUE_PORT2 2
#define VALUE_PORT3 3
//____________________________________________________________________________________________________

//___________________________________________________________________________________________________
//__________Read Value from Port______________________________________________________________________
#define READ_PORT0 0                //Read Value from Port A
#define READ_PORT1 1                 //Read Value from Port B
#define READ_PORT2 2                 //Read Value from Port C
#define READ_PORT3 3                 //Read Value from Port D
//_____________________________________________________________________________________________________


//____________________________________________________________________________________________________
//__________PIN No.___________________________________________________________________________________
#define PIN_A3	3
#define PIN_A0	0
#define PIN_A1	1
#define PIN_A2	2
#define PIN_A4	4
#define PIN_A5	5
#define PIN_A6	6
#define PIN_A7	7

#define PIN_B0	8
#define PIN_B1	9
#define PIN_B2	10
#define PIN_B3	11
#define PIN_B4	12
#define PIN_B5	13
#define PIN_B6	14
#define PIN_B7	15

#define PIN_C0	16
#define PIN_C1	17
#define PIN_C2	18
#define PIN_C3	19
#define PIN_C4	20
#define PIN_C5	21
#define PIN_C6	22
#define PIN_C7	23

#define PIN_D0	24
#define PIN_D1	25
#define PIN_D2	26
#define PIN_D3	27
#define PIN_D4	28
#define PIN_D5	29
#define PIN_D6	30



#endif /* DIO_CFG_H_ */
