#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>

int main(){


    char s_path[100];
    write(1, "enter the source path: ", strlen("enter the source path: "));
    int n1 = read(0, s_path, sizeof(s_path)-1);
    if(n1<0){
        perror("coudn't write");
        return 1;
    }

    s_path[n1] = '\0';
    s_path[strcspn(s_path, "\n")] = '\0'; //added since it would read the enter (\n) as well

    int fd1 = open(s_path, O_RDONLY);
    if(fd1<0){
        perror("coudn't open");
        return 1;
    }



    char d_path[100];
    write(1, "enter the destination path: ", strlen("enter the destination path: "));
    int n2 = read(0, d_path, sizeof(d_path)-1);
    if(n2<0){
        perror("coudn't write");
        return 1;
    }
   
    d_path[n2] = '\0';
    d_path[strcspn(d_path, "\n")] = '\0';
    
    
    int fd2 = open(d_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd2<0){
        perror("coudn't open");
        return 1;
    }



    

    char buff[1000];
    ssize_t b = read(fd1, buff, sizeof(buff));
    if(b<0){
        perror("coudn't read");
        return 1;
    }
    ssize_t written_total = 0;
    ssize_t w = 0;
    while (written_total < b)
    {
        w = write(fd2, buff + written_total, b - written_total);
        if(w<0){
            perror("coudn't write");
            return 1;
        }
        written_total+=w;
    }
    printf("%zd \n", written_total);
    close(fd1);
    close(fd2);



}