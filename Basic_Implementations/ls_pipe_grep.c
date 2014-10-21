#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE     25
#define READ_END        0
#define WRITE_END       1

int main(int argc, const char *argv[])
{
    int file_descriptor[2];
    pid_t child_pid;

    /* Open the pipe */
    pipe(file_descriptor);

    /* Create the child process */
    child_pid = fork();
    if(child_pid < 0) {
        fprintf(stderr, "\nFailed to create child\n");
        return EXIT_FAILURE;
    }
    else if(child_pid > 0) {
        /** Parent process running */
        execlp()
    }
    return 0;
}
