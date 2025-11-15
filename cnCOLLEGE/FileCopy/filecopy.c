#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char filename1[100], filename2[100];
    char buffer[1000];
    int fd1, fd2;
    
    printf("Enter first filename: ");
    scanf("%s", filename1);
    
    //get file content
    printf("Enter file content: ");
    scanf(" %[^\n]", buffer);
    
    //create first file
    fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd1, buffer, strlen(buffer));
    close(fd1);
    printf("File '%s' created!\n", filename1);
    
    //get second filename
    printf("Enter second filename: ");
    scanf("%s", filename2);
    
    //copy content to second file
    fd1 = open(filename1, O_RDONLY);
    fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    int bytes;
    while ((bytes = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, bytes);
    }
    
    close(fd1);
    close(fd2);
    printf("Content copied to '%s'!\n", filename2);
    
    return 0;
}
