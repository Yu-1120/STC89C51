#include "hwjs.h"
#include "smg.h"


u8 IrValue[6];
u8 IrTime;


void IrInit()
{
	IT0=1;//�½��ش���
	EX0=1;//���ж�0����
	EA=1;	//�����ж�

	IRIN=1;//��ʼ���˿�
}

void ReadIr() interrupt 0
{
	u8 j,k;
	u16 err;
	IrTime=0;					 
	delay(700);	//7ms

	if(IRIN==0)		//ȷ���Ƿ���Ľ��յ���ȷ���ź�
	{	 
		err=1000;				//1000*10us=10ms,����˵�����յ�������ź�
		/*������������Ϊ����ѭ���������һ������Ϊ�ٵ�ʱ������ѭ������ó�������ʱ
		�������������*/	
		while((IRIN==0)&&(err>0))	//�ȴ�ǰ��9ms�ĵ͵�ƽ��ȥ  		
		{			
			delay(1);
			err--;
		} 
		if(IRIN==1)			//�����ȷ�ȵ�9ms�͵�ƽ
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //�ȴ�4.5ms����ʼ�ߵ�ƽ��ȥ
			{
				delay(1);
				err--;
			}
			for(k=0;k<4;k++)		//����4������
			{				
				for(j=0;j<8;j++)	//����һ������
				{

					err=60;		
					while((IRIN==0)&&(err>0))//�ȴ��ź�ǰ���560us�͵�ƽ��ȥ
					{
						delay(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //����ߵ�ƽ��ʱ�䳤�ȡ�
					{
						delay(10);	 //0.1ms
						IrTime++;
						err--;
						if(IrTime>30)
						{
							return;
						}
					}
					IrValue[k]>>=1;	 //k��ʾ�ڼ�������
					if(IrTime>=8)			//����ߵ�ƽ���ִ���565us����ô��1
					{
						IrValue[k]|=0x80;
					}
					IrTime=0;		//����ʱ��Ҫ���¸�ֵ							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}


void HWJSdatapros()
{
	DisPlayData[0] = smgduan[IrValue[2]/16];
	DisPlayData[1] = smgduan[IrValue[2]%16];
	DisPlayData[2] = 0X76;
	DisPlayData[3]=0;
	DisPlayData[4]=0;
	DisPlayData[5]=0;
	DisPlayData[6]=0;
	DisPlayData[7]=0;		
}

void HWJS_Test(void)
{

	IrInit();
	while(1)
	{
		HWJSdatapros();
		DigDisplay();
		if(KeyValue!=HWJS_TEST)
		{
			EX0=0;	
			return;	
		}
	}
}