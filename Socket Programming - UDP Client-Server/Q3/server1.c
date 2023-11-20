#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

void reverseString(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char server_message[256] = "Hi, Yes, you have reached the server!";
    char buf[200];
    char request[200]; // Declare the request variable

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

    int i = 0;

    while (i < 5) {
        // Receive data from the client
        socklen_t client_address_length = sizeof(server_address);
        ssize_t bytes_received = recvfrom(server_socket, buf, sizeof(buf), 0, (struct sockaddr *)&server_address, &client_address_length);
        printf("Received %zd bytes\n", bytes_received);
        printf("Received: %.*s\n", (int)bytes_received, buf);

        // Copy the received data into the request variable
        strncpy(request, buf, sizeof(request));

        reverseString(request); // Reverse the received string

        // Send the reversed string as a response to the client
        ssize_t bytes_sent = sendto(server_socket, request, strlen(request), 0, (struct sockaddr *)&server_address, client_address_length);
        i++;
    }

    // Close the socket
    close(server_socket);

    return 0;
}

