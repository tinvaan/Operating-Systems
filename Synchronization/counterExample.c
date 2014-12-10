#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int     count = 0;
sem_t   mutex;

void *func(void *arg) {
    int num = *((int *) arg);   //local storage
    int i;
    
    for (i = 0; i < 5; i++) {
        sem_wait(&mutex);
        count++;
        printf("\nCount = %d : Updated by thread %d\n ", count, num);
        sem_post(&mutex);
    }
}

int main() {
    
    pthread_t tid[5];
    int i, num, tnum[5];
    sem_init(&mutex, 0, 1);
    
    for (i = 0; i < 5; i++) {
        tnum[i] = i+1;
        pthread_create(&tid[i], NULL, func, &tnum[i]);
    }
    for (i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    
    return 0;
}