#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void* print_message(void* arg) {
    
    int thread_id = *((int*)arg);
    for(int i = 1; i <= 5; i++){
        printf("%d ", i);
    }
    printf("Thread %d  \n", thread_id);
    
}

int main() {
    pthread_t thread1, thread2, thread3;
    int thread_ids[] = {1, 2, 3};

   
    if (pthread_create(&thread1, NULL, print_message, (void*)&thread_ids[0]) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, print_message, (void*)&thread_ids[1] ) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_create(&thread3, NULL, print_message, (void*)&thread_ids[2] ) != 0) {
        perror("Failed to create thread 3");
        return 1;
    }
    

  



    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
    }
    
    if (pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread 2");
        return 1;
    }

    if (pthread_join(thread3, NULL) != 0) {
        perror("Failed to join thread 3");
        return 1;
    }


    return 0;
}