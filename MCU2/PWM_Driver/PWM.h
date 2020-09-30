

#ifndef PWM_H_
#define PWM_H_

#ifndef DDRB
#define DDRB *((volatile uint8_t*) 0x37)
#endif

void PWM_init(void);
void PWM_Duty_Cycle(unsigned char Duty_Cycle);
extern uint8_t PWM_Speed(uint8_t speed);
#endif /* PWM_H_ */
