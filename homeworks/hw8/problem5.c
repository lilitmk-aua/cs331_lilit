#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>

int main(){

    int fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd<0){
        perror("coudn't open");
        return 1;
    }

    int w = write(fd, "START", strlen("START"));
    if(w<0){
        perror("coudn't write");
        return 1;
    }

    lseek(fd, 1024*1024, SEEK_CUR);

    w = write(fd, "END", strlen("END"));
    if(w<0){
        perror("coudn't write");
        return 1;
    }
    
    
    
    close(fd);

    fd = open("sparse.bin", O_RDONLY);
    if(fd<0){
        perror("coudn't open");
        return 1;
    }

    printf("%ld \n", lseek(fd, 0, SEEK_END));

    //since it's a sparse file, the OS doesn't allocate storage to the "empty" parts, that's why the du is smaller.


    close(fd);

    



}