//****main.c****//
#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"
#include "bitmaps.h"

#define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif


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
                			   lcd_gotoxy(0,0);
                			   lcd_puts_p(PSTR("3"));
                			   lcd_display();
                }
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
        else if (bit_is_set(PINB, 5))
        {
            cbi(PORTB, i);
            if (i == 0)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("5"));
            	            			   lcd_display();
            }
            if (i == 1)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("6"));
            	            			   lcd_display();
            }
            if (i == 2)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("7"));
            	            			   lcd_display();
            }
            if (i == 3)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
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
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("9"));
            	            			   lcd_display();
            }
            if (i == 1)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("10"));
            	            			   lcd_display();
            }
            if (i == 2)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("11"));
            	            			   lcd_display();
            }
            if (i == 3)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("12"));
            	            			   lcd_display();
            }
        }
        else if (bit_is_set(PINB, 7))
        {
            if (i == 0)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("13"));
            	            			   lcd_display();
            }
            if (i == 1)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("14"));
            	            			   lcd_display();
            }
            if (i == 2)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("15"));
            	            			   lcd_display();

            }

            if (i == 3)
            {
            	lcd_clear_buffer();
            	            			   lcd_gotoxy(0,0);
            	            			   lcd_puts_p(PSTR("16"));
            	            			   lcd_display();
            }
        }
        cbi(PORTB, i);
    }
}













int main(void){
	DDRB=0b00001111;
	PORTB=0xff;

  lcd_init(LCD_DISP_ON);    // init lcd and turn on
  
  lcd_puts("( ͡° ͜ʖ ͡°) Menu:");  // put string from RAM to display (TEXTMODE) or buffer (GRAPHICMODE)
  lcd_gotoxy(0,2);          // set cursor to first column at line 3
  lcd_puts_p(PSTR("1. Gra"));
  lcd_gotoxy(0,4);
  lcd_puts_p(PSTR("2. Animacja"));
  lcd_gotoxy(0,6);
  lcd_puts_p(PSTR("3. Nie klikaj"));
  lcd_gotoxy(0,8);
  lcd_puts_p(PSTR("4.Zakończ program"));

//#if defined GRAPHICMODE
//  lcd_drawCircle(64,32,7,WHITE); // draw circle to buffer white lines
//  lcd_display();                 // send buffer to display
//#endif

//  lcd_display();
//  lcd_drawBitmap(0,0,bitmap1,128,64,WHITE);
  lcd_display();

  for(;;){
//    getKey();
//    lcd_display();
	  lcd_clear_buffer();
	    lcd_drawBitmap(0,0,bitmap,128,64,WHITE);
	    lcd_display();
	    _delay_ms(1000);
	    lcd_clear_buffer();
	    lcd_drawBitmap(0,0,bitmap1,128,64,WHITE);
	    lcd_display();
	    _delay_ms(1000);
	    lcd_clear_buffer();
	    lcd_drawBitmap(0,0,bitmap2,128,64,WHITE);
	    lcd_display();
  }
  return 0;
}
