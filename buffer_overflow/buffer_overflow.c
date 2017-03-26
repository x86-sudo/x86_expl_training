#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main (int argc, char *argv[]) {
  
  char dstBuffer[BUFFER_SIZE];
  strcpy (dstBuffer, "dstString"); 
  
  printf ("Destination Buffer Content before strcpy () = %s\n", dstBuffer);

  // Copy user input string
  strcpy (dstBuffer, argv[1]);
  
  printf ("Destination Buffer Content = %s\n", dstBuffer);
 
  return 0; 
}
