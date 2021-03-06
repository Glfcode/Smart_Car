#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "STC12C5A60S2.h"
#include "direction.h"
#include "12864.h"

#define uint unsigned int
#define uchar unsigned char

sbit Left_L = P1^0;			//�����ߺ���ѭ��
sbit Left_R = P1^1;			//����ұߺ���ѭ��
sbit Right_L = P1^6;		//�Ҳ���ߺ���ѭ��
sbit Right_R = P1^7;		//�Ҳ��ұߺ���ѭ��

sbit BAR_LL = P2^2;			//�����ߺ������
sbit BAR_LR = P2^7;			//����ұߺ������
sbit BAR_RL = P3^6;			//�Ҳ���ߺ������
sbit BAR_RR = P3^7;			//�Ҳ��ұߺ������

extern unsigned int time_velue;
extern unsigned char time_flag;

extern void Go(void);					//ǰ��
extern void Break(void);			//����
extern void Left(void);				//��ת
extern void Right(void);			//��ת
extern void Left_break(void);	//���ֺ���
extern void Right_break(void);	//���ֺ���
extern void Stop(void);				//ͣ��

extern void Pwm_Init(void);		//PWM��ʼ��
extern void Pwm(uint x);			//PWM�ٶ����� x��ֵԽС�ٶ�Խ��

extern void Count_Init(void);		//��������ʼ��
extern uint Count0(void);				//��ȡ������0ֵ
extern uint Count1(void);				//��ȡ������1ֵ
extern void Count_Clear(void);	//����������
extern void Count_direction(uchar num_L,uchar num_R);		//����С����ʻ����

#endif
