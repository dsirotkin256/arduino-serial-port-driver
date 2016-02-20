
#ifndef pin_h
#define pin_h

#include "Arduino.h"

class Pin
{
protected:
	int address;
public:
	Pin(int addr): address(addr) {}
	virtual void write(int) = 0;
	virtual int read() = 0;
};

class DigitalPin: public Pin
{
public:
	DigitalPin(int addr): Pin(addr) { }
	void write(const int value) {
		digitalWrite(address, value);
	}
	int read() {
		return digitalRead(address);
	}
};

class AnalogPin: public Pin
{
public:
	AnalogPin(int addr): Pin(addr) { }
	void write(const int value) {
		analogWrite(address, value);
	}
	int read() {
		return analogRead(address);
	}
};

#endif
