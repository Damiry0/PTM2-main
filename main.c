//****main.c****//
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#include "lcd.h"
#include "bitmaps.h"

#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))

#ifndef cbi
#define cbi(reg, bit) reg &= ~(_BV(bit))
#endif

#ifndef sbi
#define sbi(reg, bit) reg |= (_BV(bit))
#endif

int low = 1023 * 0.061, high = 1023 * 0.125, middle= 65; // low -51 high -123

void init_PWM()
	{
		TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1); // TOP -1023
		TCCR1B |= (1 << WGM12) | (1 << CS12);				   // ustawienie prescalera na 256 bitow
	}

int getKey()
	{
		_delay_ms(2000);
		for (int i = 0; i < 4; i++)
		{
			sbi(PORTD, i);
			if (bit_is_set(PIND, 4))
			{
				cbi(PORTD, i);
				return  i + 1;
			}
			else if (bit_is_set(PIND, 5))
			{
				cbi(PORTD, i);
				return i + 5;
			}
			else if (bit_is_set(PIND, 6))
			{
				cbi(PORTD, i);
				return i + 9;
			}
			else if (bit_is_set(PIND, 7))
			{
				cbi(PORTD, i);
				return i + 13;
			}
			cbi(PORTD, i);
		}
		return 0;
	}

void ServoControl(int option)
{
	switch (option)
	{
	case 1:
	{
		lcd_clear_buffer();
		lcd_gotoxy(0, 0);
		lcd_puts_p(PSTR("Podaj wartosc kata:"));
		lcd_display();
		static char* buf="";
		while(1)
		{
			int key = getKey();
			if(key!=0)
			{
				if(key==16)
				{
					float tmp1 = 1023.0*0.06 + atof(buf)/180.0*65;
					int tmp2= tmp1;
					OCR1A = tmp2;
				}
				lcd_gotoxy(0, 4);
				char c = key + '0';
				strncat(buf, &c,1);
				lcd_puts(buf);
				lcd_display();
			}
		}
	}
	break;

	case 2:
	{
		lcd_clear_buffer();
		lcd_gotoxy(0, 0);
		lcd_puts_p(PSTR("Podaj wartosc kata:"));
		lcd_display();
	}
	break;

	case 3:
	{
		lcd_clear_buffer();
		lcd_gotoxy(0, 0);
		lcd_puts_p(PSTR("wykonuje automat"));
		lcd_display();
		while (1)
		{
			int i = 50;
			while (i != high)
			{
				OCR1A = i;
				_delay_ms(200);
				i++;
			}
			while (i != low)
			{
				OCR1A = i;
				_delay_ms(200);
				i--;
			}
		}

	}
	break;
	}

	}




	void MenuControl(int option)
	{
		switch (option)
		{
		case 1:
		{
			init_PWM();

			OCR1A = (low+high)/2;
			lcd_clear_buffer();
			lcd_gotoxy(0, 0);
			lcd_puts_p(PSTR("Obsluga serwa:"));
			lcd_gotoxy(0, 2);
			lcd_puts_p(PSTR("1. Bezwgledny kat"));
			lcd_gotoxy(0, 4);
			lcd_puts_p(PSTR("2. Wzgledny kat"));
			lcd_gotoxy(0, 6);
			lcd_puts_p(PSTR("3. Automatyczny tryb"));
			lcd_display();
			_delay_ms(2000);

			while (1)
			{
				ServoControl(getKey());
			}
		}
		break;
		case 2:
		{
			while (1)
			{
				lcd_clear_buffer();
				lcd_drawBitmap(0, 0, bitmap, 128, 64, WHITE);
				lcd_display();
				_delay_ms(1000);
				lcd_clear_buffer();
				lcd_drawBitmap(0, 0, bitmap1, 128, 64, WHITE);
				lcd_display();
				_delay_ms(1000);
				lcd_clear_buffer();
				lcd_drawBitmap(0, 0, bitmap2, 128, 64, WHITE);
				lcd_display();
				if(getKey()==4) break;
			}
		}
		break;
		case 3:
		{

			lcd_clear_buffer();
			lcd_gotoxy(0, 0);
			lcd_puts_p(PSTR("3"));
			lcd_display();
		}
		break;
		case 4:
				{
					//MainMenu();
				}
				break;
		case 16:
		{
			lcd_clear_buffer();
			lcd_gotoxy(0, 0);
			lcd_puts_p(PSTR("16"));
			lcd_display();
		}
		break;
		}
	}

	void MainMenu()
	{
		lcd_clear_buffer();
		lcd_gotoxy(0, 0);
		lcd_puts("Menu:");
		lcd_gotoxy(0, 2);
		lcd_puts_p(PSTR("1. Obsluga serwa"));
		lcd_gotoxy(0, 4);
		lcd_puts_p(PSTR("2. Animacja"));
		lcd_gotoxy(0, 6);
		lcd_puts_p(PSTR("3. Zakoncz program"));
		//lcd_drawRect(1,1,128,64,WHITE);
		lcd_display();

		for (;;)
		{
			MenuControl(getKey());
			lcd_display();
		}
	}

	int main()
	{
		DDRD = 0b00001111; // keyboard
		DDRB |= (1 << DDB1) | (1 << DDB2); // OCR registers
		PORTD = 0xff;

		lcd_init(LCD_DISP_ON); // init lcd and turn on

		MainMenu();

		return 0;
	}
