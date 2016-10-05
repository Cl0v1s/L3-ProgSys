
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h> // lseek

#define LENGTH 5

int main(int argc, char *argv[])
{
	char c[LENGTH];
	int cpt = read(0,c,LENGTH);
	while(cpt > 0)
	{
		write(1, c,cpt);
		cpt = read(0,c, LENGTH);
	}
}
