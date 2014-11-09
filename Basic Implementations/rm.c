#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define PERMS 0666

char buffer[2048];

int main(int argc, const char *argv[])
{
    int filename;

    /* Open the file in read only mode and check if file was opened correctly*/
    filename = open(argv[1], O_RDONLY);

    if(filename == -1) {
        printf("\nFile not found %s\n", argv[1]);
        exit(1);
    }

    unlink(argv[1]);
    exit(1);

    return 0;
}
