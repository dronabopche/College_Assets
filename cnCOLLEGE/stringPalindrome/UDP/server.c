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
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    
    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    
    // Configure server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    printf("UDP Palindrome Server listening on port %d...\n", PORT);
    
    len = sizeof(cliaddr);
    
    while (1) {
        // Receive message from client
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0,
                        (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
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
        
        // Send response back to client
        sendto(sockfd, (const char *)response, strlen(response), 0,
              (const struct sockaddr *)&cliaddr, len);
        printf("Sent response: %s\n\n", response);
    }
    
    close(sockfd);
    return 0;
}
