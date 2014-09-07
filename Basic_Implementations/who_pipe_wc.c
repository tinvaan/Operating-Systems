#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>

#define     READ_END        0
#define     WRITE_END       1
#define     STDOUT          1
#define     STDIN           0
#define     BUFFER_SIZE     15

int main(int argc, const char *argv[])
{
    int fd[2];
    pid_t ch_pid = fork();

    pipe(fd);

    if( ch_pid == 0) {
        /* Child process running    */
        close(STDOUT);                          // Close the standard output
        dup(fd[WRITE_END]);                     // Redirect to pipe's std_out
        close(fd[READ_END]);                    // Close the pipe's std_in
        execlp(argv[1], argv[1], NULL);         // Run the first argument
    }
    else if(ch_pid > 0){
        /* Parent process running   */
        close(STDIN);                           // Close the standard input
        dup(fd[READ_END]);                      // Redirect to the pipe's std_in
        close(fd[WRITE_END]);                   // Close the pipe's write end
        execlp(argv[2], argv[2], NULL);         // Run the second argument
    }
    else {
        fprintf(stderr, "\nFailed to create child ! \n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
