#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <libio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#define N 3

typedef double (*f_pointer)(double);


double f1(double a)
{
    return a+1;
}
double f2(double a)
{
    return a-2;
}
double f3(double a)
{
    return a*2;
}


int main(int argc, char** argv)
{
    // Définition du tableau des fonctions
    f_pointer g[N];
    g[0] = &f1;
    g[1] = &f2;
    g[2] = &f3;

    int fd[2];
    int fk;
    double data;
    char* inputname = argv[1];
    char* outputname = argv[2];


    // Lancement de la chaine 
    printf("CHAIN\n");
    for(int i = 0; i != N; i++)
    {
        pipe(fd);
        dup2(fd[0], 0);
        data = 1;
        
        fk = fork();
        if(fk == 0)
        {
            close(fd[0]);
            write(fd[1], &data, sizeof(double));
            close(fd[1]);
            exit(0);
        }
        wait(NULL);
    }



}


