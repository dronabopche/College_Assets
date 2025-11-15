#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];
    struct sockaddr_in servaddr;
    
    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    // Configure server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
    
    // Get string from user
    printf("Enter a string to check for palindrome: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline
    
    // Send string to server
    sendto(sockfd, (const char *)input, strlen(input), 0,
          (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("String sent to server: \"%s\"\n", input);
    
    // Receive result from server
    socklen_t len = sizeof(servaddr);
    int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0,
                    (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);
    
    close(sockfd);
    return 0;
}
