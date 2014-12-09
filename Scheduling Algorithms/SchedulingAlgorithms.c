/* Given the process name, arrival time, burst time and priority
 * Calculate the order of execution for different scheduling algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define     SIZE    10

int no_of_processes;

/* Define a structure for storing details of a process */
typedef struct process_details {

    char    process_name[SIZE];
    int     priority;
    float   arrival_time, exec_start, exec_end;
    float   burst_time, waiting_time, idle_time;

} p_details;

/* Function prototypes */
void    get_process_details     (int );
float   first_come_first_serve  (int );
float   shortest_job_first      (int );
void    print_process_details   (int );

/* Begining of the main method */
int main(int argc, const char *argv[])
{
    float avg_waiting_time;
    int scheduling_algorithm_choice;

    printf("\nChoose the Scheduling algorithm \n");
    printf("\n1. First Come First Serve\n2. Shortest Job First Scheduling\n");
    printf("\nEnter your choice : ");
    scanf("%d", &scheduling_algorithm_choice);

    printf("\nEnter the number of processes : ");
    scanf("%d", &no_of_processes);

    if (scheduling_algorithm_choice == 1) {
        avg_waiting_time = first_come_first_serve(no_of_processes);
    }
    else if (scheduling_algorithm_choice == 2) {
        avg_waiting_time = shortest_job_first(no_of_processes);
    }
    else {
        fprintf(stderr, "\nInvalid Choice\n");
        exit(0);
    }

    return 0;
}

/* Function definitions */
void get_process_details(int pno) {

    p_details pd[no_of_processes];

    printf("\nEnter details for process %d ", pno);
    printf("\nProcess Name : ");
    scanf("%s", pd[pno].process_name);
    printf("\nArrival Time : ");
    scanf("%f", &pd[pno].arrival_time);
    printf("\nExecution start time : ");
    scanf("%f", &pd[pno].exec_start);
    printf("\nExecution end time : ");
    scanf("%f", &pd[pno].exec_end);
    printf("\nProcess Priority : ");
    scanf("%d", &pd[pno].priority);
}

float first_come_first_serve(int n) {

    int i;
    p_details pd[n];

    // Get each process details
    for (i = 0; i < n; i++) {
        get_process_details(i);
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            pd[i].arrival_time = 0;
            pd[i].exec_start   = 0;
            pd[i].waiting_time = 0;
            pd[i].burst_time   = pd[i].exec_end - pd[i].exec_start;
            pd[i].idle_time    = pd[i].exec_start - pd[i].arrival_time;
        }
        else {
            if (pd[i].arrival_time < pd[i-1].exec_end) {
                /* Start time of the next process comes before the running process. 
                 * Hence the process can be staved off for the time being
                 * Such a process waits for ever in the case of Frist Come First Serve scheduling
                 */
                pd[i].waiting_time  = INT_MAX;
                pd[i].burst_time    = 0;
                i++;
            }
            else {
                pd[i].waiting_time  = pd[i-1].exec_end - pd[i].arrival_time;
                pd[i].burst_time    = pd[i].exec_start - pd[i].exec_end;
                pd[i].idle_time     = pd[i].exec_start - pd[i].arrival_time;
            }
        }
        
        print_process_details(i);
    }
}

// TODO : Implement the Shortest Job First Algorithm
float shortest_job_first(int n) {

}

void print_process_details(int pno) {
    
    p_details pd[no_of_processes];

    printf("\nPrinting details for process %d\n", pno);

    printf("\nProcess Name : %s\n", pd[pno].process_name);
    printf("\nWaiting time : %f\n", pd[pno].waiting_time);
    printf("\nBurst time   : %f\n", pd[pno].burst_time);
    printf("\nIdle time    : %f\n", pd[pno].idle_time);
}