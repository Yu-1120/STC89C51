#include <lint.h> //包含SDCC_mcs51定义,使编辑器支持 __sfr
#include <8052.h> //这个51的头文件
#define led P2_0
typedef unsigned int u16; //¶ÔÊý¾ÝÀàÐÍ½øÐÐÉùÃ÷¶¨Òå
typedef unsigned char u8;

void delay(u16 i)
{
    while (i--)
        ;
}
void main()
{
    while (1)
    {
        led = 0;
        delay(500);
        led = 1;
        delay(500);
    }
}
