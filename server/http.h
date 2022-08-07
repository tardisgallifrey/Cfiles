#if !defined(HTTP_H)
#define HTTP_H
#include <netinet/in.h>     //needed to decipher IPV4
#include <sys/socket.h>     //needed to build sockets
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         //needed for unix standards

#endif // HTTP_H

int http_init(int port, int opt);

char* http_response_200(void);

