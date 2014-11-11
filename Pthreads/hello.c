#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#define 	NUM_THREADS 	5

/* Function protoypes */
void *TaskCode(void *arguments);

/* Main Method */
int main(int argc, char const *argv[])
{
	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS], rc, i;

	/* Create all threads */
	for(i = 0; i<NUM_THREADS; i++) {
		thread_args[i] = i;
		printf("\nIn main() : Creating thread %d\n", i);
		rc = pthread_create(&threads[i], NULL, TaskCode, (void *) &thread_args[i]);
		assert(0 == rc);
	}

	/* Wait for all threads to complete */
	for(i = 0; i<NUM_THREADS; i++) {
		rc = pthread_join(threads[i], NULL);
	}

	exit(EXIT_SUCCESS);
}

/* Function definition */
void *TaskCode(void *arguments) {

	int tid;
	tid = *((int *) arguments);
	printf("\nPrinting thread %d\n", tid);

	return;
}