#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 4

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

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

int findCharFrequency(const char* str, char ch) {
    int frequency = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ch)
            frequency++;
    }
    return frequency;
}

int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; 
        }
        left++;
        right--;
    }
    
    return 1; 
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        int pid = fork();
        if (pid == 0) {  
            close(server_fd);

            int choice;
            if (read(new_socket, &choice, sizeof(int)) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Perform the requested operation based on the choice
            char buffer[1024];
            memset(buffer, 0, sizeof(buffer));

            switch (choice) {
                case 1: {  // Check if a number is prime
                    int num;
                    if (read(new_socket, &num, sizeof(int)) < 0) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    bool is_prime = isPrime(num);
                    write(new_socket, &is_prime, sizeof(bool));
                    break;
                }
                case 2: {  // Reverse a sentence
                    if (read(new_socket, buffer, sizeof(buffer)) < 0) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    reverseSentence(buffer);
                    write(new_socket, buffer, sizeof(buffer));
                    break;
                }
                case 3: {  // Find the frequency of a character in a string
                    char ch;
                    if (read(new_socket, &ch, sizeof(char)) < 0) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    if (read(new_socket, buffer, sizeof(buffer)) < 0) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    int frequency = findCharFrequency(buffer, ch);
                    write(new_socket, &frequency, sizeof(int));
                    break;
                }
                case 4: {  // Check if a string is a palindrome
                    if (read(new_socket, buffer, sizeof(buffer)) < 0) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    bool is_palindrome = isPalindrome(buffer);
                    write(new_socket, &is_palindrome, sizeof(bool));
                    break;
                }
                default: {
                    printf("Invalid choice from client\n");
                    break;
                }
            }

            close(new_socket);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
