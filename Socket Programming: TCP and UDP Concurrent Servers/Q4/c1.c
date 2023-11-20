#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IP address from string to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    int choice;
    printf("Menu:\n");
    printf("1. Check whether the number is prime\n");
    printf("2. Reverse a sentence\n");
    scanf("%d", &choice);

    // Send the choice to the server
    write(client_socket, &choice, sizeof(int));

    switch (choice) {
        case 1: {  // Check if a number is prime
            int num;
            printf("Enter a number: ");
            scanf("%d", &num);
            write(client_socket, &num, sizeof(int));

            int is_prime;
            if (read(client_socket, &is_prime, sizeof(is_prime)) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            if (is_prime) {
                printf("%d is prime.\n", num);
            } else {
                printf("%d is not prime.\n", num);
            }
            break;
        }
        case 2: {  // Reverse a sentence
            char buffer[1024];
            printf("Enter a sentence: ");
            getchar();  // Consume the newline character
            fgets(buffer, sizeof(buffer), stdin);

            // Remove newline character from input
            int len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }

            write(client_socket, buffer, sizeof(buffer));
            read(client_socket, buffer, sizeof(buffer));
            printf("Reversed sentence: %s\n", buffer);
            break;
        }
        
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }

    close(client_socket);
    return 0;
}
