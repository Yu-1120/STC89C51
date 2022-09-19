#include <REG52.h>
#include "UART.h"
bit flag = 1;
sbit LED = P2 ^ 0;
void main()
{
    UartInit();
    while (1)
    {
        if (flag)
        {
            printf("Hello World!");
            LED = 0;
            flag = ~flag;
        }
    }
}
