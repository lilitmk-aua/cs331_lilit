#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>




void* partial_sum(void* arg){
    int num = *((int*)arg);
    printf(" Square of %d is %d \n", num, num*num);
    return NULL;


}

int main(){

    int n = 5;
    int numbers[] = {1, 2, 3, 4, 5};
    pthread_t threads[n];

    for(int i = 0; i < n; i++){
        if (pthread_create(&threads[i], NULL, partial_sum, (void*)&numbers[i]) != 0) {
            perror("Failed to create thread 1");
            return 1;
        }
    }
    

    for(int i = 0; i < n; i++){
        if (pthread_join(threads[i], NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
        }
    }   
    
    
    
    




}