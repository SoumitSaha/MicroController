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
	float frequency=524;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	PORTC = 0b11111110;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.95419);
		PORTB=1;
		_delay_ms(0.95419);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Re_()
{
	float frequency=555.1586614;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	PORTC = 0b00000010;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.90064);
		PORTB=1;
		_delay_ms(0.90064);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Re()
{
	float frequency=588.1701133;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	PORTC = 0b11111101;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.850094);
		PORTB=1;
		_delay_ms(.850094);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Mi_()
{
	float frequency=623.1445282;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	PORTC = 0b00000100;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.80238);
		PORTB=1;
		_delay_ms(.80238);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Mi()
{
	float frequency=660.1986301;
	float periodMS=(1/frequency)*1000;
	int cycles=durationMS/periodMS;
	PORTC = 0b11111011;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.75734);
		PORTB=1;
		_delay_ms(.75734);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Fa_()
{
	float frequency=741.0479066;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b00001000;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.67472);
		PORTB=1;
		_delay_ms(.67472);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Fa()
{
	float frequency=699.4560835;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b11110111;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.71484);
		PORTB=1;
		_delay_ms(.71484);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void So()
{
	float frequency=785.1129082;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b11101111;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.63685);
		PORTB=1;
		_delay_ms(0.63685);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void La_()
{
	float frequency=831.7981511;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b00100000;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.6011073);
		PORTB=1;
		_delay_ms(0.6011073);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void La()
{
	float frequency=881.2594431;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b11011111;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.56736);
		PORTB=1;
		_delay_ms(0.56736);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void Ti_()
{
	float frequency=933.6618565;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b01000000;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.5355257);
		PORTB=1;
		_delay_ms(0.5355257);
		PORTB=0;
	}
	PORTC = 0b11111111;
}


void Ti()
{
	float frequency=989.1802796;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b10111111;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(0.50546);
		PORTB=1;
		_delay_ms(0.50546);
		PORTB=0;
	}
	PORTC = 0b11111111;
}

void DoHigh()
{
	float frequency=1048;
	float periodMS=(1/frequency)*1000;
	
	int cycles=durationMS/periodMS;
	PORTC = 0b01111111;
	for(int i=0; i<cycles; i++)
	{
		_delay_ms(.477099);
		PORTB=1;
		_delay_ms(.477099);
		PORTB=0;
	}
	PORTC = 0b11111111;
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
	if (data==10)
	{
		Re_();
	}
	if(data==11)
	{
		Mi_();
	}
	if(data==12)
	{
		Fa_();
	}
	if(data==13)
	{
		La_();
	}
	if(data==14)
	{
		Ti_();
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
	_delay_ms(100);
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
	DDRC = 0xFF;
	MCUCSR |= (1<<JTD);
	MCUCSR |= (1<<JTD);
	PORTC = 0xFF;
	ADMUX=0b00100000;
	ADCSRA=0b10000000;
	//EEPROMClear();
	sei();
	
	
    while(1)
    {
		ADCSRA|=(1<<ADSC);
		while(ADCSRA&(1<<ADSC)){;}
		int result=ADCH;
		double y=(result/256.0)*5.0;
		unsigned char a=PINA;
		unsigned char b=PIND;
		if((a&1) || (y>1.1))
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
			else if(b&(1<<3))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 10);
				}
				Re_();
			}
			else if (b&(1<<4))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 11);
				}
				Mi_();
			}
			else if (b&(1<<5))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 12);
				}
				Fa_();
			}
			else if (b&(1<<6))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 13);
				}
				La_();
			}
			else if(b&(1<<7))
			{
				if(save)
				{
					EEPROMWrite(EEPROMAddress++, 14);
				}
				Ti_();
			}
		}
	PORTC = 0b11111111;
	//PORTB = 0b11111011;		
    }
}