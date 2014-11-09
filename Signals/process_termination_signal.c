/* Program where parent creates a child and detects it's termination with a signal.
 * Child prints "I am the child message and terminates after 3 seconds".
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

/* Signal Handler */
void sig_handle() {
    printf("\nI'm the child message\n");
}

int main(int argc, const char *argv[])
{
    pid_t ch_pid;

    ch_pid = fork();

    if(ch_pid < 0) {
        /* Child creation failed */
        fprintf(stderr, "\nFailed to create the child\n");
        exit(0);
    }
    else {
        signal(SIGINT, sig_handle);
        sleep(3);
    }

    /* Infinite for loop */
    for(;;);

    return 0;
}
