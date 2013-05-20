/*
* SharpMemoryLCD.c
*
* Created: 1/10/2013 3:35:33 PM
*  Author: Andrew Evans
*/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "SPI.h"

#include "AVR-SHARP-Tile.h"
#include "font.h"

void initLCD(void){
	set_output(DDRB, DISP);
	set_output(DDRH, EXTC);
	set_output(DDRB, EXTM);
	set_output(DDRB, SI);
	set_output(DDRH, SCS);
	set_output(DDRB, SCLK);
	set_output(DDRB, SS);
	
	//turn on display
	output_high(PORTB, EXTM);
	output_high(PORTB, DISP);
	
	output_high(PORTB, SS);
	initSPI();
}

void clearLCD(void){
	output_high(PORTH, SCS); //Set Chip Select HIGH
	SPI_TX(0x04);
	SPI_TX(0x00);
	output_low(PORTH, SCS); //Set Chip Select HIGH
}

void printStringOnLine(uint8_t lineNumber, char lineText[], uint8_t invert){
	uint8_t charLine = 0;
	lineNumber *= 21;
	lineNumber++;
	// Set Chip Select HIGH
	output_high(PORTH, SCS); 
	// Send write command
	SPI_TX(0x01);
	// Send Line Address, first row of pixels is accessed by address 1 and not 0.
	for (unsigned char l = lineNumber; l < lineNumber + 21; l++){
		if(l != lineNumber)
			SPI_TX(0x00);
		SPI_TX(l);	
		// Send pixel data by retrieving tiles from font.h
		for(uint8_t i = 0; i < 18; i++){
			if (invert == 0)
				SPI_TX(pgm_read_byte(font8x21+(((unsigned char)lineText[i]-32)*21+charLine)));
			else
				SPI_TX(~(pgm_read_byte(font8x21+(((unsigned char)lineText[i]-32)*21+charLine))));
		}		
		charLine++;
	}	
	SPI_TX(0x00);
	SPI_TX(0x00);

	output_low(PORTH, SCS); //Set Chip Select LOW	
}