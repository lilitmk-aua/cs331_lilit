#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>

int main(){

    //use hello.txt as the file

    char buff[100];
    write(1, "enter the path: ", strlen("enter the path: "));
    int n = read(0, buff, sizeof(buff)-2);
    if(n<0){
        perror("coudn't write");
        return 1;
    }

    buff[n] = '\0';
    buff[strcspn(buff, "\n")] = '\0';


    int fd = open(buff, O_RDONLY);
    if(fd<0){
        perror("coudn't open");
        return 1;
    }

    int n1 = lseek(fd, 0, SEEK_END);
    printf("%d \n", n1);
    int r;
    char reverse[sstrlen(buff)];
    for(int i = 0; i <= n1; i++){

        lseek(fd, -i, SEEK_END);
        r = read(fd, reverse, 1);
        if(r<0){
            perror("coudn't read");
            return 1;
        }
    printf("%s", reverse);
    }
    
    

    
   close(fd);



}