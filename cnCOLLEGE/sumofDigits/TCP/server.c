#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int sum_of_digits(int num) {
    int sum = 0;
    num = abs(num); // Handle negative numbers
    
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
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
    
    printf("Server listening on port %d...\n", PORT);
    
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Read two numbers from client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        
        // Parse the two numbers (assuming they are separated by space or comma)
        int num1, num2;
        if (sscanf(buffer, "%d %d", &num1, &num2) == 2) {
            printf("Received numbers from client: %d and %d\n", num1, num2);
            
            // Calculate sum of digits for both numbers
            int sum1 = sum_of_digits(num1);
            int sum2 = sum_of_digits(num2);
            
            // Prepare response
            char response[BUFFER_SIZE];
            snprintf(response, sizeof(response), 
                    "Number 1: %d, Sum of digits: %d\nNumber 2: %d, Sum of digits: %d", 
                    num1, sum1, num2, sum2);
            
            // Send result back to client
            send(new_socket, response, strlen(response), 0);
            printf("Result sent to client\n");
        } else {
            // Error handling for invalid input
            char error_msg[] = "Error: Please send two numbers separated by space";
            send(new_socket, error_msg, strlen(error_msg), 0);
            printf("Invalid input received from client\n");
        }
        
        close(new_socket);
        printf("\n");
    }
    
    close(server_fd);
    return 0;
}
