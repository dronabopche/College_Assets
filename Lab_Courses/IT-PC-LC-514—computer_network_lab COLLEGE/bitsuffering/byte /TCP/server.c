#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd, nsfd;
    struct sockaddr_in addr;
    unsigned char in[1024], out[1024];
    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    bind(sfd, (struct sockaddr*)&addr, sizeof(addr));
    listen(sfd, 3);
    
    printf("Server listening on port 8080...\n");
    nsfd = accept(sfd, NULL, NULL);
    read(nsfd, in, 1024);
    
    int j = 0;
    for(int i = 0; in[i] != '\0'; i++) {
        if(in[i] == 0x7D) {
            if(in[i+1] == 0x5E) 
                out[j++] = 0x7E;
            else if(in[i+1] == 0x5D) 
                out[j++] = 0x7D;
            i++;
        } else {
            out[j++] = in[i];
        }
    }
    out[j] = '\0';
    
    printf("Received stuffed data: %s\n", in);
    printf("Destuffed data: %s\n", out);
    
    close(nsfd);
    close(sfd);
    return 0;
}