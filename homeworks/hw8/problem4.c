#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>

int main(){

    int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(fd<0){
        perror("coudn't open the source path");
        return 1;
    }

    char buff[100];
    write(1, "enter your text: ", strlen("enter your text: "));
    int n = read(0, buff, sizeof(buff)-1);
    if(n<0){
        perror("coudn't read");
        return 1;
    }

    buff[n] = '\0';
    buff[strcspn(buff, "\n")] = '\0';

    int w = write(fd, buff, strlen(buff));
    if(w<0){
        perror("coudn't write");
        return 1;
    }
    w = write(fd, "\nPID = ", strlen("\nPID = "));
    if(w<0){
        perror("coudn't write");
        return 1;
    }
    pid_t pid = getpid();
    char p[10];
    sprintf(p, "%d", (int)pid);

    w = write(fd, p, strlen(p));
    if(w<0){
        perror("coudn't write");
        return 1;
    }

    printf("\n%d \n", (int)lseek(fd, 0, SEEK_CUR));

    //the offset is being set before each write, becaue of that, SEEK_CUR returns a growing offset even with O_APPEND

    
    
    close(fd);



    



}