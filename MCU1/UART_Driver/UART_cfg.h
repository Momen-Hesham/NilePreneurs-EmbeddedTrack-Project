/*
 * UART_cfg.h
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */

#ifndef UART_DRIVER_UART_CFG_H_

#ifndef UDR
#define UDR *((volatile uint8_t*)0x2C)
#endif

#ifndef UCSRA
#define UCSRA *((volatile uint8_t *)0x2B)
#endif

#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define PE 2
#define U2X 1
#define MPCM 0

#ifndef UCSRB
#define UCSRB *((volatile uint8_t *)0x2A)
#endif

#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define TXB8 0

#ifndef UCSRC
#define UCSRC *((volatile uint8_t *)0x40)
#endif

#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0

#ifndef UBRRH
#define UBRRH *((volatile uint8_t *)0x40)
#endif

#define URSEL 7

#ifndef UBRRL
#define UBRRL *((volatile uint8_t *)0x29)
#endif


#define UART_DRIVER_UART_CFG_H_



#endif /* UART_DRIVER_UART_CFG_H_ */
