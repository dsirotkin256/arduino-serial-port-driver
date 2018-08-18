
#include "StandardCplusplus.h"
#include "config.hpp"
#include "helpers.hpp"
#include "device.hpp"
#include "command.hpp"
#include "pin.hpp"

String cmd = "";
bool isEnd = false;

// Init push_button_pin
DigitalPin push_button_pin = DigitalPin(PUSH_BUTTON_PIN_ADDRESS);
// Init blue_led_pin
DigitalPin blue_led_pin = DigitalPin(BLUE_LED_PIN_ADDRESS);
// Init led
Led* blue_led;
// Init button
Button* button;

// Init led commands for remote request execution
Command<Led>* blue_on;
Command<Led>* blue_off;
Command<Button>* push_button;
Command<Button>* release_button;

void setup() {
	Serial.begin(BAUDRATE_VALUE);

  blue_led = new Led(blue_led_pin);
  button = new Button(push_button_pin);

	blue_on =  new Command<Led>(commands::turnOnBlueLight,
		blue_led,
		&Led::turnLightOn);
	
	blue_off = new Command<Led>(commands::turnOffBlueLight,
		blue_led,
		&Led::turnLightOff);
	
	push_button = new Command<Button>(commands::pushButton,
		button,
		&Button::pushButton);
	
	release_button = new Command<Button>(commands::releaseButton, 
		button, 
		&Button::releaseButton);
	
// Blue Led subscribes on button changes.
// Thus, the led will recieve notifications
	button->subscribe(blue_led);
	
// Register commands
	cmds.push_back(blue_on);
	cmds.push_back(blue_off);
	cmds.push_back(push_button);
	cmds.push_back(release_button);
}

// Event loop
void loop() {
// Puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection
  button->listen();
// Execute remote command
  if (isEnd) { 
    executeCommand(cmd);
  }
  if (isEnd || isExceedLimit(cmd)) {
    flashString(cmd);
    isEnd = false;
  }
}

/* Listens for incoming information though the port */
void serialEvent() {
	while(Serial.available()) {
		char input = (char)Serial.read();
		if (input == CMD_END) isEnd = true;
    if (!isEnd) cmd += input;
	}
}

