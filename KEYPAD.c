#include<lpc214x.h>



#define RS     1<<24
#define RW     1<<25
#define EN     1<<26

#define R1    1<<0
#define R2    1<<1
#define R3    1<<2
#define R4    1<<3
#define C1    1<<4
#define C2    1<<5
#define C3    1<<6
#define C4    1<<7

//void delay(unsigned int time);
//void Lcd_cmd(char cmd);
//void Lcd_Data(char data);
//void LCD_init(void);


void delay(unsigned int time)
{
	unsigned int i,j;
	for ( i=0;i<time;i++)
	for(j=0; j<1275;j++);
}


void Lcd_cmd(char cmd)
{
	  IOCLR0=0x00FF0000;
    IOSET0= cmd<<16;
		IOCLR1= RS;
	  IOCLR1= RW;
	  IOSET1= EN;
	  delay(100);
	  IOCLR1= EN;
	
}
void Lcd_Data(char data)
{  
	  IOCLR0=0x00FF0000;
    IOSET0= data<<16;
		IOSET1= RS;
	  IOCLR1= RW;
	  IOSET1= EN;
	  delay(100);
	  IOCLR1= EN;
	  
}
void LCD_init(void)
{
	Lcd_cmd(0x38);
	delay(50);
	Lcd_cmd(0x06);
	delay(50);
	Lcd_cmd(0x01);
	delay(50);
	Lcd_cmd(0x0E);
	delay(50);
	Lcd_cmd(0x80);
	delay(50);
}

unsigned char keypad_init( void)
{
	unsigned char key;
	IOCLR0|=(R1|R2|R3|R4|C1|C2|C3|C4);
	
	while(1)
	{
		IOCLR0|= 1<< R1;
		IOSET0|=(R2|R3|R4);
		 if((IOPIN0 & C1)==0)
		 {
			key='7';
			return key;
		 }
		 else if((IOPIN0& C2)==0)
		 {
			key='8';
			return key;
		 }
		 else if((IOPIN0& C3)==0)
		 {
			key='9';
			return key;
		 }
		 else if((IOPIN0& C4)==0)
		 {
			key='/';
			return key;
		 }
		
		IOCLR0|=R2;
		IOSET0|=(R1|R3|R4);
		
		if((IOPIN0 & C1)==0)
		  {
			key='4';
			return key;
	  	}
		else if((IOPIN0& C2)==0)
		 {
			key='5';
			return key;
		 }
		else if((IOPIN0& C3)==0)
		 {
			key='6';
			return key;
	  	}
		 else if((IOPIN0& C4)==0)
		 {
			key='-';
			return key;
	  	}
			
		
		IOCLR0|=R3;
		IOSET0|=(R1|R2|R4);
		
	  	if((IOPIN0 & C1)==0)
		  {
			key='.';
			return key;
		  }
		  else if((IOPIN0 & C2)==0)
		  {
			key='0';
			return key;
		 }
	  	else if((IOPIN0 & C3)==0)
		  {
			key='=';
			return key;
		  }
		  else if((IOPIN0 & C4)==0)
		  {
			key='a';
			return key;
		  }
		
		IOCLR0|=R4;
		IOSET0|=(R1|R2|R3);
		
		 if((IOPIN0 & C1)==0)
		  {
			key='1';
			delay(10);
			return key;
		  }
		 else if((IOPIN0& C2)==0)
		 {
			key='2';
			delay(10);
			return key;
		 }
		 else if((IOPIN0 & C3)==0)
		 {
			key='3';
			delay(10);
			return key;
		 }
		 else if((IOPIN0 & C4)==0)
		 {
			key='*';
			delay(10);
			return key;
		 }
		
	}
}
int main()
{ 
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00000000;
	PINSEL2 = 0x00000000;
	IODIR1 = 0xFF000000;
	IODIR0 = 0x00FF000F;
  LCD_init();
	Lcd_Data('K');
	delay(10);
	Lcd_Data('E');
	delay(10);
	Lcd_Data('Y');
	delay(10);
	Lcd_cmd(0xC0);
	delay(50);
	
	while(1)
	{
		Lcd_Data(keypad_init());
		delay(10);
	}
	
}