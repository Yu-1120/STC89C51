//		@�����ٳ�  20220720
//		�߶��Ż�OLEDͼƬˢ���ʣ�
//
//		�ṩ��	��ˢ���� 	ͼƬ��ʾ������OLED_DrawBMP���� 
//					��ˢ����		ͼƬ��ʾ������OLED_DrawBMP_Fast���� 
//					��ˢ����		ͼƬ��ʾ������OLED_DrawBMP_Faster����
//					ͼƬ����ѭ���ƶ�������BMPmove()
//		0.96 OLED��ʾChromeС������Ϸ������С�����ƶ�����ԾЧ��
//		STC89C52RC/STC12C5A60S2/ST15F2K60S2�����ã�11.0592MHz��OLED��ΪI2C�ӿ�
//		OLED_SCL=P2^0;	OLED_SDA=P2^1;		

#include <reg51.h>
#include <oled.h>									//OLED�⺯��

#define uchar unsigned char				//��uchar ��ʾ unsigned char����
#define uint unsigned int					//��uint ��ʾ unsigned int����

sbit LEFTkey = P3^0;							//������  ���￴���ԭ��Ŀ��ܲ�һ��
sbit UPkey = P2^1;								//������
sbit RIGHTkey = P2^2;							//������
sbit DOWNkey = P2^4;							//������

void keyscan();										//����ɨ�躯������

extern uchar code BMPclr[];				//ͼƬ�ⲿ������������ͼƬ
extern uchar code BMP0[];					//ͼƬ�ⲿ����������С����1
extern uchar code BMP1[];					//ͼƬ�ⲿ����������С����2				
extern uchar code BMP2[];					//ͼƬ�ⲿ������������	
extern uchar code BMP3[];					//ͼƬ�ⲿ����������������
extern unsigned char code F6x8[][6];
extern unsigned char code F8X16[];
uchar bx,by;							//ͼƬ���꣬ͼƬ�ƶ�����
uchar upflag,downflag;						//��Ծ״̬��־������״̬������״̬									

void main(void)
{
	uint i;
	bx = 0;													//С������ʼ���꣺��0�У���4ҳ
	by = 4;
	upflag = downflag = 0;					//��ʼ����Ծ��־
	OLED_Init();										//��ʼ��OLED  
	OLED_Clear();										//��һ����
	while(1)
	{	
		i++;
		if(i>9999) i = 0;
		OLED_ShowNum(66,3,i,4,8);
		BMPmove(20,0,52,2,BMP2,LEFT,0);								//��ͼƬѭ������
		BMPmove(90,4,106,8,BMP3,LEFT,0);							//������ͼƬѭ������
		OLED_ShowCHinese(0,2,0);	
		OLED_ShowCHinese(16,2,1);	
		OLED_ShowCHinese(32,2,2);	
		OLED_ShowCHinese(48,2,3);
		OLED_ShowString(100,0,"000",16);		
		OLED_DrawBMP_Faster(bx,by,bx+32,by+4,BMP0);					//����С����1	
	//	delay_ms(10);																	//С����ͼ1��ͼ2��ϳ�̤��Ч����������ʱ
		OLED_DrawBMP_Faster(bx,by,bx+32,by+4,BMP1);					//����С����2
	//	delay_ms(10);																	//С����ͼ1��ͼ2��ϳ�̤��Ч����������ʱ
		if(upflag == 0 && downflag == 0) keyscan();		//С�����ڵ��ϲ�ɨ�谴������Ծ״̬����ʧЧ
		if(upflag == 1)																//��Ծ״̬-����ʱ
		{
			if(by == 0)																	//����ߴ�
			{
				upflag = 0;
				downflag = 1;															//���������־�������־��1
			}
			if(by >=1)																	//��������ڵ���1ҳʱ����ִ�м�������
			{
				OLED_DrawBMP_Faster(bx,by+3,bx+32,by+4,BMPclr);	//�������²�Ӱ
				by--;																			//�����ƶ�һҳ
			}
		}
		if(downflag == 1)															//����״̬
		{
			if(by == 4)																	//����ʹ�
			{
				downflag = 0;															//��������־
			}
			if(by <= 3)																	//������С��3ҳʱ����ִ�мӼӲ���
			{
				OLED_DrawBMP_Faster(bx,by,bx+32,by+1,BMPclr);		//����ͷ����Ӱ
				by++;																			//����һҳ
			}
		}
		
	}
}
void keyscan()																		//����ɨ��
{
	if(UPkey == 0)																	//��
	{
	//	delay_ms(10);																	//ȥ��
		if(UPkey == 0)
		{
			upflag = 1;																	//��Ծ��ʶ��1
		}
	}
	if(LEFTkey == 0)																//��
	{
	//	delay_ms(10);
		if(LEFTkey == 0)
		{
			OLED_DrawBMP_Faster(bx+32-8,by,bx+32,by+8,BMPclr);	//�����ұ߲�Ӱ
			if(bx <= 0) bx = 128;												//������128��Χ��
			bx -=8;																			//һ������8������
		}
	}
	if(RIGHTkey == 0)																//��
	{
	//	delay_ms(10);
		if(RIGHTkey == 0)
		{
			OLED_DrawBMP_Faster(bx,by,bx+8,by+8,BMPclr);				//������߲�Ӱ
			bx +=8;																			//һ������8������
			if(bx >= 128) bx = 0;												//����ס128��Χ��
		}
		
	}
}
