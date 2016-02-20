"use strict";

var express = require("express");
var app = express();
var server = require("http").createServer(app);
var io = require("socket.io")(server);
var serial = require("serialport").SerialPort;
var command = require("./command");

app.use(express.static("public"));

var port = 3000;
var arduino = new serial("/dev/cu.usbmodem1411", { baudRate: 9600 });

var arduino_message_chunk = ""; // information that is comming from arduino

// send message to client from arduino
var send_message = function(message) {	
	// send the message to the clients
	io.sockets.emit("notification", message);
}

// listen the serial port response sent from arduino and write status to client
arduino.on("data", function(data) {
	arduino_message_chunk += data.toString();
	dispatchSerialData(arduino_message_chunk);
});

arduino.on("close", function() {
	io.sockets.emit(command.client.connection_closed);
});

arduino.on("error", function(err) {
	console.log(err);
});

function dispatchSerialData(data) {
	if (data.indexOf("\r") >= 0) {
		data = data.replace(/\r\n|\n|\r/g, "");
		// check whether the message was recognised as a command 
		switch(data) {
			case command.server.blue_led_on:
			case command.server.blue_led_off: 
			case command.server.button_push:
			case command.server.button_release:  
				console.log(data);
				send_message(data);
				arduino_message_chunk = "";
				break;
		}
	}
	// if the message was not recognised flash buffer
	// if exceed limits then flash message
	if (arduino_message_chunk.length > command.server.MAX_LENGTH) {
		arduino_message_chunk = "";
	}
}

// create websocket
io.sockets.on("connection", function(socket) {
	console.log("socket::status::new_connection");
	// listen the request sent from the client to change led status on arduino
	socket.on(command.client.blue_light_set_value, function(value) {
		arduino.write(value + '\r', function() {
			console.log("socket::" + value);
		});
	});
	// detect when client goes offline
	socket.on("disconnect", function() {
		console.log("socket::status::disconnect");
	});
});

app.get("/", function(req, res) {
	res.sendFile(__dirname + "/public/client.html");
});

server.listen(port, console.log("Server is listening on " + port));
