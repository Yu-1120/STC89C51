#include "time.h"
#include "key.h"


void Timer0Init(void)
{
	TMOD|=0X01;//ѡ��Ϊ��ʱ��0ģʽ��������ʽ1������TR0��������

	TH0=0X8a;	//����ʱ������ֵ����ʱ30ms
	TL0=0Xd0;	
	ET0=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
	TR0=1;//�򿪶�ʱ��			
}


void Timer0() interrupt 1
{
	static u8 i;
	TH0=0X8a;	//����ʱ������ֵ����ʱ30ms
	TL0=0Xd0;
	i++;
	if(i==1)
	{
		i=0;
		KEY_Scan();	
	}	
}


