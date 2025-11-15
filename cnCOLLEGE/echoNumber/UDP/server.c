#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void echo_digits(char *input, char *output) {
    int j = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
    
    // If no digits found, send appropriate message
    if (j == 0) {
        strcpy(output, "No digits found in the input");
    }
}

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    char result[BUFFER_SIZE];
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
    
    printf("UDP Digit Echo Server listening on port %d...\n", PORT);
    
    len = sizeof(cliaddr);
    
    while (1) {
        // Receive message from client
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0,
                        (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Received from client: \"%s\"\n", buffer);
        
        // Extract and echo digits
        echo_digits(buffer, result);
        printf("Echoed digits: \"%s\"\n", result);
        
        // Send result back to client
        sendto(sockfd, (const char *)result, strlen(result), 0,
              (const struct sockaddr *)&cliaddr, len);
        printf("Response sent to client\n\n");
    }
    
    close(sockfd);
    return 0;
}
