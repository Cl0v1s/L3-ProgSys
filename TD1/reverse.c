#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define LENGTH 2

int main(int argc, char *argv[])
{
	int i=0;

	char* sourcefilename = argv[1];
	char* outputfilename = argv[2];

	off_t size;

    char c[LENGTH];
	
	int source = open(sourcefilename, O_RDONLY);
	int output = open(outputfilename, O_WRONLY);

	size = lseek(source, 0, SEEK_END);	
	lseek(source, 0, SEEK_SET);	

	int cpt = read(source, &c, LENGTH);

	while(cpt > 0)
	{
		lseek(output, size, SEEK_SET);
		write(output, &c, cpt);
		size = size - cpt;
		cpt = read(source, &c, LENGTH);
		
	}
	/*fd = open(outputfilename, O_WRONLY | O_CREAT);
	for(i = size-1; i >= 0; i--)
	{
		printf("%d", i);
		write(fd, &content[i], sizeof(char));
	}
	close(fd);*/
}
