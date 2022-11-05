/*
 * LM_Temp_sensor.c
 *
 * Created: 3/25/2021 6:28:26 AM
 *  Author: Mohamed Samy
 */ 


#define F_CPU  8000000
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include <avr/io.h>
#include <avr/delay.h>
#define clear 0b00000001




u16 x1,Volt_Channel0,x2,Volt_Channel1=0;
u8 Celisus=0;

int main(void)
{
	
	LCD_VidSendCommand(clear);
	_delay_ms(2);
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("Hello ");
	_delay_ms(2000);
    while(1)
    {
        x1=ADC_u16GetDigitalValue(0);
		Volt_Channel0=(x1*5000UL)/1024;
		Celisus=Volt_Channel0/10;
		_delay_ms(50);
		LCD_VidSendCommand(clear);
		_delay_ms(2);
		LCD_VidSetPosition(1,0);
		LCD_VidWriteString("TEMP : ");
		LCD_VidWriteNumber(Celisus);
		_delay_ms(200);
    }
}