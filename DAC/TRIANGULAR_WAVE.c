#include<lpc214x.h>
void ms_delay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
}
int main(void){
	unsigned int p,q;
	PINSEL1=0x00080000;
	IODIR0=0x02000000;
	while(1){
		for(p=0;p<1024;p++){
			DACR=p<<6;
		}
		for(q=1023;q>0;q--){
			DACR=q<<6;
		}
	}
}