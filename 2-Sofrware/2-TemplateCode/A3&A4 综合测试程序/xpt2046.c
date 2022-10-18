#include "xpt2046.h"
#include "smg.h"

/****************************************************************************
*��������SPI_Write
*��  �룺dat��д������
*��  ������
*��  �ܣ�ʹ��SPIд������
****************************************************************************/

void SPI_Write(uchar dat)
{
	uchar i;
	CLK = 0;
	for(i=0; i<8; i++)
	{
		DIN = dat >> 7;  	//�������λ
		dat <<= 1;
		CLK = 0;			//�����ط�������

		CLK = 1;

	}
}
/****************************************************************************
*��������SPI_Read
*��  �룺��
*��  ����dat����ȡ ��������
*��  �ܣ�ʹ��SPI��ȡ����
****************************************************************************/

uint SPI_Read(void)
{
	uint i, dat=0;
	CLK = 0;
	for(i=0; i<12; i++)		//����12λ����
	{
		dat <<= 1;

		CLK = 1;
		CLK = 0;

		dat |= DOUT;

	}
	return dat;	
}

/****************************************************************************
*��������Read_AD_Data
*��  �룺cmd����ȡ��ͨ������
*��  ����AD_Value�������źŴ���󷵻ص�ֵ
*��  �ܣ���ȡͨ���ɼ�������
****************************************************************************/
uint Read_AD_Data(uchar cmd)
{
	uchar i;
	uint AD_Value;
	CLK = 0;
	CS  = 0;
	SPI_Write(cmd);
	for(i=6; i>0; i--); 	//��ʱ�ȴ�ת�����
	CLK = 1;	  //����һ��ʱ�����ڣ����BUSY
	_nop_();
	_nop_();
	CLK = 0;
	_nop_();
	_nop_();
	AD_Value=SPI_Read();
	CS = 1;
	return AD_Value;	
}




void ADCdatapros()
{
	u16 temp;
	static u8 i;
	if(i==50)
	{
		i=0;
		temp = Read_AD_Data(0x94);		//   AIN0 ��λ��
	}
	i++;
	DisPlayData[0]=smgduan[temp/1000];//ǧλ
	DisPlayData[1]=smgduan[temp%1000/100];//��λ
	DisPlayData[2]=smgduan[temp%1000%100/10];//��λ
	DisPlayData[3]=smgduan[temp%1000%100%10];
	DisPlayData[4]=0;
	DisPlayData[5]=0;
	DisPlayData[6]=0;
	DisPlayData[7]=0;		
}

void ADC_Test(void)
{
	
	while(1)
	{
		ADCdatapros();	 //���ݴ�����
		DigDisplay();//�������ʾ����
		if(KeyValue!=ADC_TEST)
		{
			return;	
		}
	}
}