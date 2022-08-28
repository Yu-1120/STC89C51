/**************************************************************************************
PWN

***********************************/

#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
 
#define Led10 P2
typedef unsigned int u16;
 
int atime = 64;
 
// ����Ϊ��ʱ, pmsȡֵ����Ϊ 0 - 64
void delay(u16 pms) {
  u16 x, y;
  for (x=pms; x>0; x--) {
    for (y=11; y>0; y--);
  }
}
 
// �������ռ�ձ�, iȡֵ����Ϊ 0 - 64, 
// iԽ��������Խ��, ��Ϊ����ǵ�λ����, ����iԽ��LEDԽ��
void ledfade(u16 i) {
  Led10 = 0;
  delay(i);
  Led10 = 1;
  delay(atime-i);
}
 
int main(void) {
  u16 a, b;
  // ÿ��ѭ��, С��
  while(1) {
    // a����, �����Ƚ�, ������
    for (a=0; a<atime; a++) {
      for (b=0; b < (atime - a)/4; b++) {
        ledfade(a);
      }
    }
    // a��С, ��������, ���Ƚ�
    for (a=atime; a>0; a--) {
      for (b=0; b < (atime - a)/4; b++) {
        ledfade(a);
      }
    }
  }
}
