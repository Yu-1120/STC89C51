#ifndef __LED_OUT
#define __LED_OUT

#include "stc12.h"
#include "8052.h"

void led_pwm_out();
void led_out();
void ztim(void) __interrupt 1;

#endif
