#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>

/* Function to generate the fibonacci series in thread */
void *fibonacci_generate(void *size) {
	int i, prev = 0, curr = 1, next;

	printf("\n Number of terms in function() : %d\n", *((int *)size));

	printf("%d", prev);
	printf("%d", curr);

	for(i = 0; i< *((int *)size); i++ ) {
		next = prev + curr;
		printf("%d", next);
		//Update the current and prev
		prev = curr;
		curr = next;
	}
} 

/* Function to conver the command line argument(a string) to integer */
int string_to_int(string arg) {
	//res * 10 + ((int) c[0] - '0')
	int res  = 0, ret_val;
	ret_val = (res * 10) + ((int) c[0] - '0');

	return ret_val;
}


/* Main method */
int main(int argc, char const *argv[])
{
	string arg = argv[1];
	pthread_t fibonacci_generate_thread;
	int no_of_terms = string_to_int(arg);

	printf("\n Number of terms in main() : %d\n", no_of_terms);

	pthread_create(fibonacci_generate_thread, NULL, fibonacci_generate, (void *) no_of_terms);
	pthread_join(fibonacci_generate_thread, NULL);

	return 0;
}