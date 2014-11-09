#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* Global Variables */
int CTRL_C = 0, CTRL_Z = 0, pause_ret;

/* Signal Handlers */
void cnt_1(int sig) {

    ++CTRL_Z;
    if(CTRL_Z == 1) {
        printf("\nFirst occurence of 'CTRL_Z''. Pausing the program");
        pause_ret = pause();
    }
    else if(CTRL_Z > 1) {
        exit(1);
    }
}

void cnt_2(int sig) {

    ++CTRL_Z;

    if(CTRL_Z >= 1) {
        exit(1);
    }
}

int main(int argc, const char *argv[])
{
    signal(SIGINT, cnt_1);
    signal(SIGTSTP, cnt_2);     //SIGTSTP == CTRL + Z

    printf("\nBegin counting INTERRUPTS and CTRL + C\n");

    // Infinite loop
    for(;;);

    return EXIT_SUCCESS;
}
