#include <REG52.h>
#include "UART.h"
int flag = 1;
sbit LED = P2 ^ 0;
void delay(u16 i)
{
    while (i--)
        ;
}

void main()
{
    UartInit();
    while (1)
    {
        if (flag)
        {

            printf("Hello World!");
            LED = ~LED;
            delay(50000); //大约延时450ms
            flag = ~flag;
        }
    }
}
