#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>

int main(){

    int fd = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd<0){
        perror("coudn't open");
        return 1;
    }

    int w = write(fd, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n", strlen("1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"));
    if(w<0){
        perror("coudn't write");
        return 1;
    }

    close(fd);

    fd = open("numbers.txt", O_RDWR);
    if(fd<0){
        perror("coudn't open");
        return 1;
    }

    char c;
    lseek(fd, 0, SEEK_SET);
    int r;

    char buff[100];
    r = read(fd, buff, strlen(buff));
    if(r<0){
        perror("coudn't read");
        return 1;
    }
    
    for(int i = 0; i < strlen(buff); i++){
        r = read(fd, &c, 1);
        if(r<0){
            perror("coudn't read");
            return 1;
        }
        
        printf("%c \n", c);
        if(c == '4'){ 
            w = write(fd, "100", 1);
        }
        else {
            w = write(fd, &c, 1);
        }
        if(r<0){
            perror("coudn't read");
            return 1;
        }
 

    }

    close(fd);
    





}