# Hacknotts 24 Project

import time
import os
import RPI.GPIO as GPIO
import Adafruit_CharLCD as LCD





# Raspberry Pi pin setup for LCD
lcd_rs = 25
lcd_en = 24
lcd_d4 = 23
lcd_d5 = 17
lcd_d6 = 18
lad_d7 = 22
lcd_backlight = 2

# Raspberry Pi pin setup for alcohol sensor
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.IN)

# Define LCD colum and row size
lcd_columns = 16
lcd_rows = 2

lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7, lcd_columns, lcd_rows, lcd_backlight)

# Project Entry Point
def main():
	# Display Start-up Message
	startup()

def loop():
	while True:
		sensor()
		time.sleep(5.0)


def startup():
	lcd.message("Hello\nWorld!")
	time.sleep(5.0)
	lcd.clear()
	loop()

# Sensor function. Run upon button press/set times per second?
def sensor():
	input = GPIO.input(8)
	if input >= 0.012 and input <= 0.015:
		lcd.message("Ballmer Peaked!\nBAC is " + str(input) + "%")
		time.sleep(5.0)
		lcd.message("Happy Coding!")
		time.sleep(2)
		lcd.clear()
	elif input > 0.012:
		lcd.message("GET DRINKING\nBAC is " + str(input) + "%")
		time.sleep(5.0)

	elif input < 0.015:
		lcd.message("Woah there buddy\nBAC is " + str(input) + "%")
		time.sleep(5.0)

	lcd.clear()

main()
