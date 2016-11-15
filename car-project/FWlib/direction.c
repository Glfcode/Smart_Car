/*****************************************
 * 程序名：direction.c
 * 功能：控制小车的行驶方向
 * 
******************************************/
#include "config.h"

void Go(void)			  //前进
{
	Pwm(0x41);
	Z_IN1 = 0;
	Z_IN2 = 1;
	Y_IN1 = 1;
	Y_IN2 = 0;
}

void Break(void)			//后退
{
	Pwm(0x25);
	Z_IN1 = 1;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 1;
}

void Left(void)			//左转
{
	Z_IN1 = 0;
	Z_IN2 = 0;
	Y_IN1 = 1;
	Y_IN2 = 0;
}

void Right(void)			//右转
{
	Z_IN1 = 0;
	Z_IN2 = 1;
	Y_IN1 = 0;
	Y_IN2 = 0;
}

void Left_break(void)			//左轮后退
{
	Z_IN1 = 1;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 0;
}

void Right_break(void)			//右轮后退
{
	Z_IN1 = 0;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 1;
}

void Stop(void)			//停止
{
	Z_IN1 = 0;
	Z_IN2 = 0;
	Y_IN1 = 0;
	Y_IN2 = 0;
}

