#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 12345
#define MAX_BUFFER_SIZE 1024

int main()
{
    int server_socket, client_socket1, client_socket2;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[MAX_BUFFER_SIZE];

    // Create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket creation error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Bind error");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 2) == -1)
    {
        perror("Listen error");
        close(server_socket);
        exit(1);
    }

    printf("Server is listening on port %d...\n", SERVER_PORT);

    // Accept the first client connection
    if ((client_socket1 = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
    {
        perror("Accept error");
        close(server_socket);
        exit(1);
    }

    printf("Client A connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Accept the second client connection
    if ((client_socket2 = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
    {
        perror("Accept error");
        close(server_socket);
        exit(1);
    }

    printf("Client B connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1)
    {
        // Receive from client A and send to client B
        pid_t pid = fork();
        memset(buffer, 0, sizeof(buffer));
        ssize_t recv_len = recv(client_socket1, buffer, sizeof(buffer), 0);
        if (recv_len <= 0)
        {
            printf("Client A disconnected.\n");
            break;
        }
        printf("Client A: %s", buffer);
        send(client_socket2, buffer, recv_len, 0);

        // Receive from client B and send to client A
        memset(buffer, 0, sizeof(buffer));
        recv_len = recv(client_socket2, buffer, sizeof(buffer), 0);
        if (recv_len <= 0)
        {
            printf("Client B disconnected.\n");
            break;
        }
        printf("Client B: %s", buffer);
        send(client_socket1, buffer, recv_len, 0);
    }

    close(client_socket1);
    close(client_socket2);
    close(server_socket);

    return 0;
}