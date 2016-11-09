#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char** args)
{
    int target, cpt, sig;

    printf("Preparation de la séquence\n");

    argc--;
    args++;

    target = atoi(args[0]);
    args++;
    argc--;
    cpt = atoi(args[0]);
    args++;
    argc--;

    printf("Envoi de signaux %d fois à %d\n", cpt, target);

    for(int i = 0; i!= cpt; i++)
    {
        for(int u = 0; u != argc; u++)
        {
            sig = atoi(args[u]);
            kill(target, sig);
            printf("Emission de %d à %d\n", sig, target);
        }
    }


}