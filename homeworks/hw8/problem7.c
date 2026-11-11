#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>
#include <stdlib.h>

int main(){


    char file1[100];
    write(1, "enter the first file: ", strlen("enter the first file: "));
    int n1 = read(0, file1, sizeof(file1)-1);
    if(n1<0){
        perror("coudn't write");
        return 1;
    }

    file1[n1] = '\0';
    file1[strcspn(file1, "\n")] = '\0'; //added since it would read the enter (\n) as well

    int fd1 = open(file1, O_RDONLY);
    if(fd1<0){
        perror("coudn't open");
        return 1;
    }



    char file2[100];
    write(1, "enter the second file: ", strlen("enter the second file: "));
    int n2 = read(0, file2, sizeof(file2)-1);
    if(n2<0){
        perror("coudn't write");
        return 1;
    }
   
    file2[n2] = '\0';
    file2[strcspn(file2, "\n")] = '\0';
    
    
    int fd2 = open(file2, O_RDONLY);
    if(fd2<0){
        perror("coudn't open");
        return 1;
    }


    char c1;
    char c2;
    char buff1[100];
    char buff2[100];

    n1 = read(fd1, buff1, sizeof(buff1));
    if(n1<0){
        perror("coudn't read");
        return 1;
    }
    n2 = read(fd2, buff2, sizeof(buff2));
    if(n2<0){
        perror("coudn't read");
        return 1;
    }

    buff1[n1] = '\0';
    buff2[n2] = '\0';

    if(n1>n2){
        for (int i = 0; i < n1; i++)
        {
            if(*(buff1+i)!= *(buff2+i)){
                printf("Files differ at byte %d \n", i+1);
                close(fd1);
                close(fd2);
                exit(1);
            }
            if(*(buff2+i) == '\0'){
                printf("Files differ at byte %d \n", i);
                close(fd1);
                close(fd2);
                exit(1);
            }
            printf("Files are identical \n");
                close(fd1);
                close(fd2);
                exit(0);
        }
        
    }
    else{
        for (int i = 0; i < n2; i++)
        {
            if(*(buff1+i)!= *(buff2+i)){
                printf("Files differ at byte %d \n", i+1);
                close(fd1);
                close(fd2);
                exit(1);
            }
            if(*(buff1+i) == '\0'){
                printf("Files differ at byte %d \n", i);
                close(fd1);
                close(fd2);
                exit(1);
            }
            printf("Files are identical \n");
                close(fd1);
                close(fd2);
                exit(0);
        }
        
    }



    

  
    close(fd1);
    close(fd2);



}