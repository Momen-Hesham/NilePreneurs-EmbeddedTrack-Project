#include "../Infra_Structure/AVR_Reg.h"
#include "../Infra_Structure/Common_Macros.h"
#include "../Infra_Structure/Std_Types.h"
#include "timer_reg.h"
#include "PWM.h"


void PWM_init(void) {

	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	SET_BIT(TCCR0, TCCR0_COM01);
	SET_BIT(TCCR0, TCCR0_CS02);
	SET_BIT(DDRB,3);
	TCNT0 = 0;
	OCR0 = 0;

}

void PWM_Duty_Cycle(unsigned char Duty_Cycle) {
	OCR0 = Duty_Cycle;

}

extern uint8_t PWM_Speed(uint8_t speed) {
	switch (speed) {
	case 0:
		PWM_Duty_Cycle(0);
		break;
	case 1:
		PWM_Duty_Cycle(25);
		break;
	case 2:
		PWM_Duty_Cycle(50);
		break;
	case 3:
		PWM_Duty_Cycle(75);
		break;
	case 4:
		PWM_Duty_Cycle(100);
		break;
	case 5:
		PWM_Duty_Cycle(125);
		break;
	case 6:
		PWM_Duty_Cycle(150);
		break;
	case 7:
		PWM_Duty_Cycle(175);
		break;
	case 8:
		PWM_Duty_Cycle(200);
		break;
	case 9:
		PWM_Duty_Cycle(225);
		break;
	case 10:
		PWM_Duty_Cycle(255);
		break;
	default:
		return ERROR_NOK;

	}
	return ERROR_OK;
}
