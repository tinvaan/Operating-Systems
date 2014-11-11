/** Example program to calculate the square of a value */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

int value;		//Thread stores the value here

/* Function prototype */
void *square_thread(void *param);

/* Main method */
int main(int argc, char const *argv[])
{
	pthread_t tid;
	int ret_code;

	if(argc != 2) {
		fprintf(stderr, "\nUsage : ./a.out <integer value>\n");
		exit(0);
	}

	/* Create a new thread */
	ret_code  = pthread_create(&tid, NULL, square_thread, argv[1]);

	if(ret_code != 0) {
		fprintf(stderr, "\nUnable to create thread\n");
		exit(1);
	}

	/* Wait for the created thread to exit */
	pthread_join(tid, NULL);
	printf("\nParent printing the square; square = %d", value);

	return 0;
}

/* Function that prints the square of the value */
void *square_thread(void *param) {
	int i = atoi(param);

	printf("\nThis is the child. Passing the value %d\n", atoi);
	value = i*i;

	pthread_exit(0);
}