#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int num = 1; //saymaya başla

int main(void)
{
	DDRD = 0xF0;  //d4-d7 arası
	DDRB = 0xF;  //b0-b3 arası
	DDRC &= 0x03; //a0 ve a1 çıkış
	while(1)
	{
		if (PINC & 0b00000001)  // PB5 pininden 1 okunduğu zaman girilen döngü
		{
			num=num-1;
		}
		if (PINC & 0b00000010)  // PB5 pininden 1 okunduğu zaman girilen döngü
		{
			num=num+1;
		}
		_delay_ms(50); //debounce ı önlemek için


		PORTD &= 0b00001111;  //onlar basamağı
		PORTD |= num<<4;

		PORTB &= 0b11110000; //onlar basamağı
		PORTB |= num>>4;
		
		if(num==99){
			num=0;//99 u geçmeyecek
		}

	}
	return 0;
}
