//****main.c****//
#include <avr/io.h>
#include <util/delay.h>

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

void init_PWM() // zadanie 1
{
	TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1);
	TCCR1B |= (1 << WGM12) | (1 << CS12); // ustawienie prescalera na 256 bitow
}

void getKey()
{
	for (int i = 0; i < 4; i++)
	{
		sbi(PORTB, i);
		if (bit_is_set(PINB, 4))
		{
			cbi(PORTB, i);
			if (i == 0)
			{
				//init_PWM();
				int low = 1023 * 0.05, high = 1023 * 0.12;
				OCR1A = (low + high) / 2;
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts("Obsluga serwa:"); // put string from RAM to display (TEXTMODE) or buffer (GRAPHICMODE)
				lcd_gotoxy(0, 2);			// set cursor to first column at line 3
				lcd_puts_p(PSTR("1. Bezwgledny kat"));
				lcd_gotoxy(0, 4);
				lcd_puts_p(PSTR("2. Wzgledny kat"));
				lcd_gotoxy(0, 6);
				lcd_puts_p(PSTR("3. Automatyczny tryb"));
				lcd_display();

				while (1)
				{

//					if (bit_is_set(PINB, 4))
//					{
//						switch (i)
//						{
//						case 0:
//						{
//						}
//						break;
//						}
//					}

					//            			if (bit_is_clear(PIND, 1))
					//            			{
					//            				if (bit_is_clear(PIND, 2) && OCR1A < high)  //zadanie 4
					//            				{
					//            					cbi(PORTD, PD5);
					//            					OCR1A = OCR1A + 1;
					//            					_delay_ms(200);
					//            				}
					//            				if (bit_is_clear(PINB, 1) && OCR1A > low)
					//            				{
					//            					cbi(PORTD, PD5);
					//            					OCR1A = OCR1A - 1;
					//            					_delay_ms(200);
					//            				}
					//            				else
					//            				{
					//            					sbi(PORTD, PD5);
					//            					_delay_ms(200);
					//            				}
					//            			}
					//            			else
					//            			{
					//            				int i = 50;
					//            				while (i != high) //zadanie 3
					//            				{
					//            					OCR1A = i;
					//            					_delay_ms(200);
					//            					i++;
					//            				}
					//            				while (i != low)
					//            				{
					//            					OCR1A = i;
					//            					_delay_ms(200);
					//            					i--;
					//            				}
					//            			}
				}
			}
			if (i == 1)
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
					getKey();
				}
			}
			if (i == 2)
			{
				{
					lcd_clear_buffer();
					lcd_gotoxy(0, 0);
					lcd_puts_p(PSTR("3"));
					lcd_display();
				}
			}
			if (i == 3)
			{
				{
					lcd_clear_buffer();
					lcd_display();
				}
			}
		}
		else if (bit_is_set(PINB, 5))
		{
			cbi(PORTB, i);
			if (i == 0)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("5"));
				lcd_display();
			}
			if (i == 1)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("6"));
				lcd_display();
			}
			if (i == 2)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("7"));
				lcd_display();
			}
			if (i == 3)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("8"));
				lcd_display();
			}
		}
		else if (bit_is_set(PINB, 6))
		{
			cbi(PORTB, i);
			if (i == 0)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("9"));
				lcd_display();
			}
			if (i == 1)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("10"));
				lcd_display();
			}
			if (i == 2)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("11"));
				lcd_display();
			}
			if (i == 3)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("12"));
				lcd_display();
			}
		}
		else if (bit_is_set(PINB, 7))
		{
			if (i == 0)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("13"));
				lcd_display();
			}
			if (i == 1)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("14"));
				lcd_display();
			}
			if (i == 2)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("15"));
				lcd_display();
			}

			if (i == 3)
			{
				lcd_clear_buffer();
				lcd_gotoxy(0, 0);
				lcd_puts_p(PSTR("16"));
				lcd_display();
			}
		}
		cbi(PORTB, i);
	}
}

int main(void)
{
	DDRB = 0b00001111;
	PORTB = 0xff;
	//DDRD = 0x00;

	lcd_init(LCD_DISP_ON); // init lcd and turn on

	lcd_puts("( ͡°.°) Menu:"); // put string from RAM to display (TEXTMODE) or buffer (GRAPHICMODE)
	lcd_gotoxy(0, 2);		  // set cursor to first column at line 3
	lcd_puts_p(PSTR("1. Obsluga serwa"));
	lcd_gotoxy(0, 4);
	lcd_puts_p(PSTR("2. Animacja"));
	lcd_gotoxy(0, 6);
	lcd_puts_p(PSTR("3. Nie klikaj"));
	lcd_gotoxy(0, 8);
	lcd_puts_p(PSTR("4.Zakończ program"));

	lcd_display();

	for (;;)
	{
		getKey();
		lcd_display();
	}
	return 0;
}
