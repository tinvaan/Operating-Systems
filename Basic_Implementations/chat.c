#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define     BUFFER_SIZE     25
#define     READ_END        0
#define     WRITE_END       1

/* Begining of the main method */
int main(int argc, const char *argv[])
{
    // Declarations
    int fd1[2], fd2[2];
    char parent_reply[BUFFER_SIZE], child_reply[BUFFER_SIZE];
    char break_sequences[BUFFER_SIZE] = {"QUIT\0"};

    // Create pipes
    pipe(fd1);
    pipe(fd2);

    pid_t ch_pid;

    ch_pid = fork();

    if(ch_pid < 0) {
        fprintf(stderr,"\nFailed to create child ! \n");
        exit(EXIT_SUCCESS);
    }

    while(ch_pid >= 0) {

        if(((strcmp(child_reply, break_sequences) == 0)) ||
            ((strcmp(parent_reply, break_sequences) == 0))) {

            break;
            exit(EXIT_FAILURE);
        }

        if(ch_pid == 0) {
            /* Child process running */
            close(fd1[WRITE_END]);
            read(fd1[READ_END], parent_reply, BUFFER_SIZE);
            printf("\n\t\tChild recieved the string -- %s\n", parent_reply);

            printf("\nChild > ");
            scanf("%[^\n]", child_reply);
            write(fd2[WRITE_END], child_reply, BUFFER_SIZE);
        }
        else {
            /* Parent running */
            close(fd1[READ_END]);

            printf("\nParent > ");
            scanf("%[^\n]", parent_reply);
            write(fd1[WRITE_END], parent_reply, BUFFER_SIZE);

            read(fd2[READ_END], child_reply, BUFFER_SIZE);
            printf("\n\t\tParent recieved the string -- %s\n", child_reply);
        }

        getchar();
    }

    printf("\n\n");
    return 0;
}
