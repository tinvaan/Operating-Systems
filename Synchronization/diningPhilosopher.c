#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define     N           5
#define     THINKING    0
#define     HUNGRY      1
#define     EATING      2
#define     LEFT        (ph_num + 4)%N
#define     RIGHT       (ph_num + 1)%N

sem_t mutex;
sem_t s[N];

// Function prototypes
void* philosopher(void *num);
void take_fork();
void drop_fork();
void check_neighbouring_philosopher_state();

int state[N];
int phil_num[N] = {0, 1, 2, 3, 4};

int main(int argc, char *argv[]) {

    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);

    for (i = 0; i < N; i++) {
        sem_init(&s[i], 0, 0);
    }

    for (i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil_num[i]);
        printf("\nPhilosopher %d is thinking ... ", i+1);
    }
    
    for (i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }
    
    return 0;
}

void* philosopher(void *num) {
    while (1) {
        int *i = num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        drop_fork(*i);
    }
}

void take_fork(int ph_num) {
    sem_wait(&mutex);
    state[ph_num] = HUNGRY;
    printf("\nPhilosopher %d is HUNGRY\n", ph_num + 1);
    check_neighbouring_philosopher_state(ph_num);
    sem_post(&mutex);
    sem_wait(&s[ph_num]);
    sleep(1);
}

void drop_fork(int ph_num) {
    sem_wait(&mutex);
    state[ph_num] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
    printf("Philosopher %d is thinking\n",ph_num+1);
    check_neighbouring_philosopher_state(LEFT);
    check_neighbouring_philosopher_state(RIGHT);
    sem_post(&mutex);
}

void check_neighbouring_philosopher_state(int ph_num) {
    if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[ph_num] = EATING;
        sleep(2);
        printf("\nPhilosopher %d takes fork %d and %d\n", ph_num+1, LEFT+1, ph_num+1);
        printf("\nPhilosopher %d is EATING!\n", ph_num);
        sem_post(&s[ph_num]);
    }
}