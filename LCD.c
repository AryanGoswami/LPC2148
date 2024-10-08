//control RS P1.16 RW P1.17 EN P1.18
//Data    P1.24 to P1.31
//kit 1.5
#include <lpc214x.h> 

//Function to generate software delay
//Calibrated to 1ms
void  delay_ms(unsigned char time)	   
{  
 unsigned int  i, j;
 for (j=0; j<time; j++)
  for(i=0; i<1275; i++);
}

void LCD_command(unsigned char command)
{
	IOCLR1 = 0xFF<<24;	// Clear LCD Data lines
	IOCLR1=1<<16;		 		// RS=0 for command
	IOCLR1=1<<17;		 		// RW=0 for write
	IOSET1=command<<24;	// put command on data line
	IOSET1=(1<<18);			// en=1 
	delay_ms(10) ;			// delay
	IOCLR1=(1<<18);	 		// en=0
}

LCD_data(unsigned char data)
{
	IOCLR1 = 0xFF<<24;	// Clear LCD Data lines 
	IOSET1=1<<16;		 		// RS=1 for data
	IOCLR1=1<<17;		 		// RW=0 for write
	IOSET1= data<<24; 	// put command on data line
	IOSET1=(1<<18);			//en=1 
	delay_ms(10) ;	  	//delay
	IOCLR1=(1<<18);			//en=0
 }

LCD_init()
{
	LCD_command(0x38);	//8bit mode and 5x8 dotes (function set)
	delay_ms(10) ;			// delay
	LCD_command(0x0c);	//display on, cursor off, cursor char blinking off(display on/off)
	delay_ms(10) ;			// delay
	LCD_command(0x06);  //cursor increament and display shift(entry mode set)
	delay_ms(10) ;			// delay
	LCD_command(0x01); 	//clear lcd(clear command)
	delay_ms(10) ;			// delay
	LCD_command(0x80); 	//set cursor to 0th location	1st lne
	
}
 
LCD_write_string(unsigned char *string)
{
  while(*string)			//Check for End of String
  LCD_data(*string++); 	//sending data on LCD byte by byte
}

int main(void)
{
	PINSEL1 = 0x00000000;		//Configure PORT0 as GPIO
	PINSEL2 = 0X00000000;		//Configure PORT1 as GPIO
	//Configure P1.18, P1.17, P1.16 as output
	IODIR1=	0xFF070000; //Configure P0.23 - P0.16 as output
	LCD_init();				//Initialize LCD 16x2

	LCD_write_string("Hello..");
	LCD_command(0xc0);//second line
	LCD_write_string("There !!!");
	while (1);
}