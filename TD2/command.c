#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		printf("Besoin d'un paramètre\n");
		return 1;
	}
	int fk = fork();
	if(fk == 0)
		execvp(argv[1],argv+1);
	else
	{
		int status;
		wait(&status);
		printf("Code de retour: %d\n", status);
	}
}

