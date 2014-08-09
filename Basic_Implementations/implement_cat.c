#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
// Set permissions 
#define PERMS 0666
char buffer[2048];
	/* Main method */
	int main(int argc, char *argv[]) {    
	  int file_pointer;
    /* 1. Open the file
	* 2. Read the file
	* 3. Write to the display 
	*/
    file_pointer = open(argv[1], O_RDONLY);
    while((read(file_pointer, buffer, sizeof(buffer))) > 0) {
      write(1, buffer, sizeof(buffer));
    }  
    exit(EXIT_SUCCESS);
	  
}