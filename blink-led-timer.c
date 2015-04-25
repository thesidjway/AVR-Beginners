/*
 * blink-led-timer.c
 *
 * Created: 09-12-2014 23:44:18
 *  Author: sidj
 This code simulates the delay function by calling the LED on and off every 47000 times the timer counter hits full bar
 This gives a delay of about 0.75 seconds between intervals
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

int main()
{
	DDRB =~0;
	TCCR0 |= (1 << CS00); //prescaler of t/256
	TCNT0 = 0; 
	PORTB=~0;
	long int cnt;
		
	while(1)
	{
		if (TCNT0==254) //upper cap of timer 0
		{
			cnt++;
		}
		if (cnt==47000)
		{
			PORTB=0;
		}
		else if(cnt==94000)
		{
			cnt=0;
			PORTB=~0;
		}					
		}
	}
