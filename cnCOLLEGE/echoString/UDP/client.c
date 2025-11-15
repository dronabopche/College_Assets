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
    char message[BUFFER_SIZE];
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
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    // Get message from user
    printf("Enter a string to send to server: ");
    fgets(message, BUFFER_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline
    
    // Send message to server
    sendto(sockfd, (const char *)message, strlen(message), 0,
          (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Message sent to server: %s\n", message);
    
    // Receive echo from server
    socklen_t len = sizeof(servaddr);
    int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0,
                    (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    printf("Echo from server: %s\n", buffer);
    
    close(sockfd);
    return 0;
}
