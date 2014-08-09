#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define PERMS 0666
char buffer[2048];
void copy(int, int);
int main(int argc, char *argv[]) {
  int file_source, file_dest;
  //check if two files are provided 
  if(argc != 4) {
    printf("\nPlease provide two arguments\n");
    exit(EXIT_SUCCESS);
  }
  // open the source file 
  file_source = open(argv[1], O_RDONLY);
  // check for errors in opening the source file
  if(file_source == -1) {
    printf("\nError in opening file %s", argv[1]);
    exit(EXIT_SUCCESS);
  }
  // Create/Open the source file 
  file_dest = creat(argv[3], O_WRONLY | PERMS);
  // Check for errors in opening the source file
  if(file_dest == -1) {
    printf("\nError in opening the file %s", argv[3]);
    exit(EXIT_SUCCESS);
  }
  // Function call 
  copy(file_source, file_dest); 
  exit(EXIT_SUCCESS);
}
// Function definition 
void copy(int f_old, int f_new) {
  int count;
  while((count = read(f_old, buffer, sizeof(buffer))) > 0) {
    write(f_new, buffer, count);
  } 
}