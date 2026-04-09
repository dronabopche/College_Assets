#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    int client_id;
} client_info_t;

client_info_t clients[2];
char combined_string[BUFFER_SIZE * 2] = "";
int client_count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    client_info_t *info = (client_info_t *)arg;
    int client_socket = info->client_socket;
    int client_id = info->client_id;
    char buffer[BUFFER_SIZE];
    
    printf("Client %d connected\n", client_id);
    
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Received from client %d: %s\n", client_id, buffer);
        
        pthread_mutex_lock(&lock);

        if (strlen(combined_string) == 0) {
            strcpy(combined_string, buffer);
        } else {
            strcat(combined_string, buffer);
        }
        
        printf("Combined string: %s\n", combined_string);
        
        pthread_mutex_unlock(&lock);
        
        while (client_count < 2) {
            usleep(100000);
        }
        
        send(client_socket, combined_string, strlen(combined_string), 0);
        printf("Sent combined string to client %d\n", client_id);
    }
    
    close(client_socket);
    free(info);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("TCP Server listening on port %d\n", PORT);
    
    while (client_count < 2) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection accepted from %s:%d\n", 
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        client_info_t *info = malloc(sizeof(client_info_t));
        info->client_socket = new_socket;
        info->client_id = client_count + 1;
        
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, info) != 0) {
            perror("pthread_create");
            close(new_socket);
            free(info);
            continue;
        }
        
        pthread_detach(thread_id);
        client_count++;
    }

    sleep(2);
    
    close(server_fd);
    pthread_mutex_destroy(&lock);
    return 0;
}