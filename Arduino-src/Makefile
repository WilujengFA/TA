# Parameters for compiling
ARDUINO_DIR     = /usr/share/arduino
AVR_TOOLS_DIR	= /usr/share/arduino/hardware/tools/avr
TARGET          = output
ARDUINO_LIBS    =  


BOARD_TAG	= uno
BOARD_SUB	= 16MHzatmega328
# If you found problem on compile, you can uncomment and change MCU and F_CPU
# To know what MCU you can use check board.txt on end of this file
#MCU		# 16MHzatmega328
#F_CPU		= 16000000
MONITOR_PORT = /dev/ttyACM0

# Avrdude code for programming
AVRDUDE		= $(ARDUINO_DIR)/hardware/tools/avr/bin/avrdude
AVRDUDE_CONF	= $(ARDUINO_DIR)/hardware/tools/avr/etc/avrdude.conf
#AVRDUDE_ARD_PROGRAMMER	= wiring
#AVRDUDE_ARD_BAUDRATE	= 115200


# Arduino makefile
include /usr/share/arduino/Arduino.mk

# Bellow you found MCU values extracted from board.txt file. Added just to reference
# MCU data is the info after .menu.cpu.
# Example: #atmegang.menu.cpu.atmega168.build.mcu=atmega168 => MCU = atmega168
#
#atmegang.build.mcu=atmegang
#atmegang.menu.cpu.atmega168.build.mcu=atmega168
#atmegang.menu.cpu.atmega8.build.mcu=atmega8
#bt.menu.cpu.atmega328.build.mcu=atmega328p
#bt.menu.cpu.atmega168.build.mcu=atmega168
#diecimila.menu.cpu.atmega328.build.mcu=atmega328p
#diecimila.menu.cpu.atmega168.build.mcu=atmega168
#esplora.build.mcu=atmega32u4
#ethernet.build.mcu=atmega328p
#fio.build.mcu=atmega328p
#leonardo.build.mcu=atmega32u4
#lilypad.menu.cpu.atmega328.build.mcu=atmega328p
#lilypad.menu.cpu.atmega168.build.mcu=atmega168
#LilyPadUSB.build.mcu=atmega32u4
#megaADK.build.mcu=atmega2560
#mega.menu.cpu.atmega2560.build.mcu=atmega2560
#mega.menu.cpu.atmega1280.build.mcu=atmega1280
#megaADK.build.mcu=atmega2560
#micro.build.mcu=atmega32u4
#mini.menu.cpu.atmega328.build.mcu=atmega328p
#mini.menu.cpu.atmega168.build.mcu=atmega168
#nano.menu.cpu.atmega328.build.mcu=atmega328p
#nano.menu.cpu.atmega168.build.mcu=atmega168
#pro.menu.cpu.16MHzatmega328.build.mcu=atmega328p
#pro.menu.cpu.8MHzatmega328.build.mcu=atmega328p
#pro.menu.cpu.16MHzatmega168.build.mcu=atmega168
#pro.menu.cpu.8MHzatmega168.build.mcu=atmega168
#robotControl.build.mcu=atmega32u4
#robotMotor.build.mcu=atmega32u4
#uno.build.mcu=atmega328p
#yun.build.mcu=atmega32u4
