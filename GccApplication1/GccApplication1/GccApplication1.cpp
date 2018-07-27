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
#include <avr/interrupt.h>

int durationMS=10;
int save = 0;
int EEPROMAddress=0;


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




void EEPROMWrite(unsigned int address, char data)
{
	while(EECR&(1<<EEWE));
	EEAR=address;
	EEDR=data;
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);
}

char EEPROMRead(unsigned int address)
{
	while(EECR&(1<<EEWE));
	EEAR=address;
	EECR|=(1<<EERE);
	return EEDR;
}

void readNote(char data)
{
	if(data==1)
	{
		Do();
	}
	if(data==2)
	{
		Re();
	}
	if(data==3)
	{
		Mi();
	}
	if(data==4)
	{
		Fa();
	}
	if(data==5)
	{
		So();
	}
	if(data==6)
	{
		La();
	}
	if(data==7)
	{
		Ti();
	}
	if(data==8)
	{
		DoHigh();
	}
}

void playNote1s(char data)
{
	int i;
	for(i=0; i<100; i++)
	{
		readNote(data);
	}
}

void EEPROMClear()
{
	int i;
	for(i=0; i<1023; i++)
	{
		EEPROMWrite(i, 255);
	}
}

ISR(INT2_vect){
	save = 1 - save;
	if(save==0)
	{
		EEPROMWrite(EEPROMAddress, 9);
		EEPROMAddress=0;
	}
	GIFR|=(1<<INTF2);
}

void playFromEEPROM()
{
	int i=0;
	while(1)
	{
		char data=EEPROMRead(i);
		if(data==9) break;
		readNote(data);
		i++;		
	}
}


ISR(INT0_vect){
	_delay_ms(1000);
	playFromEEPROM();
	GIFR|=(1<<INTF0);
}


int main(void)
{
	DDRB=0b00000001;
	GICR |= (1<<INT2);
	GICR |= (1<<INT0);
	MCUCR |= 3; 
	MCUCSR |= (1<<ISC2);
	DDRA=0x00;
	//EEPROMClear();
	sei();
	
	
    while(1)
    {
		
		unsigned char a=PINA;
		if(a&1)
		{
			if(save)
			{
				EEPROMWrite(EEPROMAddress++, 1);
			}
			Do();
		}
		else
		{
			if(a&(1<<1))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 2);
				}
				Re();
			}
			else if(a&(1<<2))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 3);
				}
				Mi();
			}
			else if(a&(1<<3))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 4);
				}
				Fa();
			}
			else if(a&(1<<4))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 5);
				}
				So();
			}
			else if(a&(1<<5))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 6);
				}
				La();
			}
			else if(a&(1<<6))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 7);
				}
				Ti();
			}
			else if(a&(1<<7))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 8);
				}
				DoHigh();
			}
		}
					
    }
}