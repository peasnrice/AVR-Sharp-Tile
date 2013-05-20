/*
 * SPI.c
 *
 * Created: 1/10/2013 3:33:20 PM
 *  Author: Andrew Evans & Shawn Stoute
 */ 

#include <avr/io.h>
#include "SPI.h"

void initSPI(void){
	// page 202 of atmega 2560 datasheet
	// SPE = 1: SPI Enable
	// MSTR = 1: Sets device to Master
	// SPI2X = 1 & SPR0 = 1: Set prescaler to /8 (2MHz) 
	// DORD = 1: LSB first
	// CPOL = 0, CPHA = 0: SPI mode 0
	
	// Enable SPI
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPI2X)|(1<<SPR0)|(1<<DORD); 
	SPCR &= ~(1<<CPOL);
	SPCR &= ~(1<<CPHA);	
}

// Transmit 1 byte using SPI
unsigned char SPI_TX(char cData){
	SPDR = cData;
	
	// Wait for transmission to finish
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}