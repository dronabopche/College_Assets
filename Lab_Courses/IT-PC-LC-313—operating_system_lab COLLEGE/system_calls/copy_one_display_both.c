#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int n, fd1, fd2;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDWR | O_CREAT, 0644);

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
        write(fd2, buffer, n);

    lseek(fd1, 0, 0);
    lseek(fd2, 0, 0);

    write(1, "\nContents of file1.txt:\n", 25);
    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
        write(1, buffer, n);

    write(1, "\nContents of file2.txt:\n", 25);
    while ((n = read(fd2, buffer, sizeof(buffer))) > 0)
        write(1, buffer, n);

    close(fd1);
    close(fd2);
    return 0;
}
