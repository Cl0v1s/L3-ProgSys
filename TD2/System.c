#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int System(char *command)
{
	printf("running %s\n", command);
	int fk = fork();
	if(fk == 0)
	{
		execl("/bin/sh", "sh", "-c", command, 0);
	}
	else 
	{
		int status;
		wait(&status); //on attend la fin de l'execution
		printf("%d\n", status);
	}
}

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		printf("Besoin d'un paramètre\n");
		return 1;
	}


	System(argv[1]);

}