#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define TIMEOUT_SEC 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string_to_send>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    socklen_t len;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    printf("Sending to server: %s\n", argv[1]);
 
    sendto(sockfd, argv[1], strlen(argv[1]), 0,
          (const struct sockaddr *)&servaddr, sizeof(servaddr));
    
    struct timeval tv;
    tv.tv_sec = TIMEOUT_SEC;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    
    len = sizeof(servaddr);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                    (struct sockaddr *)&servaddr, &len);
    
    if (n > 0) {
        buffer[n] = '\0';
        printf("Received combined string from server: %s\n", buffer);
    } else {
        printf("Timeout: No response received from server\n");
    }
    
    close(sockfd);
    return 0;
}