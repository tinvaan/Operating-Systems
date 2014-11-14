/* Program to generate the fibonacci series using the concept of Pthreads */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>

// FIXME : Write a method that takes in the number of terms
// as a command line argument and prints the sequence till
// the same.

void *fibonacci_generate(void *arg) {
    int i, prev = 0, curr = 1, next;
    int localStorage = *((int *) arg);

    printf("\nPrinting the Fibonacci sequence till %d terms \n", localStorage);

    printf("\n%d %d", prev, curr);

    for(i = 0; i < (localStorage - 2); i++) {
        next = prev + curr;
        printf(" %d", next);
        //Update the prev and curr indices
        prev = curr;
        curr = next;
    }

    printf("\n\n");
}

/* Begining of the driver class */
int main(int argc, char const *argv[])
{
	int i, no_of_terms;

	pthread_t fibonacci_generate_thread;
	printf("\nEnter the number of terms in the sequence : ");
    scanf("%d", &no_of_terms);

	pthread_create(fibonacci_generate_thread, NULL, fibonacci_generate, &no_of_terms);
	pthread_join(fibonacci_generate_thread, NULL);
    pthread_detach(fibonacci_generate_thread);

	return EXIT_SUCCESS;
}
