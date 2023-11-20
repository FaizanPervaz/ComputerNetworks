#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1" // Replace with the server's IP address
#define SERVER_PORT 12345
#define MAX_BUFFER_SIZE 1024

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;

    // Create a TCP socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket creation error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connection error");
        close(client_socket);
        exit(1);
    }

    while (1)
    {
        char message[MAX_BUFFER_SIZE];
        printf("Client A: Enter a message to send to Client B: ");
        fgets(message, MAX_BUFFER_SIZE, stdin);

        // Send the message to the server
        if (send(client_socket, message, strlen(message), 0) == -1)
        {
            perror("Send error");
            close(client_socket);
            exit(1);
        }

        // Receive and display messages from the server relay
        memset(message, 0, sizeof(message));
        ssize_t recv_len = recv(client_socket, message, sizeof(message), 0);
        if (recv_len <= 0)
        {
            perror("Receive error");
            close(client_socket);
            exit(1);
        }
        printf("Server Relay: %s", message);
    }

    close(client_socket);
    return 0;
}