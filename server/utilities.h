#ifndef UTILITIES_H
#define UTILITIES_H

struct SocketInfo {
    int socket;
    struct sockaddr_in address;
};

char *get_timestamp() {
    time_t timer;
    char *timestamp;
    struct tm *tm_info;
    time(&timer);

    tm_info = localtime(&timer);
    strftime(timestamp, 26, "%Y-%m-%dT%H:%M:%S", tm_info);
    return timestamp;
}

char *concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

#endif