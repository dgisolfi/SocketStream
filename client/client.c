#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define VER 1
   
int transmitMessage(int port, char *msg) { 
    struct sockaddr_in address; 
    int sock, read_value;
    struct sockaddr_in serv_addr;  
    char server_response[1024] = {0}; 

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("Socket creation error"); 
        exit(EXIT_FAILURE);
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(port); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
        perror("Invalid address"); 
        exit(EXIT_FAILURE);
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
        perror("Connection to Socket Failed"); 
        exit(EXIT_FAILURE);
    } 

    send(sock, msg, strlen(msg) , 0 ); 
    printf("Client: Message sent to Server\n"); 

    read_value = read(sock, server_response, 1024); 
    printf("Server: %s\n", server_response);

    return 0; 
} 


int main(int argc, char *argv[]) {
    // TCP Stream Port
    int port;
    char *msg;
    printf("SocketStream Client v%d\n", VER );

    if ( argc == 3 ) {
      printf("Client: Sending message to TCP server on port: %s\n", argv[1]);
      port = atoi(argv[1]);
      msg = argv[2];
    } else if( argc > 3 ) {
        perror("Error: Too many arguments supplied. Please supply a valid port for the TCP client to run on.");
        exit(EXIT_FAILURE);
    } else {
        perror("Expected argument missing => Port or Message");
        exit(EXIT_FAILURE);
    }

    if (transmitMessage(port, msg) == 1) {
        perror("Client Failure while sending message");
        exit(EXIT_FAILURE);
    }

    printf("Client: Shutting Down"); 

    return 0;
}