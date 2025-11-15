#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int is_palindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        // Convert to lowercase for case-insensitive comparison
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Palindrome Server listening on port %d...\n", PORT);
    
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Read string from client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';
        printf("Received string from client: \"%s\"\n", buffer);
        
        // Check if palindrome
        int result = is_palindrome(buffer);
        
        // Prepare response
        char response[BUFFER_SIZE];
        if (result) {
            snprintf(response, sizeof(response), "\"%s\" is a palindrome!", buffer);
        } else {
            snprintf(response, sizeof(response), "\"%s\" is not a palindrome!", buffer);
        }
        
        // Send result back to client
        send(new_socket, response, strlen(response), 0);
        printf("Sent response: %s\n\n", response);
        
        close(new_socket);
    }
    
    close(server_fd);
    return 0;
}
