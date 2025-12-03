#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int n, f1, f2, f3;

    f1 = open("file1.txt", O_RDONLY);
    f2 = open("file2.txt", O_RDONLY);
    f3 = open("merged.txt", O_RDWR | O_CREAT, 0644);

    while ((n = read(f1, buffer, sizeof(buffer))) > 0)
        write(f3, buffer, n);

    while ((n = read(f2, buffer, sizeof(buffer))) > 0)
        write(f3, buffer, n);

    write(1, "\nContents of file1.txt:\n", 25);
    lseek(f1, 0, 0);
    while ((n = read(f1, buffer, sizeof(buffer))) > 0)
        write(1, buffer, n);

    write(1, "\nContents of file2.txt:\n", 25);
    lseek(f2, 0, 0);
    while ((n = read(f2, buffer, sizeof(buffer))) > 0)
        write(1, buffer, n);

    write(1, "\nContents of merged.txt:\n", 26);
    lseek(f3, 0, 0);
    while ((n = read(f3, buffer, sizeof(buffer))) > 0)
        write(1, buffer, n);

    close(f1);
    close(f2);
    close(f3);
    return 0;
}
	