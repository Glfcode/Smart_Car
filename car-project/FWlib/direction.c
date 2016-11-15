/*****************************************
 * ��������direction.c
 * ���ܣ�����С������ʻ����
 * 
******************************************/
#include "config.h"

void Go(void)			  //ǰ��
{
	Pwm(0x41);
	Z_IN1 = 0;
	Z_IN2 = 1;
	Y_IN1 = 1;
	Y_IN2 = 0;
}

void Break(void)			//����
{
	Pwm(0x25);
	Z_IN1 = 1;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 1;
}

void Left(void)			//��ת
{
	Z_IN1 = 0;
	Z_IN2 = 0;
	Y_IN1 = 1;
	Y_IN2 = 0;
}

void Right(void)			//��ת
{
	Z_IN1 = 0;
	Z_IN2 = 1;
	Y_IN1 = 0;
	Y_IN2 = 0;
}

void Left_break(void)			//���ֺ���
{
	Z_IN1 = 1;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 0;
}

void Right_break(void)			//���ֺ���
{
	Z_IN1 = 0;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 1;
}

void Stop(void)			//ֹͣ
{
	Z_IN1 = 0;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 0;
}

