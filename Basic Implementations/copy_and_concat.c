/* Program to enhance the copy program
 * Concatenates to the output file if input already exists
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

/* RW for owner, group, others */
#define PERMS 0666

/* Declare the buffer */
char buffer[2048];

/* Function prototype for copy and concatenate */
void copy_and_concat(int, int);

/* Main method */
int main(int argc, char *argv[]) {
   /* File destinations (old and new) */
   int fd_old, fd_new;

   /* Check if source and destinations are provided */
	if(argc	!= 3) {
		printf("\nPlease give the source and destinations ! \n");
		exit(1);
	}

	/* Open the source file in destination files in read only mode */
	fd_old = open(argv[1], O_RDONLY);

	/* Check for errors while opening source files */
	if(fd_old == -1) {
		printf("\nCould not open file %s\n", argv[1]);
		exit(1);
	}

	/* Create the destination file with name argv[2] and permissions*/
	fd_new = creat(argv[2], PERMS);

	/* Check errors in opening new file */
	if(fd_new == -1) {
		printf("\nFailed to create file %s\n", argv[2]);
		printf("\nCheck the permissions ! \n");
		exit(1);
	}

	/* Function call */
	copy_and_concat(fd_old, fd_new);
	exit(0);
}

/* Function definition */
void copy_and_concat(int old, int new) {
	int count = read(old, buffer, sizeof(buffer));

	/* Read till the return value > -1 */
	assert(count >= 0);

		/* Append, write save */
        /* Prototype of the lseek() system call
         * long lseek(file_descriptor, offset, whence)
         * int file_descriptor
         * long offset
         * int whence
         */
    /* Set the file pointer to end of file. */
        lseek(new, count, 0);

    /* Write to the file */
    write(new, buffer, count);
}
