#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define     BUFFER_SIZE         5
#define     PRODUCER_SLEEP_S    0
#define     CONSUMER_SLEEP_S    1


/* Defining the queue structure */
typedef struct {
    int buffer[BUFFER_SIZE];
    long head, tail;
    int empty, full;
    
    pthread_mutex_t *mut;
    pthread_cond_t  *notFull, *notEmpty;
} queue;


/* Declaring the producer and consumer methods */
void* producer(void *q);
void* consumer(void *q);


/* Declaring the queue operations */
queue* queueInit(void);
void queueDelete(queue *q);
void queueAdd(queue *q, int in);
void queueDel(queue *q, int *out);


/* Begining of the main method */
int main(int argc, char *argv) {
    
    queue *fifo;
    pthread_t prod, cons;
    
    fifo = queueInit();
    
    if (fifo == NULL) {
        fprintf(stderr, "\nFailed to initialize the queue\n");
        exit(1);
    }
    
    pthread_create(&prod, NULL, producer, fifo);
    pthread_create(&cons, NULL, producer, fifo);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    queueDelete(fifo);
    
    return EXIT_SUCCESS;
}


/* Defining Producer and Consumer methods */
void* producer(void *q) {
    
    queue *fifo;
    int i;
    
    fifo = (queue *)q;
    
    for (i = 0; i <10; i++) {
        // Acquire lock
        pthread_mutex_lock(fifo->mut);
        
        while(fifo->full) {
            // Wait if the queue is full
            printf("\nProducer Queue Full");
            pthread_cond_wait(fifo->notFull, fifo->mut);
        }
        // If queue not full, add items to the queue
        queueAdd(fifo, i);
        printf("\nProducer: Produced %d ", i);
        // Release lock
        pthread_mutex_unlock(fifo->mut);
        pthread_cond_signal(fifo->notEmpty);
        usleep(PRODUCER_SLEEP_S * 1000000);
    }
    
    return (NULL);
}

//FIXME: Control doesn't seem to pass to this function
void* consumer(void *q) {
    
    queue *fifo;
    int i, item;
    
    fifo = (queue *)q;
    
    for (i = 0; i < 10; i++) {
        // Acquire lock
        pthread_mutex_lock(fifo->mut);
        
        while(fifo->empty) {
            // Wait, if queue empty
            pthread_cond_wait(fifo->notEmpty, fifo->mut);
        }
        
        // Consume, if not empty
        queueDel(fifo, &item);
        
        //Release lock
        pthread_mutex_unlock(fifo->mut);
        pthread_cond_signal(fifo->notFull);
        
        printf("\nConsumer: Recieved %d\n", item);
        usleep(CONSUMER_SLEEP_S * 1000000);
    }
    
    return NULL;
}


/* Function definitions */
queue* queueInit() {
    queue *q;
    
    q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
        return NULL;
    
    q->empty = 1;
    q->full  = 0;
    q->head  = 0;
    q->tail  = 0;
    
    q->mut      = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(q->mut, NULL);
    q->notFull  = (pthread_cond_t *) malloc(sizeof(pthread_cond_t));
    pthread_cond_init(q->notFull, NULL);
    q->notEmpty    = (pthread_cond_t *) malloc(sizeof(pthread_cond_t));
    pthread_cond_init(q->notEmpty, NULL);
    
    return (q);
}

void queueDelete(queue *q) {
    pthread_mutex_destroy(q->mut);
    free(q->mut);
    
    pthread_cond_destroy(q->notFull);
    free(q->notFull);
    
    pthread_cond_destroy(q->notEmpty);
    free(q->notEmpty);
    
    free(q);
}

/* Add an element(integer) to the queue */
void queueAdd(queue *q, int in) {
    
    q->buffer[q->tail] = in;
    q->tail++;
    
    if (q->tail == BUFFER_SIZE) {
        q->tail = 0;
    }
    if (q->tail == q->head) {
        q->head = 1;
    }
    q->empty = 0;
    
    return;
}

/* Remove an element from the queue */
void queueDel(queue *q, int *out) {
    
    *out = q->buffer[BUFFER_SIZE];
    
    q->head++;
    
    if (q->head == BUFFER_SIZE)
        q->head = 0;
    
    if (q->head == q->tail)
        q->empty = 1;
    
    q->full = 0;
    
    return;
}