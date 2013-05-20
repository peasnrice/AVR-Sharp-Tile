AVR-Sharp-Tile
==============

A tile based library for SHARP memory LCD's, this library is tailored towards the LS013B7DH01.

In order to use this library you will need a bitmap font library.
I created the font.h file using this very useful piece of software built by a Vladamir N.
https://code.google.com/p/lcd-image-converter/

On an atmega 2560 the pins used are:
SCLK 	==> 	PB1
SI 		==> 	PB2
SCS	 	==> 	PH5
EXTC 	==> 	PH6
DISP 	==> 	PB4
EXTM 	==> 	PB5
SS 		==> 	PB0

On an arduino MEGA these pins are:
SCLK 	==> 	D52
SI 		==> 	D51
SCS	 	==> 	D8
EXTC 	==> 	D9
DISP 	==> 	D10
EXTM 	==> 	D11
SS 		==> 	D53