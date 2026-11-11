#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <fcntl.h>

int main(){

    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd<0){
        perror("coudn't open the source path");
        return 1;
    }

    ssize_t wr = write(fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
    if(wr<0){
        perror("coudn't write");
        return 1;
    }

    close(fd);

    fd = open("data.txt", O_RDWR);
    if(fd<0){
        perror("coudn't open ");
        return 1;
    }
    
    int n = (int)lseek(fd, 0, SEEK_END);
    printf("%d \n", n);

    ssize_t t = ftruncate(fd, 10);
    if(t<0){
        perror("coudn't fturncate");
        return 1;
    }

    printf("%d \n", (int)lseek(fd, 0, SEEK_END));

    lseek(fd, 0, SEEK_SET);

    char buff[100];
    ssize_t bytesRead = read(fd, buff, sizeof(buff) - 1);
    if (bytesRead == -1) {
        perror("read failed");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if(bytesRead>=0){
        buff[bytesRead] = '\0';
        printf("Read %zd bytes: \"%s\"\n", bytesRead, buff);
    }
    
    
    close(fd);



    



}