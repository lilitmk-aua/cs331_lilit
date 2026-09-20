#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t pid = fork();
    int status;
    if (pid <0){
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0){
        printf("First Child Process ID: %d\n", getpid());
    }
    
    else{
        wait(&status);
        printf("First Child Exit Status: %d\n", WEXITSTATUS(status));
        pid_t pid1 = fork();
        if (pid1 <0){
            perror("Fork failed");
            exit(1);
        }

        if (pid1 == 0){
            printf("Second Child Process ID: %d\n", getpid());
        }
        
        else{
            waitpid(pid1, &status, 0);
            printf("Second Child Exit Status: %d\n", WEXITSTATUS(status));
            printf("Parent Process ID: %d\n", getpid());
        }
        
    }
    
   
}