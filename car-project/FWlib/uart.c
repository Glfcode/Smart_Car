#include <reg52.h>
#include "uart.h"

void uart_init(void)
{
	SCON = 0x50;      //REN=1允许串行接受状态，串口工作模式1    	       	   
	TMOD|= 0x20;      //定时器工作方式2                    
	PCON|= 0x80;                                                          
	//TH1  = 0xFD;     //baud*2  /* reload value 19200、数据位8、停止位1。效验位无 (11.0592) 
	TH1 = 0xF3;		// //baud*2  /*  波特率4800、数据位8、停止位1。效验位无 (12M)
  TL1 = 0xF3;         
	TR1  = 1;                                                             
	ES   = 1;        //开串口中断                  
	EA   = 1;        // 开总中断 
	//IE = 0x0;
	//P2 = 0x00;
}

