#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
int num = 2;
int partial[2];
int size_of_array = sizeof(arr)/sizeof(int);

void* partial_sum(void* arg){
    int sum = 0;
    int thread_id = *((int*)arg);
    for(int i = thread_id *(size_of_array/num); i < (thread_id + 1 )*(size_of_array/num); i++){
        sum+=arr[i];
    }
    partial[thread_id]+=sum;
    printf("%d \n", sum);
    return NULL;


}

int main(){

    pthread_t threads[num];
    int thread_ids[num];

    for(int i = 0; i < num; i++){
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, partial_sum, (void*)&thread_ids[i]) != 0) {
            perror("Failed to create thread 1");
            return 1;
        }
    }
    

    for(int i = 0; i < num; i++){
        if (pthread_join(threads[i], NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
        }
    }   
    
    
    
    




}