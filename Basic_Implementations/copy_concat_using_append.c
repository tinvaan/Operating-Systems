#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

#define PERMS 0666

char buffer[2048];

void copy_concat(int , int);

int main(int argc, const char *argv[])
{
    int fd_old, fd_new;

    if(argc != 3) {
        printf("\nPlease provide the souce and destination\n");
        exit(1);
    }

    /* Open the source file in read only mode */
    fd_old = open(argv[1],O_RDONLY);

    /* Check if source file was opened successfully */
    if(fd_old == -1) {
        printf("\nCould not open file %s\n", argv[1]);
        exit(1);
    }

    /* Open the destination file in append mode */
    fd_new = open(argv[2],O_APPEND | PERMS);

    /* Check if destination file was opened successfully */
    if(fd_new == -1) {
        printf("\nCould not open file %s\n", argv[2]);
        exit(1);
    }

    /* Function call */
    copy_concat(fd_old, fd_new);

    return 0;
}

/* Function defintion */
void copy_concat(int old, int new) {
    int count;

    while ((count = read(old, buffer, sizeof(buffer))) > 0) {
        write(new, buffer, count);
    }
}
