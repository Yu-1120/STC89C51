#ifndef _HC595_
#define _HC595_
sbit RCK=P3^5; //595锁存
sbit SCK=P3^6; //595移位
sbit SER=P3^4; //595写入数据

//uchar不是标准写法。应当全部写成unsigned char。
void HC595_write(unsigned char byte); //写入数据
void LCD_Show(unsigned char Column,unsigned char Data); //在点阵屏中写入数据，Data数据，Column为列
void LCD_INIT();
void Code_tran(int x,int y);		//解码x，y

#endif