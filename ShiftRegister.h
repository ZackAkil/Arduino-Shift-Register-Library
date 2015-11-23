/*
  ShiftRegister.cpp - Library for communicating with shift registers.
  Created by Zackary Akil, August 17, 2014.
  Copyright (C) 2014 Zackary Akil.
*/
  
#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"

class ShiftRegister
{
	public: 
	ShiftRegister(int dataInPin, int latchPin, int clockPin, int outputSize);
	void displayBits (boolean bitsToDisplay[]);

	private:
	void pushBit(boolean bitToAdd);
	void latchBits();
	int _dataInPin;
	int _latchPin;
	int _clockPin;
	int _outputSize;
};

#endif