#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

unsigned char code[] = {
  0x48, 0x89, 0xf8,                   // mov %rdi, %rax
  0x48, 0x83, 0xc0, 0x05,             // add $5, %rax
  0xc3                                // ret
};

typedef long (*foo)(long);

int main (int argc, char *argv[]) {
  
  void* memoryRegion = mmap(0, sizeof (code),
                   PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_ANON | MAP_PRIVATE, -1, 0);

  if (memoryRegion == (void*)-1) {
    printf ("Unable to allocate memory");
    return 1;
  }
  
  memcpy (memoryRegion, code, sizeof (code));  

  foo func = memoryRegion;
  printf ("%ld\n", func (2));
  
  return 0;
}
