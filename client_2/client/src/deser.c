#include <stdio.h>
#include <stdlib.h>
#include "../build/request.pb-c.h"
#include "./net/socket.h"
#define MAX_MSG_SIZE 4096

int main() {
    Request *request;

    uint8_t buf[MAX_MSG_SIZE]; 
//     char c; int i=0;   
//     const char* filename = "output.txt";

//     // Open the file in read mode
//     FILE* file = fopen(filename, "rb");
//     if (file == NULL) {
//         perror("Error: unable to open file for reading.\n");
//         return 1;
//     }

//     while (fread(&c,1,1,file) != 0)
//   {
//     if (i >= MAX_MSG_SIZE)
//     {
//       fprintf(stderr,"message too long for allocated buffer\n");
//       return 1;
//     }
//     buf[i++] = c;
//   }
//       fclose(file);

    int socket_fd = init_socket();
    bind_socket(socket_fd);
    listen_socket(socket_fd);
    int new_socket = 0;
    while (new_socket == 0) {
        new_socket = accept_socket(socket_fd);
    }
    int len = receive_from_socket(new_socket, buf);
    request = request__unpack(NULL, len, buf);
    if (request == NULL)
    { // Something failed
    fprintf(stderr,"error unpacking incoming message\n");
    return 1;
    }
    return 0;
}


// Server side C/C++ program to demonstrate Socket
// programming
// #include <netinet/in.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <unistd.h>
// #define PORT 8080
// int main(int argc, char const* argv[])
// {
//     int server_fd, new_socket;
//     ssize_t valread;
//     struct sockaddr_in address;

//     int opt = 1;
//     socklen_t addrlen = sizeof(address);
    
//     char buffer[1024] = { 0 };
//     char* hello = "Hello from server";
 
//     // Creating socket file descriptor
//     if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
//         perror("socket failed");
//         exit(EXIT_FAILURE);
//     }
 
//     // Forcefully attaching socket to the port 8080
//     if (setsockopt(server_fd, SOL_SOCKET,
//                    SO_REUSEADDR | SO_REUSEPORT, &opt,
//                    sizeof(opt))) {
//         perror("setsockopt");
//         exit(EXIT_FAILURE);
//     }
//     address.sin_family = AF_INET;
//     address.sin_addr.s_addr = INADDR_ANY;
//     address.sin_port = htons(PORT);
 
//     // Forcefully attaching socket to the port 8080
//     if (bind(server_fd, (struct sockaddr*)&address,
//              sizeof(address))
//         < 0) {
//         perror("bind failed");
//         exit(EXIT_FAILURE);
//     }
//     if (listen(server_fd, 3) < 0) {
//         perror("listen");
//         exit(EXIT_FAILURE);
//     }
//     if ((new_socket
//          = accept(server_fd, (struct sockaddr*)&address,
//                   &addrlen))
//         < 0) {
//         perror("accept");
//         exit(EXIT_FAILURE);
//     }
//     valread = read(new_socket, buffer,
//                    1024 - 1); // subtract 1 for the null
//                               // terminator at the end
//     printf("%s\n", buffer);
//     send(new_socket, hello, strlen(hello), 0);
//     printf("Hello message sent\n");
 
//     // closing the connected socket
//     close(new_socket);
//     // closing the listening socket
//     close(server_fd);
//     return 0;
// }