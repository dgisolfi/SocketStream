#ifndef UTILITIES_H
#define UTILITIES_H

struct SocketInfo {
    int socket;
    struct sockaddr_in address;
};

char *time_stamp(){
    char *timestamp = (char *)malloc(sizeof(char) * 16);
    time_t ltime;
    ltime=time(NULL);
    struct tm *tm;
    tm=localtime(&ltime);

    sprintf(timestamp,"%04d-%02d-%02dT%02d:%02d:%02d", 
        tm->tm_year+1900, 
        tm->tm_mon, 
        tm->tm_mday, 
        tm->tm_hour, 
        tm->tm_min, 
        tm->tm_sec
    );
    return timestamp;
}
#endif