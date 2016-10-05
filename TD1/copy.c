#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define SIZE 5

void 
perror_and_exit_whenever(int assertion)
{
  if (assertion)
    {
      perror("");
      exit(EXIT_FAILURE);
    }
}

void test(int* power)
{
  power = power +1;
}

int 
main(int argc, char **argv)
{
  int power = 0;
  char p = 'a';
  char* ptr_p = &p;

  int tab[5];
  tab[1] = 6;

  int* ptr = &power;
  test(&power);

  size_t buffer_size;

 
  if (argc != SIZE)
    {
      fprintf(stderr,"%s : <input file name>"
	      " <output filename> <log2 of buffer length> \n", argv[0]);
      return EXIT_FAILURE;
    }
  
  power = strtoul(argv[3], NULL, 10);
  buffer_size = 1 << power;

  unsigned int input = open(argv[1], O_RDONLY);
  unsigned int output = open(argv[2], O_WRONLY | O_CREAT | O_SYNC);

  //printf("Copy par bloc de %d\n", buffer_size);

  char *buffer = malloc(buffer_size);
  int size;

  size = read(input, buffer, buffer_size);
  while(size > 0)
  {
    //printf("Ecriture de %d octets\n", size);
    write(output, buffer, size);
    //printf("%d octets écrits %d\n", size,buffer_size);
    size = read(input, buffer, buffer_size);
  }
  free(buffer);
  close(input);
  close(output);

 
  return EXIT_SUCCESS;
}
