/*
*	This is example code that prints 8 rows of text, each 18 characters long to a SHARP memory LCD
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


#include <avr/io.h>
#include "AVR-SHARP-Tile.h"

int main(void)
{
	initLCD();
	clearLCD();
	
    printStringOnLine(0,"Tile Based GFX Lib",1);
    printStringOnLine(1,"##  ##  ##  ##  ##",0);
    printStringOnLine(2,"      Invert!     ",1);
    printStringOnLine(3,"                  ",0);
    printStringOnLine(4,"(VERY)Easy to use!",0);
    printStringOnLine(5,"                  ",0);
    printStringOnLine(6,"I hope this helps ",0);
    printStringOnLine(7,"          somebody",0);

    while(1)
    {

    }
}