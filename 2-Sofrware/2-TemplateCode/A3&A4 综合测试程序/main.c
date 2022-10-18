/**  
���Է�����
������̵ļ�ֵ�ֲ����£�
1			2			3			4
5			6			7			8
9		   10		   11		   12
13		   14		   15		   16
����1��LED���ԣ�ʵ��Ч����һյ������LEDѭ�����ơ�
����2�����������ԣ�ʵ��Ч���Ƿ�����һֱ�졣
����3������ܲ��ԣ�ʵ��Ч�����������ʾ0-7���֡�
����4��DS18B20���ԣ�ʵ��Ч�����������ʾ�¶ȡ�
����5��LED������ԣ����Ƚ�����ģ���ϵ�J24���Ӷ̽ӵ�GND�ࣨOE��GND�̽ӣ���ʵ��Ч����������ʾ
����6��DS1302���ԣ�ʵ��Ч�������������ʾʱ�ӡ�
����7��ADC���ԣ�ʵ��Ч�����������ʾ��λ��ADֵ��
����8: DAC���ԣ�ʵ��Ч����DA1ָʾ�Ƴʺ�����Ч��
����9������ң�ز��ԣ�ʵ��Ч�������������ʾ����ң�����ļ���ֵ
����10������������ԣ����Ӻò��������ʵ��Ч���ǲ������ת��
����11��EEPROM���ԣ�ʵ��Ч���ǣ�K1��Ϊд��K2Ϊ���㣬K3Ϊ����K4Ϊ���ּ�1��������д�뵽EEPROM�ڣ�����K3������ܿ���ʾ��ȡ�����ݡ�������ɺ��踴λ��ϵͳ��
����12��LCD1602���ԣ�����LCD1602Һ��������ʾ�ַ�����Ϣ
��������ֵ������չ��������
ע�⣡��
1�����LCD1602û����ʾ������LCD�ӿ��µĵ�λ������Լ����LCD1602��һ�����ʾ��ʱ��Ϳ�����ʾ�ˡ�


*/

#include "public.h"
#include "key.h"
#include "led.h"
#include "time.h"
#include "beep.h"
#include "smg.h"
#include "leddz.h"
#include "zlmoto.h"
#include "bjmoto.h"
#include "eeprom.h"
#include "ds18b20.h"
#include "ds1302.h"
#include "xpt2046.h"
#include "dac.h"
#include "hwjs.h"
#include "lcd1602.h"


void main()
{
	Timer0Init();
	
	while(1)
	{
		switch(KeyValue)
		{
			case LED_TEST: LED_Test();break;		//LED����
			case BEEP_TEST: BEEP_Test();break;		//����������
			case SMG_TEST: SMG_Test();break;		//����ܲ���
			case DS18B20_TEST: DS18B20_Test();break;	//DS18B20����
			case LEDDZ_TEST: LEDDZ_Test();break;		//LED�������
			case DS1302_TEST: DS1302_Test();break;		//DS1302����
			case ADC_TEST: ADC_Test();break;		//ADC����
			case DAC_TEST: DAC_Test();break;		//DAC����
			case HWJS_TEST: HWJS_Test();break;		//����ң�ز���
			case BJMOTO_TEST: BJMOTO_Test();break;	//�����������
			case EEPROM_TEST: EEPROM_Test();break;	//EEPROM����
			case LCD1602_TEST: LCD1602_Test();break;	//LCD1602����
			case ZLMOTO_TEST: ZLMOTO_Test();break;	//ֱ���������			
			
		}
		
		
	}		
}
