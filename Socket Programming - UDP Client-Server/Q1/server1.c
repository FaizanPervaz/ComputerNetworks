#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include <unistd.h>

int main()
{
    char server_message[256] = "Hi, Yes, you have reached the server!";
    char buf[200];

    // Create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP and port
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Receive data from the client
    socklen_t client_address_length = sizeof(server_address);
    ssize_t bytes_received = recvfrom(server_socket, buf, sizeof(buf), 0, (struct sockaddr *)&server_address, &client_address_length);
    printf("Received %zd bytes\n", bytes_received);
    printf("Received: %.*s\n", (int)bytes_received, buf);

    // Send a response to the client
    ssize_t bytes_sent = sendto(server_socket, server_message, strlen(server_message), 0, (struct sockaddr *)&server_address, client_address_length);
    printf("Sent %zd bytes\n", bytes_sent);
    printf("Sent: %.*s\n", (int)bytes_sent, server_message);

    // Close the socket
    close(server_socket);

    return 0;
}
