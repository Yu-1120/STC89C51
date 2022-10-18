#include "oled.h"
#include "reg52.h"
//#include "intrins.h"
#include "stdlib.h"

#include "stdio.h"
//#include "bmp.h"
bit FLAG=0;


void main()
{
	unsigned char l,n,num,lasty;
//	Init();
	unsigned char i,a=0,b=0,c=127,d=63,e=0,f=0,g=0,h,j,k;
	OLED_Init();
	OLED_Clear();
/*	for(i=0;i<8;i++)
	{
		a+=7;
		b+=3;
		c-=7;
		d-=3;
		Draw_Rectangle(a,b,c,d,1);
		Delay_50ms(5);
	}
	Delay_50ms(20);
	OLED_Clear();
	for(i=0;i<4;i++)
	{
		Draw_dimond(20+e,30,20);
		Draw_dimond(20+e,30,6);
		e+=30;
		
		Delay_50ms(5);
	}
	Draw_Hline(0,128,0,20);
	Draw_Hline(0,128,63,20);
	Delay_50ms(20);
	OLED_Clear();  
	for(i=0;i<4;i++)
	{
		Draw_Hline(0,128,0+g,10);
	
		g+=16;
		

	}
	for(i=0;i<4;i++)
	{
		Draw_Vline(0,63,0+f,20);
	
		f+=16;
		
		Delay_50ms(5);
	}
	for(i=0;i<4;i++)
	{
		Draw_VlineF(0,63,0+f,20);
		f+=16;
		
		Delay_50ms(5);
	}
	for(h=0;h<7;h++)
	{
		OLED_ShowNum(3+h*16,1,h,1,8);
		Delay_50ms(3);
	}
	for(j=1;j<8;j++)
	{
		OLED_ShowNum(3+(j-1)*16,3,j,1,8);
		Delay_50ms(3);
	}
	for(k=2;k<9;k++)
	{
		OLED_ShowNum(3+(k-2)*16,5,k,1,8);
		Delay_50ms(3);
	}
   	OLED_DrawLine(0,0,128,64);
	Delay_50ms(3);
	OLED_DrawLine(0,63,128,0);
	Delay_50ms(10);
	OLED_Clear();	*/
	Draw_dimond(43,30,20);
	OLED_DrawLine(43,10,93,21);
	Delay_50ms(10);
	OLED_DrawLine(43,50,93,39);
	Draw_Hline(65,85,30,30);
	Draw_dimond(93,30,10);
	Delay_50ms(10);
    OLED_ShowString(20,50,"Hello World!",8);
	Draw_Rectangle(1,1,126,62,5);
	Delay_50ms(30);

	OLED_Clear();
	Draw_Hline(25,128,50,5);
	Draw_Vline(0,50,24,5);
	Draw_dimond(10,32,8);
	Draw_dimond(10,48,8);	 	
   	//OLED_DrawLine(30,30,70,30);  
	while(1)
	{ 


	  for(l=28;l<129;l+=5)
	  {
		  if(l>=128)
		  {
		  	 FLAG = 1;
		  }
		  if(FLAG ==1)
		  {	 	
		  	for(n=l-3;n<l+1;n++)
			{
		  	 	Clear(0,50,n,0);
			}
		  }
		  num = rand()%48;
		  OLED_ShowNum(0,0,num,2,16);

		  OLED_DrawLine(l-3,lasty,l,num);	
		  lasty = num;

		  Delay_50ms(1);

		 
	}
	
	Clear(0,50,27,0);
	Clear(0,50,28,0);
	Clear(0,50,25,0);
	Clear(0,50,26,0);			  
	  				
	}

}
