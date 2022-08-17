#include "smg.h"



void DigDisplay(void)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(1):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(2):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(3):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(4):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(5):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(6):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
			case(7):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ	
		}
		SMG_PORT=DisPlayData[7-i];//���Ͷ���
		delay(100); //���һ��ʱ��ɨ��	
		SMG_PORT=0x00;//����
	}
}

void SMG_Test(void)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		DisPlayData[i]=smgduan[i];	
	}
	while(1)
	{
	
		DigDisplay();
		
		if(KeyValue!=SMG_TEST)
		{
			SMG_PORT=0x00;
			return;	
		}	
	}
}

