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

int low = 1023 * 0.05, high = 1023 * 0.12; //low -51 high -123

void getKeyServo()
{
    for (int i = 0; i < 4; i++)
    {
        sbi(PORTD, i);
        if (bit_is_set(PIND, 4))
        {
            cbi(PORTD, i);
            if (i == 0)
            {
            				lcd_clear_buffer();
            			   lcd_gotoxy(0,0);
            			   lcd_puts_p(PSTR("1"));
            			   lcd_display();
            }
            if (i == 1)
            {
            				lcd_clear_buffer();
            			   lcd_gotoxy(0,0);
            			   lcd_puts_p(PSTR("2"));
            			   lcd_display();
            }
            if (i == 2)
            {
                {
                					lcd_clear_buffer();
                					lcd_gotoxy(0, 0);
                					lcd_puts_p(PSTR("wykonuje automat"));
                					lcd_display();
                	while(1){
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
                }}
            }
            if (i == 3)
            {
                {
                	lcd_clear_buffer();
                			   lcd_gotoxy(0,0);
                			   lcd_puts_p(PSTR("4"));
                			   lcd_display();
                }
            }
        }
        cbi(PORTD, i);
    }
}

void init_PWM()
{
	TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1); // TOP -1023
	TCCR1B |= (1 << WGM12) | (1 << CS12); // ustawienie prescalera na 256 bitow
}

void getKey()
{
	for (int i = 0; i < 4; i++)
	{
		sbi(PORTD, i);
		if (bit_is_set(PIND, 4))
		{
			cbi(PORTD, i);
			if (i == 0)
			{
				init_PWM();

				OCR1A = (low + high) / 2;
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
					getKeyServo();
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
		else if (bit_is_set(PIND, 5))
		{
			cbi(PORTD, i);
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
		else if (bit_is_set(PIND, 6))
		{
			cbi(PORTD, i);
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
		else if (bit_is_set(PIND, 7))
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
		cbi(PORTD, i);
	}
}



int main(void)
{
	DDRD = 0b00001111;
	//PORTB = 0xff;
	DDRB |= (1 << DDB1) | (1 << DDB2);
	PORTD = 0xff;

	lcd_init(LCD_DISP_ON); // init lcd and turn on
	lcd_gotoxy(0,0);
	lcd_puts("Menu:");
	lcd_gotoxy(0, 2);
	lcd_puts_p(PSTR("1. Obsluga serwa"));
	lcd_gotoxy(0, 4);
	lcd_puts_p(PSTR("2. Animacja"));
	lcd_gotoxy(0, 6);
	lcd_puts_p(PSTR("3. Zakoncz program"));

	lcd_display();

	for (;;)
	{
		getKey();
		lcd_display();
	}
	return 0;
}
