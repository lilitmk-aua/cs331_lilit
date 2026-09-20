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
        exit(0);
    }
    
    else{
 
        pid_t pid1 = fork();
        int status;
        if (pid1 <0){
            perror("Fork failed");
            exit(1);
        }

        if (pid1 == 0){
            exit(1);
        }
        else{

             // checking the exit status of the first child
            waitpid(pid, &status, 0);
            if(WEXITSTATUS(status) == 0){
                printf("Exited Normally \n");
            }
            else printf("Exited With An Error \n");
            printf("First Child Exit Status: %d\n",WEXITSTATUS(status) );


            // checking the exit status of the second child
            waitpid(pid1, &status, 0);
            if(WEXITSTATUS(status) == 0){
                printf("Exited Normally \n");
            }
            else printf("Exited With An Error \n");
            printf("Second Child Exit Status: %d\n",WEXITSTATUS(status));
        }
        
    }
    
   
}