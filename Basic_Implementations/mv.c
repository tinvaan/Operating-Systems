#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define PERMS 0666

char buffer[2048];

/* Funtion prototype */
void copy(int, int);

/* Main method */
int main(int argc, const char *argv[])
{
    int fd_old, fd_new;

    /* Check if source and destination are provided */
    if(argc != 3) {
        printf("\nPlease provide source and destination\n");
        exit(1);
    }

    /* Open the source file in read only mode */
    fd_old = open(argv[1], O_RDONLY);

    /* Check if source file was opened correctly */
    if(fd_old == -1) {
        printf("\nCould not open file %s\n", argv[1]);
        exit(1);
    }

    /* Create new file(destination) */
    fd_new = creat(argv[2], PERMS);

    /* Check for errors while opening the destination file */
    if(fd_new == -1) {
        printf("\nFailed to create new file %s\n", argv[2]);
        exit(1);
    }

    /* Function call */
    copy(fd_old, fd_new);

    /* Unlink the old file */
    unlink(argv[1]);

    exit(1);
    return 0;
}

/* Function definition  */
void copy(int old, int new) {
    int count;
    count = read(old, buffer, sizeof(buffer));

    while(count > 0) {
        write(new, buffer, count);
    }
}
