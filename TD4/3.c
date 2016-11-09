#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int cpt;

void handler(int sig)
{
    cpt++;
    printf("%d. %s\n", cpt, strsignal(sig));
}

int main()
{
    int pid;
    cpt = 0;

    pid = getpid();
    printf("PID: %d\n", pid);

    struct sigaction sa;

    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = &handler;

    for(int i = 0; i != NSIG; i++)
    {
        sigaction(i, &sa, NULL);
    }

    while(1)
    {
        //printf("Nombre signaux: %d\n", cpt);
    }

}