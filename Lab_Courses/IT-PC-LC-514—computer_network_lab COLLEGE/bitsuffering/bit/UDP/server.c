#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void destuff(char *in, char *out) {
    int c = 0, j = 0;
    for(int i = 0; in[i] != '\0'; i++) {
        if(in[i] == '1') {
            c++;
            out[j++] = in[i];
            if(c == 5) {
                i++;
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
    int sfd;
    struct sockaddr_in addr, cli;
    socklen_t len = sizeof(cli);
    char in[1024], out[1024];
    
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    bind(sfd, (struct sockaddr*)&addr, sizeof(addr));
    
    printf("Server listening on port 8080...\n");
    recvfrom(sfd, in, 1024, 0, (struct sockaddr*)&cli, &len);
    
    destuff(in, out);
    printf("Received stuffed data: %s\n", in);
    printf("Destuffed data: %s\n", out);
    
    close(sfd);
    return 0;
}