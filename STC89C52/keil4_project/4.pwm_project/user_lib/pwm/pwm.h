/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : pwm.h                           *
 **************************************************/
#ifndef _PWM_H_
#define _PWM_H_

#include <reg52.h>

void pwm_enable(char enable);

void pwm_config(unsigned char duty);

#endif
