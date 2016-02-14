
const int led_pin = 3;
const int push_button = 5;

const String on_command = "BLUE_LED::ON";
const String off_command = "BLUE_LED::OFF";

bool isCommandEnd = true;
String led_command_status = off_command; // contains client message
const int MAX_COMMAND_LENGTH = 30;

void setup() {
	Serial.begin(2400);
	pinMode(led_pin, OUTPUT);
	pinMode(push_button, INPUT);
}

void loop() {
	EventDispatcher();
}

void EventDispatcher() {
	onLedControlEvent();

	if (isCommandEnd || led_command_status.length() >= MAX_COMMAND_LENGTH) {
		flashCommandString();
	}
}

void onLedControlEvent() {
	if (isButtonPressed()) {
		turnOnLight();
		Serial.println(on_command);
	} else {
		turnOffLight();
		Serial.println(off_command);
	}
}

void flashCommandString() {
	led_command_status = "";
	isCommandEnd = false;
}

bool isButtonPressed() {
	return isPhysicallyPressed() || isRemoteButtonPressed();
}

bool isRemoteButtonPressed() {
	return isCommandEnd && led_command_status == on_command;
}

bool isPhysicallyPressed() {
	return digitalRead(push_button) == HIGH;
}

void turnOnLight() {
	digitalWrite(led_pin, HIGH);
}

void turnOffLight() {
	digitalWrite(led_pin, LOW);
}

// Listen for ingoing information though the port
void serialEvent() {
	while(Serial.available()) {
		char input = (char)Serial.read();
		if (input == '\r') {
			isCommandEnd = true;
			break;
		}
		led_command_status += input;
	}
}
