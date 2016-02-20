
var io = require("socket.io-client");
var socket = io.connect("http://192.168.0.5:3000"); 
var command = require("../command");

var button = document.getElementById("light_button");
var light_status = document.getElementById("light_status");

var isMouseDown = false;

button.addEventListener("mousedown", turnOnLight);
button.addEventListener("mouseup", turnOffLight);

var interval;

var turnOnLight = function() {
	isMouseDown = true;
	console.log("Turn on light emitted");
	socket.emit(command.client.blue_light_set_value, 
		command.server.blue_led_on);
	interval = setInterval(function() {
		if(isMouseDown) 
			socket.emit(command.client.blue_light_set_value, 
				command.server.blue_led_on);
	}, 60);
}

var turnOffLight = function() {
	isMouseDown = false;
	window.clearInterval(interval);
	console.log("Turn off light emitted");
	socket.emit(command.client.blue_light_set_value, command.server.blue_led_off);
}

socket.on("connect", function () {  
    console.log("Connected!");
    light_status.innerHTML = "";
    socket.on("notification", function(value) {
    	light_status.innerHTML = value;
	});
	socket.on(command.client.connection_closed, function() {
		light_status.innerHTML = "Hardware device is disabled";
	});
	socket.on("reconnect", function() {
		console.log("Reconnection...");
		light_status.innerHTML = "Connecting to the server...";
	});
});

turnOffLight.exports = turnOffLight;
turnOnLight.exports = turnOnLight;
