#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

    char request[256] = "Hello, HEHE";
    char buf[200];
    
    // create the socket
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // setup an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(3001);

    connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));

    while (1) {
        printf("Enter message or 'Goodbye' to exit): ");
        fgets(request, sizeof(request), stdin);
        request[strcspn(request, "\n")] = 0; 

        send(sock, request, sizeof(request), 0);

        if (strcmp(request, "Goodbye") == 0) {
            printf("Exiting...\n");
            break;
        }

        recv(sock, &buf, sizeof(buf), 0);
        printf("Server: %s\n", buf);
    }

    close(sock);

    return 0;
}

