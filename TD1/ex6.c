#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	dup2(2,1); // remplacement sorte standard par sortie standard d'erreur

	printf("Hello");
	write(1, "world",5);
	return EXIT_SUCCESS;
}
