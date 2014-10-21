#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PERMS 0666
char buffer [2048];

int main(int argc, const char *argv[])
{
    struct stat stat_buf;

    if(argc != 2) {
        printf("\nPlease enter a file to stat \n");
        exit(1);
    }

    if(stat(argv[1], &stat_buf) < 0) {
        return 1;
    }

    printf("\nFile Name : %s\n", argv[1]);
    printf("\nFile Size : %d\n", stat_buf.st_size);
    printf("\nNumber of links : %d\n", stat_buf.st_nlink);
    //printf("\nDevice containing : %s\n",stat_buf.st_dev); (GIVES A SEG_FAULT)
    printf("\nTime of last access : %d\n",stat_buf.st_atime);
    printf("\nUser ID of owner : %d\n", stat_buf.st_uid);
    printf("\nGroup ID of owner : %d\n", stat_buf.st_gid);

    return 0;
}
