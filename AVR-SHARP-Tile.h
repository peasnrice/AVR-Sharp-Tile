/*
*	SharpMemoryLCD.h
*	This library interfaces with the LS013B7DH01 but should easily be configured
*	For use with other SHARP memory LCD's

*	Copyright (C) 2013  Andrew Evans
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef AVRSHARPTILE_H
#define AVRSHARPTILE_H

#define SCREENWIDTH 144
#define SCREENHEIGHT 168

#define SCLK 1 //PB1
#define SI 2 //PB2
#define SCS 5 //PH5
#define EXTC 6 //PH6
#define DISP 4 //PB4
#define EXTM 5 //PB5
#define SS 0 //PB0

#define output_low(port,pin) port &= ~(1<<pin)
#define output_high(port,pin) port |= (1<<pin)
#define set_input(portdir,pin) portdir &= ~(1<<pin)
#define set_output(portdir,pin) portdir |= (1<<pin)

void initLCD(void);
void clearLCD(void);

// prints 18 character long string on specified line, inversion possible.
void printStringOnLine(uint8_t line, char lineText[], uint8_t invert);	

#endif /* AVRSHARPTILE_H_ */