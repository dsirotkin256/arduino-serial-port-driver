# Remote-Control-Arduino-Node.js
A simple implementation of client-server architecture application with Node.js, Socket.io and Arduino Uno board.

### Hardware requirements:
+ Arduino Uno
+ IO pluggable devices (*e.g. LED, Buttons, Servo Motors, LCD Screens, Cameras, etc.*)
 
### Software requirements:

###### Hardware specific 

+ Arduino IDE or [Arduino Like IDE](https://github.com/Robot-Will/Stino)
+ Standard C++ library for [Arduino](https://github.com/maniacbug/StandardCplusplus)

###### Client/Server specific

+ Node [npm](https://www.npmjs.com) environment
+ [Express.js](https://github.com/expressjs/express)
+ Socket.io (both [server](https://github.com/socketio/socket.io) and [client](https://github.com/socketio/socket.io-client) versions)
+ [Serialport](https://github.com/voodootikigod/node-serialport)
+ [Browserify](https://github.com/substack/node-browserify)

![alt info](https://raw.githubusercontent.com/nrdwnd/Remote-Control-Arduino-Node.js/master/.readme_material/led.jpeg "Client turns on blue light :)")
