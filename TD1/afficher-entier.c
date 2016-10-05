#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file = open("entier-genere.txt", O_RDONLY);
	unsigned int val;
	int cpt = read(file,&val, sizeof(unsigned int));
	while(cpt > 0)
	{
		write(0, &val, cpt);
		cpt = read(file, &val, sizeof(unsigned int));
	} 
}
