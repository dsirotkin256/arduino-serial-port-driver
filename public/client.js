
var io = require("socket.io-client");
var socket = io.connect("http://192.168.0.5:3000"); // domain.com

// command list supported by the server
var blue_light_set_value = "blue_light_set_value";
var blue_light_get_value = "blue_light_get_value";

var blue_light_on = "BLUE_LED::ON";
var blue_light_off = "BLUE_LED::OFF";

var button = document.getElementById("light_button");
var light_status = document.getElementById("light_status");

var isMouseDown = false;

button.addEventListener("mousedown", turnOnLight);
button.addEventListener("mouseup", turnOffLight);

var interval;

function turnOnLight() {
	isMouseDown = true;
	console.log("Turn on light emitted");
	socket.emit(blue_light_set_value, blue_light_on);
	button.innerHTML = "ON";
	interval = setInterval(function() {
		if(isMouseDown) socket.emit(blue_light_set_value, blue_light_on);
	}, 60);
}

function turnOffLight() {
	isMouseDown = false;
	window.clearInterval(interval);
	console.log("Turn off light emitted");
	socket.emit(blue_light_set_value, blue_light_off);
	button.innerHTML = "OFF";
}

turnOffLight.exports = turnOffLight;
turnOnLight.exports = turnOnLight;

socket.on("connect", function () {  
    console.log("Connected!");
    light_status.innerHTML = "";
    socket.on(blue_light_get_value, function(value) {
    	light_status.innerHTML = value;
	});
	socket.on("reconnect", function() {
		console.log("Reconnection...");
		light_status.innerHTML = "Connecting to the server...";
	});
});
