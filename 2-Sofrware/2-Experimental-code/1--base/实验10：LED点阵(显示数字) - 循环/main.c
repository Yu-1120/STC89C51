#include "reg51.h"
#include<intrins.h>
typedef unsigned int u16;
typedef unsigned char u8;
 
sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;
#define lde P0
#define lv P1
 
u8 code lie[]={0xff,0x99,0x00,0x00,0x00,0x81,0xc3,0xe7};
//心下型
u8 code hang[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//行动态扫描
u8 code liea[]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
//全1列（高电平，全灭）
u8 code lieb[]={0xff,0x81,0xe7,0xe7,0xe7,0xe7,0xe7,0x81};
//I
u8 code liec[]={0xff,0x99,0x99,0x99,0x99,0x99,0xc3,0xe7};
//U
u8 code liee[]={0xFF,0xFF,0xDB,0x81,0x81,0xC3,0xE7,0xFF};
//小心
u8 code lief[]={0xCD,0xB4,0xB5,0xB5,0xB5,0xB5,0xB5,0xC8};
//10
u8 code lieg[]={0xff,0xe7,0xDB,0xDB,0xC7,0xDF,0xDB,0xE7};
//9
u8 code lieh[]={0xFF,0xE7,0xDB,0xDB,0xE7,0xDB,0xDB,0xE7};
//8
u8 code liei[]={0xFF,0xC3,0xDB,0xDF,0xEF,0xF7,0xF7,0xF7};
//7
u8 code liej[]={0xFF,0xE7,0xDB,0xFB,0xE3,0xDB,0xDB,0xE7};
//6
u8 code liek[]={0xFF,0xC3,0xFB,0xFB,0xE7,0xDF,0xDB,0xE7};
//5
u8 code liel[]={0xFF,0xEF,0xE7,0xEB,0xED,0xC3,0xEF,0xEF};
//4
u8 code liem[]={0xFF,0xE7,0xDB,0xDF,0xEF,0xDF,0xDB,0xE7};
//3
u8 code lien[]={0xFF,0xE7,0xDB,0xDF,0xEF,0xF7,0xFB,0xC3};
//2
u8 code lieo[]={0xFF,0xEF,0xE3,0xEF,0xEF,0xEF,0xEF,0xC3};
//1
u8 code liep[]={0xFF,0xE7,0xDB,0xDB,0xDB,0xDB,0xDB,0xE7};
//0
u8 code lieQ[]={0xFF,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
u8 code lieR[]={0xDB,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
u8 code lieS[]={0x99,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
u8 code lieT[]={0x99,0x66,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
u8 code lieU[]={0x99,0x66,0x7E,0xFF,0xFF,0xFF,0xFF,0xFF};
u8 code lieV[]={0x99,0x66,0x7E,0x7E,0xFF,0xFF,0xFF,0xFF};
u8 code lieW[]={0x99,0x66,0x7E,0x7E,0xBD,0xFF,0xFF,0xFF};
u8 code lieX[]={0x99,0x66,0x7E,0x7E,0xBD,0xDB,0xFF,0xFF};
u8 code lieY[]={0x99,0x66,0x7E,0x7E,0xBD,0xDB,0xE7,0xFF};
//环心 上
u8 code lieac[]={0xFF,0x99,0x66,0x7E,0x7E,0xBD,0xDB,0xE7};
u8 code liez[]={0xFF,0x99,0x81,0x81,0xC3,0xE7,0xFF,0xFF};
//小心上
u8 code lieab[]={0xFF,0xFF,0x99,0x81,0x81,0xC3,0xE7,0xFF};
//小心下
 
 
 
 
 
 
void HC595shuru(u8 dat)
{
    u8  i;
    RCLK=0;
    SRCLK=0;
    for(i=0;i<8;i++)
         {
             SER=dat>>7 ;
             dat<<=1;
             SRCLK=1;
             _nop_();
             _nop_();
             SRCLK=0;
         }
    RCLK=1;
    _nop_();
    _nop_();
    RCLK=0;
}
 
void delay(u16 i)
{
  while(i--);
}
 
 
 void  liexuan()
 {
     u8 a;
        for(a=0;a<8;a++)
          {
            HC595shuru(hang[a]);
            lde=lie[a];
            lv=liea[a];
            delay(100);
            P0=0xff;
          }
 }
 void liexuana()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liea[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
 void liexuanb()
 {
      u8  j;
         for(j=0;j<8;j++)
         {
            HC595shuru(hang[j]);
            lde=lieb[j];
            lv=liea[j];
            delay(100);
                P0=0xff;
        }
}
 void liexuanc()
 {
      u8  k;
         for(k=0;k<8;k++)
         {
            HC595shuru(hang[k]);
            lde=liec[k];
            lv=liea[k];
            delay(100);
                P0=0xff;
        }
}
 
void liexuane()
 {
      u8  g;
         for(g=0;g<8;g++)
         {
            HC595shuru(hang[g]);
            lde=liee[g];
            lv=liea[g];
            delay(100);
                P0=0xff;
        }
}
void liexuanf()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=lief[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuang()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=lieg[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuanh()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=lieh[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuani()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liei[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuanj()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liej[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuank()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liek[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuanl()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liel[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuanm()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liem[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuann()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=lien[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuano()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=lieo[i];
            lv=liea[i];
            delay(100);
                P0=0xff;
        }
}
void liexuanp()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lde=liep[i];
            lv=liea[i];
            delay(100);
            P0=0xff;
        }
}
void liexuanQ()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieQ[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanR()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieR[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanS()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieS[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanT()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieT[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanU()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieU[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanV()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieV[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanW()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieW[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanX()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieX[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanY()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieY[i];
            delay(100);
            P1=0xff;
        }
}
void liexuanz()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieY[i];
            lde=liez[i];
            delay(100);
            P0=0xff;
            P1=0xff;
        }
}
void liexuanab()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lieac[i];
            lde=lieab[i];
            delay(100);
            P0=0xff;
            P1=0xff;
        }
}
void liexuanar()
 {
      u8  i;
         for(i=0;i<8;i++)
         {
            HC595shuru(hang[i]);
            lv=lie[i];
            lde=liea[i];
            delay(100);
            P0=0xff;
            P1=0xff;
        }
}
void main()
{
   while(1)
   {
    u8 b;
     for(b=0;b<30;b++)
        {
        liexuanf();
        }
     for(b=0;b<30;b++)
        {
        liexuana();
        }
     for(b=0;b<30;b++)
        {
        liexuang();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
     for(b=0;b<30;b++)
        {
        liexuanh();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuani();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuanj();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuank();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuanl();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuanm();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuann();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuano();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
    for(b=0;b<30;b++)
        {
        liexuanp();
        }
    for(b=0;b<30;b++)
        {
        liexuana();
        }
     for(b=0;b<30;b++)
        {
        liexuan();
        }
     for(b=0;b<30;b++)
        {
        liexuane();
        }
     for(b=0;b<30;b++)
        {
        liexuan();
        }
     for(b=0;b<30;b++)
        {
        liexuane();
        }
     for(b=0;b<30;b++)
        {
        liexuan();
        }
     for(b=0;b<30;b++)
        {
        liexuane();
        }
     for(b=0;b<30;b++)
        {
        liexuan();
        }
     for(b=0;b<30;b++)
        {
        liexuane();
        }
     for(b=0;b<30;b++)
        {
        liexuan();
        }
      for(b=0;b<30;b++)
        {
        liexuanar();
        }
      for(b=0;b<30;b++)
        {
        liexuan();
        }
      for(b=0;b<30;b++)
        {
        liexuanar();
        }
      for(b=0;b<30;b++)
        {
        liexuan();
        }
      for(b=0;b<30;b++)
        {
        liexuanar();
        }
      for(b=0;b<30;b++)
        {
        liexuan();
        }
      for(b=0;b<30;b++)
        {
        liexuanar();
        }
      for(b=0;b<100;b++)
        {
        liexuanb();
        }
      for(b=0;b<30;b++)
        {
        liexuana();
        }
      for(b=0;b<100;b++)
        {
        liexuan();
        }
      for(b=0;b<30;b++)
        {
        liexuana();
        }
      for(b=0;b<100;b++)
        {
        liexuanc();
        }
      for(b=0;b<30;b++)
        {
        liexuana();
        }
//      流水
      for(b=0;b<20;b++)
        {
        liexuanQ();
        }
        for(b=0;b<20;b++)
        {
        liexuanR();
        }
        for(b=0;b<20;b++)
        {
        liexuanS();
        }
        for(b=0;b<20;b++)
        {
        liexuanT();
        }
        for(b=0;b<20;b++)
        {
        liexuanU();
        }
        for(b=0;b<20;b++)
        {
        liexuanV();
        }
        for(b=0;b<20;b++)
        {
        liexuanW();
        }
        for(b=0;b<20;b++)
        {
        liexuanX();
        }
        for(b=0;b<20;b++)
        {
        liexuanY();
        }
//  上下
      for(b=0;b<60;b++)
        {
        liexuanz();
        }
      for(b=0;b<30;b++)
        {
        liexuanab();
        }
      for(b=0;b<30;b++)
        {
        liexuanz();
        }
      for(b=0;b<30;b++)
        {
        liexuanab();
        }
      for(b=0;b<30;b++)
        {
        liexuanz();
        }
      for(b=0;b<30;b++)
        {
        liexuanab();
        }
        for(b=0;b<150;b++)
        {
        liexuanz();
        }
    }
}