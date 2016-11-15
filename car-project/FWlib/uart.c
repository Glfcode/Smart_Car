#include <reg52.h>
#include "uart.h"

void uart_init(void)
{
	SCON = 0x50;      //REN=1�����н���״̬�����ڹ���ģʽ1    	       	   
	TMOD|= 0x20;      //��ʱ��������ʽ2                    
	PCON|= 0x80;                                                          
	//TH1  = 0xFD;     //baud*2  /* reload value 19200������λ8��ֹͣλ1��Ч��λ�� (11.0592) 
	TH1 = 0xF3;		// //baud*2  /*  ������4800������λ8��ֹͣλ1��Ч��λ�� (12M)
  TL1 = 0xF3;         
	TR1  = 1;                                                             
	ES   = 1;        //�������ж�                  
	EA   = 1;        // �����ж� 
	//IE = 0x0;
	//P2 = 0x00;
}

