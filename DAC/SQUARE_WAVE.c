#include<lpc214x.h>
void ms_delay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
}
int main(void){
	PINSEL1=0x00080000;
	IODIR0=0x02000000;
	while(1){
		DACR=0x03ff<<6;
		ms_delay(1000);
		DACR=0x0000<<6;
		ms_delay(1000);
	}
}