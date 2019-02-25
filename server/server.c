#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "utilities.h"

// C++ Requirments
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

#define VER 1
/*
Intitializes the socket connections and bindings 
for the server. returns a connection struct of 
type SocketInfo

*/
struct SocketInfo init(int port) {
    struct sockaddr_in address;
    int opt = 1; 
    
    // Create a Socket using IPV4(AF_INET) using TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Check that the socket was created
    if (sock == 0) {
        perror("Error socket stream on port");
        exit(EXIT_FAILURE);
    } else {
        printf("Server: Socket Stream created on port -> %u\n", port);
    }

    int sockset = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if (sockset == 1) {
        perror("Error setting sock address sturucture\n");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(port); 
    
    // Now bind that socket to a port
    int binded = bind(sock, (struct sockaddr *)&address, sizeof(address));
    if (binded < 0) {
        perror("Error binding to port");
        exit(EXIT_FAILURE);
    } else {
        printf("Server: Socket Binded to port -> %u\n", port);
    }

    struct SocketInfo info;
    info.socket = sock;
    info.address = address;
    return info;
}

int processMessages(int port) {
    int fresh_socket, read_value;
    char *msg = malloc(sizeof(char)); 
    
    struct SocketInfo connection = init(port);
    struct sockaddr_in address = connection.address;
    int addrlen = sizeof(address);

    // Continue accepting messages indefinetly
    while (1) {
        printf("Server: Listening for messages...\n"); 
        // Reset the the socket to our original value
        fresh_socket = connection.socket;
        if (listen(fresh_socket, 3) < 0) { 
            perror("Error while listening"); 
            exit(EXIT_FAILURE);
        } 
    
        fresh_socket = accept(fresh_socket, (struct sockaddr *)&address, (socklen_t*) &addrlen);
        if (fresh_socket < 0) { 
            perror("Error while accepting message"); 
            exit(EXIT_FAILURE);
        } 

        // Server response
        char response[1024] = "Message Received at"; 
        char *cur_time = time_stamp(); 
        snprintf(response, sizeof(response), "%s: %s", response, cur_time);

        read_value = read(fresh_socket , msg, 1024); 
        printf("Client: %s | Received at %s\n", msg, cur_time);
        
        send(fresh_socket, response, strlen(response), 0); 
        printf("Server: Message Confirmation Sent to Client\n"); 
    }
    
    return 0; 
}

int main(int argc, char *argv[]) {
    int port;
    printf("SocketStream Server v%d\n", VER );

    if ( argc == 2 ) {
      printf("Server: Starting new TCP server on port -> %s\n", argv[1]);
      port = atoi(argv[1]);
    } else if( argc > 2 ) {
        perror("Error: Too many arguments supplied. Please supply a valid port for the TCP server to run on.");
        exit(EXIT_FAILURE);
    } else {
        perror("Expected arguement missing => Port");
        exit(EXIT_FAILURE);
    }

    if (processMessages(port) == 1) {
        perror("Server Failure while handling message");
        exit(EXIT_FAILURE);
    }
    return 0;
}