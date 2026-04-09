#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char number[100];
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("Connected to server\n");
    
    // Get number from user
    printf("Enter a number: ");
    fgets(number, sizeof(number), stdin);
    
    // Remove newline character
    number[strcspn(number, "\n")] = 0;
    
    // Send number to server
    send(sock, number, strlen(number), 0);
    printf("Number sent to server: %s\n", number);
    
    // Read echoed response from server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("Server echoed: %s\n", buffer);
    
    close(sock);
    printf("Connection closed\n");
    
    return 0;
}

