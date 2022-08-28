#include "dac.h"

bit DIR;

//--����һ��ȫ�ֱ���--// 
u16 count,value,timer1;


void Timer1Init()
{
	TMOD|=0X10;//ѡ��Ϊ��ʱ��1ģʽ��������ʽ1������TR1��������

	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
		
	ET1=1;//�򿪶�ʱ��1�ж�����
	EA=1;//�����ж�
	TR1=1;//�򿪶�ʱ��			
}


void Time1(void) interrupt 3    //3 Ϊ��ʱ��1���жϺ�  1 ��ʱ��0���жϺ� 0 �ⲿ�ж�1 2 �ⲿ�ж�2  4 �����ж�
{
	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
	timer1++; 
    count++;
	
}


void DAC_Test(void)
{
	Timer1Init();  //��ʱ��1��ʼ��

	while(1)
	{
		if(count>100)							
		{  
			count=0;
			if(DIR==1)					   //DIR�������ӻ��С
			{
			  value++;
			}			
			if(DIR==0)
			{
			  value--;
			}
				
		}

		if(value==1000)
		{
		  DIR=0;
		}
		if(value==0)
		{
		  DIR=1;
		}	
				
		if(timer1>1000)  //PWM����Ϊ1000*1us
		{
			timer1=0;
		}
		if(timer1 <value)	
		{
			PWM=1;
		}
		else
		{
			PWM=0;
		}			

		if(KeyValue!=DAC_TEST)
		{
			TR1=0;
			return;	
		}
	}
}