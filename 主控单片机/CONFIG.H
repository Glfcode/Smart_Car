#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "STC12C5A60S2.h"
#include "direction.h"
#include "12864.h"

#define uint unsigned int
#define uchar unsigned char

sbit Left_L = P1^0;			//左侧左边红外循迹
sbit Left_R = P1^1;			//左侧右边红外循迹
sbit Right_L = P1^6;		//右侧左边红外循迹
sbit Right_R = P1^7;		//右侧右边红外循迹

sbit BAR_LL = P2^2;			//左侧左边红外壁障
sbit BAR_LR = P2^7;			//左侧右边红外壁障
sbit BAR_RL = P3^6;			//右侧左边红外壁障
sbit BAR_RR = P3^7;			//右侧右边红外壁障


extern void Go(void);					//前进
extern void Break(void);			//后退
extern void Left(void);				//左转
extern void Right(void);			//右转
extern void Left_break(void);	//左轮后退
extern void Right_break(void);	//右轮后退
extern void Stop(void);				//停车

extern void Pwm_Init(void);		//PWM初始化
extern void Pwm(uint x);			//PWM速度设置 x的值越小速度越快

//extern void Count_Init(void);		//计数器初始化
//extern uint Count0(void);				//读取计数器0值
//extern uint Count1(void);				//读取计数器1值
//extern void Count_Clear(void);	//计数器清零
//extern void Count_direction(uchar num_L,uchar num_R);		//控制小车行驶方向



#endif
