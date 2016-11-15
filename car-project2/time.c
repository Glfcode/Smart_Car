#include <reg52.h>

sbit time=P1^0;

unsigned int t=0;

void time_init(void)
{
	TMOD = 0x01;	//定时器0工作方式1
	TH0 = (65536-10000)/256;
	TL0 = (65536-10000)%256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void main(void)
{
	time_init();
	while(1);
}

void time0() interrupt 1
{
	TH0 = (65536-10000)/256;
	TL0 = (65536-10000)%256;
	t++;
	time = 1;
	if(t == 100)
	{
		t = 0;
		time = 0;
	}
	
}
