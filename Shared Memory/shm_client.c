/** Credits : tonythomas01 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27
#define LEN 5

int main(int argc, char *argv[]) {

	int shmid;
	key_t key = 5678;
	int k =0,i,j = 0;;
	int *array, *value;
	int convertedArray[50];

	/* Locating the segment */
	shmid = shmget(key, LEN * sizeof(int), 0666 );

	/* Attach the segment to the data space */
	array = shmat(shmid, NULL, 0);
	int size_SHM_m = array[0];
	int size_SHM_n = array[1];
	int totalSize_SHM = size_SHM_m * size_SHM_n;
	printf( "The size of the SHM is %d\n", totalSize_SHM );

	for( i = 0, j = 2; i < totalSize_SHM; i++, j++ ) {
		convertedArray[i] = array[j];
	}
	int *arrayptr = convertedArray;

	// Print as a 2-D array
	for ( i=0; i<size_SHM_m; i++ ) {
		printf( "\n" );
		for( j=0; j<size_SHM_n; j++ ) {
			printf( "%d ", *arrayptr++ );
		}
	}
	
	shmdt( array );
	exit(0);
}