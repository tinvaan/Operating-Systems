#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END    0
#define WRITE_END   1

/* Begining of the main method */
int main(int argc, const char *argv[])
{
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];

    int file_descriptor[2];
    pid_t pid;

    /* Creating the pipe */
    if(pipe(file_descriptor) == -1) {
        fprintf(stderr, "\nPipe Failed\n");
        return 1;
    }

    /* Fork a child process */
    pid = fork();

    if(pid < 0) {
        /* Failed to create fork(), print error message */
        fprintf(stderr, "\nFork failed\n");
        return 1;
    }
    else if(pid == 0) {
        /* Child process is running */

        //Close the unused end of the pipe
        close(file_descriptor[WRITE_END]);

        //Read from the pipe
        read(file_descriptor[READ_END], read_msg, BUFFER_SIZE);
        printf("\nMessage Read : %s\n", read_msg);

        //Close the read end of the pipe
        close(file_descriptor[READ_END]);
    }
    else {
        /* Parent process running */

        /* Get the input string */
        printf("\nEnter the message to be sent : ");

        /* Get the input using scanf + scanset */
        //scanf("%[^\n]%*c", write_msg);

        /* Get the input using fgets() */
        fgets(write_msg, BUFFER_SIZE, stdin);

        //Close the unused end of the pipe
        close(file_descriptor[READ_END]);

        //Write to the pipe
        write(file_descriptor[WRITE_END], write_msg, strlen(write_msg) + 1);

        //Close the write end of the pipe
        close(file_descriptor[WRITE_END]);
    }
    return EXIT_SUCCESS;
}
