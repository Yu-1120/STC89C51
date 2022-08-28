#include  <reg51.h>
void delay();

sbit LED = P0^0;
void main()
	
{   
	
	while(1){
	
	  LED = 1;
	  delay();
	 LED = 0;
	delay();
	
	}
 
}

void delay(){
   int i;
	for(i=0;i<1000;i++ );
   
}