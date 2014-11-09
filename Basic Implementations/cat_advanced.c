/* Advanced implementation of the cat command */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

#define PERMS 0666

char buffer[2048];

/* Function prototypes */
void copy(int, int);
void cat(int);

/* Begining of the driver class */
int main(int argc, const char *argv[])
{
    int file_source, file_dest;

    /* Check if two files are provided */
    if(argc != 4) {
        printf("\nPlease provide the appropriate arguments ! \n");
        exit(EXIT_SUCCESS);
    }

    /* Open source file using the open system call */
    file_source = open(argv[1], O_RDONLY);

    if(file_source == -1) {
        printf("\nFailed to open file %s", argv[1]);
        exit(EXIT_SUCCESS);
    }

    /* Creating new file using the creat() system call */
    file_dest = creat(argv[2], PERMS);

    if(file_dest == -1) {
        printf("\nFailed to create/open file %s", argv[3]);
        exit(EXIT_SUCCESS);
    }

    copy(file_source, file_dest);
    exit(EXIT_SUCCESS);

    return 0;
}

/* Function definition */
void copy(int fd_old, int fd_new) {
    int count;

    while((count = read(fd_old, buffer, sizeof(buffer))) > 0) {
        write(fd_new, buffer, count);
    }
}
