#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main() {
    char request[256];
    char buf[200];
    char response[256];

    // Create a socket
    int sock;
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // Setup the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    printf("Enter a string to reverse: ");
    fgets(request, sizeof(request), stdin);
    request[strlen(request) - 1] = '\0';  // Remove the newline character

    // Send data to the server
    ssize_t bytes_sent = sendto(sock, request, strlen(request), 0, (struct sockaddr *)&server_address, sizeof(server_address));
  
    // Receive data from the server
    socklen_t server_address_length = sizeof(server_address);
    ssize_t bytes_received = recvfrom(sock, response, sizeof(response), 0, (struct sockaddr *)&server_address, &server_address_length);
    response[bytes_received] = '\0';

    printf("Reversed: %s\n", response); // Display the reversed string received from the server

    printf("\n");

    // Close the socket
    close(sock);

    return 0;
}
