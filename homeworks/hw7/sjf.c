#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

struct Process{

    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};



int main(){

    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for(int i = 0; i < n; i++){
        proc[i].pid = i+1;
        printf("Enter the arrival and burst times of process %d:", i+1);
        scanf("%d", &(proc[i].arrival_time));
        scanf("%d", &(proc[i].burst_time));
    }
    
    printf("=== Shortest Job First (SJF) === \n");
    printf("Gannt Chart: ");

    int time = 0;
    int queue_tail = 0;
    struct Process *queue[n];
    bool stop = false;
    

    while(!stop){

        for(int i = 0; i < n; i++){
            
            if (proc[i].burst_time == time){
                queue[queue_tail] = proc+i;
                if(queue_tail != 0){
                    if((queue[queue_tail]->burst_time == queue[queue_tail - 1]->burst_time) && (queue[queue_tail]->arrival_time < queue[queue_tail -1]->arrival_time)){
                        queue[queue_tail] = proc+i-1;
                        queue[queue_tail - 1] = proc+i;
                    }
                }
                queue_tail++;

            }

        }

        if (queue_tail == n){
            stop = true;
        }
        

        time++;

    }

    for(int i = 0; i < n; i++){
        printf("| P%d ", queue[i]->pid);
    }
        
    queue[0]->waiting_time = 0;
    queue[0]->response_time = 0;
    queue[0]->turnaround_time = queue[0]->burst_time;
    for(int i = 1; i < n; i++){
        queue[i]->waiting_time = queue[i-1]->turnaround_time;
        queue[i]->response_time = queue[i]->waiting_time;
        queue[i]->turnaround_time = queue[i]->response_time + queue[i]->burst_time;
    }



    printf("\nPID  AT   BT   WT   TAT  RT \n");
    for(int i = 0; i < n; i++){
        printf("%d    %d    %d    %d    %d    %d \n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time, proc[i].response_time);
    }

    int avg_wait = 0;
    int avg_turn = 0;
    int avg_res = 0;
    for(int i = 0; i < n; i++){
        avg_wait+= proc[i].waiting_time;
        avg_turn+= proc[i].turnaround_time;
        avg_res+= proc[i].response_time;
    }
  
    printf("Average Waiting Time: %f \n", (double)avg_wait/n);
    printf("Average Turnaround Time: %f \n", (double)avg_turn/n);
    printf("Average Response Time: %f \n", (double)avg_res/n);


    return 0;
}

