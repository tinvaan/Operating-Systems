#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

#define 	MSG_SIZE 	128

/* Declare the message structure */
typedef struct msgbuf{
	long mtype;
	char mtext[MSG_SIZE];
}message_buf;

/* Main Method */
int main(int argc, char const *argv[])
{
	int msqid,
	key_t key = 1234;
	size_t buf_length;
	message_buf rbuf, sbuf;
	char readBuffer[50];

	/* Get the message queue id for the "name" 1234,
		which was created by the server
	*/
	while (1) {
		if((msqid = msgget(key, 0666)) < 0) {
			perror("msgget");
			exit(1);
		}
		printf("\nReady to recieve\n");

		/* Receive a message/reply of type 1 */
		if(msgrcv(msqid, &rbuf, MSG_SIZE, 1, 0) < 0) {
			perror("msgrcv");
			exit(1);
		}

		/* Printing the reply */
		printf("%s\n", rbuf.mtext);

		/* Send the message through outlet 2 */
		printf("\nEnter message : ");
		scanf("%s", &readBuffer);

		sbuf.mtype = 2;
		strcpy(sbuf.mtext, readBuffer);
		buf_length = strlen(sbuf.mtext) + 1;

		/* Send a message */
		if((msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT)) < 0) {
			perror("msgsnd");
			exit(1);
		}
		else {
			printf("Message : \"%s\" Sent\n", sbuf.mtext);
		}
	}

	exit(0);
}