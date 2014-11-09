#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGSZ 128

/* Declaring the message structure */
typedef struct msgbuf {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;

/* Functions to manage sending and recieving */
int send_message();
void recieve_message();

/* The main method */
int main(int argc, char *argv[]) {

  int ret;
  
  while(ret != 1) {
    ret = send_message();
    recieve_message();
  }
  
  return 0;
}

/* Defining the method to send message */
int send_message() {
  int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;

    message_buf sbuf;
    size_t buf_length;

    char user_message[MSGSZ];
    scanf("%s", user_message);
    key = 1234;

    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        exit(1);
    }
    else 
     (void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);
    
    sbuf.mtype = 1;
    (void) strcpy(sbuf.mtext, user_message);
    buf_length = strlen(sbuf.mtext) + 1 ;

    if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
       printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
        perror("msgsnd");
        exit(1);
    }
   else 
      printf("Message being sent : \"%s\" Sent\n", sbuf.mtext);

    exit(0);
   
   if(user_message == "EXIT" || user_message == "exit") {
      return 1;
    }
    else {
      return 0;
    }
}

/* Defining the method to recieve message */
void recieve_message() {
  int msqid;
    key_t key;
    message_buf  rbuf;

    key = 1234;
    if ((msqid = msgget(key, 0666)) < 0) {
        perror("msgget");
        exit(1);
    }

    if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }

    printf("%s\n", rbuf.mtext);
    exit(0);
}