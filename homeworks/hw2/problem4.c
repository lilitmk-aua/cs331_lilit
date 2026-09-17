#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    
    int ret;
    if (fork() == 0){
        ret = execl("/usr/bin/grep", "grep", "Lorem", "text.txt", NULL);
    }
    else{
        wait(NULL);
        printf("Parent Process Done \n");
    }
}