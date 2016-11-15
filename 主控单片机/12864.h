
#ifndef _12864_H_
#define _12864_H_


extern void DELAY_MS (unsigned int a);
void LCD12864_TestBusy(void);
extern void LCD12864_WriteCMD(unsigned char LCD12864_command);
extern void LCD12864_WriteData(unsigned char LCD12864_data);
extern void print(unsigned char x,unsigned char y,unsigned char *str);
extern void LCD12864_Init(void);

#endif