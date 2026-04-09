#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void stuff(unsigned char *in, unsigned char *out) {
    int j = 0;
    out[j++] = 0x7E;
    for(int i = 0; in[i] != '\0'; i++) {
        if(in[i] == 0x7E) { 
            out[j++] = 0x7D; 
            out[j++] = 0x5E; 
        }
        else if(in[i] == 0x7D) { 
            out[j++] = 0x7D; 
            out[j++] = 0x5D; 
        }
        else 
            out[j++] = in[i];
    }
    out[j++] = 0x7E;
    out[j] = '\0';
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    unsigned char msg[1024], out[1024];
    printf("Enter message: ");
    scanf("%s", msg);
    
    stuff(msg, out);
    sendto(sock, out, strlen((char*)out) + 1, 0, 
           (struct sockaddr*)&addr, sizeof(addr));
    
    close(sock);
    return 0;
}