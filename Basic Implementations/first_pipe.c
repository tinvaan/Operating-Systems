#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Begining of the main method */
int main(int argc, const char *argv[])
{
    int file_descriptor;

    file_descriptor = open("new.txt", O_WRONLY|O_CREAT, S_IREAD|S_IWRITE);

    if(file_descriptor == -1) {
        perror("new.txt");
        exit(EXIT_FAILURE);
    }

    close(1);               //Close the standard output.
    dup(file_descriptor);   //file_descriptor will be duplicated into standard out's slot
    close(file_descriptor); //Close the extra slot

    printf("\nHello World\n");

    exit(EXIT_SUCCESS);         //exit() closes all the files

    return EXIT_SUCCESS;
}
