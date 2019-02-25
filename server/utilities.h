#ifndef UTILITIES_H
#define UTILITIES_H
#define PORT 5050

struct SocketInfo {
    int socket;
    struct sockaddr_in address;
};

#endif