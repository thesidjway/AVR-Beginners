/*
 * Sinusoidal-PWM.c
 *
 * Created: 25-02-2015 20:20:41
 *  Author: sidj
 This PWM program has almost continous mapping on a sin function that makes the LED go up and down in a smooth way
 */ 


#include <avr/io.h>
#include<math.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{	
	int a=0;
	int b=0;
	DDRB=255;
	PORTB=(1<<PB3);
	TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00); //Fast PWM mode, Clear on Compare Match, 1/256 prescaler
    while(1)
    {
       if(TCNT0==254)
	   {
		   a++;	   
	   }
	   if(a==8)	
	   {	
		   b++;
		   OCR0=255*sin(b);
		   a=0;
	   }		   
	  
}
