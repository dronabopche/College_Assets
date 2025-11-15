#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int sum_of_digits(char *str) {
    int sum = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            sum += str[i] - '0'; // Convert char to int
        }
    }
    return sum;
}

int is_valid_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') {
            return 0;
        }
    }
    return 1;
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
    
    printf("UDP Digit Sum Server listening on port %d...\n", PORT);
    
    len = sizeof(cliaddr);
    
    while (1) {
        // Receive message from client
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0,
                        (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Received from client: %s\n", buffer);
        
        char response[BUFFER_SIZE];
        
        // Check if input is a valid number
        if (is_valid_number(buffer)) {
            // Calculate sum of digits
            int sum = sum_of_digits(buffer);
            
            // Prepare response
            snprintf(response, sizeof(response), 
                    "Sum of digits of %s is: %d", buffer, sum);
            printf("Calculated sum: %d\n", sum);
        } else {
            // Invalid input
            snprintf(response, sizeof(response), 
                    "Error: '%s' is not a valid number", buffer);
            printf("Invalid input received\n");
        }
        
        // Send response back to client
        sendto(sockfd, (const char *)response, strlen(response), 0,
              (const struct sockaddr *)&cliaddr, len);
        printf("Response sent to client: %s\n\n", response);
    }
    
    close(sockfd);
    return 0;
}
