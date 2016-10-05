#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int file = open("entier-genere.txt", O_WRONLY | O_CREAT);
	unsigned int cpt = 0;
	int limit = atoi(argv[1]);
	while(cpt != limit)
	{
		write(file, &cpt, sizeof(unsigned int));
		cpt++;
	}
}
