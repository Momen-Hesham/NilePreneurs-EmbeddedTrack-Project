/*
 * timer_reg.h
 *
 *  Created on: Sep 1, 2020
 *      Author: Hatim Zaghloul
 */

#ifndef TIMER_DRIVER_TIMER_REG_H_
#define TIMER_DRIVER_TIMER_REG_H_
 #define ERROR_OK     0
#define ERROR_NOK    1
#define Sreg *((volatile uint8_t*) 0x5F)
#define C 0
#define Z 1
#define N 2
#define V 3
#define S 4
#define H 5
#define T 6
#define I 7

#define TCCR0 *((volatile uint8_t*) 0x53)
#define TCCR0_CS00 0
#define TCCR0_CS01 1
#define TCCR0_CS02 2
#define TCCR0_WGM01 3
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_WGM00 6
#define TCCR0_FOC0 7

#define TCNT0 *((volatile uint8_t*) 0x52)

#define OCR0 *((volatile uint8_t*) 0x5C)

#define TIMSK *((volatile uint8_t*) 0x59)
#define TIMSK_TOIE0 0
#define TIMSK_OCIE0 1
#define TIMSK_TOIE1 2
#define TIMSK_OCIE1B 3
#define TIMSK_OCIE1A 4
#define TIMSK_TICIE1 5
#define TIMSK_TOIE2 6
#define TIMSK_OCIE2 7

#define TIFR *((volatile uint8_t*) 0x58)
#define TIFR_TOV0 0
#define TIFR_OCF0 1
#define TIFR_TOV1 2
#define TIFR_OCF1B 3
#define TIFR_OCF1A 4
#define TIFR_ICF1 5
#define TIFR_TOV2 6
#define TIFR_OCF2 7

#define TCCR1A *((volatile uint8_t*) 0x4F)
#define TCCR1A_WGM10 0
#define TCCR1A_WGM11 1
#define TCCR1A_FOC1B 2
#define TCCR1A_FOC1A 3
#define TCCR1A_COM1B0 4
#define TCCR1A_COM1B1 5
#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7

#define TCCR1B *((volatile uint8_t*) 0x4E)
#define TCCR1B_ICNC1 7
#define TCCR1B_ICES1 6
#define TCCR1B_WGM13 4
#define TCCR1B_WGM12 3
#define TCCR1B_CS12 2
#define TCCR1B_CS11 1
#define TCCR1B_CS10 0

#define TCNT1H *((volatile uint8_t*) 0x4D)
#define TCNT1L *((volatile uint8_t*) 0x4C)

#define OCR1BH *((volatile uint8_t*) 0x49)
#define OCR1BL *((volatile uint8_t*) 0x48)

#define ICR1H *((volatile uint8_t*) 0x47)
#define ICR1L *((volatile uint8_t*) 0x46)

#define TCCR2 *((volatile uint8_t*) 0x45)
#define TCCR2_CS20 0
#define TCCR2_CS21 1
#define TCCR2_CS22 2
#define TCCR2_WGM21 3
#define TCCR2_COM20 4
#define TCCR2_COM21 5
#define TCCR2_WGM20 6
#define TCCR2_FOC2 7

#define TCNT2 *((volatile uint8_t*) 0x44)

#define OCR2 *((volatile uint8_t*) 0x43)

#define ASSR *((volatile uint8_t*) 0x42)
#define ASSR_TCR2UB 0
#define ASSR_OCR2UB 1
#define ASSR_TCN2UB 2
#define ASSR_AS2 3

#define SFIOR *((volatile uint8_t*) 0x50)
#define SFIOR_PSR2 1

#endif /* TIMER_DRIVER_TIMER_REG_H_ */
