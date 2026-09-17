#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    
    int ret;
    if (fork() == 0){
        ret = execl("/usr/bin/ls", "ls", NULL);
    }
    else{
        wait(NULL);
        if (fork() == 0){
        ret = execl("/usr/bin/date", "date", NULL);
    }
        else{
            wait(NULL);
            printf("Parent Process Done \n");
        }
    }
   
}