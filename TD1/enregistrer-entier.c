#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char *filename=argv[1];
	unsigned int pos = atoi(argv[2]);
	unsigned int value = atoi(argv[3]);

	int fd = open(filename, O_WRONLY);
	lseek(fd, pos, SEEK_SET);
	write(fd, &value, sizeof(unsigned int));
	printf("\nC'est ecrit!\n");
	close(fd);

}
