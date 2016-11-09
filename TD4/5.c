#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int child_pid, father_pid, argc, cpt, ind;
char ** args;

void father_handler(int sig)
{
    if(sig == SIGKILL)
    {
        kill(child_pid, SIGKILL); // Envoi de kill au fils
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Pere: Recu %s\n", strsignal(sig));
        kill(child_pid, SIGUSR1); // Envoi de l'ACK
    }
}

void child_handler(int sig)
{
    if(sig == SIGKILL)
    {
        kill(father_pid, SIGKILL); // Envoi de kill au fils
        exit(EXIT_SUCCESS);
    }
    else if(sig == SIGUSR1) // On a recu un ACK, on envoit la commande suivante 
    {
        if(cpt == 0)
        {
            kill(father_pid, SIGKILL); // Envoi de kill au fils
            exit(EXIT_SUCCESS);
        }

        int sign = atoi(args[ind]);
        ind ++;
        if(ind >= argc)
        {
            ind = 0;
            cpt--;
        }
        kill(father_pid, sign);
        printf("Fils: Envoi %s\n", strsignal(sign));
        
    }
}

int main(int argc_o, char ** args_o)
{

    argc = argc_o;
    args = args_o;

    // Suppression de la première entrée des paramètres (nom du programme)
    argc--;
    args++;

    // Récupération du nombre d'itérations
    cpt = atoi(args[0]);
    argc--;
    args++;
    ind = 0;

    printf("Préparation\n");

    // Préparation de la structure 
    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    // on règle le handler en fonction du fils/père

    int fk = fork();
    if(fk == 0) // Fils
    {
        father_pid = getppid();
        sa.sa_handler = &child_handler;

        for(int i = 0; i != NSIG; i++)
        {
            sigaction(i, &sa, NULL);
        }

        printf("%d: Fils pret, lancement\n", getpid());
        // Envoi d'un ACK à soi même pour lancer la sequence
        kill(getpid(), SIGUSR1);
        while(1);
    }
    else // Père
    {
        child_pid = fk;
        sa.sa_handler = &father_handler;

        for(int i = 0; i != NSIG; i++)
        {
            sigaction(i, &sa, NULL);
        }        

        printf("%d: Père pret\n", getpid());        
        while(1);
    }

    exit(EXIT_SUCCESS);
}