#include  <reg51.h>


void delay(){
 unsigned int i,j,k;
	 
	for(i=0;i<167;i++);
	   for(j=0;j<133;j++);
	      for(k=0;k<14;k++);
	//��ʽ:  ��������N1*3+1��+2)*N2+1��+2)*N1+1
   //����Ϊi,j,k �������������Ҳ�����255����167��133��14
}

void main()
{  
	while(1){
   // P2 = 0x00;  //ȫ������
		
//		P2 = 0x01;
//        delay();
//		P2 = 0x01<<1;
//	     delay();
//		P2 = 0x01<<2;
//		 delay();
//		P2 = 0x01<<3;
//	     delay();
//		P2 = 0x01<<4;
//		 delay();
//		P2 = 0x01<<5;
//	     delay();
//		P2 = 0x01<<6;
//	   delay();
//		P2 = 0x01<<7;
	unsigned int x;
		for(x=0;x<8;x++){
			P2 = 0x01<<x;
           delay();
		
		}
		
	
	}
	


}

