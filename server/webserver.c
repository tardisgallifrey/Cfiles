// Server side C/C++ program to demonstrate Socket
// programming
#include <stdio.h>
#include <string.h>
#include "http.h"       //contains all http init and responses

#define PORT 8080

int main(int argc, char const* argv[])
{
    //TODO: get port from command line or config file
    int server_fd; 
    int new_socket, valread;
    struct sockaddr_in address;     //struct from in.h? 
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char *field;
    char *request;
    char *html_file;
    char *eol = "\n";
    

    const char* body = "<html>"
    "<head></head>"
    "<body>"
    "<h1>Hello World</h1>"
    "</body></html>";

    //All of socket and port initialization
    //happens here. TODO: move function to header file.
    server_fd = http_init(PORT, opt);

    //This is the server loop.
    while(1){
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
            valread = read(new_socket, buffer, 1024);
            printf("%s\n", buffer);
            send(new_socket, http_response_200(), strlen(http_response_200()), 0);
            send(new_socket, body, strlen(body), 0);
            printf("Response sent\n");

            //TODO: functionize and return a struct
            //or string array?
            int count = 0;
            field = strtok(buffer, eol);
            request = strtok(field, " ");
            puts(request);
            html_file = strtok(NULL, " ");
            puts(html_file);
            
            
        
            // closing the connected socket
            close(new_socket);
    }

  // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}

