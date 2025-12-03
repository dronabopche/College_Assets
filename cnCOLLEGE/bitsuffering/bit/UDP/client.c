#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void stuff(char *in, char *out) {
    int c = 0, j = 0;
    for(int i = 0; in[i] != '\0'; i++) {
        if(in[i] == '1') {
            c++;
            out[j++] = in[i];
            if(c == 5) {
                out[j++] = '0';
                c = 0;
            }
        } else {
            c = 0;
            out[j++] = in[i];
        }
    }
    out[j] = '\0';
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    char msg[1024], out[1024];
    printf("Enter binary message: ");
    scanf("%s", msg);
    
    stuff(msg, out);
    printf("Original: %s\n", msg);
    printf("Stuffed: %s\n", out);
    
    sendto(sock, out, strlen(out) + 1, 0, 
           (struct sockaddr*)&addr, sizeof(addr));
    
    close(sock);
    return 0;
}