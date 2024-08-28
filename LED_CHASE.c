#include<lpc214x.h>
void msdelay(unsigned int itime);
void main(void){
	PINSEL0=0x00000000;
	IODIR0=0x000000ff;
	IOSET0=0x00000001;
	while(1){
		unsigned int k;
		unsigned int p=0x00000001;
		for(k=0;k<8;k++){
			IOSET0<<k;
			msdelay(1000);
			p=p<<1;
			IOCLR0=p;
			msdelay(1000);
		}
	}
}
void msdelay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
}