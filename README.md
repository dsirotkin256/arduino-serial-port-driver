# LED Control From Browser with an usage of Arduino and Node.js
A simple implementation of client-server architecture application with Node.js, Socket.io and Arduino Uno board.

### Hardware requirements:
+ Arduino Uno
+ LED
+ Button (*Optional*)

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

# Illustration
<img src="https://raw.githubusercontent.com/nrdwnd/Remote-Control-Arduino-Node.js/master/.readme_material/led.jpeg" alt="Drawing" height="400"/>

# Bugs and Feedback
For bugs, questions and discussions please use the [issues](https://github.com/nrdwnd/Remote-Control-Arduino-Node.js/issues).

#LICENSE
The MIT License (MIT)
Copyright \(c\) 2016 Dmitry Sirotkin

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
