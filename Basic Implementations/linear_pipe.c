/* Program to implement a linear pipe */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define BUFFER_SIZE     25
#define READ_END        0
#define WRITE_END       1

/* Begining of the main method */
int main(int argc, const char *argv[])
{
    // Declarations
    char first[BUFFER_SIZE], second[BUFFER_SIZE], third[BUFFER_SIZE];
    int first_pipe[2], second_pipe[2];
    pid_t child1, child2;

    /* Create the pipe */
    if( pipe(first_pipe) == -1 ) {
        fprintf(stderr, "Pipe creation failed\n");
        return EXIT_FAILURE;
    }

    /* Creating the first child process */
    child1 = fork();

    if(child1 < 0) {
        /* Failed to create child */
        fprintf(stderr, "Failed to create child\n");
        exit(EXIT_FAILURE);
    }
    else if(child1 > 0) {
        /** Parent process running.
         *  The parent writes to the pipe.
         */

        //Close the read end
        close(first_pipe[READ_END]);

        //Write the message to the pipe
        write(first_pipe[WRITE_END], argv[0], strlen(argv[0]));

        //Close the write end
        close(first_pipe[WRITE_END]);
    }
    else {
        /** Child process running.
         *  The child reads the message sent from the parent.
         *  The child will write the message it reads to the  second pipe.
         */

        //Read the message coming through the pipe, sent by the parent
        read(first_pipe[READ_END], second, BUFFER_SIZE);

        /* Create a child process */
        child2 = fork();

        if(child2 < 0) {
            /* Failed to create child */
            fprintf(stderr, "\nFailed to create the child process\n");
            return EXIT_FAILURE;
        }
        else if(child2 > 0) {
            /* The parent process(The current child) running */

            //Write the message read from parent to the next child, via pipe
            write(second_pipe[WRITE_END], third, strlen(third) + 1);

            //Close the write end of the pipe
            close(second_pipe[WRITE_END]);
        }
    }
    return 0;
}
