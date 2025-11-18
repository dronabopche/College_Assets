#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
  
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    printf("UDP Server listening on port %d...\n", PORT);
    
    len = sizeof(cliaddr);

    int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0,
                    (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Received from client: %s\n", buffer);

    sendto(sockfd, (const char *)buffer, strlen(buffer), 0,
          (const struct sockaddr *)&cliaddr, len);
    printf("Echo sent back to client\n");
    
    close(sockfd);
    return 0;
}
