#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
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
        exit(0);
    }
    
    else{
        wait(NULL);
        sleep(20);
        printf("Parent Process ID: %d\n", getpid());
    }
    return 0;
    
   
}