u/* Implementing the cp command */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/* RW for owner, group, others */
#define PERMS 0666

/* Declare the buffer */
char buffer[2048];

/* Function prototype for copy */
void copy(int, int);

int main(int argc, char *argv[]) {
   /* File destinations (old and new) */
    int fd_old, fd_new;

   /* Check if source and destination are provided */
   if(argc != 3) {
	printf("\nPlease enter source and destination ! \n");
  	exit(1);
    }
    /* Prototype for open() system call
     * int open(file_name, option_flags[,mode])
     * char *file_name
     * int option_flags, mode
     */
    /* Opening the source destination file in Read Only mode */
    fd_old = open(argv[1], O_RDONLY);

	/* Check for errors while opening source file */
	if(fd_old == -1) {
		printf("\nCould not open file %s\n", argv[1]);
		exit(1);
	}

	/* Prototype for the creat() system call
	 * int creat(file_name, mode)
	 * char *file_name;
	 * int mode;
	 */
	/* Create new file(destination) */
	fd_new = creat(argv[2], PERMS);

	/* Check for errors in opening new file */
	if(fd_new == -1) {
		printf("\nCould not create new file %s\n",argv[2]);
		printf("\nCheck the permissions ! \n");
		exit(1);
	}

	copy(fd_old, fd_new);
	exit(0);
}

void copy(int old, int new) {
	int count;

	/* Prototype for the read command
	 * int read(file_descriptor, buffer_pointer, transfer_size)
	 * int file_descriptor
	 * char *buffer_pointer
	 * unsigned transfer_size
	 */

	/* Read till return value > -1 */
	while((count = read(old, buffer, sizeof(buffer))) > 0)
		/* Prototype for the write command
		 * int write(file_descriptor, buffer_pointer, transfer_size)
		 * int file_descriptor
		 * char *buffer_pointer
		 * unsigned transfer_size
		 */

		/* Write to the destination file */
		write(new, buffer, count);
}
