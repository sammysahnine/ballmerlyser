# Hacknotts 24 Project

import time
import Adafruit_CharLCD as LCD

# Raspberry Pi pin setup
lcd_rs = 25
lcd_en = 24
lcd_d4 = 23
lcd_d5 = 17
lcd_d6 = 18
lad_d7 = 22
lcd_backlight = 2

# Define LCD colum and row size
lcd_columns = 16
lcd_rows = 2

lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7, lcd_columns, lcd_rows, lcd_backlight)

# Project Entry Point
def main():
	# Display Start-up Message
	startup()


def startup():
	lcd.message("Hello\nWorld!)
	time.sleep(5.0)
	lcd.clear()


main()
