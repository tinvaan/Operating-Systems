#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, const char *argv[])
{
    pid_t child1, child2, child3, child4;

    if((child1 = fork()) == 0) {
        printf("\nParent PID : %d\nChild PID : %d\n", getppid(),getpid());
    }
    else {
        if((child2 = fork()) == 0)
            printf("\nParent PID : %d\nChild PID : %d\n", getppid(), getpid());
        else if((child3 = fork()) == 0)
            printf("\nParent PID : %d\nChild PID : %d\n", getppid(), getpid());
        else if((child4 = fork()) == 0)
            printf("\nParent PID : %d\nChild PID : %d\n", getppid(), getpid());
        wait();
    }