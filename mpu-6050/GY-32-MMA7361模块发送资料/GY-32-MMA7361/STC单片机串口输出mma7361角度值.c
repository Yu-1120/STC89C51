//名称：单片机串口输出MMA7361角度值
//使用单片机：stc12c5a60s2
//晶振：11.0592m
//X轴->(ADC0)P1.0  
//Y轴->(ADC1)P1.1 
//Z轴->(ADC1)P1.2
//用pc串口助手显示时，选择字符显示 
//参考宏晶网址例程
#include "reg51.h"
#include "intrins.h"
#include  <math.h>    //Keil library  
#include  <stdio.h>   //Keil library

//#define FOSC  18432000L
#define FOSC    11059200L  //晶振11.0592M
#define BAUD    9600

typedef unsigned char BYTE;
typedef unsigned int WORD;

#define   uchar unsigned char
#define   uint unsigned int	

/*Declare SFR associated with the ADC */
sfr AUXR1       =   0XA2;
sfr ADC_CONTR   =   0xBC;           //ADC control register
sfr ADC_RES     =   0xBD;           //ADC high 8-bit result register
sfr ADC_RESL    =   0xBE;
sfr ADC_LOW2    =   0xBE;           //ADC low 2-bit result register
sfr P1ASF       =   0x9D;           //P1 secondary function control register

/*Define ADC operation const for ADC_CONTR*/
#define ADC_POWER   0x80            //ADC power control bit
#define ADC_FLAG    0x10            //ADC complete flag
#define ADC_START   0x08            //ADC start control bit
#define ADC_SPEEDLL 0x00            //420 clocks
#define ADC_SPEEDL  0x20            //280 clocks
#define ADC_SPEEDH  0x40            //140 clocks
#define ADC_SPEEDHH 0x60            //70 clocks

void InitUart();
void InitADC();
void SendData(BYTE dat);
int GetADCResult(BYTE ch);
void Delay(WORD n);
uchar ge,shi,bai,qian,wan;           //显示变量

void conversion(uint temp_data)  
{  
    wan=temp_data/10000+0x30 ;
    temp_data=temp_data%10000;   //取余运算
	qian=temp_data/1000+0x30 ;
    temp_data=temp_data%1000;    //取余运算
    bai=temp_data/100+0x30   ;
    temp_data=temp_data%100;     //取余运算
    shi=temp_data/10+0x30    ;
    temp_data=temp_data%10;      //取余运算
    ge=temp_data+0x30; 	
}

/*----------------------------
Get ADC result
----------------------------*/
int GetADCResult(BYTE ch)
{   int AD10bitResult; 
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
    _nop_();                        //Must wait before inquiry
    _nop_();
    _nop_();
    _nop_();
    while (!(ADC_CONTR & ADC_FLAG));//Wait complete flag
    ADC_CONTR &= ~ADC_FLAG;         //Close ADC

    AD10bitResult=ADC_RES;
    AD10bitResult<<=8;
    AD10bitResult|=ADC_RESL;
    return AD10bitResult;                  //Return 10BIT ADC result
}
/*----------------------------
Initial UART
----------------------------*/
void InitUart()
{
    SCON = 0x5a;                    //8 bit data ,no parity bit
    TMOD = 0x20;                    //T1 as 8-bit auto reload
    TH1 = TL1 = -(FOSC/12/32/BAUD); //Set Uart baudrate
    TR1 = 1;                        //T1 start running
}

/*----------------------------
Initial ADC sfr
----------------------------*/
void InitADC()
{
    P1ASF = 0xff;                   //Open 8 channels ADC function

	AUXR1=AUXR1|0X04;              //ad值左对齐
    ADC_RES = 0;                    //Clear previous result
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
    Delay(2);                       //ADC power-on and delay
}

/*----------------------------
Send one byte data to PC
Input: dat (UART data)
Output:-
----------------------------*/
void SendData(BYTE dat)
{
    while (!TI);                    //Wait for the previous data is sent
    TI = 0;                         //Clear TI flag
    SBUF = dat;                     //Send current data
}

/*----------------------------
Software delay function
----------------------------*/
void Delay(WORD n)
{
    WORD x;

    while (n--)
    {
        x = 5000;
        while (x--);
    }
}

//******************************************************************************

void main()
{   int x,y,z;
	float Q,T,K,Roll,Pitch;
    InitUart();                     //Init UART, use to show ADC result
    InitADC();                      //Init ADC sfr
    while (1)
    {
		x=GetADCResult(0);
		y=GetADCResult(1);
		z=GetADCResult(2);
		// 0-5v 对应 0-1024  
		// 3.3v/2  = 1.65v（0g时候值）
		// 1.65v ->= 338   (AD值即十进制338，十六进制0X0152)
		x-=0X0152; //
		y-=0X0152;
		z-=0X0152;	
    Q=x;
    T=y;
    K=z;
    Q=-Q;
    Roll=(float)(((atan2(K,Q)*180)/3.14159265)+180);
    Pitch=(float)(((atan2(K,T)*180)/3.14159265)+180);
    conversion(Roll);    //横滚角0-360度
  //conversion(Pitch); //俯仰角0-360度
    SendData(bai);
	SendData(shi);
	SendData(ge);

	SendData(0x0d); 
	SendData(0x0a);//换行，回车

    Delay(30);
    }
}