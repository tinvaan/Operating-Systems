#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

sig_handler() {
    printf("\nGot signal signum\n");
    exit(1);
}

int main(int argc, const char *argv[])
{
    int a;

    signal(SIGSEGV, sig_handler);

    //Read address 0
    a = *(int *)0;

    return 0;
}
