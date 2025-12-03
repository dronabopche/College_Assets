#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int n, fd;

    write(1, "Write from terminal to file...\n", 31);
    fd = open("file1.txt", O_RDWR | O_CREAT, 0644);

    n = read(0, buffer, sizeof(buffer));
    write(fd, buffer, n);

    lseek(fd, 0, 0);
    n = read(fd, buffer, sizeof(buffer));
    write(1, buffer, n);

    close(fd);
    return 0;
}
