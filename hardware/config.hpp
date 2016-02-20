// config.hpp

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "Arduino.h"

const char CMD_END = '\r';

const unsigned short MAX_COMMAND_LENGTH = 30;
const unsigned short BAUDRATE_VALUE = 9600; // 2400
const unsigned char BLUE_LED_PIN_ADDRESS = 3;
const unsigned char PUSH_BUTTON_PIN_ADDRESS = 5;

#endif
