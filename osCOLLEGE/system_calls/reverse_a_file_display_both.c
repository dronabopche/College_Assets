#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char ch;
    int fd1, fd2;
    off_t size;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("revfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    size = lseek(fd1, 0, SEEK_END);

    while (size--) {
        lseek(fd1, size, SEEK_SET);
        read(fd1, &ch, 1);
        write(fd2, &ch, 1);
    }

    write(1, "\nContents of file1.txt:\n", 25);
    lseek(fd1, 0, 0);
    while (read(fd1, &ch, 1) > 0)
        write(1, &ch, 1);

    write(1, "\nContents of revfile.txt:\n", 26);
    lseek(fd2, 0, 0);
    while (read(fd2, &ch, 1) > 0)
        write(1, &ch, 1);

    close(fd1);
    close(fd2);
    return 0;
}
