#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

	int file = open("ERREURS-LIRE.log", O_WRONLY | O_CREAT | O_APPEND);
	dup2(file, 2); //remplacement erreurs standards par fichier de log
 

	char *filename = argv[1];
	unsigned int position = atoi(argv[2]);
	unsigned int value;

	int fd = open(filename, O_RDONLY);
	lseek(fd, position, SEEK_SET);
	read(fd, &value, sizeof(unsigned int));
	
	write(1, &value, sizeof(unsigned int));
	printf("Value: %d\n", value);

	close(fd);
	close(file);
}
