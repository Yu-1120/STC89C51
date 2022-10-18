//		@布丁橘长  20220720
//		高度优化OLED图片刷新率，
//
//		提供：	低刷新率 	图片显示函数：OLED_DrawBMP（） 
//					中刷新率		图片显示函数：OLED_DrawBMP_Fast（） 
//					高刷新率		图片显示函数：OLED_DrawBMP_Faster（）
//					图片左右循环移动函数：BMPmove()
//		0.96 OLED显示Chrome小恐龙游戏动画，小恐龙移动、跳跃效果
//		STC89C52RC/STC12C5A60S2/ST15F2K60S2均适用，11.0592MHz，OLED屏为I2C接口
//		OLED_SCL=P2^0;	OLED_SDA=P2^1;		

#include <reg51.h>
#include <oled.h>									//OLED库函数

#define uchar unsigned char				//用uchar 表示 unsigned char类型
#define uint unsigned int					//用uint 表示 unsigned int类型

sbit LEFTkey = P3^0;							//按键左  这里看你的原理改可能不一样
sbit UPkey = P2^1;								//按键右
sbit RIGHTkey = P2^2;							//按键上
sbit DOWNkey = P2^4;							//按键下

void keyscan();										//按键扫描函数声明

extern uchar code BMPclr[];				//图片外部变量声明：空图片
extern uchar code BMP0[];					//图片外部变量声明：小恐龙1
extern uchar code BMP1[];					//图片外部变量声明：小恐龙2				
extern uchar code BMP2[];					//图片外部变量声明：云	
extern uchar code BMP3[];					//图片外部变量声明：仙人掌
extern unsigned char code F6x8[][6];
extern unsigned char code F8X16[];
uchar bx,by;							//图片坐标，图片移动坐标
uchar upflag,downflag;						//跳跃状态标志，上升状态，下落状态									

void main(void)
{
	uint i;
	bx = 0;													//小恐龙初始坐标：第0列，第4页
	by = 4;
	upflag = downflag = 0;					//初始化跳跃标志
	OLED_Init();										//初始化OLED  
	OLED_Clear();										//清一次屏
	while(1)
	{	
		i++;
		if(i>9999) i = 0;
		OLED_ShowNum(66,3,i,4,8);
		BMPmove(20,0,52,2,BMP2,LEFT,0);								//云图片循环左移
		BMPmove(90,4,106,8,BMP3,LEFT,0);							//仙人掌图片循环左移
		OLED_ShowCHinese(0,2,0);	
		OLED_ShowCHinese(16,2,1);	
		OLED_ShowCHinese(32,2,2);	
		OLED_ShowCHinese(48,2,3);
		OLED_ShowString(100,0,"000",16);		
		OLED_DrawBMP_Faster(bx,by,bx+32,by+4,BMP0);					//绘制小恐龙1	
	//	delay_ms(10);																	//小恐龙图1和图2组合成踏步效果，稍作延时
		OLED_DrawBMP_Faster(bx,by,bx+32,by+4,BMP1);					//绘制小恐龙2
	//	delay_ms(10);																	//小恐龙图1和图2组合成踏步效果，稍作延时
		if(upflag == 0 && downflag == 0) keyscan();		//小恐龙在地上才扫描按键，跳跃状态按键失效
		if(upflag == 1)																//跳跃状态-上升时
		{
			if(by == 0)																	//到最高处
			{
				upflag = 0;
				downflag = 1;															//清空上升标志，下落标志置1
			}
			if(by >=1)																	//行坐标大于等于1页时，才执行减减操作
			{
				OLED_DrawBMP_Faster(bx,by+3,bx+32,by+4,BMPclr);	//消除脚下残影
				by--;																			//往上移动一页
			}
		}
		if(downflag == 1)															//下落状态
		{
			if(by == 4)																	//到最低处
			{
				downflag = 0;															//清空下落标志
			}
			if(by <= 3)																	//行坐标小于3页时，才执行加加操作
			{
				OLED_DrawBMP_Faster(bx,by,bx+32,by+1,BMPclr);		//消除头顶残影
				by++;																			//下移一页
			}
		}
		
	}
}
void keyscan()																		//按键扫描
{
	if(UPkey == 0)																	//上
	{
	//	delay_ms(10);																	//去抖
		if(UPkey == 0)
		{
			upflag = 1;																	//跳跃标识置1
		}
	}
	if(LEFTkey == 0)																//左
	{
	//	delay_ms(10);
		if(LEFTkey == 0)
		{
			OLED_DrawBMP_Faster(bx+32-8,by,bx+32,by+8,BMPclr);	//消除右边残影
			if(bx <= 0) bx = 128;												//控制在128范围内
			bx -=8;																			//一次左移8列像素
		}
	}
	if(RIGHTkey == 0)																//右
	{
	//	delay_ms(10);
		if(RIGHTkey == 0)
		{
			OLED_DrawBMP_Faster(bx,by,bx+8,by+8,BMPclr);				//消除左边残影
			bx +=8;																			//一次右移8列像素
			if(bx >= 128) bx = 0;												//控制住128范围内
		}
		
	}
}
