#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void out1(){
    printf("Child terminated\n");
}
void out2(){
    printf("Parent terminated\n");
}



int main(){

    pid_t pid = fork();
    if (pid <0){
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0){
        printf("Child Process ID: %d\n", getpid());
        atexit(out1);
        
    }
    
    else{
        printf("Parent Process ID: %d\n", getpid());
        atexit(out2);
        
    }
    
   exit(0);
}