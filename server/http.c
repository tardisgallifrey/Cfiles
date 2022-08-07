// Server side C/C++ program to demonstrate Socket
// programming
#include "http.h"

//http socket initialization
int http_init(int port, int opt){

    int server_fd;
    struct sockaddr_in address;     //struct from in.h? 
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //fill appropriate members of struct address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
  
    
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on %d ...\n", port);

    return server_fd;
}

char* http_response_200(void){
    char* response = "HTTP/1.1 200\n"
    "Content-Type: text/html\n"
    "Connection: keep-alive\n\n";

    return response;
}
