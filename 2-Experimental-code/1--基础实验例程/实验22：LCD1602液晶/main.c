/*************************************************************************************

*
实验现象：下载程序后插上LCD1602液晶在开发板上，即可显示
		  
接线说明： (具体接线图可见开发攻略对应实验的“实验现象”章节)

	
注意事项：根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释										

										  
**************************************************************************************

*/

#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "lcd.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

u8 Disp[]="    Hello,world    ";

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main(void)
{
	u8 i;
	LcdInit();
	for(i=0;i<16;i++)
	{
		LcdWriteData(Disp[i]);	
	}
	while(1);				
}
