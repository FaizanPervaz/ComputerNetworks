#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 12345
#define MAX_BUFFER_SIZE 1024

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;

    // Create a UDP socket
    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket creation error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    while (1)
    {
        char message[MAX_BUFFER_SIZE];
        printf("Enter a message to send to the server (or type 'exit' to quit): ");
        fgets(message, MAX_BUFFER_SIZE, stdin);

        // Check if the user wants to exit
        if (strcmp(message, "exit\n") == 0)
            break;

        // Send the message to the server
        if (sendto(client_socket, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        {
            perror("Send error");
            close(client_socket);
            exit(1);
        }
    }

    close(client_socket);
    return 0;
}