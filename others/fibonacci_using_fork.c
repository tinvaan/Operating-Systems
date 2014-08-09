/* Program to display the fibonacci series in a child program */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

#define PERMS 0666

/* Function prototype */
void print_fib(int );

int main(int argc, const char *argv[])
{
    pid_t pid;
    int n;

    /* Get the input */
    printf("\nEnter the upper limit for the fibonacci series : ");
    scanf("%d", &n);

    /* Creating the child process */
    pid = fork();

    if(pid == 0) {
        /* Child process running */
        print_fib(n);               //Function call
        exit(1);
    }
    else if(pid > 1) {
        wait();
        printf("\nChild process terminated ! \n");
        exit(0);
    }
    else {
        printf("\nFailed to create child \n");
        exit(1);
    }

    exit(EXIT_SUCCESS);

    return 0;
}

/* Function definition */
void print_fib(int upper_limit) {
    int temp, next_term = 0, i;

    int first_term = 0;
    int second_term = 1;

    for(i=0; i<upper_limit; i++) {
        next_term = first_term + second_term;
        printf(" %d", next_term);
        temp = second_term;
        second_term = next_term;
        first_term = temp;
    }
}
