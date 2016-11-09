#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

void handler(int sig)
{
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);
    printf("ctrl-c\n");
}

int main()
{
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_handler = &handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);


    while(1)
    {

    }
}