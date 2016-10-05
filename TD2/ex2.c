#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define TRUE 0
#define FALSE 1

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		printf("Need 1 parameter\n");
		return 1;
	}

	int number = atoi(argv[1]);
	int i = 0;
	int child = FALSE;
	int pid;

	while(i != number && child == FALSE)
	{
		pid = fork();
		if(pid == 0)
			child = TRUE;
		i++;	
	}

	if(child == TRUE) // bloc logique d'instruction des fils 
	{
		printf("Je suis %d\n", i - 1);
	}
	else // bloc d'instruction du père
	{
		for(i = 0; i != number; i++)
		{
			wait(0); // On attend la fin de tout les enfants
		}
	}
}