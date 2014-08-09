#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    /* Varialbe to store the pid */
    pid_t pid;

    /* Fork a child process */
    pid = fork();

    if(pid < 0) {
        printf("\nFork failed ! \n");
        exit(1);
    }
    else if(pid == 0) {
        /* Runniing the child process */
        execlp("/bin/ls", "ls", NULL);
    }
    else {
        /* Parent process running */
        /* Make the parent wait for the child to complete */
        wait(NULL);
        printf("\nChild complete !\n");
        exit(0);
    }
    return 0;
}
