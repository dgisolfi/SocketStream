#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "utilities.h"

/*
Intitializes the socket connections and bindings 
for the server. returns a connection struct of 
type SocketInfo
*/
struct SocketInfo init() {
    struct sockaddr_in address;
    int opt = 1; 
    
    // Create a Socket using IPV4(AF_INET) using TCP
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Check that the socket was created
    if (sock == 0) {
        printf("Error socket stream on port: %u\n", PORT);
        exit(1);
    } else {
        printf("Socket Stream created on port: %u\n", PORT);
    }

    int sockset = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if (sockset == 1) {
        printf("Error setting sock address sturucture\n");
        exit(1);
    }

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Now bind that socket to a port
    int binded = bind(sock, (struct sockaddr *)&address, sizeof(address));
    if (binded < 0) {
        printf("Error binding to port: %u\n", PORT);
        exit(1);
    } else {
        printf("Socket Binded to port: %u\n", PORT);
    }

    struct SocketInfo si;
    si.socket = sock;
    si.address = address;
    return si;
}

int main() {
    int fresh_socket, read_value;
    char msg = 0; 
     
    struct SocketInfo connection = init();
    fresh_socket = connection.socket;
    struct sockaddr_in address = connection.address;
    int addrlen = sizeof(address);

    char *response = "Message Received by Server"; 


    if (listen(fresh_socket, 3) < 0) { 
        printf("Error while listening"); 
        exit(1);
    } 

    fresh_socket = accept(fresh_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (fresh_socket < 0) { 
        printf("Error while accepting message"); 
        exit(1);
    } 

    read_value = read(fresh_socket , &msg, 1024); 
    printf("%c\n", msg); 
    send(fresh_socket , response , strlen(response) , 0 ); 
    printf("Message Confirmation Sent to Client\n"); 
    return 0; 

}