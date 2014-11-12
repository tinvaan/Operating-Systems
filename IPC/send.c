#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define 	MSG_SIZE	128

/* Declare the message structure */
typedef struct msgbuf {
	long mtype;
	char mtext[MSG_SIZE];
}msg_buf;

int main(int argc, char const *argv[])
{
	int msqid, msgflg = IPC_CREAT | 0666;
	key_t key = 1234;
	size_t buf_length;
	char readBuffer[50];
	msg_buf sbuf, rbuf;

	while (1) {
		if((msqid = msgget(key, msgflg)) < 0) {
			perror("msgget");
			exit(1);
		}
		else {
			printf("\nSucceeded in calling msgget. Moving to chat\n");		
		}

		printf("\nYour message : ");
		scanf("%s", &readBuffer);
		sbuf.mtype = 1;
		strcpy(sbuf.mtext, readBuffer);
		buf_length = strlen(sbuf.mtext) + 1;

		// Sending the message
		if(msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
			perror("\nmsgsnd");
			exit(1);
		}
		else {
			printf("\nMessage :\"%s\" sent successfully\n", sbuf.mtext);
		}

		/* Receive the reply */
		if(msgrcv(msqid, &rbuf, MSG_SIZE, 2, 0) < 0) {
			perror("\nFailed to get reply\n");
			exit(1);
		}
		printf("\nReceived message : %s\n", rbuf.mtext);
	}
	
	exit(0);
}