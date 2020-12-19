/*
 * Graduation_Project.c
 *
 * Created: 12/11/2020 7:37:18 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "SPI.h"
#include "UART.h"

volatile unsigned char rxdata=0;

volatile unsigned char UART_data=0;

ISR(USART_RXC_vect)
{
	UART_data = 1;
	rxdata = UDR;
}

int main(void)
{
	uint8 receive = 0;
	HC05_vInit();
	SPI_Master_Init();
	SPI_Master_Init_Trans();
	_delay_ms(1000);
	
    while(1)
    {
        
		if(UART_data == 1 )
		{
			
		
			receive = SPI_Transiver(rxdata);
			UART_data = 0;
			
			_delay_ms(1000);
		}			
    }
}