#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

    pid_t pid = fork();
    if (pid <0){
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0){
        printf("Child Process ID: %d\n", getpid());
    }
    
    else{
        printf("Parent Process ID: %d\n", getpid());
    }
    
   
}