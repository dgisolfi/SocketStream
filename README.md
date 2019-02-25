# SocketStream
A TCP stream for sending data from an instance of a client to a server.

## Server

The server can be run on any available port and can receive messages from any number of clients. To run a SocketStream server the source code must be pulled and built on the host machine.

### Building the Server

To build the server on a host machine run the following command in the server directory `make server`. The result of this command will be a executable called "server" within the same directory.

### Running the Server

After the executable is built the server can be run using the following command `./server <port>`. Make sure to pass the program a valid port when booting it up.

<!-- ## Client -->
