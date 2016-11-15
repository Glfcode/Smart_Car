#include "config.h"
	
void Pwm_Init(void)
{
	CCON = 0;
	CMOD = 0x02;
	CL = 0x00;
	CH = 0x00;
	CCAP1L = 0x38;
	CCAP1H = 0x38;  //pwm1,P1.4
	CCAP0L = 0x38;  //pwm0,p1.3
	CCAP0H = 0x38;  //越大低电平时间越久
	CCAPM0 = 0x42;
	CCAPM1 = 0x42;
	CR = 1;	
}

void Pwm(uint x)
{
	CCAP1L = x;
	CCAP1H = x;  //pwm1,P1.4
	CCAP0L = x;  //pwm0,p1.3
	CCAP0H = x;  //越大低电平时间越久
}