#include "beep.h"


void BEEP_Test(void)
{
	while(1)
	{	
	
		BEEP=~BEEP;
		delay(10); //ͨ���޸Ĵ���ʱʱ��ﵽ��ͬ�ķ���Ч��
		
		if(KeyValue!=BEEP_TEST)
		{
			return;	
		}	
	}
}