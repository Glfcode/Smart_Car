#include "exti.h"

unsigned int time_velue = 0;   // �ⲿ�ж�0  ʱ��/S
unsigned char time_flag;

void Exti_Init(void)
{
	EA=1;   
	EX0=1;   
	IT0=1;//�½��ش���,P3.2
	EX1=1;
	IT1=1;//�½��ش���,P3.3
}

/********�ⲿ�ж�0 ******/
void exti0() interrupt 0
{
	time_velue++;
	time_flag = 0;
}

/********�ⲿ�ж�1**********/
void exti1() interrupt 2
{
//     line_velue++;
}
