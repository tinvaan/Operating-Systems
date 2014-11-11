/** Credits : tonythomas01 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define 	SHMSZ 	27

int main(int argc, char *argv[]) {

	char c;
	int shmid;
	key_t key = 5678;
	int *shm, *s;
	int *array, value;

	/* Creating the shared memory segment */
	shmid = shmget(key, SHMSZ, IPC_CREAT | 0666 );

	/* Attach the segment to the data space */
	array = shmat(shmid, NULL, 0);

	/* Feed data into the memory for the client to read */
	int i,j,m,n,k=0;
	printf( " Enter the order of the matirx ( m * n ): " );
	scanf( "%d %d" , &m);
	scanf( "%d" , &n );
	
	*( array++ ) = m;
	*( array++ ) = n;
	
	for ( i=0; i<m; i++ ) {
		for( j=0; j<n; j++ ) {
			printf( "Enter the value to insert :");
			scanf( "%d", array++ );
		}
	}

	shmdt( array );
	exit(0);
}