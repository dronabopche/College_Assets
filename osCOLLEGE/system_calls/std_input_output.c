#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int n;

    write(1, "Enter text:\n", 12);
    n = read(0, buffer, sizeof(buffer));
    write(1, buffer, n);

    return 0;
}
