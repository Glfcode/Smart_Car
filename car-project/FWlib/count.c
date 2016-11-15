#include "config.h"

/********初始化计数***********/
void Count_Init(void)
{
	TMOD = 0x55;    // 定时器0，1作为计数器
	TH0  = 0;   
	TL0  = 0;
	TH1  = 0;
	TL1  = 0;
	TR0  = 1;      //   打开计数器0，T0 -- P3.4 ,左轮
	TR1  = 1;      //   打开计数器1，T1 -- P3.5 ，右轮
	EA   = 1;      //   开总中断

	Stop();
}

/*************读取计数器0值******************/
uint Count0(void)
{
		uint IN0_num;
	  IN0_num = TH0*256 + TL0;
	  return IN0_num;
}

/*************读取计数器0值******************/
uint Count1(void)
{
		uint IN1_num;
	  IN1_num = TH1*256 + TL1;
	  return IN1_num;
}

/*********清零计数传感器************/
void Count_Clear(void)
{   
	  uint a,b;
	  TR0  = 0;      //   关闭计数器0
	  TR1  = 0;      //   关闭计数器1
	  a = TH0 + TH1;
	  b = TL0 + TL1;
    TH0  = a /2;   
	  TL0  = b /2;
	  TH1  = TH0;
	  TL1  = TL0;
	  TR0  = 1;      //   打开计数器0
	  TR1  = 1;      //   打开计数器1
}

/************光电测速控制小车程序***************/
void Count_direction(uchar num_L,uchar num_R)
{
		uint IN0_L,IN1_R;
	  IN0_L = Count0() + num_L;
	  IN1_R = Count1() + num_R;
	  if(IN0_L == IN1_R)
		{
      Go();
		}
		if(IN0_L > IN1_R)
		{
		  Left();
		}
		if(IN0_L < IN1_R)
		{
			Right();
    }
}