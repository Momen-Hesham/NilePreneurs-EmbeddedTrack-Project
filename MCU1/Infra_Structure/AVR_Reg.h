/*
 * AVR_Reg.h
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */

#ifndef DIO_DRIVER_AVR_REG_H_
#define DIO_DRIVER_AVR_REG_H_

#ifndef SREG
#define SREG  *((volatile uint8_t*) 0x5F)
#endif

#ifndef PORTA
#define PORTA *((volatile uint8_t*) 0x3B)
#endif

#ifndef PORTB
#define PORTB *((volatile uint8_t*) 0x38)
#endif

#ifndef PORTC
#define PORTC *((volatile uint8_t*) 0x35)
#endif

#ifndef PORTD
#define PORTD *((volatile uint8_t*) 0x32)
#endif

#ifndef PINA
#define PINA *((volatile uint8_t*) 0x39)
#endif

#ifndef PINB
#define PINB *((volatile uint8_t*) 0x36)
#endif

#ifndef PINC
#define PINC *((volatile uint8_t*) 0x33)
#endif

#ifndef PIND
#define PIND *((volatile uint8_t*) 0x30)
#endif

#ifndef DDRA
#define DDRA *((volatile uint8_t*) 0x3A)
#endif

#ifndef DDRB
#define DDRB *((volatile uint8_t*) 0x37)
#endif

#ifndef DDRC
#define DDRC *((volatile uint8_t*) 0x34)
#endif

#ifndef DDRD
#define DDRD *((volatile uint8_t*) 0x31)
#endif

#define I_BIT	7

#endif /* DIO_DRIVER_AVR_REG_H_ */
