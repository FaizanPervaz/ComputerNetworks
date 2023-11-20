#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[MAX_BUFFER];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error in socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) == 0) {
        printf("Hi, Yes you have reached the server \n");
    } else {
        perror("Error while listening");
        exit(1);
    }

    addr_size = sizeof(client_addr);

    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);

    while (1) {
        printf("Menu:\n");
        printf("1. Issue a book\n");
        printf("2. Return a book\n");
        printf("Enter your choice (1 or 2): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "1") == 0 || strcmp(buffer, "2") == 0) {
            //Department
            char dept[50];
            send(client_socket, buffer, sizeof(buffer), 0);

            memset(buffer, 0, sizeof(buffer));
            recv(client_socket, buffer, sizeof(buffer), 0);

            printf("%s\n", buffer);
            for(int i=0;i<strlen(buffer);i++)
            {
                dept[i]=buffer[i];
            }
            //Name
            char name[50];
            send(client_socket, buffer, sizeof(buffer), 0);

            memset(buffer, 0, sizeof(buffer));
            recv(client_socket, buffer, sizeof(buffer), 0);

            printf("%s\n", buffer);
            for(int i=0;i<strlen(buffer);i++)
            {
                name[i]=buffer[i];
            }
            //Book
            char book[50];
            send(client_socket, buffer, sizeof(buffer), 0);

            memset(buffer, 0, sizeof(buffer));
            recv(client_socket, buffer, sizeof(buffer), 0);

            printf("%s\n", buffer);
            for(int i=0;i<strlen(buffer);i++)
            {
                book[i]=buffer[i];
            }
            //Time
            send(client_socket, buffer, sizeof(buffer), 0);

            memset(buffer, 0, sizeof(buffer));
            recv(client_socket, buffer, sizeof(buffer), 0);

            printf("%s\n", buffer);
            char time[50];
            for(int i=0;i<strlen(buffer);i++)
            {
                time[i]=buffer[i];
            }

            char result[150];
            strcpy(result, dept);
            strcat(result, " ");
            strcat(result, name);

            strcat(result, " ");
            strcat(result, time);

            printf("%s\n", result);

        } 
        else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }

    close(client_socket);
    close(server_socket);

    return 0;
}
