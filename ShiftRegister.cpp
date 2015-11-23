/*
  ShiftRegister.cpp - Library for communicating with shift registers.
  Created by Zackary Akil, August 17, 2014.
  Copyright (C) 2014 Zackary Akil.
*/

#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int dataInPin, int latchPin, int clockPin, int outputSize)
{
	pinMode(dataInPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);

	_dataInPin = dataInPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
	_outputSize = outputSize;
}

void ShiftRegister::pushBit (boolean bitToAdd)
{
  digitalWrite(_clockPin, LOW); 
  digitalWrite(_dataInPin, bitToAdd); 
  digitalWrite(_clockPin, HIGH); 
  digitalWrite(_clockPin, LOW);
}

void ShiftRegister::latchBits ()
{
	digitalWrite(_latchPin, HIGH);
	digitalWrite(_latchPin, LOW);
}

void ShiftRegister::displayBits (boolean bitsToDisplay[])
{
	for(int i = 0; i < _outputSize; i++){
		pushBit(bitsToDisplay[i]);
	}
	latchBits();
}

