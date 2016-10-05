#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int father_pid;
	int fk = fork(); // Duplication du processus

	if(fk == 0) // fork contient 0 si je suis dans le fils 
	{

		int child_pid = getpid();
		father_pid = getppid();
		//waitpid(father_pid, 0, 0); // On ajoute waitpid pour que le fils affiche toujours son message après le père, sert aussi pour faire un processus orphelin
		printf("Je suis %d et je suis le fils de %d\n", child_pid, father_pid);
	}
	else // Sinon il contient le PID du fils dans le père 
	{
		//wait(0); // On ajoute wait pour que le père attende son fils
		//sleep(5); On ajoute sleep pour faire du fils un processus zombie
		father_pid = getpid(); // Récupération du pid du père
		printf("Je suis %d et je suis le père de %d\n", father_pid, fk);
	}

	return (EXIT_SUCCESS);
}