
#ifndef helpers_h
#define helpers_h

#include "config.hpp"
#include "Arduino.h"

/* Prevents buffer overflow by checking cmd */
bool isExceedLimit(const String& cmd) {
	return cmd.length() > MAX_COMMAND_LENGTH;
}
/* Prepares command String for a new value */
void flashString(String& _) {
	_ = "";
}

#endif
