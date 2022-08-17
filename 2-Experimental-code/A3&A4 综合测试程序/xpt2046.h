#ifndef _xpt2046_H
#define	_xpt2046_H

#include "public.h"


//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

#ifndef ulong
#define ulong  unsigned long
#endif

//---����ʹ�õ�IO��---//
sbit DOUT = P3^7;	  //���
sbit CLK  = P3^6;	  //ʱ��
sbit DIN  = P3^4;	  //����
sbit CS   = P3^5;	  //Ƭѡ

uint Read_AD_Data(uchar cmd);
uint SPI_Read(void);
void SPI_Write(uchar dat);



void ADC_Test(void);


#endif