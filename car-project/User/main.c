#include "config.h"  
#include "uart.h"
#include "exti.h"

unsigned char a;  
unsigned int Count_old,Count_new,n,s;

void display_12864(uint time ,uint line);   //12864Һ����ʾʱ���·��
//void delay_car(unsigned int z);

void main(void)
{
	LCD12864_Init();				//12864Һ����ʼ��
	Pwm_Init();							//PWM��ʼ��
	Exti_Init();						//�ⲿ�жϳ�ʼ��
	Count_Init();
	while(1)
	{
		switch(a)
		{
			case 0 :
				Count_Clear();
				a++;
			break;
			
			case 1 :
				if((Right_L == 0) && (Right_R == 0) 
				 && (Left_L == 0) && (Left_R == 0)) 
				{
					a = 2;
				}
				if((Right_L == 1) || (Right_R == 1))
				{
					a = 5;
					Count_old = Count1;
				}
				if((Left_L == 1) || (Left_R == 1))
				{
					a = 6;
					Count_old = Count0;
				}
				if(((Right_L == 1) || (Right_R == 1)) 
				 && ((Left_L == 1) || (Left_R == 1))) 
				{
					Stop();
					time_flag = 1;
					while(1);
				}
			break;
				
			case 2 :
				if((BAR_LL == 1) && (BAR_LR == 1) 
				   && (BAR_RL == 1) && (BAR_RR == 1))			
				{
				  Count_direction(0,0);
					a = 1;     
        }					
				if((BAR_LR == 0) || (BAR_RR == 0)) 				
				{
					a = 3;       
        }
				if((BAR_RL == 0) || (BAR_LL == 0))            
				{
					a = 4;      
        }					
		 	break;
				
			case 3 :            
			Count_direction(80,0);
        a = 0;			
			break;
			
			case 4 :
			 Count_direction(0,80); 
			  a = 0;
			break;
			
			case 5 :             
				Left_break();   
			  Count_new = Count0();   
			  n = Count_new - Count_old;
			  if(n > 10)
				{
					if((BAR_RR == 1) && (BAR_RL == 1) 
				    && (BAR_LR == 1) && (BAR_LL == 1))
					{
            a = 0;
          }
        }	  
			break;
				
			case 6 :
			  Right_break();   
			  Count_new = Count1();    
			  n = Count_new - Count_old;
			  if(n > 10)
				{
					if((BAR_RR == 1) && (BAR_RL == 1) 
				      && (BAR_LR == 1) && (BAR_LL == 1))
					{
            a = 0;
          }
        }
			break;
				
			default:
			break;	
		}
		if(time_flag == 0)
		{
			s = Count0();
			s=s*15;
			s=s/12;
			display_12864(time_velue, s);  //��1��ˢ��һ��
			time_flag = 1;
		}
	}
}


/***************12864��ʾ����******************/
void display_12864(uint time ,uint line)
{
		print(0x80,2,"����С��");
	
		print(0x90,0,"ʱ�䣺");
		print(0x90,3," ");			   //	  �ڶ�����ʾ
		LCD12864_WriteData(time/100+0x30);
		LCD12864_WriteData(time/10%10+0x30);
		LCD12864_WriteData(time%10+0x30);
		print(0x90,5,"s");
	
	  print(0x88,0,"�ٶȣ�");
	  print(0x88,3," ");			   //	  ��������ʾ
	  LCD12864_WriteData(line/time/10+0x30);
		LCD12864_WriteData(line/time%10+0x30);
    print(0x88,5,"cm/s");
	  
		print(0x98,0,"·�̣�");
		print(0x98,3," ");				  //	��������ʾ
	  LCD12864_WriteData(line/1000+0x30);
		LCD12864_WriteData(line/100%10+0x30);
		LCD12864_WriteData(line/10%10+0x30);
		LCD12864_WriteData(line%10+0x30);
		print(0x98,6,"cm");
}
