#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SERVER_PORT 12345
#define MAX_BUFFER_SIZE 1024

int main()
{
    int server_socket;
    struct sockaddr_in server_addr, client_addr1, client_addr2;
    socklen_t client_addr_len = sizeof(client_addr1);
    char buffer[MAX_BUFFER_SIZE];

    // Create a UDP socket
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
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

    printf("Server is listening on port %d...\n", SERVER_PORT);

    // Receive data from clients and forward it to the other client
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        ssize_t recv_len1 = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr1, &client_addr_len);

        if (recv_len1 <= 0)
        {
            printf("Client 1 disconnected.\n");
            break;
        }

        printf("Client 1 (%s:%d): %s", inet_ntoa(client_addr1.sin_addr), ntohs(client_addr1.sin_port), buffer);

        // Forward the message to the second client
        sendto(server_socket, buffer, recv_len1, 0, (struct sockaddr *)&client_addr2, sizeof(client_addr2));

        memset(buffer, 0, sizeof(buffer));
        ssize_t recv_len2 = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr2, &client_addr_len);

        if (recv_len2 <= 0)
        {
            printf("Client 2 disconnected.\n");
            break;
        }

        printf("Client 2 (%s:%d): %s", inet_ntoa(client_addr2.sin_addr), ntohs(client_addr2.sin_port), buffer);

        // Forward the message to the first client
        sendto(server_socket, buffer, recv_len2, 0, (struct sockaddr *)&client_addr1, sizeof(client_addr1));
    }

    // Close the server socket
    close(server_socket);

    return 0;
}