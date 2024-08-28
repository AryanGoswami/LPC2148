#include<lpc214x.h>
void msdelay(unsigned int itime);
void main(void){
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	IODIR0=0xffffffff;
	IODIR1=0xffffffff;
	while(1){
		IOSET0=0xffffffff;
		IOSET1=0xffffffff;
		msdelay(500);
		IOCLR0=0xffffffff;
		IOCLR1=0xffffffff;
		msdelay(500);
	}
}
void msdelay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<2175;j++);
}