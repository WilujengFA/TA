/*
Project:	coba
Board:		uno
MCU:		16MHzatmega328
FRENQUENCY:	16000000

Created using QtCreator
*/
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

int main()
{
    // Initialize Arduino Librairies
    init();

    setup();

    while (1)
    {
        loop();
    }

}
