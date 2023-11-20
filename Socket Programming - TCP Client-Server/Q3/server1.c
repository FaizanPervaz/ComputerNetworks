#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {
    char server_message[256] = "Hi, you have reached the server!";
    char buf[200];
    
    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(server_socket, 5);
    
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    while (1) {
        memset(buf, 0, sizeof(buf));
        recv(client_socket, buf, sizeof(buf), 0);
        printf("Client: %s\n", buf);

        if (strcmp(buf, "exit") == 0) {
            printf("Client has exited.\n");
            break;
        }

        printf("Enter response: ");
        fgets(server_message, sizeof(server_message), stdin);
        server_message[strcspn(server_message, "\n")] = 0;
        send(client_socket, server_message, sizeof(server_message), 0);
        
        if (strcmp(server_message, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    close(client_socket);
    close(server_socket);

    return 0;
}

