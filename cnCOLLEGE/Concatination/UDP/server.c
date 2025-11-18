#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 2

typedef struct {
    struct sockaddr_in address;
    char string[BUFFER_SIZE];
    int received;
} client_data_t;

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buffer[BUFFER_SIZE];
    client_data_t clients[MAX_CLIENTS];
    int client_count = 0;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].received = 0;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    printf("UDP Server listening on port %d\n", PORT);
    
    while (client_count < MAX_CLIENTS) {
        len = sizeof(cliaddr);
        
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, 
                        (struct sockaddr *)&cliaddr, &len);
        if (n > 0) {
            buffer[n] = '\0';
 
            int found = 0;
            int client_index = -1;
            
            for (int i = 0; i < client_count; i++) {
                if (clients[i].address.sin_addr.s_addr == cliaddr.sin_addr.s_addr &&
                    clients[i].address.sin_port == cliaddr.sin_port) {
                    found = 1;
                    client_index = i;
                    break;
                }
            }
            
            if (!found && client_count < MAX_CLIENTS) {
                client_index = client_count;
                clients[client_index].address = cliaddr;
                clients[client_index].received = 1;
                strcpy(clients[client_index].string, buffer);
                client_count++;
                
                printf("New client %d connected: %s:%d\n", client_index + 1,
                       inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                printf("Received from client %d: %s\n", client_index + 1, buffer);
            } else if (found) {
                clients[client_index].received = 1;
                strcpy(clients[client_index].string, buffer);
                printf("Updated data from client %d: %s\n", client_index + 1, buffer);
            }
            
            if (client_count == MAX_CLIENTS) {
                int all_received = 1;
                for (int i = 0; i < MAX_CLIENTS; i++) {
                    if (!clients[i].received) {
                        all_received = 0;
                        break;
                    }
                }
                
                if (all_received) {
                    char combined_string[BUFFER_SIZE * 2] = "";
                    strcpy(combined_string, clients[0].string);
                    strcat(combined_string, clients[1].string);
                    
                    printf("Combined string: %s\n", combined_string);

                    for (int i = 0; i < MAX_CLIENTS; i++) {
                        sendto(sockfd, combined_string, strlen(combined_string), 0,
                              (const struct sockaddr *)&clients[i].address, 
                              sizeof(clients[i].address));
                        printf("Sent combined string to client %d\n", i + 1);
                    }
                    
                    client_count = 0;
                    for (int i = 0; i < MAX_CLIENTS; i++) {
                        clients[i].received = 0;
                    }
                }
            }
        }
    }
    
    close(sockfd);
    return 0;
}