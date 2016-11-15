/********************�����׶� ********************
 * �ļ���  ��12864.c
 * ����    �����������        
 * ����    ������ 
 * Ӳ�����ӣ� -------------------------------
 *           |   |
 *           |   |
 *           |   |
 *           |   |
 *           |   |
 *            -------------------------------
 * ʱ��    ��2013��5��24 
***************************************************/
#include "config.h"

/*****************************************************************************
                    ���Ŷ���  �����Ӳ��ɱ�ģ�
/****************************************************************************/
#define		LCD12864_DB0_DB7		P0		    // ����LCD1602����������
sbit LCD12864_RS   = P2 ^ 3;			// ����LCD1602��RS������
sbit LCD12864_RW   = P2 ^ 4;					// ����LCD1602��RW������
sbit LCD12864_E    = P2 ^ 5;					// ����LCD1602��E������
sbit PSB = P2^6;
/*****************************************************************************
����LCD12864ָ� ����ϸ����鿴12864ָ��ֲᣩ
/****************************************************************************/
#define			CMD_clear		0x01             // �����Ļ
#define			CMD_back		0x02             // DDRAM����λ
#define			CMD_base		0x30		      // ����ָ�
#define			CMD_expand		0x36		     // ��չָ�
#define			CMD_display		0x0c             // ����ʾ_�ع��_�ع����˸
#define			CMD_set			0x38             // 8λ����_2����ʾ
#define			line_one		0x80             // ��һ��д���ַ
#define			line_two		0x90             // �ڶ���д���ַ
#define			line_three		0x88             // ������д���ַ
#define			line_four		0x98             // ������д���ַ
/*****************************************************************************
�������DELAY_MS ()
������ unsigned int a
����ֵ����
��ע�����뼶�ӳٺ���
/****************************************************************************/

void DELAY_MS (unsigned int a)
{
	unsigned int i;
	while( a-- != 0)
	{
		for(i = 0; i < 600; i++);
	}
}
/*****************************************************************************
��������LCD12864_TestBusy����
������ ��
����ֵ����
��ע��LCD12864��æ����LCD12864����æ״̬�����������ȴ�����æ״̬
****************************************************************************/
void LCD12864_TestBusy(void)
{
	LCD12864_DB0_DB7=0xff;
	LCD12864_RS=0;
	LCD12864_RW=1;
	LCD12864_E=1;
   	while(LCD12864_DB0_DB7&0x80);
	LCD12864_E=0;
}

/*****************************************************************************
��������LCD12864_TestBusy����
������ unsigned char LCD12864_command
����ֵ����
��ע��дָ��
****************************************************************************/

void LCD12864_WriteCMD(unsigned char LCD12864_command)
{
	LCD12864_TestBusy();
	LCD12864_RS=0;
	LCD12864_RW=0;
	LCD12864_E=1;
	LCD12864_DB0_DB7=LCD12864_command;
	LCD12864_E=0;
}	
			  
/*****************************************************************************
�������LCD12864_WriteData()
������ unsigned char LCD12864_command
����ֵ����
��ע��  ��LCD12864д����

/****************************************************************************/
void LCD12864_WriteData(unsigned char LCD12864_data)
{
	LCD12864_TestBusy();
	LCD12864_RS=1;
	LCD12864_RW=0;
	LCD12864_E=1;
	LCD12864_DB0_DB7=LCD12864_data;
	LCD12864_E=0;
}

/*****************************************************************************
�������pprint()
������ unsigned char x,unsigned char y,unsigned char *str
����ֵ����
��ע��  ��ӡ�ַ������򣨱���������ָ�뺯������LCD����һ���ַ���,����64�ַ�֮�� 
/****************************************************************************/
void print(unsigned char x,unsigned char y,unsigned char *str)
{
	LCD12864_WriteCMD(x+y);
	while(*str!='\0')
	{					
    	LCD12864_WriteData(*str++); 
	}
	*str=0;
}

/*****************************************************************************
�������LCD12864_Init()
������ ��
����ֵ����
��ע��LCD12864��ʼ�� 
/****************************************************************************/
void LCD12864_Init(void)
{
	PSB = 1; // ѡ�񲢿�ģʽ
	LCD12864_WriteCMD(CMD_base);				//��ʼ������ָ���Ϊ����ָ��
	LCD12864_WriteCMD(CMD_back);        //  DDRAM����λ,����Ƶ���ͷԭ��λ��
	LCD12864_WriteCMD(CMD_display);			//	����ʾ_�ع��_�ع����˸
	LCD12864_WriteCMD(CMD_clear);				//  ����
}