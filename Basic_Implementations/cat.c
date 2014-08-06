/* Program to implement the cat command */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

/* Define permissions */
#define PERMS 0666

/* Creating character buffer */
char buffer[2048];

/* Function prototype */
//void cat();

/* Begining of the main function */
int main(int argc, const char *argv[])
{
    int file_dest;
    char ch;

    /* Check if file is provided in command line */
    if(argc != 2) {
        printf("\nPlease enter the filename ! ");
        exit(1);
    }

    /* Open the file using the open system call */
    //file_dest = open(argv[1]), O_WRONLY|O_CREAT, PERMS);

    /* Check for errors while opening the file */
   /** if(file_dest == -1) {
        printf("\nCould not open file %s ", argv[1]);
        exit(1);
    }*/

    FILE *file_pointer;

    file_pointer = fopen(argv[1],"r");  //Opening file in read only mode and storing the value in file pointer

    if(file_pointer == NULL) {
        printf("\nError while opening the file %s", argv[1]);
        exit(1);
    }

    while((ch = fgetc(file_pointer)) != EOF) {
        printf("%c", ch);
    }

    fclose(file_pointer);

    exit(0);
    return 0;
}

/* Function definition */
/**void cat(int file_dest) {
    char ch;
    FILE *fp;

    file_dest = open(argv[1],O_RDONLY);

    if(file_dest == -1) {
        printf("\nCould not open the file \n");
        exit(1);
    }

    while((ch = fgetc(fp)) != EOF)
        printf("%c",ch);

    fclose(fp);
}*/
