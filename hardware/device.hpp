
#ifndef device_h
#define device_h

#include "Arduino.h"
#include "StandardCplusplus.h"
#include "observer.hpp"
#include "command.hpp"
#include "pin.hpp"

class IODevice
{
protected:
	Pin* pin;
	IODevice(Pin& pin): pin(&pin) { }
	virtual ~IODevice() { };
};

class Led: public IODevice, public IOListener
{
public:
	Led(Pin& pin): IODevice(pin) { }
	~Led() {}
	void turnLightOff() {
		pin->write(LOW);
	}
	void turnLightOn() {
		pin->write(HIGH);
	}
	void notify(const int value) {
		switch (value) {
			case HIGH:
				turnLightOn();
				break;
			case LOW:
				turnLightOff();
				break;
		}
	}
};

class Button: public IODevice, public Broadcaster
{
private:
	int _state;
public:
	Button(Pin& pin): IODevice(pin) { }
	~Button() {}
	bool state() const {
		return _state;
	}
	void pushButton() {
		Serial.println(commands::pushButton);
		_state = HIGH;
		broadcast();
	}
	void releaseButton() {
		Serial.println(commands::releaseButton);
		_state = LOW;
		broadcast();
	}
	void listen() {
		_state = pin->read();
		switch(_state) {
			case HIGH:
			pushButton();
			break;
			case LOW:
			releaseButton();
			break;
		}
	}
	void broadcast() {
		for (auto observer : observers) {
			observer->notify(_state);
		}
	}
};

#endif /* device_h */
