/*
 * GccApplication1.cpp
 *
 * Created: 7/17/2018 11:32:54 AM
 *  Author: ASUS
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h> 

int durationMS=10;

void Do()
{
	float frequency=262;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.90839);
		PORTB=1;
		_delay_ms(1.90839);
		PORTB=0;
	}
}

void Re()
{
	float frequency=294.08;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.7);
		PORTB=1;
		_delay_ms(1.7);
		PORTB=0;
	}
}

void Mi()
{
	float frequency=330.099;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.5147);
		PORTB=1;
		_delay_ms(1.5147);
		PORTB=0;
	}
}

void Fa()
{
	float frequency=349.7277;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.42968);
		PORTB=1;
		_delay_ms(1.42968);
		PORTB=0;
	}
}

void So()
{
	float frequency=392.5560;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.2737);
		PORTB=1;
		_delay_ms(1.2737);
		PORTB=0;
	}
}

void La()
{
	float frequency=440.6292;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.13474);
		PORTB=1;
		_delay_ms(1.13474);
		PORTB=0;
	}
}

void Ti()
{
	float frequency=494.58955;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(1.0109);
		PORTB=1;
		_delay_ms(1.0109);
		PORTB=0;
	}
}

void DoHigh()
{
	float frequency=524;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.95419);
		PORTB=1;
		_delay_ms(.95419);
		PORTB=0;
	}
}


#include <avr/io.h>

int main(void)
{
	DDRB=0xFF;
	DDRA=0x00;
	
    while(1)
    {
		
		unsigned char a=PINA;
		if(a&1)
		{
			Do();
		}
		else
		{
			if(a&(1<<1))
			{
				Re();
			}
			else if(a&(1<<2))
			{
				Mi();
			}
			else if(a&(1<<3))
			{
				Fa();
			}
			else if(a&(1<<4))
			{
				So();
			}
			else if(a&(1<<5))
			{
				La();
			}
			else if(a&(1<<6))
			{
				Ti();
			}
			else if(a&(1<<7))
			{
				DoHigh();
			}
		}
					
    }
}