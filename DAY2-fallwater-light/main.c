#include  <reg51.h>


void delay(){
 unsigned int i,j,k;
	 
	for(i=0;i<167;i++);
	   for(j=0;j<133;j++);
	      for(k=0;k<14;k++);
	//公式:  （（（（N1*3+1）+2)*N2+1）+2)*N1+1
   //又因为i,j,k 都是正整数而且不超过255、得167，133，14
}

void main()
{  
	while(1){
   // P2 = 0x00;  //全部点亮
		
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

