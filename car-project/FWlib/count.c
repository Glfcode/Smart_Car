#include "config.h"

/********��ʼ������***********/
void Count_Init(void)
{
	TMOD = 0x55;    // ��ʱ��0��1��Ϊ������
	TH0  = 0;   
	TL0  = 0;
	TH1  = 0;
	TL1  = 0;
	TR0  = 1;      //   �򿪼�����0��T0 -- P3.4 ,����
	TR1  = 1;      //   �򿪼�����1��T1 -- P3.5 ������
	EA   = 1;      //   �����ж�

	Stop();
}

/*************��ȡ������0ֵ******************/
uint Count0(void)
{
		uint IN0_num;
	  IN0_num = TH0*256 + TL0;
	  return IN0_num;
}

/*************��ȡ������0ֵ******************/
uint Count1(void)
{
		uint IN1_num;
	  IN1_num = TH1*256 + TL1;
	  return IN1_num;
}

/*********�������������************/
void Count_Clear(void)
{   
	  uint a,b;
	  TR0  = 0;      //   �رռ�����0
	  TR1  = 0;      //   �رռ�����1
	  a = TH0 + TH1;
	  b = TL0 + TL1;
    TH0  = a /2;   
	  TL0  = b /2;
	  TH1  = TH0;
	  TL1  = TL0;
	  TR0  = 1;      //   �򿪼�����0
	  TR1  = 1;      //   �򿪼�����1
}

/************�����ٿ���С������***************/
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