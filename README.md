# SocketStream
A TCP stream for sending data from an instance of a client to a server.

## Server

The server can be run on any available port and can receive messages from any number of clients. To run a SocketStream server the source code must be pulled and built on the host machine.

### Building the Server

The Server is implemented in C and C++ each perform exactly the same and are both built with the same process. To build the server on a host machine run the following command in the server directory `make server` or to build in C++ run `make cppserver`. The result of this command will be an executable called "server" within the same directory.

### Running the Server

After the executable is built the server can be run using the following command `./server <port>`. Make sure to pass the program a valid port when booting it up. To exit the server press any key.

## Client

The client should be run on the same port that a running server is on. The client will send the message passed to it and then exit. To use the client as the server it must be built first.

### Building the Client

The Client is implemented in C and C++ each perform exactly the same and are both built with the same process. Inside the client directory run `make client` or `make cppclient`.

### Running the Client

Like the Server the Client takes an argument for the port it should create a connection to. Additionally after the port, the message to be sent to the Server should be provided. `./client <port> <msg>

Example: `./server 8080 test`